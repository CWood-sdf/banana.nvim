v/= Expect/d

%s/^const /---@alias Banana._header.
%s/= Expect(//e
%s/= ExpectStruct("\(.*\)", .*/\1/e
%s/= ExpectStr("//e
%s/");/
%s/);/
%s/)/):/
%s/fn/fun/

%s/Highlight/u32/g

%s/\(u\|i\)\d\d/number/ge
%s/\(u8\|i8\)/number/ge
%s/bool/boolean/ge
%s/void/nil/ge
