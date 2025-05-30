This section will detail how each tag works and any relevant notes for when using them.

The currently implemented tags are:

## TOC

- [`body`](#body)
- [`canvas`](#canvas)
- [`br`](#br)
- [`div`](#div)
- [`h1`](#h1)
- [`head`](#head)
- [`li`](#li)
- [`meta`](#meta)
- [`nml`](#nml)
- [`ol`](#ol)
- [`p`](#p)
- [`pre`](#pre)
- [`span`](#span)
- [`template`](#template)
- [`slot`](#slot)
- [`title`](#title)
- [`ul`](#ul)

## `body`

the body tag for an nml document

for all instances there MUST be one `<body>` under the `<nml>`

## `br`

inserts a line break

## `canvas`

A canvas that can be rendered to. See [canvas](Canvas) documentation for more

## `div`

a generic block-type container that has no default styling properties of its own

## `h1`

a heading level-one element. currently it has no default styling so it just appears as a `<p>` tag. a good default styling would be, but that is currently not enforced:

```ncss
h1 {
  hl-bold: true;
  hl-fg: hl-extract(fg, Title);
}
```

## `head`

the head tag for all `<nml>` documents. a place to put all `<meta>`, `<style>`, `<script>`, `<title>`, etc tags

## `li`

A list item tag. See [ul](Tag-ul) and [ol](Tag-ol) for reference

## `meta`

sets window and buffer properties on the [Instance](Instance)

to use this tag, just have an attribute that starts with an identifier, then a hyphen, then the attribute name, with a value

for example, to set the buffer filetype, use this tag:

```html
<meta name="buf-filetype" value="lua" />
```

if only one attribute is set on the meta tag, you can use the shorthand:

```html
<meta buf-filetype="lua" />
```

currently, the only supported identifiers are `buf-name` and `win-name` (for `vim.bo\[bufnr].name` and `vim.wo\[winnr].name`, respectively).

## `nml`

the nml tag for a document

Notes/Rules:

- all nml files that are directly opened by an instance (eg passed as the file parameter to create an instance) must have an nml tag as root tag
- setting the background on an `<nml>` tag or `<body>` tag sets the background for the whole window

## `ol`

creates an ordered list

the list type defaults to a number ("1."), but it can be set with [list-style-type](Prop-list-style-type)

## `p`

an unstyled block wise element. the only difference between this and [div](Tag-div) is that all elements inside of `<p>` must be inline, whereas `<div>` can contain block elements

## `pre`

This tag does not work fully yet **PLEASE DONT USE**

Contains unformatted text (eg any text in a pre will not be touched by the formatter)

### Example

```html
<nml>
  <head>
    <template name="Greet">
      <slot> hi </slot>
    </template>
  </head>

  <body>
    <Greet></Greet>
    <!-- says "hi" -->
    <Greet><span> hola </span></Greet>
    <!-- says "hola" -->
  </body>
</nml>
```

## `span`

an inline element with no default styles. literally consider this element as an inline div

## `template`

An element used to create a component. There are three attributes that it can have: `name`, `import`, and `use-imports-from`.

- if `name` is set, it creates a component tag that can be used with that name
- if `import` is set, the parser adds the listed file to the component search path for the current tree
- if `use-imports-from` is set, the parser adds all the items in the component search path at the root of the specified file to the current tree's component search path. Allows for the creation of component barrel files

### `name` example

```html
<nml>
  <head>
    <template name="Greet">
      <slot> hi </slot>
    </template>
  </head>

  <body>
    <Greet></Greet>
    <!-- says "hi" -->
    <Greet><span> hola </span></Greet>
    <!-- says "hola" -->
  </body>
</nml>
```

### `import` example

```html
<!-- in PLUGINDIR/banana/plugin/Greet.nml -->
<div>
  <template name="Greet">
    <slot> hi </slot>
  </template>
</div>

<!-- in some other file -->
<nml>
  <head>
    <template import="plugin/Greet"> </template>
  </head>

  <body>
    <Greet></Greet>
    <!-- says "hi" -->
    <Greet><span> hola </span></Greet>
    <!-- says "hola" -->
  </body>
</nml>
```

### `use-imports-from` example

```html
<!-- in PLUGINDIR/banana/plugin/Greet.nml -->
<div>
  <template name="Greet">
    <slot> hi </slot>
  </template>
</div>

<!-- in PLUGINDIR/banana/plugin/barrel.nml -->
<div>
  <template import="plugin/Greet"> </template>
</div>

<!-- in some other file -->
<nml>
  <head>
    <template use-imports-from="plugin/barrel"> </template>
  </head>

  <body>
    <Greet></Greet>
    <!-- says "hi" -->
    <Greet><span> hola </span></Greet>
    <!-- says "hola" -->
  </body>
</nml>
```

## `slot`

A place for optional user content in a component

See the above examples for template for example usage

## `title`

Sets the name of the buffer

for use in a `<head>` tag

## `ul`

creates an unordered list

the list type defaults to a star ("\*"), but it can be set with [list-style-type](Prop-list-style-type)
