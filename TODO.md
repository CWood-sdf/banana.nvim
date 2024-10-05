# TODO

## 1.0 requirements

- Able to make actual uis with same level of difficulty as html
- Able to query any element on the page easily (with as much code as dom)
- As easy to write as html
- A proper framework for loading nml/ncss files (hopefully similar in usage to lua require)
- tests for pretty much every styling condition (uggh)
- impl all the styles not in the "Later styles section"
- dev tools

## Roadmap

### Upcoming big projects

- Animations + Transitions
- Components

### Api

- [x] Easy to load nml files
- [x] Title tag sets title of buf
- [x] Meta tags set attributes (like maybe float...)
- [x] Nml width height sets win width/height
- [x] Nml left, right, top, bottom sets win position

### Markup Language

- [ ] Character Entity Support
- [x] Basic Renderer
- [x] Very Fast rendering
- [x] Attributes
- [x] Good attributes api
- [x] DOM Manipulation
- [ ] Hypermedia attributes
- [x] Basic templating (maybe just substitution of attribute values)
- [x] Read File

### Components

- [ ] Per-file components? or define components with special tag (template?)?
- [ ] Child content (\<slot>)
- [ ] Attributes
- [ ] Dom queryable in contained scripts, but not outside (unless shadow=false)
- [ ] Inline/block detection
- [ ] Need a special renderer that just renders sub stuff?
- [ ] Seperate shadow dom (aka all component doms are stored as seperate trees)
- [ ] `shadow` property? (if !shadow then clone tree (also queryabledom), if shadow then noclone)
- [ ] Closelyish follows webcomponents
- [ ] should be similarish to loadNmlTo

### Styling Language

- [x] Basic Styling
- [ ] Complex styling (animations, transitions)
- [ ] Efficient style recalculation (not needed (hopefully) bc current application so fast (hopefully))
- [x] Very Fast rendering
- [x] Few errors
- [x] Based on css
- [x] Have to do some inversions on the style treesitter tree

### Properties to implement

- [x] handles overflow
- [x] text-align (missing justify)
- [ ] aspect-ratio
- [x] display: flex, grid, none
- [x] height/width
- [ ] list-style
- [x] list-style-type (needed for ol)
- [ ] max/min-\*size
- [ ] float: seems hard, do later

### Flex box

- [x] flex-grow
- [ ] flex-direction
- [x] flex-wrap
- [x] flex-basis
- [x] fr units
- [x] flex-shrink

### Grid

- [x] repeat()
- [x] grid-template-columns
- [x] grid-template-rows
- [ ] grid-template-areas
- [ ] grid-template (shorthand prop)
- [ ] grid-auto-columns
- [ ] grid-auto-rows
- [ ] grid-auto-flow
- [ ] grid
- [ ] grid-row-start
- [ ] grid-column-start
- [ ] grid-row-end
- [ ] grid-column-end
- [x] grid-row
- [x] grid-column
- [ ] grid-area
- [x] row-gap
- [x] column-gap
- [ ] gap

### Abs/relative position

- [x] left/right/top/bottom
- [x] z-index
- [x] position

### Fixed Position

- [ ] position: fixed

### Sticky

- [ ] position: sticky

### Transitions and animations

- [ ] transition
- [ ] animation

### Gradients

- [x] linear-gradient()
- [ ] Color space support
- [x] radial-gradient()
- [ ] conic-gradient()
- [ ] repeating-linear-gradient()

#### Later stuff

- [ ] outline?
- [ ] content? seems hard, do it later
- [ ] direction? seems easy but not extremely useful for now
- [ ] hyphenate-character (needs hyphenation) (currently using vim style hyphenation)

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
- [x] Need to actually compute width/height restrictions and follow them
- [x] Flexbox?
- [x] Respect the styling
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

Rewrite into rust or zig using nvim-oxi or ffi and stuff so that it can be much faster. Maybe rewrite just core rendering stuff (ast.lua/tags.lua and leave remaps and stuff in lua)
