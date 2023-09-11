% (d^2 * y) / (d * t^2) = a*y

syms y(t) a
eqn = diff(y,t,2) == a * y;
ysolve(t) = dsolve(eqn);