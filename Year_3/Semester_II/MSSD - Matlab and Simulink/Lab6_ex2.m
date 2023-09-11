% rotate two triangles into a circle such as to optain a rectangle. The
% final shape of the resulting figure of the rotated rectangles will
% be a circle.

t = linspace(0, 2 * pi, 100);
x = 2 * cos(t);
y = 2 * sin(t);

axis([-2 2 -2 2]);

for i=1:length(x)
    X = [-2; 2; x(i)];
    Y = [0; 0; y(i)];
    fill(X, Y, 'b');
    hold on;
    drawnow
end
