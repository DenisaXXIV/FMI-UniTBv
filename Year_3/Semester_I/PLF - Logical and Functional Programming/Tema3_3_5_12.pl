/*
Vasile Denisa- Georgiana, grupa 10LF203

 (Tema) 3. Scrieți un predicat care sa determine toate descompunerile unui număr  în suma de  numere consecutive. 
  Eg. desc(9) => 2+3+4.

              		    ╔══
              		    ╠  true			, L=[l1,l2] && l1+1=l2
 isConsec(l1,l2,..., ln) ═ ╠  isConsec(l2,...,ln)	, l1+1=l2 && n>2			
              		    ╠  false			, otherwise
              		    ╚══

*/
decomp2(N, X, Y) :-
    between(1, N, X),
    between(1, N, Y),
   % X < Y,
    N =:= X + Y.

decomp(N, [N]).
decomp(N, [X|L]) :-
    decomp2(N, X, Y), 
    decomp(Y, L).

isConsec([X,Y]):-
    X+1=:=Y.
isConsec([H1,H2|T]):-
    H2=:=H1+1, 
    isConsec([H2|T]).

nAsSumOfConsecutives(N,L):-
    decomp(N,X), 
    isConsec(X), L=X.

main3(N,L):-findall(R,nAsSumOfConsecutives(N,R),L).

/*
 main3(9,L) -> L = [[2, 3, 4], [4, 5]]
 main3(25,L) -> L = [[3, 4, 5, 6, 7], [12, 13]]
 main3(0,L) -> L = []
 main3(-9,L) -> L = []
*/

/*
 (Hands-on) 5. Scrieți un predicat care determina   toate aranjamentele de k elementele ale  unei liste.
Eg.: [2, 3, 4] K=2 => [[2,3], [3,2], [2,4], [4,2], [3,4], [4,3]] (nu neaparat in aceasta ordine)

              		 ╔══
              		 ╠  []        	 	, []
 arrang(l1,l2,...,ln,k) ═ ╠  [] 		, k > l.size()	
              		 ╠  arrang(l2,..ln,k)   	, otherwise
              		 ╚══

*/

arrang(L, N, [H|T]) :-
    N > 1,
    select(H, L, M), 
    N1 is N-1,      
    arrang(M, N1, T).   
arrang(L, 1, [X]) :- member(X, L).

main5(Elements, K, Arrangement) :-
    findall(A,arrang(Elements, K, A),Arrangement).

/*
 main5([2,3,4],2,A) -> A = [[2, 3], [2, 4], [3, 2], [3, 4], [4, 2], [4, 3]]
 main5([],2,A) -> A = []
 main5([2],2,A) -> A = []
 */

/*
 (Tema) 12. Scrieți un predicat care generează toate descompunerile unui număr n in suma de k,  numere naturale (nu neaparat consecutive).
    Eg: 9 = 2+3+4; (k=3)
           9 = 5+4;(k=2)
           9 = 8+1, (k=2) etc

              		        ╔══
              		        ╠  0 			, []
 list_length(l1,l2,...,ln,k) ═ ╠  
              		        ╠  list_length(l2,..,ln,k)   	, otherwise
              		        ╚══

*/

list_length(Xs,L) :- list_length(Xs,0,L) .
list_length( []     , L , L ) .
list_length( [_|Xs] , T , L ) :-
  T1 is T+1 ,
  list_length(Xs,T1,L).

nAsSum(N,K,L):-
    decomp(N,X), 
    list_length(X,K1),
    L=X,
    K1 =:= K.

main12(N,K,L):-findall(R,nAsSum(N,K,R),L).

/*
 main12(9,8,L) -> L = [[1, 1, 1, 1, 1, 1, 1, 2]]
 main12(9,4,L) -> L = [[1, 1, 1, 6], [1, 1, 2, 5], [1, 1, 3, 4], [1, 2, 1, 5], [1, 2, 2, 4], [1, 3, 1, 4], [1, 3, 2, 3], [2, 1, 1, 5], [2, 1, 2, 4], [2, 2, 1, 4], [2, 2, 2, 3], [2, 3, 1, 3], [3, 1, 1, 4], [3, 1, 2, 3], [3, 2, 1, 3], [4, 1, 1, 3], [4, 2, 1, 2]]
 main12(9,0,L) -> L = []
 main12(9,1,L) -> L = [[9]]
 main12(9,9,L) -> L = [[1, 1, 1, 1, 1, 1, 1, 1, 1]]
*/







