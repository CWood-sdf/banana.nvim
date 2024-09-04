# Gradients

this is just random thoughts on how to implement gradients

width/height has to be determined on the box level somehow (bc of grid/flex gradient cant rely on searching for bounds at render time)

- HAVE to determine the primary box of the gradient so that we have width/height data (might have to restructure pad/margin rendering to engorce this hierachy) (or some sort of transfer of manager on appendBelow and append)
- could just use the box width data to inform the gradient, then have the gradient be actually done at render time (prolly best this one bc it reduces new strings)
- or could have some split function in box:clean() or a box:move() method that splits up the thing into individual characters

once have box bounds can determine radius/axis then its just quik meths to get the values

# NEW THOUGHTS

dont necessarily need some sort of power transfer device where one box has all the control over the width/height of gradient, just need a method to be called after padding called like setGradient or something that sets the wh of the gradient, and if it's wrong element it doesnt matter bc it will be reset by parent
