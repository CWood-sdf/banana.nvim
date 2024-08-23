# Changelog

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
