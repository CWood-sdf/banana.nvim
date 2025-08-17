# Banana.nvim

A blazingly fast html renderer that allows you to write uis for neovim in html

> [!CAUTION]
>
> This project is still in early development.  
> Expect breaking changes and bugs, and please report any issues you encounter.

> [!NOTE]
>
> If there is a css/html feature that is not currently implemented, please submit an issue and it should probably be implemented within a few days

> [!NOTE]
>
> Banana only works on neovim version 0.11.0 and above

## Why

If you've ever written a UI for neovim using `nvim_buf_set_lines` for content and `nvim_buf_add_extmark` for highlights, you know that it is not very easy to do as soon as you want something that is not easily understandable as a bunch of lines. 
Sometimes, it is easier to think about a UI as independent boxes that can be moved around, padded, margined, etc. 

This is why banana exists: it allows you to express a UI as html to vastly simplify the process of everything

## Example

To create a simple hello world, put the following code in a file that ends with `.nml` and run the command `:BananaSo` (just like running `:so` in a lua file) inside it:

```html
<nml>
  <head>
    <!-- we will put stuff here later -->
  </head>
  <body>
    <div>Hello World!</div>
  </body>
</nml>
```

If you want to resize the window, you can add the following code to the `<head>` tag:

```html
<head>
  <style>
    nml {
      left: 10%;
      top: 10%;
      width: 50%;
      height: 50%;
    }
  </style>
</head>
```

If you want to change element colors, you can add the following code to the stylesheet:

```css
div {
  /* hl-<name> passes <name> to nvim_set_hl, currently only some properties are supported */
  hl-bg: red;
  hl-fg: black;
  hl-bold: true;
}
```

If you want to add a script to the page, you can add the following code to the body tag:

```html
<body>
<script>
  -- its just lua code here!
  local div = document:getElementByTagName("div")[1]
  -- makes it so that when you press K with the cursor over the div, it prints a message
  div:attachRemap("n", "K", { "hover" }, function()
    print("Hovering over the div!")
  end, {})
</script>
</body>
```

If you want to create a UI that can be reopened and closed, save the nml file to `<folder>/banana/<name>/<file>.nml` (where `<folder>` is somewhere in your lua path (eg `~/.config/nvim`)), and run the following lua code:

```lua
-- NOTE: This can go multiple directories down (eg dir1/dir2/<file>)
local document = require("banana.instance").newInstance("<name>/<file>", "Window name")

document:open()
document:close()
```

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
