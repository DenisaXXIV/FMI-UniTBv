t = -10 : 0.0001 : 10;
n = length(t);

for i = 1 : n
    if (( t( i) >= -10 ) & ( t( i) < -4 )) | (( t( i) >= 4 ) & ( t( i) <= 10))
        f( i) = sin( t( i));
    else
        f( i) = cos( 5 * t( i));
    end
end
plot(t,f,'k');