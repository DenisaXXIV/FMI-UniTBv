
(defun cmmdc (a b)       ; definim functia
  (if (zerop b)          ; daca b = 0,
      a                  ; atunci cmmdc = a
      (cmmdc b (mod a b) ; altfel cmmdc(b, a%b)
      )
  )
)



