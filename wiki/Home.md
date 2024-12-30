Welcome to the banana.nvim wiki!

> [!CAUTION]
>
> The wiki is still a work in progress so if you find something missing, please submit an issue with the title "wiki: YOUR_ISSUE"

The main point of this wiki is to show the differences between the banana rendering implementation and the w3 spec.
Articles will (eventually), when possible, link to relevant MDN docs pages with notes on the differences between what's in those pages and what's actually implemented in banana.

## Goals

_Currently_, the goal for banana is to implement enough of a subset of html and css such that it is possible to make anything. There are several niceties in html and css that would probably be very easy to implement right now (namely other css selector types), but my goals are to get maximize the library capabilities before rounding out the feature set. If you would like one of these features, post an issue. I will happily add a feature if you want it, but I will not work on some of these features unless asked to.

## Getting started

To get started, you can either run the command `:BananaSo` while in an nml file, or set up an instance for your plugin

`:BananaSo` is intended for testing purposes only, but it will open up your nml in the current neovim instance

To set up an instance for usage in a plugin, use the below code:

```lua
-- the buffer name can be overriden using the <title> tag
local document = require('banana.instance').newInstance("banana require path", "initial buffer name")

-- can also use
local document = require("banana.instance").emptyInstance()
document:requireNml("banana require path")
document:setBufName("initial buffer name")

-- opens the window
document:open()
```

## Banana require path/structuring plugins

Banana will look for all nml and ncss files in the `Plugin/banana/` folder. The require string format is nearly exactly like lua require strings, except it uses `/` seperator rather than `.`. The default file name is `index.nml` as opposed to lua's `init.lua`:

```
∟ Plugin
    ∟ banana/
        ∟ pluginName/
            ∟ markup.nml
            ∟ index.nml
    ∟ lua/
        ∟ pluginName/
            ∟ plugin.lua
```

```lua
-- the above plugin could be ran with
local document = require('banana.instance').newInstance("pluginName/index", "initial buffer name")
-- or
local document = require('banana.instance').newInstance("pluginName", "initial buffer name")
```

An example plugin, [banana-example](https://github.com/CWood-sdf/banana-example), exists that better shows how banana recommends plugins be layed out.
