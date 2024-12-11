# Changelog

## [0.2.0](https://github.com/CWood-sdf/banana.nvim/compare/v0.1.0...v0.2.0) (2024-12-11)

This release introduces support for two really important things: gradients and components!

Gradients (unlike in css) can be applied as both a background *and* foreground highlight. Currently, only radial and linear gradients are supported (but without custom color space interpolation), however, a framework is currently in place that will allow other gradient types to be made really easily. 

Components are also a very important thing for building good applications. The current component system is partially inspired by web components and svelte's component system. It is currently very rudimentary but is powerful enough for most use cases while avoiding the headaches of web components.


### Features

* **api:** add getComponentRoot and getAttributeSubstitution ([09c4cab](https://github.com/CWood-sdf/banana.nvim/commit/09c4cab006b636e76574e95bdeefffac24c886a7))
* **api:** remove getComponentRoot ([2d6749e](https://github.com/CWood-sdf/banana.nvim/commit/2d6749efb720c23bce711336b4a94361768256b6))
* **component:** dont render after running scripts jic the script changes layout ([a4d7b2b](https://github.com/CWood-sdf/banana.nvim/commit/a4d7b2bd633ddfe4bc463548e6fa6fd9124e3b1e))
* **component:** import when declared in a script ([758c6f0](https://github.com/CWood-sdf/banana.nvim/commit/758c6f0b92496f151d1069691748ea424045ad66))
* **component:** more component work ([a9636b8](https://github.com/CWood-sdf/banana.nvim/commit/a9636b8118678c28212277e4672e7c347b7e8b41))
* **component:** more work ([9a17671](https://github.com/CWood-sdf/banana.nvim/commit/9a17671b84b97944d069e7d59b4dd77d58bb5da3))
* **component:** more work on getting the system working ([4aab84f](https://github.com/CWood-sdf/banana.nvim/commit/4aab84fad9508101a80afdfb8943033bc44e169f))
* **components:** start working on components ([bf0b7dc](https://github.com/CWood-sdf/banana.nvim/commit/bf0b7dcb07ee9ec59f87e6b2bb3194c28dd80303))
* counter ([948dd0b](https://github.com/CWood-sdf/banana.nvim/commit/948dd0bccd9e431115236ec5b51a986ad85118b5))
* **Gradient:** add caching for linear colors ([82fb519](https://github.com/CWood-sdf/banana.nvim/commit/82fb519ddf1225c3deac97c6d5616447587b2613))
* **Gradient:** add caching for radial-gradient ([38df71f](https://github.com/CWood-sdf/banana.nvim/commit/38df71fce096c035386927d89d3fc9894d3c3d54))
* **gradient:** add color stop parser, and have functions return mult ([a948fb1](https://github.com/CWood-sdf/banana.nvim/commit/a948fb1980657f696f5d7813bb1a71ef2f250d9c))
* **gradient:** add name to color parser ([b2e97ad](https://github.com/CWood-sdf/banana.nvim/commit/b2e97adb5d8f07269c014da4c9a3b7d4a53e1274))
* **gradient:** add og radial-gradient ([fa6146b](https://github.com/CWood-sdf/banana.nvim/commit/fa6146b341121b7b6fe723ed2fc056fd0e2ad8af))
* **gradient:** first working linear-grad prototype ([df221ee](https://github.com/CWood-sdf/banana.nvim/commit/df221ee2e91c1ff7bf95191c1c31f2e525b2709d))
* **gradient:** fix random things ([ba59292](https://github.com/CWood-sdf/banana.nvim/commit/ba59292a8041b3b7e8c29b5a05a53783a266e623))
* **gradient:** full color stops ([62a610f](https://github.com/CWood-sdf/banana.nvim/commit/62a610f0e08fb475ff87d49ae230cf61a5bd2e45))
* **gradient:** linear works for all angles ([9c81a00](https://github.com/CWood-sdf/banana.nvim/commit/9c81a003fa41fa62011d985a087d73af8fb7059c))
* **grid:** add nfr unit ([d6b72b4](https://github.com/CWood-sdf/banana.nvim/commit/d6b72b4978ecff5e4f34a19ebda52aac5d750381))
* **Instance:** add debug window for debug output (instead of bottom) ([82fb519](https://github.com/CWood-sdf/banana.nvim/commit/82fb519ddf1225c3deac97c6d5616447587b2613))
* **linear-gradient:** add support for "to ..." ([3b4f813](https://github.com/CWood-sdf/banana.nvim/commit/3b4f813ae79ac60490bb1090e5fd9b086197eb06))
* **linear-gradient:** support for angle ([7c47b15](https://github.com/CWood-sdf/banana.nvim/commit/7c47b15924e545d5464fde51109808fda06e4740))
* **ncss:** add aspect-ratio ([09c4cab](https://github.com/CWood-sdf/banana.nvim/commit/09c4cab006b636e76574e95bdeefffac24c886a7))
* **ncss:** add nth-child pseudo class selector ([caba20a](https://github.com/CWood-sdf/banana.nvim/commit/caba20a8a99dd6d8906eabcd77605763cb6e187b))
* **nml:** prep treesitter for components ([80f2b3f](https://github.com/CWood-sdf/banana.nvim/commit/80f2b3f45601c0c6541bccf5198d3ab5399ff963))
* **render:** dont have infinite loop when width=0 ([2e3d837](https://github.com/CWood-sdf/banana.nvim/commit/2e3d837bf0f1e80ad8f4fb44d7b0250773cfb74d))
* **tag:** move functions to new file ([4aab84f](https://github.com/CWood-sdf/banana.nvim/commit/4aab84fad9508101a80afdfb8943033bc44e169f))


### Bug Fixes

* **aspect-ratio:** floor values ([d6b72b4](https://github.com/CWood-sdf/banana.nvim/commit/d6b72b4978ecff5e4f34a19ebda52aac5d750381))
* **box:** prevent nil errors ([d6b72b4](https://github.com/CWood-sdf/banana.nvim/commit/d6b72b4978ecff5e4f34a19ebda52aac5d750381))
* **box:** regression in grid unit tests ([eb33842](https://github.com/CWood-sdf/banana.nvim/commit/eb33842899c27ad847d37efcac259ba770d33f26))
* **component:** force componentStack to be a guaranteed value ([8f1e8c8](https://github.com/CWood-sdf/banana.nvim/commit/8f1e8c8ad8030a499a7717abbc8f0d54fb5f543f))
* **component:** import things properly ([20aa25c](https://github.com/CWood-sdf/banana.nvim/commit/20aa25c6b31a84dcb836434b3805900e8acbbc9e))
* **component:** prevent cyclic imports ([934b1d5](https://github.com/CWood-sdf/banana.nvim/commit/934b1d56111c38e151fc4227e4215f513aaed33a))
* **gradient:** properly compute widthToCorner for linear ([2a1f524](https://github.com/CWood-sdf/banana.nvim/commit/2a1f524de29ff6ee0459f000a1e0eeb2cdb0cd10))
* **grid:** call .render() ([ab65019](https://github.com/CWood-sdf/banana.nvim/commit/ab65019b5f0f0624739924dbb096bbcd0d3c7c2a))
* **grid:** prevent 0 index from being used ([09c4cab](https://github.com/CWood-sdf/banana.nvim/commit/09c4cab006b636e76574e95bdeefffac24c886a7))
* **instance:** check if dir exists so netrw doesnt open up ([3350039](https://github.com/CWood-sdf/banana.nvim/commit/3350039f1fd223ba960d1fc2622bbf2086ebb4ab))
* **nml:** attach src= scripts to component ([09c4cab](https://github.com/CWood-sdf/banana.nvim/commit/09c4cab006b636e76574e95bdeefffac24c886a7))
* **render:** list style color contains color of parent element ([cef59e9](https://github.com/CWood-sdf/banana.nvim/commit/cef59e97ce906b936d3b6beb4dcca7e370f13fd0))

## [0.1.0](https://github.com/CWood-sdf/banana.nvim/compare/v0.0.1...v0.1.0) (2024-08-23)


### ⚠ BREAKING CHANGES

* **render:** frs not allowed in flexbox

### Features

* **ast:** add nil checks for instance usage ([0fc2a55](https://github.com/CWood-sdf/banana.nvim/commit/0fc2a55dd3c29329502132b3e23481daf6afc89a))
* **css validation:** add support for param packs and repeat() ([2b3e098](https://github.com/CWood-sdf/banana.nvim/commit/2b3e0981481a50988e2f6b457adc3a1a97b56b59))
* **example:** able to run both examples ([64de431](https://github.com/CWood-sdf/banana.nvim/commit/64de4314609dcc432c73549b1750f3450e19b95f))
* **examples:** add "lazy.nvim" example ([17ce8e2](https://github.com/CWood-sdf/banana.nvim/commit/17ce8e28afdf1df1773f3a752b591de02bab8ec8))
* **examples:** add todo ([5b5f205](https://github.com/CWood-sdf/banana.nvim/commit/5b5f205ebd9e792cd62bf68ac8a65fae8d16f20c))
* **examples:** counter ([9232740](https://github.com/CWood-sdf/banana.nvim/commit/923274031aa7bea992e355da5c1f1a52788a71d6))
* **grid:** grid is scary ([7634ace](https://github.com/CWood-sdf/banana.nvim/commit/7634ace51a873ba9eb0455e8a637606c1a82021d))
* **grid:** nearly done with main prototype ([3d03af5](https://github.com/CWood-sdf/banana.nvim/commit/3d03af550e0d9946d39225ad60a9d02a3563a8d9))
* **h1:** add h1 tag ([adb3f25](https://github.com/CWood-sdf/banana.nvim/commit/adb3f256fc1c6181cccfd833dd9333511b252b95))
* **instance:** add resize rerender event ([918097d](https://github.com/CWood-sdf/banana.nvim/commit/918097d53a7422cfcc1b5bf6f615fd3b1690b1e9))
* **instance:** check for other existing instances ([#6](https://github.com/CWood-sdf/banana.nvim/issues/6)) ([203ab3e](https://github.com/CWood-sdf/banana.nvim/commit/203ab3e76417f46b882c021e982501ec46068ecd))
* **instance:** defer imported scripts to access computed props ([3113a67](https://github.com/CWood-sdf/banana.nvim/commit/3113a67f386ca9ec2be16d5625b7e16b692c395a))
* multiple fixes and prep for v0.1 ([fe962cd](https://github.com/CWood-sdf/banana.nvim/commit/fe962cd331a124ca2ac7897783f9ce3b5232c468))
* **ncss:** add slash support ([8c4e0c2](https://github.com/CWood-sdf/banana.nvim/commit/8c4e0c2516046971bd396c579f50e2ff66070ef1))
* **readme:** update ([9671cc7](https://github.com/CWood-sdf/banana.nvim/commit/9671cc7ebe7a6295b51e1821c45930c075fa6a29))
* **render:** add grid-template-rows ([bd1832e](https://github.com/CWood-sdf/banana.nvim/commit/bd1832e6f55af1382a685f04e74698b52e3bd614))
* **render:** add row-gap and column-gap ([7a3a11d](https://github.com/CWood-sdf/banana.nvim/commit/7a3a11d1aa25ae77ca3b381cd6bf844fc4e72c6a))
* **render:** first working part-proto for grid ([0972135](https://github.com/CWood-sdf/banana.nvim/commit/0972135731577ad0263e3285a0cbe6f2ec027529))
* **render:** grid-template-columns implementation ([1104d2e](https://github.com/CWood-sdf/banana.nvim/commit/1104d2ee2535bb7864c72ac38a985a7d1edc9298))
* **render:** more grid work ([7e7da9f](https://github.com/CWood-sdf/banana.nvim/commit/7e7da9f174b64405d05fb25c244b755940f9ccc8))
* **render:** more grid work ([3e79a5e](https://github.com/CWood-sdf/banana.nvim/commit/3e79a5e93c8374074fa1b07ad57e556ed9a2ce5e))
* **render:** use rows as 1fr height when height defined ([f0a6325](https://github.com/CWood-sdf/banana.nvim/commit/f0a63258b37713d2e403c0e8b7d6784742b29bd6))
* **validations:** improve grid-row/col for more grid stuff ([eef394e](https://github.com/CWood-sdf/banana.nvim/commit/eef394e9dc5a747abca9d6e47e0c185d895fc81d))
* **zig:** add box.zig ([a5a6af7](https://github.com/CWood-sdf/banana.nvim/commit/a5a6af791f364fd4e06cd10ce1c5ee7d1da44e6a))


### Bug Fixes

* **ast:** dont clear id in case cloning from loadNmlTo ([bd5a1b7](https://github.com/CWood-sdf/banana.nvim/commit/bd5a1b7f6d03e17a8b67ddb88727d37810d783ac))
* **box:** adjust width in renderOver ([c2541a8](https://github.com/CWood-sdf/banana.nvim/commit/c2541a8704902d122201995054c17dc0d90c4f06))
* **box:** properly compute dirty in renderOver ([9ad90cd](https://github.com/CWood-sdf/banana.nvim/commit/9ad90cd37166b87a9e741efcb4589d802ed35dc2))
* **box:** stripRight works ([1615fef](https://github.com/CWood-sdf/banana.nvim/commit/1615fef9c1d0cf2766797d7d08368fec763c3822))
* build should work now ([a4efc3a](https://github.com/CWood-sdf/banana.nvim/commit/a4efc3aa37d5d2f3ea126c688b86afc7770c4972))
* **grid:** fix failures in grid tests ([e0007ba](https://github.com/CWood-sdf/banana.nvim/commit/e0007ba0e2849e27eb2232a77e04208deb6e297f))
* **highlight:** memory leak bc not cleaning up highlights ([904d9c8](https://github.com/CWood-sdf/banana.nvim/commit/904d9c880db4417e71e60a7cfae2b67a43179844))
* **instance:** properly compute new bounds ([918097d](https://github.com/CWood-sdf/banana.nvim/commit/918097d53a7422cfcc1b5bf6f615fd3b1690b1e9))
* **li:** no error when content empty ([42890bc](https://github.com/CWood-sdf/banana.nvim/commit/42890bcdd4b771bf1caf6356d9ae7330efd852a4))
* **nml:** wasnt grabbing inline scripts ([3808bab](https://github.com/CWood-sdf/banana.nvim/commit/3808babc50d3e4a2af515cca6520f1dc5de696bf))
* remove accidental treesitter stuff ([07f62c8](https://github.com/CWood-sdf/banana.nvim/commit/07f62c8765881cee91e0fa76c146f0c0ad946822))
* **render, hl:** render empty divs properly, hl based on bytes not chars ([5f951f0](https://github.com/CWood-sdf/banana.nvim/commit/5f951f098cc362861ce1475d02960fab152ceaa7))
* **render:** frs not allowed in flexbox ([0972135](https://github.com/CWood-sdf/banana.nvim/commit/0972135731577ad0263e3285a0cbe6f2ec027529))
* **render:** properly apply box centering when minsize is used (aka flexbox) ([6690185](https://github.com/CWood-sdf/banana.nvim/commit/669018501e5f5f42b69f4802c4469206eb2e6d46))


### Performance Improvements

* **box:** remove copying ([265f4d7](https://github.com/CWood-sdf/banana.nvim/commit/265f4d721bd1ec5fb7243e511575232bca880cf6))
* **grid:** slight improvements in distribution ([77184ba](https://github.com/CWood-sdf/banana.nvim/commit/77184ba674acd1b15b55a2103c575cfb03bcb690))
* **hl:** 3x speed increase in hl ([9094117](https://github.com/CWood-sdf/banana.nvim/commit/90941174480d41bc26010f8265a4a4e78e58bc35))


### Miscellaneous Chores

* revert release to 0.1.0 ([702f1ee](https://github.com/CWood-sdf/banana.nvim/commit/702f1ee9b477d546b4a8e31971098913b8c7f88e))
