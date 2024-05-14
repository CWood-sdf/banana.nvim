# Banana.nvim

This plugin seeks to turn neovim into a hypermedia client through its own custom markup, styling, and scripting interface for extensions. It will also try to use the hypermedia controls similar to what htmx uses to make building extensions easier.

## Roadmap

### Markup Language

- [x] Basic Renderer
- [ ] Very Fast rendering
- [x] Attributes
- [ ] Good attributes api
- [ ] DOM Manipulation
- [ ] Hypermedia Controls
- [x] Read File

### Styling Language

- [x] Basic Styling
- [ ] Complex styling (animations, transitions, absolute positioning)
- [x] Very Fast rendering
- [ ] Few errors
- [x] Based on css
- [x] Have to do some inversions on the style treesitter tree

### Styler

- [x] Should take in a page AST, and the styling AST, then apply all the rules
- [ ] Needs to be really fast

### Style/Markup interface

- [ ] Need some sort of priority mechanism so that it isn't order based
- [ ] Need maybe some caching, and some sort of trigger mechanism that lives on each element so that (for example) a class change can just retrigger only the needed selectors
- [ ] Needs a good way of applying declarations to elements

### Renderer Goals

- [ ] Should have a target that it can give the rendered lines to (this target could like render to a part of a buffer, or be a whole buffer renderer...)
- [x] Should take in AST and return Word[][]
- [ ] Need to actually compute width/height restrictions and follow them
- [ ] Flexbox?
- [ ] Respect the styling
- [ ] Robust (aka styling still works if win really small)

### Events

- [ ] Good event interface

### Cleaner

- [ ] Follow the html [block formatting spec](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_display/Block_formatting_context) and [inline formatting spec](https://developer.mozilla.org/en-US/docs/Web/CSS/Inline_formatting_context)
- [ ] Should clone ast before cleaning?

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

- [ ] Basic Lua Scripting
- [ ] Events
- [ ] DOM Manipulation

#### Much later roadmap

### LSP

- [ ] Markup Language Server
- [ ] Styling
- [ ] Lua Scripting

### Tree-sitter

- [ ] Markup Language
- [ ] Styling
