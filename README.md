# Banana.nvim

This plugin seeks to turn neovim into a hypermedia client through its own custom markup, styling, and scripting interface for extensions. It will also try to use the hypermedia controls similar to what htmx uses to make building extensions easier.

Banana is designed to make neovim uis absurdly easy by using html. For this, it has a custom html language offshoot and a custom css offshoot. The goal of banana is to have an lsp and also a devtools-esque debug window to make development easier.

> [!CAUTION]
>
> This project is still in early development.  
> Expect breaking changes and bugs, and please report any issues you encounter.

The banana renderer takes a design architecture that allows it to be blazingly fast: rendering is done in _one_ pass. There will be no reflowing of any elements ever because later elements were rendered. This also means that complicated box trees and render trees (for example, I believe ladybird uses two trees to render) are _not_ allowed in the renderer. This allows the renderer to be very simple (and fast) while also supporting most of the features of modern html and css. This rendering architecture does make some things (particularly floats) more complicated, but it lets everything else be very fast. This simplification is required because banana is written in lua (slower than the c++ that modern browsers use).

Partial or complete implementations exist for the following elements:

- div
- title
- meta
- ul
- ol
- li
- span

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
- display (currently just flex, inherit, initial, and none)
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

## NEEDED DOCUMENTATION

- creating and opening instance
- instance/ast api
- scripting support
- banana path
- using remaps
- developing banana
- developing a banana plugin
