
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



