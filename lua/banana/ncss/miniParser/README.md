# ncss mini parser

this folder contains what will eventually be a mini parser for ncss that produces the exact same ast structure that treesitter does

the point of this is to (hopefully) make dynamic styling possible because it wont take 5ms to parse a ncss stylesheet (hopefully)

bc right now, if we tried to do that, we would have to make tons of bg buffers (which is sus and i think what is causing the speed reduction)

i just dont want to work on this right now bc parsers are kinda boring lowkey
