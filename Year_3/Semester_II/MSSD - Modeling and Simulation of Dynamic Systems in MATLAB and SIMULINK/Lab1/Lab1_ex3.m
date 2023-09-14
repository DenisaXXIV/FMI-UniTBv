x=[0:2*pi];
plot(x,3*sin(x) + 2* cos(x),'b--*',x,sin(2*x)+cos(3*x),'g-.o',x,sin(5*x),'r-x');
xlabel('x = [0, 2π]');
ylabel('f (x), g(x), h(x)');
title('The graphic of the trigonometric functions');
legend('f(x) = 3*sin(x) + 2* cos(x)','g(x) = sin(2*x)+cos(3*x)','h(x) = sin(5*x)');