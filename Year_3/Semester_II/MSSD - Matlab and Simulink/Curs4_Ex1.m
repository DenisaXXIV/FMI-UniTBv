% dy / dt = ay

syms y(t) a
eqn = diff(y,t) == a * y;
S = dsolve(eqn);