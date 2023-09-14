rectangle( 'Position' , [ 2 0 4 4 ] , 'FaceColor' , 'g' , 'EdgeColor' , 'g' );

hold on;

x=[ 2.5 ; 5.5 ; 4 ];
y=[ 0.5 ; 0.5 ; 3.5 ];
patch( x , y , 'r' );

title('Draw a red triangle inside of a green square.');
axis( [ 0 10 -2 5 ] );
xlabel('dreapta Ox');
ylabel('dreapta Oy');
grid on;