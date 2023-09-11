% sin x + y * y' = 0 ; y(0) = 1
syms y(x)
eqn = diff( y , x ) == -sin( x ) / y;
cond = [ y(0) == 1];
ysolve(x) = dsolve(eqn, cond);
x = linspace(0,2,100);
plot(x, real(ysolve(x)),'r',x,imag(ysolve(x)),'b');

% call: ysolve(x)
% ysolve(x) = 2^(1/2)*(cos(x) - 1/2)^(1/2);