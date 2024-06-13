<div align="center">
  <h1>PLF - Logical and Functional Programming
</h1>
  </div>
  <p>Procedural programming uses a list of instructions to tell the computer what to do step by step. Procedural programming relies on procedures, also known as routines. A procedure contains a series of computational steps to be carried out. Procedural programming is also referred to as imperative or structured programming.</p>
  <p>Procedural programming is intuitive in the sense that it is very similar to how you would expect a program to work. If you want a computer to do something, you should provide step-by-step instructions on how to do it. Many of the early programming languages are all procedural. Examples of procedural languages include Fortran, COBOL and C, which have been around since the 1960s and 70s.</p>
  <p>A common technique in procedural programming is to repeat a series of steps using iteration. This means you write a series of steps and then tell the program to repeat these steps a certain number of times. This makes it possible to automate repetitive tasks. </p>

## I. Algorithms

| No. | Algorithm                                                       | Prolog File | Lisp File |
|:---:| --------------------------------------------------------------- |:-----------:|:---------:|
|     | **Fundamental**                                                 |             |           |
| 1   | Minimum                                                         | [x](#)      | [x](#)    |
| 2   | Maximum                                                         | [x](#)      | [x](#)    |
| 3   | Greatest Common Divisor                                         | [x](#)      | [x](#)    |
| 4   | Least Common Multiple                                           | [x](#)      | [x](#)    |
| 5   | Factorial of a number                                           | [x](#)      | [x](#)    |
|     | **Delete**                                                      |             |           |
| 6   | Delete the first occurrence of the minimum                      | [x](#)      | [x](#)    |
| 7   | Delete all occurrences of the maximum                           | [x](#)      | [x](#)    |
| 8   | Delete all occurrences of n                                     | [x](#)      | [x](#)    |
| 9   | Delete the repeating elements                                   | [x](#)      | [x](#)    |
|     | **Insert**                                                      |             |           |
| 10  | Add n from m to m positions                                     | [x](#)      | [x](#)    |
| 11  | Add to the powers of 2 positions                                |             |           |
|     | **Create**                                                      |             |           |
| 12  | Creating a list of pairs consisting of [atom, atom_occurrences] |             |           |
|     | **Multiple lists**                                              |             |           |
| 13  | Interclassing two lists                                         |             |           |

## II. Code

1. Minimum
   
   ```Mathematical
   minimum([H|T]) = { x            , daca L = {x}
                    { minimum(T,H) , daca H < R
                    { minimum(T,R) , daca H >= R
   ```
   
   | Prolog                                                                             | Lisp                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-11-03-24-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-03-11-18-45-image.png" title="" alt="" width="678"> |
   
   ```Prolog
   minim([R], R).
   minim([H|T], R) :-
       minim(T, R),
       H >= R.
   minim([H|T], R) :-
       minim(T, R1),
       H < R1,
       R is H.
   
   main(L) :-
       minim(L,R),
       writeln(R).
   ```
   
   ```LISP
   (defun minimum (lst)    ; definim functia
     (if (null (cdr lst))  ; verificam daca lst are un singur element
         (car lst)         ; daca da, atunci returnam primul element
         (let ((r (minimum (cdr lst)))) ; daca nu, atunci cream un r
           (if (< (car lst) r)   ; comparam primul element cu r
               (car lst)         ; daca da, atunci returneaza elementul
               r                 ; daca nu, atunci returneaza r
           )
         )
     )
   )
   ```

2. Maximum
   
   ```Mathematical
   maximum([H|T]) = { x            , daca L = {x}
                    { maximum(T,H) , daca H > R
                    { maximum(T,R) , daca H =< R
   ```
   
   | Prolog                                                                             | Lisp                                                                               |
   | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-11-51-45-image.png) | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-11-51-33-image.png) |
   
   ```Prolog
   maximum([R], R).
   maximum([H|T], R) :-
       maximum(T, R),
       H =< HR.
   maximum([H|T], R) :-
       maximum(T, R1),
       H > R1,
       R is H.
   
   main(L) :-
       maximum(L,R),
       writeln(R).
   ```
   
   ```LISP
   (defun maximum (lst)    ; definim functia
     (if (null (cdr lst))  ; verificam daca lst are un singur element
         (car lst)         ; daca da, atunci returnam primul element
         (let ((r (maximum (cdr lst)))) ; daca nu, atunci cream un r
           (if (> (car lst) r)          ; comparam primul element cu r
               (car lst)                ; daca da, atunci returneaza elementul
               r                        ; daca nu, atunci returneaza r
           )
         )
     )
   )
   ```

3. Greatest Common Divisor
   
   ```Mathematical
   cmmdc(M,N,CMMDC) ═ {M , N = 0
                      {cmmdc(N,M % N,cmmdc) , altfel
   ```
   
   | Prolog                                                                             | Lisp                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-12-42-28-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-03-12-42-07-image.png" title="" alt="" width="409"> |
   
   ```Prolog
   cmmdc(M, N, CMMDC) :-
       N =:= 0,
       CMMDC is M.
   
   cmmdc(M, N, CMMDC) :-
       N =\= M,
       Y is M mod N,
       cmmdc(N, Y, CMMDC).
   
   main(M,N) :-
       cmmdc(M,N,CMMDC),
       writeln(CMMDC).
   ```
   
   ```LISP
   (defun cmmdc (a b)       ; definim functia
     (if (zerop b)          ; daca b = 0,
         a                  ; atunci cmmdc = a
         (cmmdc b (mod a b) ; altfel cmmdc(b, a%b)
         )
     )
   )
   ```

4. Least Common Multiple
   
   ```Mathematical
   cmmmc(M,N,CURR) ═ {CURR = max(M,N) , max(M,N) % N = 0
                     {cmmmc(M, N, CURR + A ) , altfel
   ```
   
   | Prolog                                                                             | Lisp                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-13-49-49-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-03-13-09-00-image.png" title="" alt="" width="570"> |
   
   ```Prolog
   cmmmc(_,N,CURR,LCM) :- 
       Y is CURR mod N,
       Y =:= 0,
       LCM is CURR.
   
   cmmmc(M,N,CURR,LCM) :-
       Y is CURR mod N,
       Y =\= 0,
       Z is CURR + M,
       cmmmc(M,N,Z,LCM).
   
   main(M,N) :-
       cmmmc(M,N,max(M,N),LCM),
       writeln(LCM).
   ```
   
   ```LISP
   (defun cmmmc (a b current)        ; definim functia
     (if (zerop (mod current b))     ; daca curr%b = 0
         current                     ; atunci returnam curr
         (cmmmc a b (+ current a)))) ; altfel cmmmc(a,b,curr+a)
   
   (defun main (a b)                 ; definim functia main
     (cmmmc a b (max a b)))          ; cmmmc(a,b, max(a,b) )
   ```

5. Factorial of a number
   
   ```Mathematical
   factorial(M) ═ {1 , M = 0
                  {M + factorial( M - 1 ) , altfel
   ```
   
   | Prolog                                                                             | Lisp                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-14-16-17-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-03-14-40-31-image.png" title="" alt="" width="386"> |
   
   ```Prolog
   fact(0,1).
   
   fact(N,R) :-
       N > 0,
       N1 is N-1,
       fact(N1,R1),
       R is N * R1.
   
   main(N) :-
       fact(N,R),
       writeln(R).
   ```
   
   ```LISP
   (defun factorial (num) ; definim functia
     (if (zerop num)      ; daca num = 0,
       1                  ; atunci returnam 1
       (* num 
          (factorial (- num 1) )
       )      ;altfel returnam num*factorial(num-1)
     )
   )
   ```

6. Delete the first occurrence of the minimum
   
   ```Mathematical
   delete_first_occ(L) = { []                        , daca L = []
                         { delete_first_occ(L,H,T)   , daca H == Min
                         { delete_first_occ(T,Min,R) , altfel punem H in R
   ```
   
   | Prolog                                                                             | Lisp                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-05-16-40-30-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-05-20-28-53-image.png" title="" alt="" width="454"> |
   
   ```Prolog
   delete_first_occ([], _, []).
   delete_first_occ([H|T], H, T) :- !. 
   delete_first_occ([H|T], E, [H|R]) :-
       delete_first_occ(T, E, R).
   
   main(L) :-
       minim(L,Min),
       delete_first_occ(L, Min, R),
       writeln(R).
   ```
   
   ```LISP
   (defun delete-first-occurrence(x lst)
     (cond
      ((null lst) nil)
      ((equal x (car lst)) (cdr lst))
      (t (cons (car lst) (delete-first-occurrence x (cdr lst))))
     ) 
   )
   
   (defun main(lst)
    (delete-first-occurrence (minim lst) lst)
   )
   ```

7. Delete all occurrences of the maximum
   
   ```Mathematical
   delete_all(L,val,R) = { []                            , daca L = [] 
          { delete_all(l1,val) U delete_all(l2...ln,val) , daca l1 =lista
          { delete_all(l2...ln,val)                      , daca l1 =val
          { l1 U delete_all(l2....ln,val)                , altfel
   ```
   
   | Prolog                                                                             | Lisp                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-05-23-04-39-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-05-23-23-50-image.png" title="" alt="" width="383"> |
   
   ```Prolog
   delete_all_occ([],_,[]).
   delete_all_occ([H|T],H,R):- 
       delete_all_occ(T,H,R).
   delete_all_occ([H|T],X,[H|R]):-
       delete_all_occ(T,X,R).
   
   main(L) :-
       maxim(L,R1), 
       delete_all_occ(L,R1,R),
       writeln(R).
   ```
   
   ```LISP
   (defun delete-all(x lst)
    ( cond 
      ((null lst) nil) 
      ((equal x (car lst)) (delete-all x (cdr lst)))
      (t (cons (car lst) (delete-all x (cdr lst))))
     ) 
   )
   
   (defun main(lst)
       (delete-all (maximum lst) lst)
   )
   ```

8. Delete all occurrences of n
   
   ```Mathematical
   delete_all(L,val,R) = { []                            , daca L = [] 
          { delete_all(l1,val) U delete_all(l2...ln,val) , daca l1 =lista
          { delete_all(l2...ln,val)                      , daca l1 =val
          { l1 U delete_all(l2....ln,val)                , altfel
   ```
   
   | Prolog                                                                             | Lisp                                                                               |
   | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-07-19-19-52-image.png) | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-07-19-19-34-image.png) |
   
   ```Prolog
   delete_all_occ([],_,[]).
   delete_all_occ([H|T],H,R):- 
       delete_all_occ(T,H,R).
   delete_all_occ([H|T],X,[H|R]):-
       delete_all_occ(T,X,R).
   
   main(L,N) :-
       delete_all_occ(L,N,R),
       writeln(R).
   ```
   
   ```LISP
   (defun delete-all(x lst)
    ( cond 
      ((null lst) nil) 
      ((equal x (car lst)) (delete-all x (cdr lst)))
      (t (cons (car lst) (delete-all x (cdr lst))))
     ) 
   )
   
   (defun main(n lst)
       (delete-all n lst)
   )
   ```

9. Delete the repeating elements
   
   ```Mathematical
   member(val,L) = { nimic                   , daca val = l1
                   { member(val,l2l3,...,ln) , altfel
   
   delete_repeats(L,Vazut,R) = { []                                  , daca L = [] 
                               { l1 U Vazut                          , daca l1 ⊄ Vazut
                               { delete_repeats(l2,l3...,ln,Vazut,R) , altfel
   ```
   
   | Prolog                                                                             | Lisp                                                                               |
   | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-07-19-39-52-image.png) | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-07-19-44-14-image.png) |
   
   ```Prolog
   member(X, [X|_]).
   member(X, [_|T]) :- 
       member(X, T).
   
   delete_repeats([], _, []).  
   delete_repeats([H|T], Seen, [H|R]) :- 
       \+ member(H, Seen),
       delete_repeats(T, [H|Seen], R).
   delete_repeats([H|T], Seen, R) :-  
       member(H, Seen),
       delete_repeats(T, Seen, R).
   
   main(L) :-
       delete_repeats(L,[],R),
       writeln(R).
   ```
   
   ```LISP
   (defun memberp (elem lst)
     (cond
       ((null lst) nil)
       ((equal elem (car lst)) t)
       (t (memberp elem (cdr lst)))))
   
   (defun delete-repeats (lst)
     (labels ((delete-repeats-helper (lst seen)
                (cond
                  ((null lst) nil)
                  ((memberp (car lst) seen)
                   (delete-repeats-helper (cdr lst) seen))
                  (t (cons (car lst)
                           (delete-repeats-helper 
                               (cdr lst) 
                               (cons (car lst) seen)
                           ))))))
       (delete-repeats-helper lst nil)))
   
   (defun main(lst)
    (delete-repeats lst))
   ```

10. Add n from m to m positions
    
    ```Mathematical
    insert(n,m,L) = { []                         , daca L=[]
                    { insert(n,m,l1,l2,n,...,ln) , altfel
                    { nimic                      , altfel
    ```
    
    | Prolog                                                                             | Lisp                                                                               |
    | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
    | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-07-20-04-19-image.png) | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-07-20-14-20-image.png) |
    
    ```Prolog
    insert_n_at_m_positions(_, _, [], _, []).  
    
    insert_n_at_m_positions(N, M, [H|T], Pos, [H, N|R]) :-
        Pos mod M =:= 0, 
        NextPos is Pos + 1,
        insert_n_at_m_positions(N, M, T, NextPos, R).
    
    insert_n_at_m_positions(N, M, [H|T], Pos, [H|R]) :-
        Pos mod M =\= 0,  
        NextPos is Pos + 1,
        insert_n_at_m_positions(N, M, T, NextPos, R).
    
    main(N, M, List) :-
        insert_n_at_m_positions(N, M, List, 1, Result),
        writeln(Result).
    ```
    
    ```LISP
    (defun insert-n-at-m-positions (n m lst)
      (labels ((helper (lst pos)
                 (cond
                   ((null lst) nil)  ; Base case: empty list
                   ((= (mod pos m) 0) (cons n (cons (car lst) (helper (cdr lst) (1+ pos)))))  ; Insert N at this position
                   (t (cons (car lst) (helper (cdr lst) (1+ pos)))))))  ; Do not insert N at this position
        (helper lst 1)))
    
    ;; Main function to insert N at M positions and print the result
    (defun main (n m lst)
      (print (insert-n-at-m-positions n m lst)))
    ```

## III. Exams:

| No. | Algorithm              | Prolog File | Lisp File |
|:---:| ---------------------- |:-----------:|:---------:|
|     | **Partial**            |             |           |
| 1   | PROLOG 2022            |             |           |
| 2   | LISP 2023              |             |           |
| 3   | LISP 2024              |             |           |
|     | **Lab Re-examination** |             |           |
| 4   | winter 2023            |             |           |
| 5   | winter 2024            |             |           |
| 6   | summer 2024            |             |           |
|     | **Examination**        |             |           |
| 7   | 2023 - no. 1           |             |           |
| 8   | 2023 - no. 2           |             |           |
| 9   | 2024 - no. 1           |             |           |
| 10  | 2024 - no. 2           |             |           |
|     | **Re-examination**     |             |           |
| 11  | 2024                   |             |           |
|     | **Re-Re-examination**  |             |           |
| 12  | PLF 2023               |             |           |
| 13  | PLF 2024               |             |           |

### 1) partial PROLOG 2022

1. Calculate the maximum of a given list. main([23, 1, 2, 3]) -> 23
   
   | Mathematical model                                                                 | Prolog                                                                             |
   | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
   | main([5,2,9,9,1]) -> 9                                                             | (main '(9 2 3 5)) -> 9                                                             |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-10-19-35-08-image.png) | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-11-51-33-image.png) |

2. Calculate the sum of the numbers from a given list. main([23, 1, 2, 3]) -> 29
   
   | Mathematical model | Prolog |
   | ------------------ | ------ |
   |                    |        |

### 2) partial LISP 2023

1. For a non-linear list, calculate the sum of the elements in the even positions. The counter will be reset in each sublist. - Each sublist will be scanned, regardless of whether it is in even or odd position. - The elements of the sublist, however, must comply with the conditions in the statement. 
   
   (1 (1 16 3 32) 4 28 (2 24 5 64) 64 6 64 7 8 6) => 300
   
   Explanation: (16 +32) +28+(24+64)+64+64+8 = 300

2. For a type 1 tree, calculate the number of leaves (nodes without successors). Return the list of all leaf nodes.
   
   (leaves_no '(A 2 B 0 C 2 D 0 E 0)) => no = 3 , leaves = (B D E)

### 3) Lab Re-examination 2023

1. **PROLOG:** Write a function to check whether a list is linear or not.

2. **PROLOG:** Write a function to reverse only the continuous sequences in a non-linear list.
   
   [1 [2 [1 3 [2 4] 3] 1] [1 4]] ==> [1 [2 [3 1 [4 2 ] 3 ] 1] [4 1]]

3. **PROLOG:** Write a function that returns a set of all the elements of a non-linear list.

4. **PROLOG:** Determine all permutations with sum S of a non-linear list. (the backtracking method will be used, and the result will be returned with the findall/3 function).

5. **LISP:** Write a function to check whether a list is linear or not.

6. **LISP:** Write a function to reverse only the continuous sequences in a non-linear list.
   
   (1 (2 (1 3 (2 4) 3) 1) (1 4)) ==> (1 (2 (3 1 (4 2 ) 3 ) 1) (4 1))

7. **LISP:** Write a function that returns a set of all the elements of a non-linear list.

8. **LISP:** Write a function to calculate the least common multiple of the elements of a non-linear list.

9. **LISP:** Return the level (and its list of nodes) with the maximum number of nodes for a tree of type (2). The root node level is 0.

10. **LISP:** Return the level (and its list of nodes) with the maximum number of nodes for a tree of type (1). The root node level is 0.

**Obs!:** Poate fi reprezentat:

(1) (A 2 B 0 C 2 D 0 E 0)

(2) (A (B) (C (D) (E)))

### 4) Examination PLF 2023 - no. 1

1. Write a predicate that deletes the first 3 occurrences of an element from a list. If the element appears less than 3 times, all occurrences of this element will be deleted.

2. Write a predicate that calculates the sum of two numbers, represented as lists (without converting the lists into numbers).
   
   sum([1,1,1] , [1,2,9]) => [2,4,0]

### 5) Examination PLF 2023 - no. 2

1. Determine the position(s) of the maximum element of a linear list.
   
   maxpos([10,14,12,14,14],L) => L = [2,5]

2. Determine the successor of a number represented as a list (without turning the list into a number).
   
   [9 9 9] => [1 0 0 0]

### 6) Re-Re-examination PLF 2023

1. Delete the minimum value from a list. 
   
   | Prolog                                       | LISP                                                        |
   | -------------------------------------------- | ----------------------------------------------------------- |
   | main([11,1,3,31,0,7,0,3]) -> [11,1,3,31,7,3] | (main '(11'(1 3)'(1 31 0) 7 0 5)) -> '(11'(1 3)'(1 31) 7 5) |

2. Insert after each power of 2 the maximum value of the even numbers from the list. main([23, 1, 2, 3]) -> [23, 2, 3]

| Prolog                                                                           | LISP                                                                              |
| -------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| main([1, 3, 8, 9, 10, 15, 4, 16]) -> [1, 16, 3, 16, 8, 9, 16, 10, 15, 4, 16, 16] | (main '(1 '(3 8) 9 '(10 15) 4 16)) -> '(1 16 '(3 16 8 16) '(10 16 15 16) 4 16 16) |

### 7) partial LISP 2024

1. Delete the minimum value from a list.

### 8) Lab Re-examination winter 2024

1. For a non-linear list, calculate the sum of elements at even positions. The counter will be reset in each sublist.
   
   - Each sublist will be traversed regardless of whether it is in odd or even position.
   
   - The elements of the sublist, therefore, must respect the conditions of a statement.
   
   (1 (1 16 3 32) 4 28 (2 24 5 64) 64 6 64 7 8 6 )=> P= (16+32)+28+(24+64)+64+64+8=>3

2. For a tree of type 1 , calculate the number of leaves (nodes without successors). Return the list of all leaf nodes.
   
   Ex: (leaves_no ‘(A 2 B 0 C 2 D 0 E 0) )=> no=3, leaves=(B D E)

### 9) Examination 2024 - nr1

1. Write a predicate that deletes the first 3 occurrences of an element from a list. If the element appears less than 3 times, all occurrences of that element will be deleted
   
   | Prolog                                        | LISP                                        |
   | --------------------------------------------- | ------------------------------------------- |
   | main([10, 14, 12, 13, 14],14) -> [10, 12, 13] | (main '(10 14 12 13 14) '14) -> '(10 12 13) |

2. Write a predicate that calculates the sum of two numbers, represented as lists (without converting the lists to numbers).
   
   | Prolog                               | LISP                                |
   | ------------------------------------ | ----------------------------------- |
   | main([1, 1, 1],[1,2,9]) -> [2, 4, 0] | (main '(1 1 1) '(1 2 9) -> '(2 4 0) |

### 10) Examination 2024 - nr2

1. Determine the position/positions of the maximum element of a linear list.
   
   | Prolog                               | LISP                               |
   | ------------------------------------ | ---------------------------------- |
   | main([10, 14, 12, 13, 14]) -> [2, 5] | (main '(10 14 12 13 14)) -> '(2 5) |

2. Determine the successor of a number represented as a list (without converting the list to a number)
   
   | Prolog                       | LISP                          |
   | ---------------------------- | ----------------------------- |
   | main([9, 9, 9]) -> [1 0 0 0] | (main '(9 9 9)) -> '(1 0 0 0) |

### 11) Lab Re-Examination summer 2024

1. **PROLOG:** Define a predicate that determines the difference of two numbers written in the list representation, without converting the list to a number.
   
   ```Mathematical
   reverse_list(L,Aux,R) = { r1 = auxn                                      , daca L = []
                           { reverse_list([l2,...,ln],[l1,aux1,...,auxn],R) , altfel
                           
   trim_zeros(L,R) = { [0]                     , daca L = [0]
                     { trim_zeros(l2,...,ln,R) , daca l1 = 0
                     { nimic                   , daca l1 != 0
                     
   diff_lists(A,B,Borrow,R) = { []                                      , daca A = [] si B = []
                              { diff_lists([a2,...,an],[],1,R)          , daca a1-Borrow < 0 si B=[]
                              { diff_lists([a2,...,an],[],0,R)          , daca a1-Borrow >= 0 si B=[]
                              { diff_lists([],[b2,...,bn],1,R)          , daca -b1-Borrow < 0 si A=[]
                              { diff_lists([],[b2,...,bn],0,R)          , daca -b1-Borrow >= 0 si A=[]
                              { diff_lists([a2,...,an],[b2,...,bn],1,R) , daca a1-b1-Borrow < 0 
                              { diff_lists([a2,...,an],[b2,...,bn],0,R) , daca a1-b1-Borrow >= 0
   ```
   
   | Prolog                                                                                                                                                               |
   | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
   | [3, 4, 5] - [1, 1, 1] -> [2 3 4]                                                                                                                                     |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-10-19-44-51-image.png)![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-10-19-45-04-image.png) |
2. **PROLOG:** Given a linear numeric list, delete all sequences of consecutive values.
   
   ```Mathematical
   skip_seq(x,L) = { skip_seq(l2, l3,l4,...,ln) , daca l1 + 1 = l2
                     { l2,l3,...,ln             , altfel
   
   delete_consecutives(L) = { []                                              , daca L = []
                            { delete_consecutives(l2,l3,...,ln)               , daca l1 + 1 != l2
                            { delete_consecutives(skip_seq(l1, l2,l3,...,ln)) , altfel
   ```
   
   | Prolog                                                                             |
   | ---------------------------------------------------------------------------------- |
   | [1, 2, 4, 6, 7, 8, 10] -> [4, 10]                                                  |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-10-19-47-15-image.png) |
3. **PROLOG:** Given a list of integers, generate the list of subsets of the list.
   
   ```Mathematical
   
   ```
   
   | Prolog |
   | ------ |
   |        |
   
   
4. **LISP:** Write a function that, receiving a list, returns the set of all pairs of non-numeric atoms in the list.
   
   ```Mathematical
   p-non-num(x,L) =    { NIL      , daca L=[NIL]
                       { [[x,l1]] , daca x non-numeric, daca l1
                                          non-numeric si daca [x,l1] sau
                                          [l1,x] apartine deja de Rest
                       { []      , altfel
   
   main(L) = { NIL             , daca L =[NIL]
             { [...,[ln-1,ln]] , altfel
   ```
   
   | LISP                                                                               |
   | ---------------------------------------------------------------------------------- |
   | (A 2 B 3 C D 1) --> ((A B) (A C) (A D) (B C) (B D) (C D))                          |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-10-19-52-47-image.png) |
   
   
5. **LISP:** Write a function that inserts a given element in all positions in a linear list and returns a list of lists.
   
   ```Mathematical
   
   ```
   
   | LISP                                              |
   | ------------------------------------------------- |
   | (inserare '1 '(2 3)) --> ((1 2 3) (2 1 3) (2 3 1) |
   
   
6. **LISP:** Define a function that determines the sum of two numbers in list representation, without converting the numbers to base 10.
   
   ```Mathematical
   
   ```
   
   | LISP                       |
   | -------------------------- |
   | (1 1 1) (2 2 2) -> (3 3 3) |
   
   

### 12) Re-Examination 2024

1. Given a linear list, determine the minimum element of the list.
   
   ```Mathematical
   minim(L) = { x	 , daca L = {x} 
   	       { R = x   	 , daca L= [x|Tail] si x<R
   	       { nimic	, daca L= [x|Tail] si x>R 
   ```
   
   | Prolog                                                                             | LISP                                                                                                                          |
   | ---------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
   | main([9, 2, 3]) -> 2                                                               | (main '(9 2 3)) -> '2                                                                                                         |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-11-03-24-image.png) | <img src="file:///C:/Users/Denisa/AppData/Roaming/marktext/images/2024-06-03-11-18-45-image.png" title="" alt="" width="678"> |

2. **nr1:** A list of integers is given. To replace the elements on the even positions with the difference between their value and the minimum value of the list.
   
   | Prolog                             | LISP                            |
   | ---------------------------------- | ------------------------------- |
   | main([9, 2, 3, 5]) -> [9, 0, 3, 3] | (main '(9 2 3 5)) -> '(9 0 3 3) |

3. **nr2:** A list of integers is given. Write a predicate that inserts before the 1st, 3rd, 9th, etc... the value of the maximum element of the list.
   
   | Prolog                                               | LISP                                       |
   | ---------------------------------------------------- | ------------------------------------------ |
   | main([12, 2, 8, 9, 12]) -> [12, 12, 2, 12, 8, 9, 12] | (main '(12 2 8 9 12)) -> '(12 12 2 12 8 9) |

### 13) Re-Examination 2024

1. Given a linear list, determine the maximum element of the list
   
   ```Mathematical
   maximum(L) = { x	     , daca L = {x} 
                { R = x   	 , daca L= [x|Tail] si x>R 
                { nimic	 , daca L= [x|Tail] si x<R
   ```
   
   | Prolog                                                                             | LISP                                                                               |
   | ---------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
   | main([9, 2, 3, 5]) -> 9                                                            | (main '(9 2 3 5)) -> 9                                                             |
   | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-10-19-35-08-image.png) | ![](C:\Users\Denisa\AppData\Roaming\marktext\images\2024-06-03-11-51-33-image.png) |
2. Insert the maximum of a linear list after each multiple of 3 position.
   
   | Prolog | LISP |
   | ------ | ---- |
   |        |      |

## IV. Homeworks:

### 1)  Java

#### a) Homework 1 : Recursion

*    Ex.6 
  
  - (a) Add an item to the end of a list
  
  - (b) Concatenate two lists

### 2) Prolog

    Prolog is a logic programming language associated with artificial intelligence and     computational linguistics.

#### a) Homework 2 : Lists in Prolog

* Ex.1 - Write a predicate that calculates the c.m.m.d.c. between the minimum and maximum elements of a list.
* Ex.3 - Write a predicate that deletes the first occurrence of the minimum from a list.
* Ex.8 - Write a predicate that transforms a list into one of the form: [(element, element_occurrences)].

#### b) Homework 3 : Lists in Prolog

### 3) Lisp

Lisp is a family of programming languages with a long history and a distinctive, fully parenthesized prefix notation. Originally specified in 1958, Lisp is the second-oldest high-level programming language still in common use.

<br>
<br>
<br>
I hope that this repository helped you, for more details about me, you can access my website: [here](https://denisa-vasile.info/).
