% x'(t) = x(t) + 2 * y(t) - z(t)
% y'(t) = x(t) + z(t)
% z'(t) = 4 * x(t) - 4 * y(t) + t * z(t)

syms x(t) y(t) z(t)

ec1 = diff(x,t) == x(t) + 2 * y(t) - z(t);
ec2 = diff(y,t) == x(t) + z(t);
ec3 = diff(z,t) == 4 * x(t) - 4 * y(t) + 5 * z(t);

cond = [ x(0) == 1 ; y(0) == 1 ; z(0) == 1 ];
M = [ec1;ec2;ec3];
[xsol(t),ysol(t),zsol(t)] = dsolve(M,cond);
t = linspace(0,2,100);
plot(t,real(xsol(t)),'r',t,real(ysol(t)),'g',t,real(zsol(t)),'b');

% call: dsolve(M, cond)
% dsolve(M, cond) =
%       x: 4*exp(2*t) - (3*exp(3*t))/2 - (3*exp(t))/2
%       y: (3*exp(3*t))/2 - 2*exp(2*t) + (3*exp(t))/2
%       z: 6*exp(3*t) - 8*exp(2*t) + 3*exp(t)