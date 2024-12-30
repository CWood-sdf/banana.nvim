# Banana.nvim

A blazingly fast html renderer for neovim

> [!CAUTION]
>
> This project is still in early development.  
> Expect breaking changes and bugs, and please report any issues you encounter.

> [!NOTE]
>
> If there is a css/html feature that is not currently implemented, please submit an issue and it should probably be implemented within a few days

> [!NOTE]
>
> Banana only works on neovim version 0.10.0 and above

## Example

This is the banana hello world:

```html
<nml>
  <!-- in banana/stuff/foo.nml -->
  <head>
    <style>
      nml {
        width: 75%;
        height: 75%;
        left: 12%;
        top: 12%;
      }
    </style>
  </head>
  <body>
    <div>Hello World!</div>
  </body>
</nml>
```

then in a lua file:

```lua
local instance = require('banana.instance').newInstance("stuff/foo", "random buffer name")
instance:open()
```

or you can run the command `:BananaSo` inside that file for banana to automatically set up a testing instance

all of that code results in this window:

![helloworld](./assets/images/helloworld.png)

The file structure for this example can be seen below:

<img alt="banana-example-filetree" src="https://github.com/user-attachments/assets/0743a4d3-1c41-49eb-9c23-dd6609be3bb2" width="325" /><br />

this may seem underwhelming as the above result can be done in a few lines of lua, but banana starts becoming extremely helpful when you start doing more complex rendering cases like nested tags, css grid display, or css flex display. For a better example, check out [banana-example](https://github.com/CWood-sdf/banana-example) or the other examples below

### Other examples

Currently there are four examples: a todo app, a partial clone of the lazy.nvim plugin ui, an example tree element, and a counter app.

The todo's files are contained in banana/example/todo.nml and lua/banana_example/todo.lua. You can run it with `require('banana').runTodo()`

![TODO](./assets/images/todo.jpg)

The counter's files are contained in banana/example/counter.nml and lua/banana_example/counter.lua. You can run it with `require('banana').runCounter()`

![counter](./assets/images/counter.jpg)

Lazy's files are contained in banana/example/lazy/ and lua/banana_example/lazy/ and can be run with `require('banana').runLazy()`

![lazy](./assets/images/lazy.jpg)

The tree's files are contained in the same location as tree.nml and tree.lua and can be run with `require('banana').runTree()`

![tree](./assets/images/tree.jpg)

## Installation

> [!NOTE]
>
> Banana requires zig to be installed on your system

Banana can be installed like this in lazy:

```lua
return {
  "CWood-sdf/banana.nvim",
  opts = {
    -- if set to false, then you must call require("banana").initTsParsers() somewhere else
    -- this allows you to remove treesitter as a dependency so that you can continue lazy loading it
    -- if set to true, then it auto creates the treesitter parsers and loads nvim-treesitter
    setupTs = true,
  },
  dependencies = {
      "nvim-treesitter/nvim-treesitter",
  },
}
```

or it can be added as a dependency to your plugin.

There is no need to lazy load banana as all functionality inside the library is already lazy loaded

## Documenation

Please refer to the [banana wiki](https://github.com/CWood-sdf/banana.nvim/wiki) for documentation

## NEEDED DOCUMENTATION

- developing banana
- developing a banana plugin
- specifics about all the apis and stuff

## Contributing

There is a lot of work still to be done. If you want to help out, the primary areas work is needed in are:

- table rendering
- documentation
- tests
- apis
- extensibility

If you have a css/html feature that you really want implemented, post it in an issue and I will see what I can do. However, there are currently no plans to support jsx or the like because it will add a massive amount of complexity (in plugin dev's dx (lsp), my sanity (and dx), and probably the end user's experience too (perf issues)).

## Self promotion

Follow me on [x](https://x.com/CWood_sdf)

Try out my other two plugins: [spaceport](https://github.com/CWood-sdf/spaceport.nvim) and [pineapple](https://github.com/CWood-sdf/pineapple)

Follow me on github
