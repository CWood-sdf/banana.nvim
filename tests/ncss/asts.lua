local Ast = require("banana.nml.ast").Ast

---@diagnostic disable-next-line: param-type-mismatch
local id = Ast:new("div", nil, "t")
id:setAttribute("id", "test")

---@diagnostic disable-next-line: param-type-mismatch
local class = Ast:new("div", nil, "t")
class:setAttribute("class", "test1")

---@diagnostic disable-next-line: param-type-mismatch
local class2 = Ast:new("div", nil, "t")
class2:setAttribute("class", "test1 test2")

---@diagnostic disable-next-line: param-type-mismatch
local div = Ast:new("div", nil, "t")
---@diagnostic disable-next-line: param-type-mismatch
local span = Ast:new("span", nil, "t")
return {
    id = id,
    class = class,
    class2 = class2,
    div = div,
    span = span,
}
