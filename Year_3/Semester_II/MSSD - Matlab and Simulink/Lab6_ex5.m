% Realize a robot using geometric bodies: cube, 
% paralelipiped, pyramid, cyclinder, sphere.

figure;
hold on;
axis equal;

% Create robot parts using geometric shapes
body = createParallelepiped(0, 0, 0, 1, 1, 3);
head = createCube(0.25, 0.25, 3, 0.5);

% Limbs
left_leg = createCylinder(0.25, 0.5, -1.5, 0.25, 1.5);
right_leg = createCylinder(0.75, 0.5, -1.5, 0.25, 1.5);
left_arm = createCylinder(-0.25, 0.5, 1.5, 0.25, 1.5);
right_arm = createCylinder(1.25, 0.5, 1.5, 0.25, 1.5);

% Hands
left_hand = createSphere(-0.25, 0.5, 1.4, 0.25);
right_hand = createSphere(1.25, 0.5, 1.4, 0.25);

% Tetrahedron on top of the head
tetrahedron = createPyramid(0.25, 0.25, 3.5, 0.5);

% Adjust the view for better visualization
view(3);
grid on;
xlabel('X');
ylabel('Y');
zlabel('Z');



function h = createCylinder(x, y, z, r, h)
    [X, Y, Z] = cylinder(r);
    Z = Z * h;
    X = X + x;
    Y = Y + y;
    Z = Z + z;
    h = surf(X, Y, Z, 'FaceColor', 'b');
end

function h = createParallelepiped(x, y, z, l, w, h)
    vertices = [x y z; x+l y z; x+l y+w z; x y+w z; x y z+h; x+l y z+h; x+l y+w z+h; x y+w z+h];
    faces = [1 2 6 5; 2 3 7 6; 3 4 8 7; 4 1 5 8; 1 2 3 4; 5 6 7 8];
    h = patch('Vertices', vertices, 'Faces', faces, 'FaceColor', 'r');
end

function h = createCube(x, y, z, s)
    h = createParallelepiped(x, y, z, s, s, s);
end

function h = createSphere(x, y, z, r)
    [X, Y, Z] = sphere;
    X = r * X + x;
    Y = r * Y + y;
    Z = r * Z + z;
    h = surf(X, Y, Z, 'FaceColor', 'g');
end

function h = createPyramid(x, y, z, s)
    vertices = [x y z; x+s y z; x+s/2 y+s z; x+s/2 y+s/2 z+s];
    faces = [1 2 3; 1 2 4; 2 3 4; 1 3 4];
    h = patch('Vertices', vertices, 'Faces', faces, 'FaceColor', 'y');
end
