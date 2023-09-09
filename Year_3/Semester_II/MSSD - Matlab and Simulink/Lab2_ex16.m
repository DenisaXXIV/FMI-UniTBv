arr = [2 3 -4 1 0];
displayPositives(arr);

function a = displayPositives(v)
for i = 1 : length(v)
    if( v( i) > 0 )
        disp( v( i) )
    end
end
end