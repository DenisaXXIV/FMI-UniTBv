% y' = z
% z' = -y'    , y = y(t) , z = z(t)

syms y(t) z(t)
eqns = [ diff(y,t) == z , diff(z,t) == -y]
S = dsolve(eqns);

%S = 
%  struct with fields:
%    z: C2*cos(t) - C1*sin(t)
%    y: C1*cos(t) + C2*sin(t)