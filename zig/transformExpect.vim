v/= Expect/d

%s/^const /---@alias 
%s/= Expect(/
%s/);/
%s/)/):/
%s/fn/fun/

%s/Highlight/u32/g

%s/\(u\|i\)\d\d/number/g
" %s/bool/boolean/g
%s/void/nil/g
