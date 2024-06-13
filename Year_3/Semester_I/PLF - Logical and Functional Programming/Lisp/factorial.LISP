
(defun factorial (num) ; definim functia
  (if (zerop num)      ; daca num = 0,
    1                  ; atunci returnam 1
    (* num 
       (factorial (- num 1) )
    )      ;altfel returnam num*factorial(num-1)
  )
)









