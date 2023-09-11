%%reprezentati o sfera de raza r=5
[X,Y,Z]=sphere;
surf(X*5,Y*5,Z*5)
hold on


%reprezentati o sfera de raza r=2 centrata in (2,3,4)
%[X,Y,Z]=sphere;
surf((X+2)*2, (Y+4)*2, (Z+4)*2);

axis equal