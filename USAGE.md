# Usage

The first step to developing using any plugin/framework/voodoo ritual is setting up your environment. To get started with developing using nml and ncss, and get that fancy-schmancy syntax highlighting, it's best to include this line in your plugin config:

```lua
require("banana").initTsParsers()
```

This ensures that the tree-sitter parsers for nml & ncss are installed on your system, as well as registering the nml & ncss filetypes with neovim.

In addition, when developing a plugin which uses banana for its UI, make sure that you add the plugin to your plugin manager as a local plugin. Here's how to do this using lazy.nvim:

```lua
return {
    dir = "~/path/to/project/directory",
    config = function()
        -- Bees knees
    end,
}
```
