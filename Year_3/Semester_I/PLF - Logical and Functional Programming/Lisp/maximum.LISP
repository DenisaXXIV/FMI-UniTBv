
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








