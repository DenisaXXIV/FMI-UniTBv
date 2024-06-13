(defun cmmmc (a b current)        ; definim functia
  (if (zerop (mod current b))     ; daca curr%b = 0
      current                     ; atunci returnam curr
      (cmmmc a b (+ current a)))) ; altfel cmmmc(a,b,curr+a)

(defun main (a b)                 ; definim functia main
  (cmmmc a b (max a b)))          ; cmmmc(a,b, max(