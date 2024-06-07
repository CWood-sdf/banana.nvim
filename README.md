# Banana.nvim

This plugin seeks to turn neovim into a hypermedia client through its own custom markup, styling, and scripting interface for extensions. It will also try to use the hypermedia controls similar to what htmx uses to make building extensions easier.

## 1.0 requirements

- Able to make actual uis with same level of difficulty as html
- Able to query any element on the page easily (with as much code as dom)
- As easy to write as html
- A proper framework for loading nml/ncss files (hopefully similar in usage to lua require)
- tests for pretty much every styling condition (uggh)
- impl all the styles not in the "Later styles section"

## Roadmap

### Api

- [x] Easy to load nml files
- [x] Title tag sets title of buf
- [ ] Meta tags set attributes (like maybe float...)
- [x] Nml width height sets win width/height
- [ ] Nml left, right, top, bottom sets win position

### Markup Language

- [x] Basic Renderer
- [x] Very Fast rendering
- [x] Attributes
- [ ] Good attributes api
- [ ] DOM Manipulation
- [ ] Hypermedia attributes
- [x] Read File

### Styling Language

- [x] Basic Styling
- [ ] Complex styling (animations, transitions, absolute positioning)
- [ ] Efficient style recalculation
- [x] Very Fast rendering
- [x] Few errors
- [x] Based on css
- [x] Have to do some inversions on the style treesitter tree

### Properties to implement

- [x] handles overflow
- [x] text-align (missing justify)
- [ ] aspect-ratio
- [ ] display: flexbox, grid, inline, inline-block, none, block
- [x] height/width
- [ ] list-style
- [ ] list-style-type (needed for ol)
- [ ] max/min-\*size

#### Later stuff

- [ ] outline?
- [ ] content? seems hard, do it later
- [ ] direction? seems easy but not extremely useful for now
- [ ] hyphenate-character (needs hyphenation)

#### Abs/float position

- [ ] left/right/top/bottom: needs abs position
- [ ] float: seems hard, do later
- [ ] z-index: req abs
- [ ] position: abs seems kinda difficult

#### Table stuff

- [ ] gap: more table stuff, do later
- [ ] row-gap: req table
- [ ] empty-cells: later

### Styler

- [x] Should take in a page AST, and the styling AST, then apply all the rules
- [ ] Needs to be really fast

### Style/Markup interface

- [x] Follow [this](https://stackoverflow.com/questions/25105736/what-is-the-order-of-precedence-for-css)
- [ ] Need maybe some caching, and some sort of trigger mechanism that lives on each element so that (for example) a class change can just retrigger only the needed selectors (might not be necessary bc it pretty fast)
- [x] Needs a good way of applying declarations to elements

### Renderer Goals

- [ ] Should have a target that it can give the rendered lines to (this target could like render to a part of a buffer, or be a whole buffer renderer...)
- [x] Should take in AST and return Word[][]
- [ ] Render caching?
- [ ] Need to actually compute width/height restrictions and follow them
- [ ] Flexbox?
- [ ] Respect the styling
- [ ] Robust (aka styling still works if win really small)

### Events

- [x] Good event interface (just using autocmd lol)

### Cleaner

- [x] Follow the html [block formatting spec](hhttps://developer.mozilla.org/en-US/docs/Web/CSS/CSS_display/Block_formatting_contextthttps://developer.mozilla.org/en-US/docs/Web/CSS/CSS_display/Block_formatting_contexttps://developer.mozilla.org/en-US/docs/Web/CSS/CSS_display/Block_formatting_context) and [inline formatting spec](https://developer.mozilla.org/en-US/docs/Web/CSS/Inline_formatting_context)

### Rendering pipeline

1. Parse nml
2. Parse styling
3. Apply styling
4. Execute Scripting? (js runs while the html is parsed(I think?)? should do this with lua? kinda feels like unneccessary added complexity (esp bc we have to apply styling while parsing) but im not sure)
5. Clean AST
6. Renderer
7. Pipe rendered words into the renderer target
8. Scripting now?

### Lua Scripting Interface

- [x] Basic Lua Scripting
- [x] Events (just using autocmd)
- [x] DOM Manipulation (very basic)

## Much later roadmap

### LSP

- [ ] Markup Language Server
- [ ] Styling
- [ ] Lua Scripting

### Tree-sitter

- [x] Markup Language
- [x] Styling

### Rewrite in rust (or zig)

Rewrite into rust or zig using nvim-oxi or ffi and stuff so that it can be much faster.
