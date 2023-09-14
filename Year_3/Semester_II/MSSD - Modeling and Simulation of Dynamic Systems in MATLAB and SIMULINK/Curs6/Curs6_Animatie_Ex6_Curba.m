% Sa se reprezinte animatia curbei y=sin(x), x in [0,10pi]
h= animatedline('color','r','linewidth',3, 'LineStyle',':');
axis([0,4*pi,-1,1])
x=linspace(0,10*pi,1000);
y=sin(x);
for k=1:length(x)
addpoints(h,x(k),y(k));
drawnow
end