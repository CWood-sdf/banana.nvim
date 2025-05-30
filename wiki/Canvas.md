Banana currently has a *very* minimal implementation of the canvas api. This is to allow elements to be used as freeform drawing areas to create anything. See the [mdn article](https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D) to learn more about what is being partially implemented here

## Setup

All listed methods below are supposed to be called on a `Banana.Nml.CanvasContext`.

Obtaining a canvas context is trivial:

```lua
-- somehow get a canvas element
local canvas = document:getElementsByTagName("canvas")[1]

-- done!
local context = canvas:getContext()
```

After that, you can just call methods and stuff to render

## TOC


# Methods
  
## `setFillChar`

- **Parameters**:

  - `char` (string): 

## `setFillFg`

Sets the foreground (the text color) of fillChar

- **Parameters**:

  - `fg` (any): A string or other `vim.api.nvim_set_hl(..., { fg = ` acceptable value

## `setFillBg`

Sets the background (highlight) of fillChar

- **Parameters**:

  - `bg` (any): A string or other `vim.api.nvim_set_hl(..., { bg = ` acceptable value

## `text`

Writes the text at the specified position, and truncates it if it goes over the canvas width. Does not render anything if x or y are less than 0 (will be fixed eventually). If maxWidth is passed, then the text will be wrapped to fit in maxWidth, if necessary

- **Parameters**:

  - `str` (string): The string to render
  - `x` (number): The x offset to render at
  - `y` (number): The y offset to render at
  - `maxWidth` (number?): The maximum width of the text

## `point`

Places fillChar at x and y with the current bg and fg

- **Parameters**:

  - `x` (any): The x offset to render at
  - `y` (any): The y offset to render at

## `width`

Returns the width of the canvas

- **Returns**: `number` - width

## `height`

Returns the height of the canvas

- **Returns**: `number` - height

## `rect`

Draws a rectangle of fillChars with width `w` and height `h` at the specified x and y position

- **Parameters**:

  - `x` (number): The x position to draw at
  - `y` (number): The y position to draw at
  - `w` (number): The w position to draw at
  - `h` (number): The h position to draw at

## `background`

Clears the canvas with fillChar. (basically just calling rect(0, 0, width(), height())
