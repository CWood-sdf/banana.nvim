" transforms a zig file with lua export functions into a json file of
" declarations
v/^pub fn/d
%s/pub fn /
%s/ {/
v/box_/d
%s/!/
%s/\[]const u8/string/g
%s/Highlight/u16/g
%s/\(\w*\): \([a-zA-Z0-9?]*\)/["\1", "\2"]/g
%s/ \(\w*\)$/, ["\1"],
%s/(/, "params": [
%s/,$/],
%s/^\(\w*\)/"name": "\1"
%s/]),/],
%s/),/
%s/^\(.*\),$/{\1},
%s/\(\w*Expect\)/Banana._header.\1/g
norm ggO[
norm Go]
norm Gk$x
exe "normal ggVG\<esc>"

'<,'>!jq

%s/\(u\|i\)\d\d/number/ge
%s/\(u8\|i8\)/number/ge
%s/usize/number/ge
%s/bool/boolean/ge
%s/void/nil/ge
