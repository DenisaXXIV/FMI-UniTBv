
(defun insert-n-at-m-positions (n m lst)
  (labels ((helper (lst pos)
             (cond
               ((null lst) nil)  
               ((= (mod pos m) 0) 
                     (cons n (cons 
                               (car lst) 
                               (helper (cdr lst) (1+ pos))
                             )
                      )
               ) 
               (t (cons (car lst) 
                    (helper (cdr lst) (1+ pos))
                  )
                )
             )))  
    (helper lst 1))
)


(defun main (n m lst)
  (print (insert-n-at-m-positions n m lst)))


