# Scripting

There are two scripting methods available: separate lua files and embedded lua.

## separate files

Of the two, separate lua files has much better support (lsp and parameter passing).

Loading a separate lua file into an nml document is very simple:

```html
<script src="lua require path"></script>
```

this will work if the script returns either a function or a table with a key of \_\_banana_run that is a function.

```lua
--- Add types for luals
---@param document Banana.Instance
---@param opts table
return function(document, opts)
    -- any params passed from ?param=value
    -- only supported on loadNmlTo currently
    local params = opts.params
    local element = document:getElementById("asdf")
end
-- also allowed
return {
  -- ... other keys
  __banana_run = function(document, opts)
    -- scripting code
  end,
}
```

## embedded

Embedded lua is also very simple, banana predefines the document variable for you:

```html
<script>
  local element = document:getElementById("asdf")
</script>
```

## `when` Attribute

The `when` attribute allows you to control when youre scripts are ran in the document lifecycle. Currently, there are two times that a script can run: right before the first render and right after the first render. The default is right after the first render so that functions that return rendering information (eg `Ast:getWidth()`) are able to return correct values. However, a script that mutates the tree (eg with `Ast:appendChild()`) causes two renders to happen (once to gather the render information and run the scripts, and again to actually render). This can cause a significant slowdown if done too much, this is why banana provides the `when` attribute. The default value is `postrender`, however, that might not be desirable in all cases. If your script both mutates the tree and doesn't need render information, then setting `when="prerender"` can cause a rendering performance improvement.

### Examples

```lua
-- a good script to set prerender on
local el = document:createElement("div")
-- Mutates the tree
document:body():appendChild(el)
-- ... and doesnt need any render information
-- setting when="prerender" will improve performance
```

```lua
-- a bad script to set prerender on
local el = document:createElement("div")

-- needs render information: setting when="prerender" will cause a nil error
print(document:body():getWidth())
```

```lua
-- setting when= will have no affect on the performance
document:body():attachRemap("n", "K", { "hover" }, function()

end, {})
```

