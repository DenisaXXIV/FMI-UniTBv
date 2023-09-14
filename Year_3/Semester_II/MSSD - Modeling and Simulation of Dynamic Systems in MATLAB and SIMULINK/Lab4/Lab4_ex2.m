% y' = 4 + (y/x) + (y/x)^2    ;   y(1) = 2

syms y(x)
eqn = diff(y,x) == 4 + (y/x) + (y/x)^2;
cond = [y(1) == 2 ];
ysolve(x) = dsolve(eqn,cond);
x = linspace(1 , 2, 100);
plot(x,real(ysolve(x)),'r',x,imag(ysolve(x)),'b');

% call: ysolve(x)
% ysolve(x) = - x*2i + (4*x)/(x^4i - 1i)