/*
Vasile Denisa-Georgiana, grupa 10LF203
1. Scrieți un predicat care calculează c.m.m.d.c. dintre minimul și 
maximul elementelor unei liste.
                         	 ╔══
                         	 ╠   min	               	 	, [min]
 min(l1,l2,....,ln,min) ═╠   l1			, l1<min
                         	 ╠   min(l2,l3,...,ln,min)  	, altfel
                         	 ╚══

                         	   ╔══
                         	   ╠   max	                	 	, [max]
 max(l1,l2,....,ln,max) ═╠   l1			, l1>max
                         	   ╠   max(l2,l3,...,ln,min) 	, altfel
                         	   ╚══

                   	       ╔══
                   	       ╠   M	                	 		, M=N
 cmmdc(M,N,CMMDC) ═╠   cmmdc(M,N-M,cmmdc) 		, N>M
                   	       ╠   cmmdc(M-N,N,cmmdc) 		, altfel
                   	       ╚══

*/
exercitiul1([Head|Tail], CMMDC) :-
    minim([Head|Tail], MIN),
    maxim([Head|Tail], MAX),
    cmmdc(MIN, MAX, CMMDC).

cmmdc(M, N, CMMDC) :-
    M =:= N,
    CMMDC is M.

cmmdc(M, N, CMMDC) :-
    N>M,
    Y is N-M,
    cmmdc(M, Y, CMMDC).
    
cmmdc(M, N, CMMDC) :-
    N<M,
    Y is M-N,
    cmmdc(Y, N, CMMDC).


minim([Result], Result).
minim([Head|Tail], Result) :-
    minim(Tail, Result),
    Result =< Head.
minim([Head|Tail], Result) :-
    minim(Tail, R1),
    Head < R1,
    Result is Head.

maxim([Result], Result).
maxim([Head|Tail], Result) :-
    maxim(Tail, Result),
    Result >= Head.

maxim([Head|Tail], Result) :-
    maxim(Tail, R1),
    Head > R1,
    Result is Head.

/*
 exercitiul1([20,15,17,18,19,10],CMMDC) -> 10
 exercitiul1([10,15,17,18,19,20],CMMDC) -> 10
 exercitiul1([10],CMMDC) 				-> 10
 exercitiul1([10,20],CMMDC) 			-> 10
 exercitiul1([],CMMDC) 					-> false
*/

/*
3. Scrieți un predicat care șterge prima apariție a minimului dintr-o listă.

                   	       ╔══
                   	       ╠   []	                	 		, [min]
 delete_first(l1,l2,..,ln,min) ═╠   [l2,l3,...,ln]              , min=l1
                   	       ╠   delete_first(l2,l3,...,ln,min) 		, altfel
                   	       ╚══

*/

sterge(MIN, [MIN|Tail], Tail).
sterge(MIN, [Head|Tail], [Head|Result]) :-
    sterge(MIN, Tail, Result).

exercitiul2([Head|Tail], [Head1|Result]) :-
    minim([Head|Tail], MIN),
    sterge(MIN, [Head|Tail], [Head1|Result]).

/*
  exercitiul2([10,15,12,16,17],[H|T])   -> [15,12,16,17]
  exercitiul2([15,12,8,16,17],[H|T])	-> [15,12,16,17]
*/
