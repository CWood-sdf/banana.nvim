# Changelog

## [0.1.0](https://github.com/CWood-sdf/banana.nvim/compare/v0.0.1...v0.1.0) (2024-08-09)


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
* **instance:** check for other existing instances ([#6](https://github.com/CWood-sdf/banana.nvim/issues/6)) ([203ab3e](https://github.com/CWood-sdf/banana.nvim/commit/203ab3e76417f46b882c021e982501ec46068ecd))
* **readme:** update ([9671cc7](https://github.com/CWood-sdf/banana.nvim/commit/9671cc7ebe7a6295b51e1821c45930c075fa6a29))
* **render:** add grid-template-rows ([bd1832e](https://github.com/CWood-sdf/banana.nvim/commit/bd1832e6f55af1382a685f04e74698b52e3bd614))
* **render:** first working part-proto for grid ([0972135](https://github.com/CWood-sdf/banana.nvim/commit/0972135731577ad0263e3285a0cbe6f2ec027529))
* **render:** grid-template-columns implementation ([1104d2e](https://github.com/CWood-sdf/banana.nvim/commit/1104d2ee2535bb7864c72ac38a985a7d1edc9298))
* **validations:** improve grid-row/col for more grid stuff ([eef394e](https://github.com/CWood-sdf/banana.nvim/commit/eef394e9dc5a747abca9d6e47e0c185d895fc81d))


### Bug Fixes

* **ast:** dont clear id in case cloning from loadNmlTo ([bd5a1b7](https://github.com/CWood-sdf/banana.nvim/commit/bd5a1b7f6d03e17a8b67ddb88727d37810d783ac))
* **box:** adjust width in renderOver ([c2541a8](https://github.com/CWood-sdf/banana.nvim/commit/c2541a8704902d122201995054c17dc0d90c4f06))
* **box:** properly compute dirty in renderOver ([9ad90cd](https://github.com/CWood-sdf/banana.nvim/commit/9ad90cd37166b87a9e741efcb4589d802ed35dc2))
* **box:** stripRight works ([1615fef](https://github.com/CWood-sdf/banana.nvim/commit/1615fef9c1d0cf2766797d7d08368fec763c3822))
* build should work now ([a4efc3a](https://github.com/CWood-sdf/banana.nvim/commit/a4efc3aa37d5d2f3ea126c688b86afc7770c4972))
* **li:** no error when content empty ([42890bc](https://github.com/CWood-sdf/banana.nvim/commit/42890bcdd4b771bf1caf6356d9ae7330efd852a4))
* **render, hl:** render empty divs properly, hl based on bytes not chars ([5f951f0](https://github.com/CWood-sdf/banana.nvim/commit/5f951f098cc362861ce1475d02960fab152ceaa7))
* **render:** frs not allowed in flexbox ([0972135](https://github.com/CWood-sdf/banana.nvim/commit/0972135731577ad0263e3285a0cbe6f2ec027529))


### Performance Improvements

* **box:** remove copying ([265f4d7](https://github.com/CWood-sdf/banana.nvim/commit/265f4d721bd1ec5fb7243e511575232bca880cf6))
* **hl:** 3x speed increase in hl ([9094117](https://github.com/CWood-sdf/banana.nvim/commit/90941174480d41bc26010f8265a4a4e78e58bc35))


### Miscellaneous Chores

* revert release to 0.1.0 ([702f1ee](https://github.com/CWood-sdf/banana.nvim/commit/702f1ee9b477d546b4a8e31971098913b8c7f88e))
