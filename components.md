- [ ] Per-file components? or define components with special tag (template?)?
- [ ] Child content (\<slot>)
- [ ] Attributes
- [ ] Dom queryable in contained scripts, but not outside (unless shadow=false)
- [ ] Inline/block detection
- [ ] Need a special renderer that just renders sub stuff?
- [ ] Seperate shadow dom (aka all component doms are stored as seperate trees)
- [ ] `shadow` property? (if !shadow then clone tree and inline, if shadow then clone still for scripting, but noinline)
- [ ] should be similarish to loadNmlTo (whatever that means)
- [ ] Shadow dom components need a special root node so that a components individual root node can be removed by a script (the template tag)
- [ ] Force component files to start with a \<template>?
- [ ] If using template then what's the point of per-file components (lookup? scripting?)
- [ ] Need to think about how component libraries would work in this (cant have a global import because every ui is one instance (unlike react where everything is seperate file))
- [ ] Treat imports on a per ast node basis? (ew) (but maybe this could be done well)
- [ ] maybe just per file and ref via path? (that's so much repeating tho)
- [ ] So should template finding be done on a parse level? or on a render level?

Idk im still kinda confused about what we need to do. like whats the exact process

rendering is easy because we can just go to the other tree temporarily. then we can have a inherit variable that is a lookup table for slots (then we wouldn't have to find and update slots, instead lazy load in the tree)

what about scripting, styling, and lookup

scripting could prolly be done similar to loadNmlTo

but that has to be managed on the instance level

but that can be done pretty easily because every ast has inst reference, so we can just use the same mechanisms that loadNmlTo uses.

styling also shouldnt be too hard because if it's just a shadow dom then we can just style seperately

but styling is done in Instance so do we need a component tracker in instance? that feels ugly.
should component shadow doms be tracked on the ast node level?

thats prolly best

but still where is styling handled

i think that can be done on an ast level, maybe have a subclass that the ast node can reference. then just reinvoke styling when the ast styling is called

ok so we have scripting and styling handled but theyre seperated which feels kinda ugly but ig thats just what we doing

tbf, thats kinda already what we doing for other elements

ok so lookup

so first thing is that parser should return component trees seperately that can then be tracked by nmlRequire

ok then we still need to be able to resolve the full path

ugggh idk maybe some weird meta tag (but out of head \<meta> feels ugly). scripting it feels HELLA ugly so it does need to be done in nml. maybe a \<template> tag with a special attribute like idk "import" or something.

but templates are returned out of tree, so we need a check in Parser for that attribute to keep it in tree. or maybe parser can just not return the special template, keep it out of tree, then apply the path changes as a final post processing step

than when a component is encountered we can just search up the tree until a good lookup is found. do we search up the tree above a component? i dont think that would be very easy but maybe we want global imports.

so maybe have a global flag for global imports that can be stored in Instance. no that is unneccessary if we tagging imports on an ast node basis (global imports are just available at the root node). maybe want a global import for project specific components?

## the plan (i think)

### parsing

- just need to return the components parsed

### rendering (ez)

- we have specialized ast nodes that refer to the component (need to ensure that slots have links to main node for O(1) lookup on child elements)
- render can just be a passthrough function on the component ast

### lookup (less ez)

- node paths are store in ast
- can lazy load component tree copies at render time
- prolly lazy load imports at render time. do imports through a template tag or something (have template for import forwarding (like use-imports-from) and one for templates from path (import))

### scripting/styling

- Instance already has support for this
