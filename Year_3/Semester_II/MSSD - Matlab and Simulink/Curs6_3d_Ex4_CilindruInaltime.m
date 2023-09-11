% sa se reprezinte un cilindru de inaltime h=20
r = 2;
h = 20;
[X,Y,Z] = cylinder(r);
Z = Z*h;
surf(X+2,Y+6,Z)