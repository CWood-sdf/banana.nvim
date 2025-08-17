The AST class is the second of two API surfaces that you will use for any interaction with the dom tree in banana (the other one being Instance).

Not all of the browser api functions are implemented, but what I have now is hopefully enough for the API to be usable.
If there are any missing features of the browser API that you would really like ported to banana, submit an issue or a pr.

The functions are grouped into a few categories.

## TOC

- [`getData`](#getData)
- [`setData`](#setData)
- [`getContext`](#getContext)
- [`getRootNode`](#getRootNode)
- [`getTagName`](#getTagName)
- [`setInnerNml`](#setInnerNml)
- [`hasStyle`](#hasStyle)
- [`assertHasStyle`](#assertHasStyle)
- [`marginLeft`](#marginLeft)
- [`marginRight`](#marginRight)
- [`marginTop`](#marginTop)
- [`marginBottom`](#marginBottom)
- [`paddingLeft`](#paddingLeft)
- [`paddingRight`](#paddingRight)
- [`paddingTop`](#paddingTop)
- [`paddingBottom`](#paddingBottom)
- [`cloneNode`](#cloneNode)
- [`insertBefore`](#insertBefore)
- [`removeChild`](#removeChild)
- [`replaceChild`](#replaceChild)
- [`firstChild`](#firstChild)
- [`lastChild`](#lastChild)
- [`nextSibling`](#nextSibling)
- [`previousSibling`](#previousSibling)
- [`ownerDocument`](#ownerDocument)
- [`clone`](#clone)
- [`setAttribute`](#setAttribute)
- [`getAttributes`](#getAttributes)
- [`setStyle`](#setStyle)
- [`setStyleValue`](#setStyleValue)
- [`hasClass`](#hasClass)
- [`removeClass`](#removeClass)
- [`addClass`](#addClass)
- [`toggleClass`](#toggleClass)
- [`getBoundBox`](#getBoundBox)
- [`getWidth`](#getWidth)
- [`getHeight`](#getHeight)
- [`isNil`](#isNil)
- [`remove`](#remove)
- [`getAttribute`](#getAttribute)
- [`hasAttribute`](#hasAttribute)
- [`appendTextNode`](#appendTextNode)
- [`appendTextNodeNoEscape`](#appendTextNodeNoEscape)
- [`appendChild`](#appendChild)
- [`isLineHovering`](#isLineHovering)
- [`isHovering`](#isHovering)
- [`removeChildren`](#removeChildren)
- [`children`](#children)
- [`childIterWithI`](#childIterWithI)
- [`allChildIter`](#allChildIter)
- [`childIter`](#childIter)
- [`child`](#child)
- [`getAttributeSubstitution`](#getAttributeSubstitution)
- [`getTextContent`](#getTextContent)
- [`setTextContent`](#setTextContent)
- [`parent`](#parent)
- [`isHidden`](#isHidden)
- [`attachRemap`](#attachRemap)

## `getData`

Returns the data associated with the ast [UNSTABLE]

Functionally, this is a non-string version of get/setAttribute. This is
intended to be used with components to pass data as parameters to them

- **Parameters**:

  - `item` (string?): The name of the data item to get

- **Returns**: `any?` - the value of the data item

## `setData`

Sets the data associated with the array [UNSTABLE]

Functionally, this is a non-string version of get/setAttribute. This is
intended to be used with components to pass data as parameters to them

- **Parameters**:

  - `key` (string): The name of the data item to set
  - `value` (any): the value of the data item

## `getContext`

Returns a canvas context that can be used to render.
This ONLY returns a valid context on `<canvas>` elements, otherwise, it
returns nil.
See [canvas rendering](https://github.com/CWood-sdf/banana.nvim/wiki/Canvas)
for more details

- **Returns**: `Banana.Nml.CanvasContext` - 

## `getRootNode`

Returns the root node of this section of the DOM tree

In components, this will return a the <template> tag that the component runs
inside, otherwise, it will return the <nml> tag

- **Returns**: `Banana.Ast` - The root node

## `getTagName`

Returns the name of the tag that this ast node is for (eg. 'div')

- **Returns**: `string` - The tag name

## `setInnerNml`

Sets the nodelist of this ast to be equivalent to the NML string provided.

note: due to a limitation of the current nml parser, the entire string MUST
be contained inside a single element (eg setInnerNml('<span>asdf <span> idk </span></span>')
is allowed but setInnerNml('asdf <span> idk </span>') is not)

- **Parameters**:

  - `nml` (string): The nml string to set this ast's content to

## `hasStyle`

Returns true if the style {style} (eg. 'hl-fg') is in the node's style list

- **Parameters**:

  - `style` (string): the style to lookup

- **Returns**: `boolean` - True if the style is in the node's style list

## `assertHasStyle`

Throws an error if the style {style} has not been set in the node's style list

- **Parameters**:

  - `style` (string): the style to lookup

## `marginLeft`

Returns the actual left side margin of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `marginRight`

Returns the actual right side margin of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `marginTop`

Returns the actual top side margin of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `marginBottom`

Returns the actual bottom side margin of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `paddingLeft`

Returns the actual left side padding of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `paddingRight`

Returns the actual right side padding of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `paddingTop`

Returns the actual top side padding of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `paddingBottom`

Returns the actual bottom side padding of the element (in characters)

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `cloneNode`

Duplicates the ast node to eg allow it to be located in two different places
in the tree.

This is the same function as `ast:clone()`, but is here for dom api
compatibility

note: DOES NOT clone remaps or associated scripts

- **Parameters**:

  - `deep` (boolean?): Whether to also clone the child nodes (default true)

- **Returns**: `Banana.Ast` - 

## `insertBefore`

Adds {child} to this node's child list right before {referenceNode}

note: if passing string parameters for {child}, there is the possibility that
the same string is located multiple times in the ast's nodelist, leading to
strange results. there is also the possibility that the string passed for
{child} is not found due to the formatting

- **Parameters**:

  - `child` (Banana.Ast|string): The child in the nodelist to insert before
  - `referenceNode` (Banana.Ast|string): The node to insert into the tree

## `removeChild`

Removes {child} from this node's child list and then returns it

note: if passing string parameters for {child}, there is the possibility that
the same string is located multiple times in the ast's nodelist, leading to
strange results. there is also the possibility that the string passed for
{child} is not found due to the formatting

- **Parameters**:

  - `child` (Banana.Ast|string): The node to remove

- **Returns**: `Banana.Ast|string|nil` - 

## `replaceChild`

Replaces {child} from this node's child list with {newChild} and then returns
the removed element

note: if passing string parameters for {child}, there is the possibility that
the same string is located multiple times in the ast's nodelist, leading to
strange results. there is also the possibility that the string passed for
{child} is not found due to the formatting

- **Parameters**:

  - `child` (Banana.Ast|string): The child to replace
  - `newChild` (Banana.Ast|string): The new child to put in place

- **Returns**: `Banana.Ast|string|nil` - 

## `firstChild`

Returns the first child node

- **Parameters**:

  - `allowString` (boolean): whether to include the string nodes (default false)

- **Returns**: `Banana.Ast|string` - 

## `lastChild`

Returns the last child node

- **Parameters**:

  - `allowString` (boolean): whether to include the string nodes (default false)

- **Returns**: `Banana.Ast|string` - 

## `nextSibling`

Returns the node that comes after this node in the dom order

Returns the nil ast if there is no node after this node

```nml
<div>
  <div id="1">
    <div id="2">
    </div
  </div>
  <div id="3">
  </div>
</div>
```

```lua
document:getElementById('1'):nextSibling() -- returns node 3
document:getElementById('2'):nextSibling():isNil() -- evals to true
```

- **Parameters**:

  - `allowString` (boolean): whether to include the string nodes

- **Returns**: `Banana.Ast|string` - 

## `previousSibling`

Returns the node that comes before this node in the dom order.

Returns the nil ast if there is no node before this node

```nml
<div>
  <div id="1">
    <div id="2">
    </div
  </div>
  <div id="3">
  </div>
</div>
```

```lua
document:getElementById('3'):previousSibling() -- returns node 1
document:getElementById('1'):previousSibling():isNil() -- evals to true
```
@overload fun(allowString: true): Banana.Ast|string

- **Parameters**:

  - `allowString` (false?): whether to include the string nodes

- **Returns**: `Banana.Ast` - 

## `ownerDocument`

Returns the document that this ast is a part of

- **Returns**: `Banana.Instance` - 

## `clone`

Duplicates this node (note: does NOT copy attached events)

- **Parameters**:

  - `deep` (boolean): Whether to clone children too or just this node

- **Returns**: `Banana.Ast` - 

## `setAttribute`

Sets the attribute {name} to {value}

- **Parameters**:

  - `name` (string): the name of the attribute
  - `value` (string): the new value of the attribute

## `getAttributes`

Returns a map of all attributes and their string values

```nml
<div id="1" class="class1 class2">
</div>
```

```lua
document:getElementById('1'):getAttributes()
-- returns { id="1", class="class1 class2"}
-- or returns { id="1", class="class2 class1"}
```

- **Returns**: `{` - [string]: string}

## `setStyle`

Sets the elements custom style rules to {value}.

This is the same as calling setAttribute("style", value)

- **Parameters**:

  - `value` (string): the ncss style string to set this element's style rules to

## `setStyleValue`

Sets the style declaration for {name} (eg hl-bg) to be {value}

- **Parameters**:

  - `name` (string): the name of the style to set
  - `value` (string): the string of the value

## `hasClass`

Returns true if the node has class {c}

- **Parameters**:

  - `c` (string): the class to find

- **Returns**: `boolean` - 

## `removeClass`

Removes the class {c} from the node's class list

- **Parameters**:

  - `c` (string): the class to unset

## `addClass`

Adds the class {c} to the node's class list

- **Parameters**:

  - `c` (string): the class to set

## `toggleClass`

Toggles the class {c} to the node's class list
(eg calls addClass(c) if hasClass(c) is false)

- **Parameters**:

  - `c` (string): the class to toggle

## `getBoundBox`

Returns the node's bounding box (content+padding) in characters

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `Banana.Ast.BoundingBox` - 

## `getWidth`

Returns the width of the node's bounding box (content+padding) in characters

note: this method will return an invalid value on scripts with when="prerender"

- **Returns**: `number` - 

## `getHeight`

Returns the height of the node's bounding box (content+padding) in characters

note: this method will return an invalid value on scripts with when="prerender"

## `isNil`

Returns true if the node is a nil node

Most functions that may or may not return an ast will return this instead of
nil

A nil node throws an error if any method is called on it

- **Returns**: `boolean` - 

## `remove`

removes the ast node from the dom and deletes ALL associated keymaps

## `getAttribute`

Returns the attribute value for {name} or nil if not found

- **Parameters**:

  - `name` (string): the name of the attribute to get

- **Returns**: `string?` - 

## `hasAttribute`

Returns true if this node has attribute {name} set

- **Parameters**:

  - `name` (string): the attribute to search for

- **Returns**: `boolean` - 

## `appendTextNode`

Adds {text} to the child list of the node

Escapes the text if it starts with an & or %

```nml
<span id="1">asdf</span>
```

```lua
-- "1" renders as `asdf` right now
document:getElementById("1"):appendTextNode("text")
-- "1" will now render as `asdftext`
document:getElementById("1"):appendTextNode("%asdf")
-- "1" will now render as `asdftext%asdf`
```

- **Parameters**:

  - `text` (string): the text to add to the node

## `appendTextNodeNoEscape`

Adds {text} to the child list of the node

Does NOT escape the text

```nml
<span id="1">asdf</span>
```

```lua
-- "1" renders as `asdf` right now
document:getElementById("1"):appendTextNodeNoEscape("&lt;")
-- "1" will now render as `asdf<`
```

- **Parameters**:

  - `text` (string): the text to add to the node

## `appendChild`

Adds ast {node} as a child to this node

note: if you add a block element (eg <div>) as a descendant of an inline
element (eg <span>) you will get a LineTooBig error when trying to render

note: {node} CANNOT be a string

- **Parameters**:

  - `node` (Banana.Ast): the node to append as a child

## `isLineHovering`

Returns true if the cursor is on the same line as this node

- **Returns**: `boolean` - 

## `isHovering`

Returns true if the cursor is hovering over this ast

- **Returns**: `boolean` - 

## `removeChildren`

Removes all children from this node (including text)

## `children`

Returns all ast node children of this element (not text nodes)

- **Returns**: `Banana.Ast[]` - 

## `childIterWithI`

Returns an iterator that allows iteration over all ast children with indexing

```lua
for i, v in ast:childIterWithI() do
end
```

- **Returns**: `fun(): number?, Banana.Ast?` - 

## `allChildIter`

Returns an iterator over all the children of this node (including text)

- **Returns**: `fun():(Banana.Ast|string)?` - 

## `childIter`

Returns an iterator over all the ast children of this node

- **Returns**: `fun():Banana.Ast?` - 

## `child`

Returns the nth non-string child of this node

- **Returns**: `Banana.Ast` - 

## `getAttributeSubstitution`

returns what the attribute substitution (eg %attr in nml) would be for {name}

```nml
<div name="idk">
  <span id="1">%name</span> <!-- renders as "idk" -->
</div>
```

```lua
document:getElementById("1"):getAttributeSubstitution("name") -- returns "idk"
```

- **Parameters**:

  - `name` (string): the attribute to lookup

- **Returns**: `string?` - 

## `getTextContent`

Returns the printed text value of this element (does not include newlines)

Note: This is currently bugged as entities (eg &amp;) and attr substitutions
(eg %attr) will not return their printed value

- **Returns**: `string` - 

## `setTextContent`

Sets the text content of this element. Removes all other children

Replaces newlines with <br> elements (note: if newlines are passed inside an
inline element (eg. <span>), it will cause a LineTooBig error)

- **Parameters**:

  - `str` (string): the text to set this element's content to

## `parent`

Returns the parent node of this node

- **Returns**: `Banana.Ast` - 

## `isHidden`

Returns true when this node is not rendered (eg the style `display: none`)

- **Returns**: `boolean` - 

## `attachRemap`

Attaches the given remap to the ast

## Explanation

For those wondering why one should not just use `vim.keymap.set` there are a few reasons.

1. Remap collision. `vim.keymap.set` can only set one remap per buffer which means that if you want multiple ast nodes to handle remaps differently (eg in mason when you try to install a package pressing `i` on different lines installs different packages) you have to have a central function handle everything. `attachRemap` allows "decentralized" remaps (ie each ast node can figure out how to best handle the remap)
2. Remap deletion. Remembering to delete remap handlers when an ast is deleted can be annoying. Using `attachRemap` does that for you
