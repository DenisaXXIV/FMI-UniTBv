syms x y z;
% (a)
% S = solve([x-y+z==2,2*x-y+z==2,x+z==1],[x,y,z])
% S = [S.x S.y S.z]
%
% (b)
% M = [ 3 4 -1; 1 2 1; 1 1 0]
% R = [ -2; -2; 0 ]
% S = inv(M)*R
%
% (c)
% S = solve([x-3*y-z==2,2*x-y-z==1,x+2*y+z==1],[x,y,z])
% S = [S.x S.y S.z]