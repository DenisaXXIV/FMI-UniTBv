(defun minim(lst)
  (if (null (cdr lst))
      (car lst)
      (let ((r (minim (cdr lst))))
        (if (< r (car lst))
            r
            (car lst)
            )
        )
      )
  )

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


