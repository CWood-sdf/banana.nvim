## Properties

For most of the properties on this page, you can just look up its documentation on the mdn docs [here](https://developer.mozilla.org/en-US/docs/Web/CSS/Reference)

## TOC

- [hl-underline](#hl-underline)
- [hl-italic](#hl-italic)
- [hl-bold](#hl-bold)
- [hl-fg](#hl-fg)
- [hl-bg](#hl-bg)
- [hl-\_\_name](#hl-__name)
- [hl-link](#hl-link)
- [width](#width)
- [height](#height)
- [aspect-ratio](#aspect-ratio)
- [list-style-type](#list-style-type)
- [text-align](#text-align)
- [display](#display)
- [flex-basis](#flex-basis)
- [flex-shrink](#flex-shrink)
- [flex-grow](#flex-grow)
- [flex-wrap](#flex-wrap)
- [grid-template-columns](#grid-template-columns)
- [grid-template-rows](#grid-template-rows)
- [grid-row](#grid-row)
- [grid-column](#grid-column)
- [row-gap](#row-gap)
- [column-gap](#column-gap)
- [position](#position)
- [z-index](#z-index)
- [left](#left)
- [right](#right)
- [top](#top)
- [bottom](#bottom)
- [padding](#padding)
- [padding-left](#padding-left)
- [padding-right](#padding-right)
- [padding-top](#padding-top)
- [padding-bottom](#padding-bottom)
- [margin](#margin)
- [margin-left](#margin-left)
- [margin-right](#margin-right)
- [margin-top](#margin-top)
- [margin-bottom](#margin-bottom)

Following is all the properties currently allowed:

# Highlighting

## hl-underline

Accepts:

- `<bool>`

## hl-italic

Accepts:

- `<bool>`

## hl-bold

Accepts:

- `<bool>`

## hl-fg

Accepts:

- `<color>`
- `<gradient>`
- `<plain value>` (eg red)

## hl-bg

Accepts:

- `<color>`
- `<gradient>`
- `<plain value>` (eg red)

## hl-\_\_name

Sets the name of the highlight group to allow global overriding. See [Highlights](Highlights) for more info

Accepts:

- `<string>`
- `<plain value>`

## hl-link

Accepts:

- `<string>`
- `<plain value>`

# Sizing

## width

Accepts:

- `<number>(ch|%)`

## height

Accepts:

- `<number>(ch|%)`

## aspect-ratio

Sets the aspect ratio of the element

[docs](https://developer.mozilla.org/en-US/docs/Web/CSS/aspect-ratio)

Accepts:

- `<number>`

# Miscellaneous

## text-align

Accepts:

- `left`
- `right`
- `center`
- `initial`
- `inherit`

## display

Accepts:

- `grid`
- `flex`
- `inherit`
- `initial`
- `none`

## list-style-type

Changes the bullet point type of all children elements. (Default "\*")

Accepts:

- `<string>` (eg "● " changes ul li's to ●)
- `roman`. Lowercase roman numerals (only works in `<ol>`)
- `Roman`. Uppercase roman numerals (only works in `<ol>`)
- `alpha`. Lowercase letters (only works in `<ol>`)
- `Alpha`. Uppercase letters (only works in `<ol>`)
- `number`. Numbers (only works in `<ol>`)
- `star`. A "\*" (only works in `<ul>`)
- `dash`. A "-" (only works in `<ul>`)

# Flex properties

## flex-basis

Accepts:

- `<number>(ch|%)`

## flex-shrink

Accepts:

- `<number>`

## flex-grow

Accepts:

- `<number>`

## flex-wrap

Accepts:

- `wrap`
- `nowrap`

# Grid properties

## grid-template-columns

The special thing about this is the `nfr` unit. This stands for "non expandable fractional". This exists because the default behavior in banana is to fill all available spacewhen using `fr` potentially causing the first few columns to be bigger than the last columns by a character or two. This might break other things like `aspect-ratio`

Accepts:

- `<number>(ch|%|fr|nfr)...`

## grid-template-rows

Accepts:

- `<number>(ch|%|fr|nfr)...`

## grid-row

Accepts:

- `<integer>`
- `span <integer>`
- `<integer> / <integer>`
- `<integer> / span <integer>`

## grid-column

Accepts:

- `<integer>`
- `span <integer>`
- `<integer> / <integer>`
- `<integer> / span <integer>`

## row-gap

Accepts:

- `<number>(ch|%)`

## column-gap

Accepts:

- `<number>(ch|%)`

# positioning

## position

Accepts:

- `absolute`
- `static`
- `relative`
- `inherit`
- `initial`

## z-index

Accepts:

- `<integer>`

## left

Accepts:

- `<number>(ch|%)`

## right

Accepts:

- `<number>(ch|%)`

## top

Accepts:

- `<number>(ch|%)`

## bottom

Accepts:

- `<number>(ch|%)`

# padding and margin

## padding

Accepts:

- `<unit>`
- `<unit> <unit>`
- `<unit> <unit> <unit>`
- `<unit> <unit> <unit> <unit>`

## padding-left

Accepts:

- `<number>(ch|%)`

## padding-right

Accepts:

- `<number>(ch|%)`

## padding-top

Accepts:

- `<number>(ch|%)`

## padding-bottom

Accepts:

- `<number>(ch|%)`

## margin

Accepts:

- `<unit>`
- `<unit> <unit>`
- `<unit> <unit> <unit>`
- `<unit> <unit> <unit> <unit>`

## margin-left

Accepts:

- `<number>(ch|%)`

## margin-right

Accepts:

- `<number>(ch|%)`

## margin-top

Accepts:

- `<number>(ch|%)`

## margin-bottom

Accepts:

- `<number>(ch|%)`
