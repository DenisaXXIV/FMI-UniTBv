%Sa se reprezinte miscarea unei sfere de raza r=2 pe curba parametrica 3D:
%x=t, y=sin(2pi t), z=cos(2pi t), t in [0, 10]
[X,Y,Z]=sphere(20,2)
t=linspace(0,10,100);
for i=1:length(t)
surf(X+t(i),Y+sin(2*pi*t(i)),Z+cos(2*pi*t(i)))
hold on
drawnow
end