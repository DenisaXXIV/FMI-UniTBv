syms x(t) y(t)

eq1 = diff(x,t) == y + t;
eq2 = diff(y,t) == x + exp(t);
eqns = [ eq1  ; eq2 ];
cond = [ x(0) == 1 ; y(0) == 1 ];
[ xsol(t) , ysol(t) ] = dsolve( eqns , cond );
t = linspace( 0 , 3 , 100 );
plot( t , real( xsol(t) ) , 'r' , t , real( ysol(t) ) , 'g' );

title( 'Differential system of equation represented graphically:')
legend([ "x' = y + t " , "y' = x + e^t" ], "Location" , "northwest" );
grid on;