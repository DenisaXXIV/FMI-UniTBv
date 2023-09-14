% y''' - 3 * y' + 2 * y = sin(x) + 2 * cos(x)

syms y(x)
Dy = diff(y,x,1);
Dy2 = diff(y,x,2);
ec = diff(y,x,3) == sin(x) + 2 * cos(x) + 3 * Dy - + 2 * y;
cond = [y(0) == 1 ; Dy(0) == 0 ; Dy2(0) == 0 ; Dy3(0) == 0 ];
ysol(x) = dsolve(ec, cond);
x = linspace(0,3,100);
plot(x,real(ysol(x)),'r',x,imag(ysol(x)),'g');

% call: dsolve(ec, cond)
% dsolve(ec, cond) = (2*exp(-2*x))/45 + cos(x + atan(3/4))/2 + (5*exp(x))/9 - (x*exp(x))/6