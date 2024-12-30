The following functions are implemented:

## TOC

- [`rgb`](#rgb)
- [`hl-extract`](#hl-extract)
- [`linear-gradient`](#linear-gradient)
- [`radial-gradient`](#radial-gradient)
- [`repeat`](#repeat)

## `rgb`

Converts three numbers to an rgb color

- **Parameters**:
  - `red` (number): the red value
  - `green` (number)
  - `blue` (number)

Usage:

```css
div {
  hl-bg: rgb(255, 128, 0);
}
```

## `hl-extract`

Extracts a color value from a highlight group

- **Parameters**:
  - `section` (string or plain value): the section to extract (eg "fg" or "bg")
  - `group` (string or plain value): the highlight group to extract from

## `linear-gradient`

see [highlighting](Highlights) for more details

## `radial-gradient`

see [highlighting](highlights) for more details

## `repeat`

A macro for `grid-template-columns` that repeats a unit value n times

```ncss
div {
  display: grid;
  grid-template-columns: repeat(4, 1fr) 2fr;
}
```
