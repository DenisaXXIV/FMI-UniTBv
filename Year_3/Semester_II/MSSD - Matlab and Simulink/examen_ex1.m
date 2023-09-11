% Deseneaza un romb ininteriorul unui cerc

rectangle('Position',[1 0 4 4], 'curvature', [1 1], 'FaceColor','r');
hold on;

x = [2, 3, 4, 3];
y = [2, 3, 2, 1];
diamond = polyshape(x,y);
plot(diamond,'FaceColor','k');

title('Exercitiul 1');
axis([0 10 -2 6]);
grid on;