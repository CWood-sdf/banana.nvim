# Banana.nvim

A blazingly fast html renderer for neovim

> [!CAUTION]
>
> This project is still in early development.  
> Expect breaking changes and bugs, and please report any issues you encounter.

## The problem

I have made two large plugins for neovim: [pineapple](https://github.com/CWood-sdf/pineapple) and [spaceport](https://github.com/CWood-sdf/spaceport.nvim). For both of these plugins I ended up making my own specialized rendering frameworks. This was originally because I did not know about [nui](https://github.com/MunifTanjim/nui.nvim), but I did not switch my plugins over because there are a two major roadblocks with nui:

- It's a whole new set of tools that I have to learn
- It seems a little bit verbose

## The solution

Html!

I don't think it is too bold an assumption to say that every developer knows at least a little bit of html. So, it would be really nice if this knowledge everyone has could be transferrable to writing neovim plugins. This makes it so that rather than having to solve the problems of rendering, core features, and ui design, plugin authors do not need to solve rendering because it is all html.

So, the mission of banana is to make neovim uis absurdly easy by using html. For this, it has a custom html language offshoot and a custom css offshoot.

In the future, I would also like to have a lot of "extra" features that usually come to browsers via third-party libraries (eg jquery.load) so that plugin authors can just add banana as a dependency and start coding.

The banana renderer takes a design architecture that allows it to be blazingly fast: rendering is done in _one_ pass. There will be no reflowing of any elements ever because later elements were rendered. This also means that complicated box trees and render trees (for example, I believe ladybird uses two trees to render) are _not_ allowed in the renderer. This allows the renderer to be very simple (and fast) while also supporting most of the features of modern html and css. This rendering architecture does make some things (particularly floats) more complicated, but it lets everything else be very fast. This simplification is required because banana is written in lua (slower than the c++ that modern browsers use).

## Features

Partial or complete implementations exist for the following elements:

- div
- title
- script
- style
- meta
- ul
- ol
- li
- span

Html character entity support does not currently exist

Banana has added a very simple text templating system via the % character. Adding the text %asdf to an html element causes the renderer to replace %asdf with the value of the attribute 'asdf' in the first parent element that chas that attribute.

Partial or complete implementations exist for the following css properties (for the most uptodate list check lua/banana/ncss/validations.lua):

- hl-\* properties for highlighting (use the same properties as nvim_set_hl)
- hl-underline
- hl-italic
- hl-bold
- hl-fg
- hl-bg
- hl-link
- hl-\_\_name
- list-style-type (very partial)
- width
- height
- display (currently just flex, inherit, initial, and none) (block, inline... are not planned to be supported because banana only formats the tree once)
- flex-basis
- flex-shrink
- flex-grow
- flex-wrap
- text-align (missing justify)
- position (position: sticky is not possible to implement in neovim)
- z-index
- left
- right
- top
- bottom
- padding
- padding-left
- padding-right
- padding-top
- padding-bottom
- margin
- margin-left
- margin-right
- margin-top
- margin-bottom

Implementations for the following selectors exist:

- pseudo class (currently supporting :not, :last-child, :first-child. for uptodate list, see lua/banana/ncss/queryParser.lua)
- universal (\*)
- descendant (space)
- tag name
- child selector (>)
- class
- id

Currently the following css functions are implemented (for uptodate list see cssFunctions variable in lua/banana/ncss/valueParser.lua):

- rgb()
- hl-extract() (to get the values from a neovim highlight group)

The following units are implemented (for uptodate list see M.calcUnitNoMod in lua/banana/nml/ast.lua):

- ch
- fr
- %

## Structuring plugins

Banana searches for all nml and ncss in the banana/ folder in the neovim require path (similar to the lua/ folder for plugins), thus your plugins can be structured like this:

```
∟ Plugin
    ∟ banana/
        ∟ pluginName/
            ∟ markup.nml
    ∟ lua/
        ∟ pluginName/
            ∟ plugin.lua
```

Requiring these markup files uses the slash seperator that links use (rather than the dot lua uses). The filenames index.nml and index.ncss are the "init.lua"s for banana. So to require the file in banana/plugin/index.nml, the require path would just be "plugin"; to require banana/plugin/other.nml, the require path would be "plugin/other".

When using Instance:loadNmlTo(), adding "?..." allows parameter passing in the same way browsers use it. This feature is currently not spread accross the entire ecosystem, but it will happen eventually.

## Executing banana plugins

Opening a banana plugin is very simple:

```lua
-- the buffer name can be overriden using the <title> tag
local document = require('banana.instance').newInstance("require path", "initial buffer name")

-- opens the window
document:open()
```

## Scripting

There are two scripting methods available: seperate lua files and embedded lua.

Of the two, seperate lua files has much better support (lsp and parameter passing).

Loading a seperate lua file into an nml document is very simple:

```html
<script src="lua require path"></script>
```

this will work if the script returns either a function or a table with a key of \_\_banana_run that has a function.

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
```

Embedded lua is also very simple, banana predefines the document variable for you:

```html
<script>
  local element = document:getElementById("asdf")
</script>
```

## Api

The api is modeled very closely after the browser api, some extra functions might come later that make it also possible to use similar to jquery. Currently most of banana's internal api functions are listed as public, but start with an underscore; thus there are two rules for the api:

- _NEVER_ use a function that starts with an underscore
- _ONLY_ use the api functions, never use a property. To be safe, only use : for field access

### Extra api functions

A banana nml ast node (dom element) has a function called attachRemap. This function enables two features:

- remaps bound to a certain ast are cleaned up when that ast is removed
- remaps that require hovering over the element are only called when that is the case

The attachRemap function is almost the exact same as vim.keymap.set, but with an extra third parameter which is an array of restrictions. The array of restrictions is currently OR'd together

```lua
local ast = document:getElementById("foo")

ast:attachRemap(
    "n", "<leader>a", { 1, "hover" --[[ "line-hover" is also an option ]]},
    function()
        print("Either you prefixed this map with 1, or are hovering over the element")
    end,
    {
        -- buffer is already set, a feature is needed to prevent auto setting
    }
)

```

## NEEDED DOCUMENTATION

- developing banana
- developing a banana plugin
- specifics about all the apis and stuff

## Contributing

There is a lot of work still to be done. If you want to help out, the primary areas work is needed in are:

- table rendering
- grid rendering
- gradients
- documentation
- tests
- apis
- extensibility

## Final notes

As you can probably tell, this plugin is nowhere close to being done. If you would like to contribute to this plugin, by all means please do. If you don't want to contribute, but still find this project interesting, then give it a star. If you want to follow the progress, then "watch" it on github.

## Self promotion

Follow me on [X](https://x.com/CWood_sdf)

Try out my other two plugins: [spaceport](https://github.com/CWood-sdf/spaceport.nvim) and [pineapple](https://github.com/CWood-sdf/pineapple)

Follow me on github
