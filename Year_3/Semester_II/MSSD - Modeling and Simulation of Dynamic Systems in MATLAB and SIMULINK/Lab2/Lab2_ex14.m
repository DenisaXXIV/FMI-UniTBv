S = sumUntil20();

function x = sumUntil20()
i = 1;
x = 0;
while x < 20
    x = x + sqrt( 2 * i - 1 );
    i = i + 1;
end
end