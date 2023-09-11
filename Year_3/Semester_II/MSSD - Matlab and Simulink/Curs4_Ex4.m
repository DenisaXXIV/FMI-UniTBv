% ((d^2) * y) / ( d * (t^2)) = (a^2) * y , y(0) = b , y'(0) = 1

syms y(t) a b
eqn = diff(y,t,2) == a^2 * y;
Dy = diff(y,t);
cond = [ y(0) == b , Dy(0) == 1]
ysolve(t) = dsolve(eqn,cond);