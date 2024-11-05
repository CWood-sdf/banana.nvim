# Gradient todo list

- [x] Color stops
- [x] Color medians (halfways pts)
- [ ] Better \<pre\> support
- [x] Radial (Should just be a swap of the mult generator)
- [ ] Shapes for radial
- [ ] Radius for radial
- [x] Have linear/radiant generate a mult that can then be used to interpolate between colors
- [x] ^^Other option is to find the interpolation space (ie 40%-60%) that mult is in, then do interpolation in that
- [x] Need to normalize start/halfway points (ie from real length to pct/num)
- [x] Math caching/is it worth it (0.148ms for 455 ch (.3us/ch)). Maybe worth it linear but not radial
- [ ] Color spaces???
