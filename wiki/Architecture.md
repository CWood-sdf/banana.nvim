In order that banana might still be fast, a lot of cuts had to be made to what the browsers do.

## Distinctness

One of the really nice things about browsers is that js code can start executing while the page is still being rendered (even before all of the dom nodes have been loaded).
This js code must also be able to access render information (like computed size) about dom nodes (even if it may be incomplete) and set information about the node that might possibly change how the page is rendered (like class names).

Managing all of that in lua would be a slow mess, so I have decided to seperate out all the individual components from that equation, leading to a render loop that looks like this:

1. Treesitter compile the given nml text
0. Translate that to the Banana.Ast tree
0. Apply formatting to the tree (to remove newlines and stuff)
0. Run scripts that the user says do not need render information
0. Collect render information about the tree (by rendering it to an intermediate buffer)
0. If there are unran scripts, run them, then queue a return to the previous step
0. Render everything to a buffer
0. User events trigger state changes, queue a return to step 4

A lot of work is cut out that may leave some features missing however I believe that the architecture above provides for a set of features that is close enough to what browsers use that nearly all plugin devs will be happy.

The major feature that the distinct architecture prevents is change the state of an ast node (eg a class) then seeing any new render information about the node (eg its width) on the next line.
Like this:

```lua
local node = document:getElementById("node")

node:addClass("class")
-- getWidth is invalid here (it won't reflect the addition of .class)
print(node:getWidth())
```

## Performance

If for any reason your render update time for a small (about 2-3x `vim.v.rows`) page exceeds **15ms**, _**PLEASE POST AN ISSUE**_ as I consider that a critical performance error.
If the rerender time is noticeable, that is completely unacceptable.

> [!NOTE]
>
> If you are using gradients, the render time is expected to be over 5ms because of neovim performance issues with large numbers of highlight groups

Currently banana is very performant despite very little work going into optimizing anything.
Banana, as of now, on every single render recalculates every style, rerenders every ast node, and refreshes the entire buffer.
There is currently no caching of any render information or any incremental stuff.
Despite this, banana retains very fast rerenders mostly due to the simplified architecture.
