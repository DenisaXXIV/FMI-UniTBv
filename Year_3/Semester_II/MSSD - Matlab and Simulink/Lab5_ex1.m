% Represent a neutral face.
% ochi = 6 4.5
% ochi = 7.5 4.5
% gura = 5.5 3 <-> 8 3

rectangle('Position',[ 5 2 3.5 3.5 ], 'curvature', [1 1], 'FaceColor','y');
hold on;

tochi=linspace(0,2*pi,100);
xos=6+0.1*cos(tochi);
yos=4.5+0.1*sin(tochi);
fill(xos,yos,'g');
hold on;

xod=7.5+0.1*cos(tochi);
yod=4.5+0.1*sin(tochi);
fill(xod,yod,'g');
hold on;

xlinie=[5.5;8];
ylinie=[3;3];
plot(xlinie,ylinie,'r');
title("Neutral Face");
axis([4.5 8.5 2 5.5]);
grid on;

