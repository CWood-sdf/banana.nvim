# Banana.nvim

This plugin seeks to turn neovim into a hypermedia client through its own custom markup, styling, and scripting languages for extensions. It will also try to use the hypermedia controls that htmx uses to make building extensions easier.

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

- [ ] Basic Styling
- [ ] Complex styling (animations, transitions, position:absolute)
- [ ] Very Fast rendering
- [ ] Few errors
- [ ] Based on css

### Styler

- [ ] Should take in a page AST, and the styling AST, then apply all the rules

### Renderer Goals

- [ ] Should have a target that it can give the rendered lines to (this target could like render to a part of a buffer, or be a whole buffer renderer...)
- [x] Should take in AST and return Word[][]
- [ ] Respect the styling
- [ ] Robust (aka styling still works if buf really small)

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
