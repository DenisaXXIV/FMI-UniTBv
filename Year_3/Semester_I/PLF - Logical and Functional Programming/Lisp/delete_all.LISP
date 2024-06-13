(defun maximum (lst)
  ( if (null (cdr lst))
      (car lst)
      (let (( r (maximum ( cdr lst))))
           (if (< r (car lst))
                 (car lst)
                 r
           )
       )
    )
)

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
