## Selectors

Banana currently supports the following minimal list of selectors:

- The universal selector (`*`)
- Descendant selectors (a space between two other selectors)
- Tag name selectors
- child selectors (`>`)
- id selectors
- class selectors
- Pseudo classes (currently only supporting `:not`, `:first-child`, `:last-child`, `:nth-of-type`, and `:nth-child`)

```css
/* universal selector. selects all elements on page */
* {
}
/* descendant. selects all elements that have two divs in their ancestry list */
div div * {
}

/* tag name */
div {
}

/* child selectors. selects all divs that have their parent a div */
div > div {
}

/* id */
#foo {
}

/* class */
.foo {
}

/* pseudo classes */
:not(div) {
}

div:first-child {
}
```

## Pseudo classes

### `:not(selector)`

`:not` selects any of the elements that do not match the given selector:

```css
/* selects any element that has a div parent, but is not a div */
div > :not(span) {
}
```

```html
<div>
  <div>not selected</div>
  <span> selected </span>
</div>
```

### `:first-child`

Selects any element that is the first child of its parent

### `:last-child`

Selects any element that is the last child of its parent

### `:nth-child(an+b)`

Selects any element that matches the equation. See [mdn documentation](https://developer.mozilla.org/en-US/docs/Web/CSS/:nth-child) for more info

### `:nth-of-type(an+b)`

This one has a little bit of weird behavior that differs from the css spec. It filters the input element list without caring about sibling relationships or anything
