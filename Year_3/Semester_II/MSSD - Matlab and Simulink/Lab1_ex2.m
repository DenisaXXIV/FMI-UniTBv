x = 0:2*pi;
plot(x,3*sin(x) + 5*exp(2*x),'r');
xlabel('x=[0,2*pi]');
ylabel('f(x)');
title('The graphic of f (x) = 3*sin(x) + 5*exp(2*x)');
axis([0 3 0 1000]);