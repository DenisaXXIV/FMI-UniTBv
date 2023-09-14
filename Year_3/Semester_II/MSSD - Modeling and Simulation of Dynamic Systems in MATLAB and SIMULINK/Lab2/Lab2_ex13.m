% F = [ 0 1 1 2 3 5 ] 
n = 5;
F = fibonacci(n);

function x = fibonacci(y)

a = 0;
x = 1;

for i = 2 : y
    i = a + x;
    a = x;
    x = i;
end
end