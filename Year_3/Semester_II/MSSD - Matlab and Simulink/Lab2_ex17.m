n = 5;
M = generateMat(n);

function A = generateMat(n)

A = zeros(n,n+1);

for i = 1 : n
    for j = 1 : n+1
        if( abs( i - j ) == 1 )
            A( i , j ) = -1;
        elseif i == j
            A( i , j ) = 2;
        else
            A( i , j ) = 0;
        end
    end
end
end
