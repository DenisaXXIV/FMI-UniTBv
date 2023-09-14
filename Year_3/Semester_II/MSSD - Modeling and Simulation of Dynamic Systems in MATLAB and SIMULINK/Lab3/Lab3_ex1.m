t0 = 0;
t1 = 4;
t2 = 8;
y0 = 1500;
y1 = 6000;
y3 = 96000;
R = ex1( t0 , t1 , t2 , y0 , y1 , y3 );

function y = ex1( t0 , t1 , t2 , y0 , y1 , y3 )
k = 1 / t1 * log( y1 / y0 );
y2 = y0 * exp( k * t2 );
t3 = 1 / k * log( y3 / y0);
end