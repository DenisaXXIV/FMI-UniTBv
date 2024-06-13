

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



