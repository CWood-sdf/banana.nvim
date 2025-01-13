The AST class is the second of two API surfaces that you will use for any interaction with the dom tree in banana (the other one being Instance).

Not all of the browser api functions are implemented, but what I have now is hopefully enough for the API to be usable.
If there are any missing features of the browser API that you would really like ported to banana, submit an issue or a pr.

The functions are grouped into a few categories.

## TOC

- [`ownerDocument`](#ownerDocument)
- [`firstChild`](#firstChild)
- [`lastChild`](#lastChild)
- [`previousSibling`](#previousSibling)
- [`nextSibling`](#nextSibling)
- [`getTagName`](#getTagName)
- [`getRootNode`](#getRootNode)
- [`assertHasStyle`](#assertHasStyle)
- [`paddingLeft`](#paddingLeft)
- [`paddingRight`](#paddingRight)
- [`paddingTop`](#paddingTop)
- [`paddingBottom`](#paddingBottom)
- [`marginLeft`](#marginLeft)
- [`marginRight`](#marginRight)
- [`marginTop`](#marginTop)
- [`marginBottom`](#marginBottom)
- [`hasClass`](#hasClass)
- [`getWidth`](#getWidth)
- [`getHeight`](#getHeight)
- [`isNil`](#isNil)
- [`getAttribute`](#getAttribute)
- [`isLineHovering`](#isLineHovering)
- [`isHovering`](#isHovering)
- [`children`](#children)
- [`allChildIter`](#allChildIter)
- [`childIterWithI`](#childIterWithI)
- [`childIter`](#childIter)
- [`child`](#child)
- [`getTextContent`](#getTextContent)
- [`parent`](#parent)
- [`isHidden`](#isHidden)
- [`cloneNode`](#cloneNode)
- [`setAttribute`](#setAttribute)
- [`setStyle`](#setStyle)
- [`setStyleValue`](#setStyleValue)
- [`removeClass`](#removeClass)
- [`addClass`](#addClass)
- [`toggleClass`](#toggleClass)
- [`remove`](#remove)
- [`insertBefore`](#insertBefore)
- [`replaceChild`](#replaceChild)
- [`removeChild`](#removeChild)
- [`appendTextNode`](#appendTextNode)
- [`appendChild`](#appendChild)
- [`removeChildren`](#removeChildren)
- [`setTextContent`](#setTextContent)
- [`attachRemap`](#attachRemap)

# Reflection

These are functions that provide information on the state of the tree.

> [!NOTE]
>
> Any function that returns information about the render state of the tree (eg `getWidth()`) will not contain correct information directly after calling a function that would change the render (eg `appendChild()`).

## `ownerDocument`

Returns the instance that owns this ast

- **Returns**: `Banana.Instance` - The instance that owns the ast

## `firstChild`

Returns the first child node

- **Parameters**:

  - `allowString` (boolean?): Whether to consider strings as child nodes or not (default false)

- **Returns**: `string`|`Banana.Ast` - The first child node. If `allowString` is nil or false, then this function only returns `Banana.Ast`

## `lastChild`

Returns the last child node

- **Parameters**:

  - `allowString` (boolean?): Whether to consider strings as child nodes or not (default false)

- **Returns**: `string`|`Banana.Ast` - The last child node. If `allowString` is nil or false, then this function only returns `Banana.Ast`

## `previousSibling`

Returns the node that comes before this node in the dom

- **Parameters**:

  - `allowString` (boolean?): Whether to consider strings as previous nodes or not (default false)

- **Returns**: `string`|`Banana.Ast` - The previous node. If `allowString` is nil or false, then this function only returns `Banana.Ast`

## `nextSibling`

Returns the node that comes after this node in the dom

- **Parameters**:

  - `allowString` (boolean?): Whether to consider strings as nodes or not (default false)

- **Returns**: `string`|`Banana.Ast` - The next node. If `allowString` is nil or false, then this function only returns `Banana.Ast`

## `getTagName`

Returns the name of the tag that the ast represents (eg. 'div')

- **Returns**: `string` - the tag name

## `getRootNode`

Returns the root node of this section of the DOM tree.

- **Returns**: `Banana.Ast` - The root node.

## `assertHasStyle`

Throws an error if the specified style is not set in the node's style list.

- **Parameters**:
  - `style` (string): The style to look up.

## `paddingLeft`

Returns the left padding of the element in characters.

- **Returns**: `number` - The left padding in characters.

## `paddingRight`

Returns the right padding of the element in characters.

- **Returns**: `number` - The right padding in characters.

## `paddingTop`

Returns the top padding of the element in characters.

- **Returns**: `number` - The top padding in characters.

## `paddingBottom`

Returns the bottom padding of the element in characters.

- **Returns**: `number` - The bottom padding in characters.

## `marginLeft`

Returns the left margin of the element in characters.

- **Returns**: `number` - The left margin in characters.

## `marginRight`

Returns the right margin of the element in characters.

- **Returns**: `number` - The right margin in characters.

## `marginTop`

Returns the top margin of the element in characters.

- **Returns**: `number` - The top margin in characters.

## `marginBottom`

Returns the bottom margin of the element in characters.

- **Returns**: `number` - The bottom margin in characters.

## `hasClass`

Checks if the node has the specified class.

- **Parameters**:
  - `c` (string): The class name.
- **Returns**: `boolean` - `true` if the class is present, `false` otherwise.

## `getWidth`

Returns the width of the node's bounding box (content + padding).

- **Returns**: `number` - The width of the bounding box.

## `getHeight`

Returns the height of the node's bounding box (content + padding).

- **Returns**: `number` - The height of the bounding box.

## `isNil`

Checks if the node is a "nil" node, meaning it represents an absence or non-existence in the DOM structure.

- **Returns**: `boolean` - `true` if the node is a nil node, `false` otherwise.

## `getAttribute`

Gets the attribute value for the specified name, or `nil` if not found.

- **Parameters**:
  - `name` (string): The attribute name.
- **Returns**: `string?` - The attribute value or `nil`.

## `getAttributes`

Returns a map of all attributes to their values

- **Returns**: `{ [string]: string }` - A map of every attribute to its value

## `isLineHovering`

Checks if the cursor is on the same line as this node.

- **Returns**: `boolean` - `true` if the cursor is on the same line, `false` otherwise.

## `isHovering`

Checks if the cursor is hovering over this node.

- **Returns**: `boolean` - `true` if hovering, `false` otherwise.

## `children`

Returns all child AST nodes of this element (excluding text nodes).

- **Returns**: `Banana.Ast[]` - An array of child nodes.

## `allChildIter`

Returns an iterator that iterates over all children (including text nodes).

### Example

```nml
<nml>
  <body>
    <div> div 1</div>
    text node
    <div> div 2</div>
    <div> div 3</div>
    <script>
      local body = document:body()

      for node in body:childIterWithI() do
        if type(node) == "string" then
          print(node)
        else
          print(node:getTextContent())
        end
      end
      -- prints:
      -- div 1
      -- text node
      -- div 2
      -- div 3
    </script>
  </body>
</nml>
```

## `childIterWithI`

Returns an iterator that can be used to iterate over all ast children with their corresponding index

### Example

```nml
<nml>
  <body>
    <div> div 1</div>
    text node
    <div> div 2</div>
    <div> div 3</div>
    <script>
      local body = document:body()

      for i, node in body:childIterWithI() do
        print(i .. ": " .. node:getTextContent())
        assert(body:child(i) == node)
      end
      -- prints:
      -- 1: div 1
      -- 2: div 2
      -- 3: div 3
    </script>
  </body>
</nml>
```

## `childIter`

Returns an iterator that can be used to iterate over all ast children

### Example

```nml
<nml>
  <body>
    <div> div 1</div>
    <div> div 2</div>
    <div> div 3</div>
    <script>
      local body = document:body()

      for node in body:childIter() do
        print(node:getTextContent())
      end
      -- prints:
      -- div 1
      -- div 2
      -- div 3
    </script>
  </body>
</nml>
```

## `child`

Returns the nth non-string child of the node.

- **Parameters**:
  - `i` (number): The index of the child.
- **Returns**: `Banana.Ast` - The child node.

### Example

```nml
<body>
  <div foo="bar" id="asdf">
    <!-- will set the text content to 'bar' -->
    %foo
  </div>
  <script>
    local asdf = document:getElementById("asdf")
    -- prints 'bar'
    print(asdf:getAttributeSubstitution("foo"))
  </script>
</body>
```

## `getTextContent`

**Warning**: `getTextContent` currently only works for elements that only contain text/ast nodes (not attribute substitutions or character entities)

Gets the printed text value of this element (excludes newlines).

- **Returns**: `string` - The text content.

## `parent`

Gets the parent node of this node.

- **Returns**: `Banana.Ast` - The parent node.

## `isHidden`

Checks if this node is not rendered.

- **Returns**: `boolean` - `true` if not rendered, `false` otherwise.

## `cloneNode`

Duplicates the node. Since the same node cannot be in the tree at two different places (that would introduce rendering weirdness), you should use clone sometimes

- **Parameters**:

  - `deep` (boolean): Whether to duplicate the entire subtree (children...) or just the caller node

- **Returns**: A duplicated ast node

# Setters

These are functions that change the state of the tree and trigger a rerender

## `setAttribute`

Sets the attribute to the specified value.

- **Parameters**:
  - `name` (string): The attribute name.
  - `value` (string): The new value of the attribute.

## `setStyle`

Sets custom style rules, overriding any styles set with `style=""`.

- **Parameters**:
  - `value` (string): The NCSS style string.

## `setStyleValue`

Sets the style declaration to the specified value.

- **Parameters**:
  - `name` (string): The style name.
  - `value` (string): The value to set.

## `removeClass`

Removes the specified class from the node's class list.

- **Parameters**:
  - `c` (string): The class name.

## `addClass`

Adds the specified class to the node's class list.

- **Parameters**:
  - `c` (string): The class name.

## `toggleClass`

Toggles the specified class in the node's class list.

- **Parameters**:
  - `c` (string): The class name.

## `remove`

Removes the node from the DOM and deletes all associated keymaps

## `insertBefore`

Inserts the first parameter into this ast before the reference node. See [mdn docs](https://developer.mozilla.org/en-US/docs/Web/API/Node/insertBefore) for more info

- **Parameters**:
  - `child` (string|`Banana.Ast`): The node to add
  - `referenceNode` (string|`Banana.Ast`): The node to insert before

## `replaceChild`

Replaces the second parameter with the first parameter in this node's child list. Does nothing if `newNode` is not in this node's child list

- **Parameters**:

  - `newNode` (string|`Banana.Ast`): The node to remove
  - `node` (string|`Banana.Ast`): The node to replace

- **Returns**: `string`|`Banana.Ast`|`nil` - The removed node, or nil if the node is not found

## `removeChild`

Removes the passed node from this node's child list then returns the new node

- **Parameters**:

  - `child` (string|`Banana.Ast`): The node to remove

- **Returns**: `string`|`Banana.Ast`|`nil` - The removed node, or nil if the node is not found

## `appendTextNode`

Appends text to the node's child list.

- **Parameters**:
  - `text` (string): The text to add.

## `appendChild`

Appends a child node to this node.

- **Parameters**:
  - `node` (`Banana.Ast`): The child node to append.

## `removeChildren`

Removes all children from the node, including text.

## `setTextContent`

Sets the text content of this element.

- **Parameters**:
  - `str` (string): The text to set.

# Event handlers

These are functions that register some callback that is related to the AST node. Calling these functions does not trigger a rerender

## `attachRemap`

Attaches the specified remap to the AST.

- **Parameters**:
  - `mode` (string): The mode of the keymap.
  - `lhs` (string): The left-hand side of the keymap.
  - `mods` (`Banana.Remap.Constraint[]`): A list of remap constraints.
  - `rhs` (string | function): The right-hand side or a function.
  - `opts` (`vim.keymap.set.Opts?`): Keymap options.

### Explanation

For those wondering why one should not just use `vim.keymap.set` there are a few reasons.

1. Remap collision. `vim.keymap.set` can only set one remap per buffer which means that if you want multiple ast nodes to handle remaps differently (eg in mason when you try to install a package pressing `i` on different lines installs different packages) you have to have a central function handle everything. `attachRemap` allows "decentralized" remaps (ie each ast node can figure out how to best handle the remap)
2. Remap deletion. Remembering to delete remap handlers when an ast is deleted can be annoying. Using `attachRemap` does that for you

### Contraints

Currently, the supported constraints are "hover", "line-hover", and \<number\>.

```lua
-- this will only be called if the cursor is over the node when the user types `<leader>w` or if the user types `1<leader>w`
ast:attachRemap("n", "<leader>w", { "hover", 1 }, function()

end, {})
```

Line-hover is similar to hover except that it calls the remap if the cursor is on the same line as the ast node, instead of strictly hovering over it
