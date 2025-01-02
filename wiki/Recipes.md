Here are some useful snippets/solutions for various problems.

## Creating a Command

```lua
local M = {}

M.instance = nil

function M.setup()
  -- Call `:YourCommand` in neovim to create the instance
  vim.api.nvim_create_user_command("YourCommand", function()
    if M.instance == nil then
      M.instance = require("banana.instance").newInstance("stuff", "arbitrary-buffer-name")
    end
    M.instance:open()
  end, {})
end
```

where `stuff` is associated to the file: `your-plugin-name/banana/stuff/index.nml`

## Load nml into element on command "init"

```lua
function M.__banana_run(document)
  local container = document:getElementById("container")
  if #container:children() == 0 then
    document:loadNmlTo("stuff/coolPage", container)
  end
end
```

where `container` is a `div` [tag](https://github.com/CWood-sdf/banana.nvim/wiki/Tags#div) in loaded nml.

```html
<nml>
  <head>
    <style>
      nml {
        /* for positioning the floating window */
        left: 5%;
        top: 5%;
      }
      body {
        /* for setting the floating window background color */
        hl-bg: red;
      }
    </style>
  </head>
  <body>
    <div id="container"></div>
  </body>
</nml>
```

and `coolPage` is associated to the file: `your-plugin-name/banana/stuff/coolPage.nml`.
