% Represent the animated epicycloid:
%     /
%    |   x = (a+b) * cos(t) + b * cos(((a+b)/b) * t)
%    |                                                ,a = 12, b = 5,
%    |                                                   t ∈ [0,10*pi]
%    |   y = (a+b) * sin(t) + b * sin(((a+b)/b) * t)
%     \

a = 12;
b = 5;

for t = 0:0.1:10*pi
    x = (a+b) * cos(t) + b * cos(((a+b)/b) * t);
    y = (a+b) * sin(t) + b * sin(((a+b)/b) * t);
    plot(x, y, 'o');
    hold on
    drawnow
    axis([-50 50 -50 50]);
end
