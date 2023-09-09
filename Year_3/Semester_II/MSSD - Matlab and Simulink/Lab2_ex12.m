arr = [ 1 5 3 7 4 4 6 -1 0];
S = sumEven(arr);

function x = sumEven(v)

x = 0;

for i = 1 : length(v)

    if mod(v(i), 2) == 0
        x = x + v(i);
    end
end
end
