% ( 1 + x^2) * y' - 2*x*y = x ; y(0) = 1/2

syms y(x)
eqn = diff(y,x) == (x + 2*x*y)/(1 + x^2);
cond = [y(0) == 1/2];
ysolve( x ) = dsolve(eqn,cond);
x = linspace(0,2,100);
plot(x,real(ysolve(x)),'k',x,imag(ysolve(x)),'c');

% call: dsolve(eqn,cond)
% dsolve(eqn,cond) = x^2 + 1/2