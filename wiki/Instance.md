The Instance class is the first of two API surfaces that you will use for most of your code in banana. It is the type of the `document` variable that is predefined on all `<script>` tags

## TOC

- [`body`](#body)
- [`close`](#close)
- [`createElement`](#createElement)
- [`forceRerender`](#forceRerender)
- [`getBufnr`](#getBufnr)
- [`getElementById`](#getElementById)
- [`getElementsByClassName`](#getElementsByClassName)
- [`getElementsByTag`](#getElementsByTag)
- [`getScriptParams`](#getScriptParams)
- [`getPrimaryNode`](#getPrimaryNode)
- [`isOpen`](#isOpen)
- [`loadNmlTo`](#loadNmlTo)
- [`on`](#on)
- [`open`](#open)
- [`querySelectorAll`](#querySelectorAll)
- [`setBufName`](#setBufName)
- [`useBuffer`](#useBuffer)
- [`useFile`](#useFile)
- [`useNml`](#useNml)
- [`useWindow`](#useWindow)

The methods are:

## `body`

Returns the body node of the instance.

- **Returns**: `Banana.Ast` - The body node.

## `close`

Closes the window that this instance is managing.

## `createElement`

Creates a new element with the specified tag name that can later be attached to the DOM.

- **Parameters**:
  - `name` (string): The name of the element tag.
- **Returns**: `Banana.Ast` - The created AST node.

## `forceRerender`

Forces the instance to re-render the window. **Use sparingly, as this may affect performance.** If there is a problem with the library that requires you to use this function, please submit a bug report

## `getBufnr`

Gets the buffer number used by the instance.

- **Returns**: `number?` - The buffer number or `nil` if not set.

## `getElementById`

Finds an element by its ID, similar to JavaScript's `getElementById`.

- **Parameters**:
  - `name` (string): The ID to search for.
- **Returns**: `Banana.Ast` - The matched AST node.

## `getElementsByClassName`

Finds elements by their class name, similar to JavaScript's `getElementsByClassName`.

- **Parameters**:
  - `name` (string): The class name to search for.
- **Returns**: `Banana.Ast[]` - An array of matched AST nodes.

## `getElementsByTag`

Finds elements by their tag name, similar to JavaScript's `getElementsByTagName`.

- **Parameters**:
  - `name` (string): The tag name to search for.
- **Returns**: `Banana.Ast[]` - An array of matched AST nodes.

## `getScriptParams`

Returns the parameters for the currently running script associated with the instance.

- **Returns**: `Banana.Instance.RouteParams?` - The route parameters or `nil` if not set.

## `getPrimaryNode`

Returns the root node that the script runs in
For components, returns the `<template>` tag of the current component.
For scripts running in the main loaded nml file, returns the `<body>` tag.
For scripts loaded from `loadNmlTo()`, returns the root node of the loaded document

- **Returns**: `Banana.Ast` - The root node of the current script context

### Example

```nml
<nml>
  <head>
    <template name="Tag">
      <script>
        -- Returns the template that the script is running in
        local node = document:getPrimaryNode()

      </script>
    </template>
  </head>
  <body>

    <script>
      -- returns the body node
      local node = document:getPrimaryNode()
    </script>
  </body>
</nml>
```

## `isOpen`

Checks if the instance is currently open.

- **Returns**: `boolean` - `true` if the instance is open, `false` otherwise.

## `loadNmlTo`

Loads a partial NML file to the specified AST node.

- **Parameters**:
  - `file` (string): The NML file to load.
  - `ast` (`Banana.Ast`): The AST node to load the content into.
  - `remove` (boolean?): Whether to remove all child elements (default: `true`).
  - `preserve` (boolean?): Whether to prevent cloning the AST (default: `false`).

## `new`

Creates a new instance.

- **Returns**: `Banana.Instance` - The new instance object.

## `on`

A wrapper around `nvim_create_autocmd` that attaches the autocmd to the render buffer

This function also allows you to use the special events:

- `Close` when the window is closed with `:q` or `document:close()`
- `Leave` fired on `WinLeave`
- `Open` fired on `document:open()`
- `OpenPost` fired after document render on `document:open()`
  - After this event, render information is guranteed to exist
- `ScriptDone` fired after scripts have ran

- **Parameters**:
  - `ev` (string|string[]): The event or events to associate with.
  - `opts` (`vim.api.keyset.create_autocmd`): Options for creating the auto-command.
- **Returns**: `number` - The event ID.

## `open`

Opens the window that this instance is managing.

## `querySelectorAll`

Selects all elements matching the specified selector, similar to JavaScript's `querySelectorAll`.

- **Parameters**:
  - `sel` (string): The selector to match elements.
- **Returns**: `Banana.Ast[]` - An array of matched AST nodes.

## `setBufName`

Sets the name of the buffer.

- **Parameters**:
  - `str` (string): The new buffer name.

## `useBuffer`

Sets the specified buffer number as the buffer for the instance.

- **Parameters**:
  - `bufnr` (number): The buffer number to use.

## `requireNml`

Loads the nml file specified at the nml require string as the root of the document

- **Parameters**:
  - `location` (string): The nml require string

## `useFile`

Uses a nml specified file as the source of the instance

- **Parameters**:
  - `filename` (string): The NML file to use as the source.

## `useNml`

Uses a given NML string as the source of the instance.

- **Parameters**:
  - `nml` (string): The NML string to use.

## `useWindow`

Sets the specified window ID as the window for the instance to render to.

- **Parameters**:
  - `winid` (number): The window ID to use.
