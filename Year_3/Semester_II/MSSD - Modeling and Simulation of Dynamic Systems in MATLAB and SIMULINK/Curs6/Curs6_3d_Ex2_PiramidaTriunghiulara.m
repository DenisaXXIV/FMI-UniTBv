% sa se reprezinte o piramida triunghiulata VABC determinata de
%V(3/2, 3/2, 2), A( 1 1 1), B(1 2 1), C(2 2 1)
varf=[
    3/2 3/2 2; 
    1 1 1; 
    1 2 1; 
    2 2 1
    ];
%fetele piramidei sunt: V=1 A=2 B=3 C=4
fete = [1 2 3; 1 2 4; 2 3 4; 1 3 4];
patch('Faces', fete, 'Vertices', varf, 'facecolor', 'g');
view (-80,120);
alpha('color');
grid on;