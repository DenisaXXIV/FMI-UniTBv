% y^5 + 4 * Y^4 + 5 * y''' - 6 * y' - 4 * y = 0

syms y(x)
Dy = diff(y,x,1);
Dy2 = diff(y,x,2);
Dy3 = diff(y,x,3);
Dy4 = diff(y,x,4);
ec = diff(y,x,5) == 4*y + 6 * Dy - 5 * Dy3 - 4 * Dy4;
cond = [y(0) == 1 ; Dy(0) == 0 ; Dy2(0) == 0 ;Dy3(0) == 0 ;Dy4(0) == 0 ];
ysolve(x) = dsolve(ec,cond);
x = linspace(0,2,100);
plot(x,real(ysolve(x)),'r',x,imag(ysolve(x)),'c');

% call: dsolve(ec, cond)
% dsolve(ec, cond) = 2*exp(-x) - exp(-2*x)/3 + (2*exp(x))/15 - (4*exp(-x)*cos(x))/5 + (2*exp(-x)*sin(x))/5