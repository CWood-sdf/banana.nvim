# Usage

Below is a minimal config for using banana during development:

```lua
return {
    dir = "~/path/to/project/directory",
    build = function() 
        require("banana").installTsParsers()
    end,
    config = function()
        require("banana").initTsParsers()
    end,
}
```

Because banana uses custom parsers for nml and ncss, they must be registered and compiled manually by treesitter. With this config, you are able to get fancy-schmancy syntax highlighting for ncss and nml.

## Project Setup

Banana's hello world uses the below directory structure:

```
PWD
├── jumpstart.lua
├── banana
│   └── random_name
│       └── index.nml
└── lua
    └── example
        └── init.lua
```

The `jumpstart.lua` file will contain the following code, which will not change:

```lua
-- jumpstart.lua

local instance = require("banana").newInstance("stuff/clock", "random buffer name")

vim.keymap.set("n", "<leader>o", function()
    instance:open()
end, {})
```

By sourcing this file using the `:so` command, you are able to toggle opening and closing the banana page instance. This file is used for launching pages directly. If you want to launch your page later, as part of your plugin logic, then all you need to do is place these lines in whatever configuration that your plugin needs.

Notice that the banana nml package and the lua package don't have the same name. Banana does not require any sort of name coupling between the names of packages requiring each other; you can expect banana's require to have similar behaviour to that of lua's require. (Remember that banana uses "/" instead of ".")

## Project Content

Alright, enough preamble, it's time to get to the fun part. One thing that's important to remember when developing a banana plugin is that the nml is your entry point into your banana page; all of your lua scripts are called from that nml page. With that in mind, let's take a look at the following nml file:

```html
<nml>
  <head>
    <style>
      nml {
        width: 50%;
        height: 50%;
      }
      div {
        hl-bg: red;
        width: 50%;
      }
    </style>
  </head>
  <body>
    <div>Hello World!</div>
  </body>
</nml>
```

Awfully underwhelming, huh?
