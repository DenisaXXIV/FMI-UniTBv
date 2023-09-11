%sa se reprezinte miscarea unui punct pe o curba 3D:
%x=cos(t), y=sin(t), z=2t, t in [0, 6pi]
t=linspace(0, 6*pi, 100);
x=cos(t);
y=sin(t);
z=2*t;
for i=1:length(t)
plot3(x,y,z,'color','b')
hold on
plot3(x(i),y(i),z(i),'or')
hold on
drawnow
end