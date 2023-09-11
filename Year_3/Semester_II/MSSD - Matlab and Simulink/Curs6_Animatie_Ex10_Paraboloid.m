%sa se reprezinte miscarea unui paraboloid pe verticala
%z=0.5*x^2+y^2), x,y in [-2,2]
x=linspace(-2,2,100);
y=x;
[X,Y]=meshgrid(x,y);
Z=0.5*(X.^2+Y.^2);
h=surf(X,Y,Z)
axis([-2 2 -2 2 0 50])
for i=1:0.01:10
set (h,'xdata', X, 'ydata', Y, 'zdata', i*Z)
drawnow
end