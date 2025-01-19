# Changelog

## [0.3.0](https://github.com/CWood-sdf/banana.nvim/compare/v0.2.0...v0.3.0) (2025-01-19)


### ⚠ BREAKING CHANGES

* **ast:** rename some methods

### Features

* add a project conf ([3cc8dfb](https://github.com/CWood-sdf/banana.nvim/commit/3cc8dfb4b3ea21fbef4cc54d7076d20896ce77ea))
* **ast:** add comments for BoundingBox ([6a10bdc](https://github.com/CWood-sdf/banana.nvim/commit/6a10bdc384e3a8baa001455caab3385e09ddcf0e))
* **ast:** add getAttributes ([5278e0d](https://github.com/CWood-sdf/banana.nvim/commit/5278e0d0d3f751ce20a0f4d885d55adcb5413d2a))
* **ast:** add some more methods to fit DOM Node interface more ([2037149](https://github.com/CWood-sdf/banana.nvim/commit/2037149f3cc7a08b9864c955f06f9f3ae1fa48c6))
* **ast:** allow attr subst's to end with semicolon ([c5d3385](https://github.com/CWood-sdf/banana.nvim/commit/c5d3385a6938b48723eab97a0474eb3904d1d80e))
* **ast:** better managing class list ([69ad506](https://github.com/CWood-sdf/banana.nvim/commit/69ad5063759fe55a909dd4cbc94f9c3a7700be21))
* **ast:** make style private and force style usage through functions for exprTree ([809dfae](https://github.com/CWood-sdf/banana.nvim/commit/809dfae415f7907671b8d4827e2a5aa7ff5459f3))
* **ast:** rename some methods ([2037149](https://github.com/CWood-sdf/banana.nvim/commit/2037149f3cc7a08b9864c955f06f9f3ae1fa48c6))
* **ast:** set the formatType to component's formatType on mount ([5c44286](https://github.com/CWood-sdf/banana.nvim/commit/5c44286bea88b19b59f323be05d45ba1c036198f))
* **box:** make fillChar actually used ([809dfae](https://github.com/CWood-sdf/banana.nvim/commit/809dfae415f7907671b8d4827e2a5aa7ff5459f3))
* **box:** weak tables make long term storage unstable ([aafbb03](https://github.com/CWood-sdf/banana.nvim/commit/aafbb034facc0b35cf2ffd37392827ca016c87ad))
* **canvas:** add fillBg and fillFg ([69ad506](https://github.com/CWood-sdf/banana.nvim/commit/69ad5063759fe55a909dd4cbc94f9c3a7700be21))
* **canvas:** prototype for basic things ([cc8800d](https://github.com/CWood-sdf/banana.nvim/commit/cc8800d22ff9ed8c85cd86f5917bd53504b7ef7d))
* **cleanAst:** marginally better errors ([20ceba4](https://github.com/CWood-sdf/banana.nvim/commit/20ceba4e21dbe462b686c55481abdff2b89b79e2))
* **command:** add :BananaSo ([09ae230](https://github.com/CWood-sdf/banana.nvim/commit/09ae23024c0ca987bd51d79e27751a2a0ee1688b))
* **command:** add notification for instance id ([fa5eea9](https://github.com/CWood-sdf/banana.nvim/commit/fa5eea992d82e5e7584974727e145a5a6a493a2a))
* **debug:** add class wrap ([6f64cfc](https://github.com/CWood-sdf/banana.nvim/commit/6f64cfc20ed2fe311c5eb4918d3d291dbf0ab7ac))
* **doc:** add autodocgen scripts ([925af34](https://github.com/CWood-sdf/banana.nvim/commit/925af34492c56f6b5679a73159cb1e99be74018d))
* **entity:** add entity support ([182719c](https://github.com/CWood-sdf/banana.nvim/commit/182719c51f1e665c61c94415d72be2cb8c7c20f7))
* **init:** add editorSetup and initFiletypes ([1865a2b](https://github.com/CWood-sdf/banana.nvim/commit/1865a2ba1b4340649e7f6774129b388de0efb320))
* **instance:** add events and random changes ([7cbb687](https://github.com/CWood-sdf/banana.nvim/commit/7cbb6879cbca20e8e3f21c2d183fa911a59e601b))
* **instance:** add getPrimaryNode ([5278e0d](https://github.com/CWood-sdf/banana.nvim/commit/5278e0d0d3f751ce20a0f4d885d55adcb5413d2a))
* **instance:** add OpenPost event ([8134640](https://github.com/CWood-sdf/banana.nvim/commit/8134640a0858cdac01ffcf8210e10437474e7a69))
* **Instance:** update events and undeprecate `Instance:on` ([84d540c](https://github.com/CWood-sdf/banana.nvim/commit/84d540cb0a1293462c1d1918e8287054445bb405))
* **instance:** use extmarks for highlighting ([3593320](https://github.com/CWood-sdf/banana.nvim/commit/3593320e5d0141baf80bd6c7299f9553d52f421f))
* **log:** change default level to warn for parse warnings visible by default ([3614967](https://github.com/CWood-sdf/banana.nvim/commit/3614967bc05b8bab7d68fedb1e5f3d9275ba6eea))
* **log:** prototype log context addition ([d2af775](https://github.com/CWood-sdf/banana.nvim/commit/d2af7752fbdbff14ba623ddefc588c1a175eef7d))
* **meta:** allow shorthand syntax ([c769468](https://github.com/CWood-sdf/banana.nvim/commit/c7694686f475e3e297813e43a5394b0d8f924ee6))
* **meta:** compute numerical and boolean properties ([d1b45f0](https://github.com/CWood-sdf/banana.nvim/commit/d1b45f078c64b2009535286f2247da3325aa05db))
* move filetype setup to own file ([783de00](https://github.com/CWood-sdf/banana.nvim/commit/783de002b895ef5fbf971a7533aa662eaeb18571))
* **ncss:** add calc() prototype ([809dfae](https://github.com/CWood-sdf/banana.nvim/commit/809dfae415f7907671b8d4827e2a5aa7ff5459f3))
* **ncss:** add list-style-type:number ([2178260](https://github.com/CWood-sdf/banana.nvim/commit/2178260de647b48b375663b945af768744ca7061))
* **ncss:** add support for nth-of-type ([4302d40](https://github.com/CWood-sdf/banana.nvim/commit/4302d400990ba1bc815abbeb9bf40d026b6cf4be))
* **ncss:** rework exprtree and remove plain value ([e70ad40](https://github.com/CWood-sdf/banana.nvim/commit/e70ad402a5d967087844c6e906e5bf52a00ddfdf))
* **nml grammar:** add canvas element ([0b8f41d](https://github.com/CWood-sdf/banana.nvim/commit/0b8f41d606ab628de064163e246577f8788621f4))
* **nml:** actually make templates inline ([2d3389a](https://github.com/CWood-sdf/banana.nvim/commit/2d3389a30a8036a767b727e931d04032b89f0e3f))
* **nml:** allow end tags to contain spaces ([a6e61db](https://github.com/CWood-sdf/banana.nvim/commit/a6e61dbdcb6cf672ccff7b8805b7500408a24297))
* **nml:** finish template parser ([2f839e7](https://github.com/CWood-sdf/banana.nvim/commit/2f839e77826dbd4a5f597a2f7c9ec19c46315c05))
* **nml:** parser styles attrs into both attr and decl ([20ceba4](https://github.com/CWood-sdf/banana.nvim/commit/20ceba4e21dbe462b686c55481abdff2b89b79e2))
* **Query:** add helper functions ([4302d40](https://github.com/CWood-sdf/banana.nvim/commit/4302d400990ba1bc815abbeb9bf40d026b6cf4be))
* **require:** allow force reloading ([aac500e](https://github.com/CWood-sdf/banana.nvim/commit/aac500e018099cbf2ca508562eb921f108179c44))
* **setup:** add setup functions for people's configs ([c958b07](https://github.com/CWood-sdf/banana.nvim/commit/c958b07e4de16e774c3359e18b532c890d181db1))
* **slot:** allow inline slots ([a6c7d2b](https://github.com/CWood-sdf/banana.nvim/commit/a6c7d2b482710c30bd2fa2ec837c649350061dfe))
* **tags:** add &lt;a&gt; support ([3593320](https://github.com/CWood-sdf/banana.nvim/commit/3593320e5d0141baf80bd6c7299f9553d52f421f))
* update tree dump ([deabbfd](https://github.com/CWood-sdf/banana.nvim/commit/deabbfd29271e79591ac59ea8d9a950f82f60200))
* **zig:** add stuff ([c720dc2](https://github.com/CWood-sdf/banana.nvim/commit/c720dc2fc5cac6a955fff92778d2fee2bb17b22f))


### Bug Fixes

* **ast:** componentPath shouldnt be nil, and should be in clone() ([7cf22f2](https://github.com/CWood-sdf/banana.nvim/commit/7cf22f2e160f6fd8c7326c4413bf14ccbf9ce14f))
* **ast:** parsing class list incorrectly ([1175194](https://github.com/CWood-sdf/banana.nvim/commit/1175194705be2999f82f0c7bccc4b3ecd6bc14a2))
* **body, nml:** setting hl-bg sets windows background ([4297c30](https://github.com/CWood-sdf/banana.nvim/commit/4297c303cdc595cb8da96091f773868df638e641))
* **flex:** compute bounding box correctly on wrap ([5af8421](https://github.com/CWood-sdf/banana.nvim/commit/5af84216a99bb3f712db5d206a4fcc9bef8ea415))
* **gradient:** allow gradients to be applied to multiple ast nodes ([8c88f11](https://github.com/CWood-sdf/banana.nvim/commit/8c88f11490d7918742baadac40e437c571d52719))
* **head:** pass child component to render ([eea57e6](https://github.com/CWood-sdf/banana.nvim/commit/eea57e6d6979af027cd936a82da2c64b18fff03a))
* **li:** compute bounding box correctly ([cdacb26](https://github.com/CWood-sdf/banana.nvim/commit/cdacb268f3f45984d512fd15c612c75afa7c40be))
* **ncss:** allow parsing comments ([bdf1a3f](https://github.com/CWood-sdf/banana.nvim/commit/bdf1a3f44ad76f3d3dee412a62db6259096aebc5))
* **nml:** include whitespace around text as part of the parsed text ([594a810](https://github.com/CWood-sdf/banana.nvim/commit/594a810f69793f90fe06df247adff8f779b800f5))


### Miscellaneous Chores

* revert release to 0.3.0 ([2d66a2b](https://github.com/CWood-sdf/banana.nvim/commit/2d66a2b4774dfbaf30094864f6230cfe20a59482))

## [0.2.0](https://github.com/CWood-sdf/banana.nvim/compare/v0.1.0...v0.2.0) (2024-12-11)


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
