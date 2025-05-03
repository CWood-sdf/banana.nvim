" transforms a zig file with lua export functions into a json file of
" declarations
v/^pub fn/d
%s/pub fn /
%s/ {/
v/box_/d
%s/!/
%s/\[]const u8/string/g
%s/Highlight/u32/g
%s/\(\w*\): \(\w*\)/"\1": "\2"/g
%s/ \(\w*\)$/, "_ret": "\1",
%s/(/: {
%s/,$/},
%s/^\(\w*\)/"\1"
%s/"),/",
%s/),/
norm ggO{
norm Go}
norm Gk$x
exe "normal ggVG\<esc>"
'<,'>!jq
