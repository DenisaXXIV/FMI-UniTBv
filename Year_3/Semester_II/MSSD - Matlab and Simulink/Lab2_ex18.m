nr = 5;
% nr = 5i +3;
a = complex(nr);

function isComplex = complex(nr)
    isComplex = not(isreal(nr));
end