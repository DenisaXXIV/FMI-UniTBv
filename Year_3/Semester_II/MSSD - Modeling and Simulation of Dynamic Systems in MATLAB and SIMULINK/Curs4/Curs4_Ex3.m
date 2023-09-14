% (d * y) / (d * t) = a*y , y(0) = 5

syms y(t) a
eqn = diff(y,t) == a * y;
cond = y(0) == 5;
ysolve(t) = dsolve(eqn , cond);