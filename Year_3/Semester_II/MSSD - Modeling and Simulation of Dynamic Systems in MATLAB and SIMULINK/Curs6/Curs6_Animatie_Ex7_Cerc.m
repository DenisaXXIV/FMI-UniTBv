% Sa se reprezinte animatia cercului determinat de
%x=5cos(t), y=5sin(t), t in [0,2pi]
for t=0:0.05:2*pi
x=5*cos(t);
y=5*sin(t);
pause(0.01)
plot(x,y,'o')
hold on
drawnow
axis ([-5 5 -5 5])
end