%sa se reprezinte un cub ABCDEFGH determinat decele 8 varfuri si cele 6 fete
%A(1,1,1), B(1,2,1), C(2,2,1), D(2,1,1)
%E(1,1,2), F(1,2,2), G(2,2,2,) H(2,1,2)
%se declara varfurile:
varf=[ 
    1 1 1; 
    1 2 1; 
    2 2 1; 
    2 1 1;
    1 1 2; 
    1 2 2; 
    2 2 2; 
    2 1 2
    ];
%se declara fetele cubului A=1; B=2; C=3; D=4; E=5;F=6; G=7; H=8;
fete=[1 2 3 4; 2 3 7 6; 6 7 8 5; 5 8 4 1; 4 3 7 8; 1 2 6 5];
% se deseneaza cubul
patch('faces', fete, 'Vertices', varf, 'facecolor', 'r')
%pentru vedere 3D se declara unghiul view(azimut = unghiul in coord polare,
% inaltimea de la care se priveste planul xOy)
view(-30,30);
%pentru a face figura transparenta
alpha('color');
grid on;