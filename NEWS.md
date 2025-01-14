# News

This is for documenting the major changes in each release version

## 0.2.0

This release introduced two major changes: gradients and components.

Gradients, unlike in the w3 spec, can be specified for both `hl-fg` and `hl-bg`. Currently, banana only supports `linear-gradient` and a subset of the features of `radial-gradient`, but adding support for other gradients will be relatively trivial now.

Components are an easy way to share markup across projects and in libraries. Thye are modeled somewhat closely off of webcomponents, by using the `<template>` and `<slot>` tags. However, unlike webcomponents, banana components require no scripting to work. More work still needs to be put in so that components can share data amongst each other and conditionally render markup for that data.

Along with these improvements, there were several bugfixes, most notably, making `aspect-ratio` work better

## 0.1.0

The biggest change in this release is the addition of grid rendering. Now, you can add `display: grid` to an element and all of its children become grid elements. This allows child elements to be layed out in a grid format rather than top to botttom as they normally are. Please see the [mdn documentation](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_grid_layout) to learn more. Currently, the following properties still need to be implmented:

- grid-template-areas
- grid-template (shorthand prop)
- grid-auto-columns
- grid-auto-rows
- grid-auto-flow
- grid
- grid-row-start
- grid-column-start
- grid-row-end
- grid-column-end
- grid-row
- grid-column
- grid-area
- gap

Along with that, there were some basic bugfixes and perf improvements: most notably, no longer allowing `fr` to be used as a sizing unit in flexbox (to follow the w3 spec).

## 0.0.1

First release, with a basic working library
