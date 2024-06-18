local u = require('banana.utils.string')
describe("string sub", function()
    it("basic strings work", function()
        assert(u.sub("asdf", 1, 3) == "asd", "basic test failed")
    end)

    it("substring at the start", function()
        assert(u.sub("lua programming", 1, 3) == "lua", "start substring failed")
    end)

    it("substring at the end", function()
        assert(u.sub("lua programming", 12, 15) == "ming", "end substring failed")
    end)

    it("substring in the middle", function()
        assert.equal(u.sub("lua programming", 5, 14), "programmin", "middle substring failed")
    end)

    it("substring with unicode characters", function()
        assert(u.sub("Привет, мир!", 1, 12) == "Привет, мир!", "unicode substring failed")
    end)

    it("substring with emojis", function()
        assert(u.sub("Hello, 😀!", 8, 9) == "😀!", "emoji substring failed")
    end)

    it("substring with combining characters", function()
        assert(u.sub("café", 1, 4) == "café", "combining character substring failed")
    end)
    it("thing that fails a bunch", function()
        assert.equal(
            u.sub(
                "🏙  A clean, dark Neovim theme written in Lua, with support for lsp, treesitter and lots of plugins. Includes additional themes for Kitty, Alacritty, iTerm an",
                1, 52), "🏙  A clean, dark Neovim theme written in Lua, with s", "combining character substring failed")
    end)
end)
