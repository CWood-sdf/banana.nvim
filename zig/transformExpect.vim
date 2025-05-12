v/= Expect/d

%s/^const /---@alias 
%s/= Expect(//e
%s/= ExpectStr("//e
%s/");/
%s/);/
%s/)/):/
%s/fn/fun/

%s/Highlight/u32/g

%s/\(u\|i\)\d\d/number/ge
%s/bool/boolean/ge
%s/void/nil/ge
