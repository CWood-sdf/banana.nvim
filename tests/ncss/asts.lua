local Ast = require('banana.nml.ast').Ast

local id = Ast:new('div')
id:setAttribute('id', 'test')

local class = Ast:new('div')
class:setAttribute('class', 'test1')

local class2 = Ast:new('div')
class2:setAttribute('class', 'test1 test2')

local div = Ast:new('div')
local span = Ast:new('span')
return {
    id = id,
    class = class,
    class2 = class2,
    div = div,
    span = span,
}
