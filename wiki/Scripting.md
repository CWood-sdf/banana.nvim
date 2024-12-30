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
