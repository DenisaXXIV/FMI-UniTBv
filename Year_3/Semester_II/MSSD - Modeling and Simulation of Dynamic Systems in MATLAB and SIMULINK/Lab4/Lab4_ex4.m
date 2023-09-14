% y''' - 3 * y' + 2 * y = x^2 * exp(x)

syms y(x)
Dy = diff(y,x);
Dy2 = diff(y,x,2);
ec = diff(y,x,3) == (x^2)*exp(x) + 3*Dy - 2*y;
cond = [y(0) == 0 ; Dy(0) == 0 ; Dy2(0) == 0];
ysol(x) = dsolve(ec,cond);
x = linspace(0,2,100);
plot(x,real(ysol(x)),'k',x,imag(ysol(x)),'c');

% call: dsolve(ec,cond)
% dsolve(ec,cond) = (x^4*exp(x))/9 - (2*exp(-2*x))/243 + (exp(x)*(9*x^2 - 6*x + 2))/243 - (x^3*exp(x)*(9*x + 4))/108