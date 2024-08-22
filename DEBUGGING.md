# Debugging

Debugging banana is not the simplest thing to do

## Lua

The lua code is easy to debug if you already no how to debug lua with [osv](https://github.com/jbyuki/one-small-step-for-vimkind). I personally use [do-the-needful](https://github.com/catgoose/do-the-needful.nvim) to start up debug tmux windows really easily. The script i use to launch lua debug is the debug one in .tasks.json.

## Zig

Debugging the zig code is not as easy

This requires attaching to a running neovim process that _ALREADY_ has the zig .so included with lua ffi. It also requires special privilege overriding in linux

to first override privileges so that gdb can attach to a process without any problems requires this to be run in a shell:

```sh
echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
```

Then, you need to have gdb installed on your system and have this configuration for zig:

```lua

dap.configurations.zig = {
    {
        name = "Select and attach to process",
        type = "gdb",
        request = "attach",
        pid = function()
            local name = vim.fn.input('Executable name (filter): ')
            return require("dap.utils").pick_process({ filter = name })
        end,
    },
    -- this is so that we keep any other configurations
    unpack(dap.configurations.zig),
}
dap.adapters.gdb = {
    type = "executable",
    command = "gdb",
    args = { "--interpreter=dap", "--eval-command", "set print pretty on" }
}

```

After that is setup, you need to launch a neovim process, ensure that the zig .so is loaded, and then you can connect by just launching the above configuration and selecting the neovim process

### Selecting the neovim process

The zig debug script in .tasks.json contains a command to launch neovim with an init.lua that ensures that the zig shared object is loaded, it is recommended to use that script to test any zig problems

There are also a few intricacies to finding the right neovim process. On my machine (using the bob version manager for neovim), there are three processes started up when i open neovim. The important one is the one that is launched with the --embed flag. That is the one to connect to to debug the zig code
