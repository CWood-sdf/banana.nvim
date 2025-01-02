---@module 'banana.utils.log'
local log = require("banana.lazyRequire")("banana.utils.log")
---@module 'banana.ncss.unit'
local unit = require("banana.lazyRequire")("banana.ncss.unit")
local M = {}
---@enum Banana.Ncss.ExpressionTree.Types
local exprTypes = {
    sub = "sub",
    add = "add",
    mul = "mul",
    div = "div",
    var = "var",
}

---@param v Banana.Ncss.StyleValueType
local function isexpr(v)
    if type(v) ~= "table" then return false end

    return v.isExprTree == true
end

-- {

---@class (exact) Banana.Ncss.ExpressionTree
---@field type Banana.Ncss.ExpressionTree.Types
---@field computed Banana.Ncss.StyleValue?
---@field compute fun(self: Banana.Ncss.ExpressionTree, parentWidth: number): Banana.Ncss.StyleValue
---@field computeClone fun(self: Banana.Ncss.ExpressionTree, parentWidth: number): Banana.Ncss.StyleValue
---@field getType fun(self: Banana.Ncss.ExpressionTree): Banana.Ncss.StyleValue.Types
---@field flatten fun(self: Banana.Ncss.ExpressionTree): Banana.Ncss.StyleValue
---@field isExprTree true
local ExprTree = {

}
function ExprTree:flatten()
    return {
        type = self:getType(),
        value = self,
    }
end

--}

-- {
---@class (exact) Banana.Ncss.ExpressionTree.AddSub : Banana.Ncss.ExpressionTree
---@field left Banana.Ncss.StyleValue
---@field right Banana.Ncss.StyleValue
local AddSubTree = {
}

setmetatable(AddSubTree, { __index = ExprTree })

---@param left Banana.Ncss.StyleValue
---@param right Banana.Ncss.StyleValue
---@return Banana.Ncss.ExpressionTree
function M.newAddTree(left, right)
    ---@type Banana.Ncss.ExpressionTree.AddSub
    local ret = {
        isExprTree = true,
        left = left,
        right = right,
        computeClone = AddSubTree.compute,
        flatten = AddSubTree.flatten,
        type = exprTypes.add,
        getType = AddSubTree.getType,
        compute = AddSubTree.compute,
    }
    setmetatable(ret, {
        __index = AddSubTree
    })
    return ret
end

---@param left Banana.Ncss.StyleValue
---@param right Banana.Ncss.StyleValue
---@return Banana.Ncss.ExpressionTree
function M.newSubTree(left, right)
    ---@type Banana.Ncss.ExpressionTree.AddSub
    local ret = {
        isExprTree = true,
        left = left,
        right = right,
        computeClone = AddSubTree.compute,
        flatten = AddSubTree.flatten,
        type = exprTypes.sub,
        getType = AddSubTree.getType,
        compute = AddSubTree.compute,
    }
    setmetatable(ret, {
        __index = AddSubTree
    })
    return ret
end

---@param l Banana.Ncss.StyleValue.Types
---@param r Banana.Ncss.StyleValue.Types
---@return Banana.Ncss.StyleValue.Types
local function floatConvert(l, r)
    if l == "float" and r == "integer" then
        return "float"
    end
    if l == "integer" and r == "float" then
        return "float"
    end
    return l
end

---@return Banana.Ncss.StyleValue.Types
function AddSubTree:getType()
    local left = self.left.type
    local right = self.right.type

    if floatConvert(left, right) ~= floatConvert(right, left) then
        log.throw(
            "Left and right types are not the same in an add/sub ncss expression tree. NOTE: Got '" ..
            left .. "' and '" .. right .. "'")
    end
    if left ~= "unit" and left ~= "integer" and left ~= "float" then
        log.throw(
            "Can only add and subtract units, integers, and floats in ncss calc(). NOTE: got two " ..
            left .. "'s")
    end
    return left
end

---@return Banana.Ncss.StyleValue
function AddSubTree:flatten()
    if isexpr(self.left.value) or isexpr(self.right.value) then
        return {
            value = self,
            type = self:getType()
        }
    elseif self:getType() ~= "unit" then
        -- can send 0 in parentWidth bc not computing a unit
        return self:compute(0)
    elseif self.left.value.unit == self.right.value.unit then
        local lv = self.left.value.value
        local rv = self.right.value.value
        if self.type == "sub" then
            rv = -rv
        end
        return {
            type = "unit",
            value = unit.newUnit(self.left.value.unit, lv + rv),
        }
    end
    return {
        value = self,
        type = self:getType()
    }
end

---@param parentWidth number
---@return Banana.Ncss.StyleValue
function AddSubTree:compute(parentWidth)
    local left = self.left.value
    local right = self.right.value
    local leftType = self.left.type
    local rightType = self.right.type
    if type(left) == "table" and left.isExprTree then
        ---@diagnostic disable-next-line: cast-local-type, param-type-mismatch
        left = left:compute(parentWidth)
    elseif type(left) == "table" then
        left:compute(parentWidth)
    end
    if type(right) == "table" and right.isExprTree then
        ---@diagnostic disable-next-line: cast-local-type, param-type-mismatch
        right = right:compute(parentWidth)
    elseif type(right) == "table" then
        right:compute(parentWidth)
    end
    local ret
    if leftType == "integer" or leftType == "float" then
        if self.type == exprTypes.add then
            ret = {
                type = floatConvert(leftType, rightType),
                value = left + right,
            }
        else
            ret = {
                type = floatConvert(leftType, rightType),
                value = left - right,
            }
        end
    elseif self.type == exprTypes.add then
        ret = {
            type = "unit",
            value = unit.newUnit("ch",
                left.computed + right.computed,
                left.computed + right.computed)
        }
    else
        ret = {
            type = "unit",
            value = unit.newUnit("ch",
                left.computed - right.computed,
                left.computed - right.computed)
        }
    end
    self.computed = ret
    return ret
end

--}


-- {

---@class (exact) Banana.Ncss.ExpressionTree.Div : Banana.Ncss.ExpressionTree
---@field left Banana.Ncss.StyleValue
---@field right Banana.Ncss.StyleValue
local DivTree = {
}

setmetatable(DivTree, { __index = ExprTree })

---@param left Banana.Ncss.StyleValue
---@param right Banana.Ncss.StyleValue
---@return Banana.Ncss.ExpressionTree
function M.newDivTree(left, right)
    ---@type Banana.Ncss.ExpressionTree.Div
    local ret = {
        isExprTree = true,
        left = left,
        right = right,
        computeClone = DivTree.compute,
        flatten = DivTree.flatten,
        type = exprTypes.div,
        getType = DivTree.getType,
        compute = DivTree.compute,
    }
    setmetatable(ret, {
        __index = DivTree
    })
    return ret
end

---@return Banana.Ncss.StyleValue.Types
function DivTree:getType()
    local left = self.left.type
    local right = self.right.type

    if left ~= "unit" and left ~= "integer" and left ~= "float" then
        log.throw(
            "Can only divide units, integers, and floats in ncss calc(). NOTE: got  " ..
            left .. "' on the left side of a division")
    end
    if right ~= "integer" and right ~= "float" then
        log.throw(
            "Can only divide by integers and floats in ncss calc(). NOTE: got  " ..
            right .. "' on the right side of a division")
    end
    if left == "unit" then
        return "unit"
    end
    return floatConvert(left, right)
end

---@return Banana.Ncss.StyleValue
function DivTree:flatten()
    if isexpr(self.left.value) or isexpr(self.right.value) then
        return {
            type = self:getType(),
            value = self
        }
    elseif self:getType() ~= "unit" then
        return self:compute(0)
    else
        local u = self.left.value.unit
        local lv = self.left.value.value
        local rv = self.right.value
        return {
            type = "unit",
            value = unit.newUnit(u, lv / rv),
        }
    end
end

---@param parentWidth number
---@return Banana.Ncss.StyleValue
function DivTree:compute(parentWidth)
    local left = self.left.value
    local right = self.right.value
    local leftType = self.left.type
    local rightType = self.right.type
    if isexpr(left) then
        ---@diagnostic disable-next-line: cast-local-type, param-type-mismatch
        left = left:compute(parentWidth)
    elseif type(left) == "table" then
        left:compute(parentWidth)
    end
    if isexpr(right) then
        ---@diagnostic disable-next-line: cast-local-type, param-type-mismatch
        right = right:compute(parentWidth)
    elseif type(right) == "table" then
        right:compute(parentWidth)
    end
    ---@type Banana.Ncss.StyleValue
    local ret
    if leftType == "unit" then
        ret = {
            type = "unit",
            value = unit.newUnit("ch", left.value / right)
        }
    else
        ret = {
            type = floatConvert(leftType, rightType),
            value = left / right
        }
        if ret.type == "integer" then
            ---@diagnostic disable-next-line: param-type-mismatch
            ret.value = math.floor(ret.value)
        end
    end
    self.computed = ret
    return ret
end

--}

-- {

---@class (exact) Banana.Ncss.ExpressionTree.Mult : Banana.Ncss.ExpressionTree
---@field left Banana.Ncss.StyleValue
---@field right Banana.Ncss.StyleValue
local MultTree = {
}

setmetatable(MultTree, { __index = ExprTree })

---@param left Banana.Ncss.StyleValue
---@param right Banana.Ncss.StyleValue
---@return Banana.Ncss.ExpressionTree
function M.newMultTree(left, right)
    ---@type Banana.Ncss.ExpressionTree.Mult
    local ret = {
        isExprTree = true,
        left = left,
        right = right,
        computeClone = MultTree.compute,
        flatten = MultTree.flatten,
        type = exprTypes.div,
        getType = MultTree.getType,
        compute = MultTree.compute,
    }
    setmetatable(ret, {
        __index = MultTree
    })
    return ret
end

---@return Banana.Ncss.StyleValue.Types
function MultTree:getType()
    local left = self.left.type
    local right = self.right.type

    if left ~= "unit" and left ~= "integer" and left ~= "float" then
        log.throw(
            "Can only multiply units, integers, and floats in ncss calc(). NOTE: got  " ..
            left .. "' on the left side of a multiplication")
    end
    if right ~= "integer" and right ~= "float" and right ~= "unit" then
        log.throw(
            "Can only multiply by units, integers, and floats in ncss calc(). NOTE: got  " ..
            right .. "' on the right side of a multiplication")
    end
    if left == "unit" and left == right then
        log.throw(
            "Two unit values cannot be multiplied together in ncss calc().")
    end
    if left == "unit" or right == "unit" then
        return "unit"
    end
    return floatConvert(left, right)
end

---@return Banana.Ncss.StyleValue
function MultTree:flatten()
    if isexpr(self.left.value) or isexpr(self.right.value) then
        return {
            type = self:getType(),
            value = self
        }
    elseif self:getType() ~= "unit" then
        return self:compute(0)
    else
        local u = ""
        local lv = 0
        local rv = 0
        if type(self.left.value) == "table" then
            u = self.left.value.unit
            lv = self.left.value.value
            ---@diagnostic disable-next-line: cast-local-type
            rv = self.right.value
        else
            u = self.right.value.unit
            lv = self.right.value.value
            ---@diagnostic disable-next-line: cast-local-type
            rv = self.left.value
        end
        return {
            type = "unit",
            value = unit.newUnit(u, lv * rv),
        }
    end
end

---@param parentWidth number
---@return Banana.Ncss.StyleValue
function MultTree:compute(parentWidth)
    local left = self.left.value
    local right = self.right.value
    local leftType = self.left.type
    local rightType = self.right.type
    if isexpr(left) then
        ---@diagnostic disable-next-line: cast-local-type, param-type-mismatch
        left = left:compute(parentWidth)
    elseif type(left) == "table" then
        left:compute(parentWidth)
    end
    if isexpr(right) then
        ---@diagnostic disable-next-line: cast-local-type, param-type-mismatch
        right = right:compute(parentWidth)
    elseif type(right) == "table" then
        right:compute(parentWidth)
    end
    ---@type Banana.Ncss.StyleValue
    local ret
    if leftType == "unit" then
        ret = {
            type = "unit",
            value = unit.newUnit("ch", left.value.value * right.value)
        }
    elseif rightType == "unit" then
        ret = {
            type = "unit",
            value = unit.newUnit("ch", left.value * right.value.value)
        }
    else
        ret = {
            type = floatConvert(leftType, rightType),
            value = left.value * right.value
        }
    end
    self.computed = ret
    return ret
end

--}

return M
