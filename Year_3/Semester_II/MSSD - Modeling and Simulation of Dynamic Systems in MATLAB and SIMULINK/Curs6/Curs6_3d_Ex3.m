% sa se reprezinte o piramida triunghiulata VABC determinata de
%V(3/2, 3/2, 2), A( 1 1 1), B(1 2 1), C(2 2 1)
%se declara varfurile unei fete si se umple cu culoare
%fetele piramidei sunt: V=1 A=2 B=3 C=4
figure
%fata 1 =VAB
x1=[3/2 1 1];
y1=[3/2 1 2];
z1=[2 1 1];
fill3(x1,y1,z1,'r')
hold on
%fata 2 =VBC
x2=[3/2 1 2];
y2=[3/2 2 2];
z2=[2 1 1];
fill3(x2,y2,z2,'g')
hold on
%fata 3 =VAC
x3=[3/2 1 2];
y3=[3/2 1 2];
z3=[2 1 1];
fill3(x3,y3,z3,'b')
hold on
%baza ABC
x4=[1 1 2];
y4=[1 2 2];
z4=[1 1 1];
fill3(x4,y4,z4,'y')

grid on;