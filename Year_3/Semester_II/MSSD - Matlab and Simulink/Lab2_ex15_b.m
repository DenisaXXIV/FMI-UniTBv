t = -10 : 0.0001 : 10;
n = length(t);

for i = 1 : n
    if t( i) <= 4
        f( i) = 3 * t( i) + 5;
    else
        f( i) = 3 * t( i)^2 + 4 * t( i);
    end
end

plot(t,f);