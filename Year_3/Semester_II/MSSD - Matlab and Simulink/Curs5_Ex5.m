% smile face = cerc centrat in C(3,4) R=2, ochii B(2,4.5) A(4,4.5)
% gura este un arc de cerc => x,y = coord polare ale cercului centrat in
% D(3,3.5) raza R=1, unghiul descris de gura smile [pi,2pi]

tochi=linspace(0,2*pi,100);
xos=2+0.1*cos(tochi);
yos=4.5+0.1*sin(tochi);
fill(xos,yos,'k', 'EdgeColor','r','LineWidth',4)
hold on

xod=4+0.1*cos(tochi);
yod=4.5+0.1*sin(tochi);
fill(xod,yod,'k')

tgura=linspace(pi+pi/4,2*pi-pi/4,100);
xgura=3+1*cos(tgura);
ygura=3.8+1*sin(tgura);
plot(xgura,ygura,'k')