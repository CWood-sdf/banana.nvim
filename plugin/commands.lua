vim.api.nvim_create_user_command("BananaSo", function (opts)
    local file
    -- vim.print(opts)
    if #opts.fargs == 0 then
        file = vim.api.nvim_buf_get_name(0)
    else
        file = opts.args[1]
    end
    local buftitle = "scratch"
    local inst = require("banana.instance").emptyInstance()
    inst.DEBUG_showPerf = true
    inst.DEBUG_stressTest = true
    inst.DEBUG = true
    require("banana.require").parseReload()
    inst:useFile(file)
    inst:setBufName(buftitle)
    inst:open()
    vim.notify("Instance id: " .. inst.instanceId)
end, {
    nargs = "*",
})
