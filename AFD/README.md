# Automat  Finit Determinist

## 🖥️ GUI

Interfata grafica realizata exclusiv consola.

## 📜 Tuple

O tuplă este o structură de date imutabilă care poate păstra mai multe elemente separate prin virgulă.

Altfel spus, o tuplă este precum o listă, doar că imutabilă. 

## 🦊 Cerinta

Să se implementeze un AFD (automat finit determinist) astfel: se citesc din fișier elementele componente ale automatului Q, Sigma, Delta, q0, F. Se citește de la tastatură un cuvânt și se verifică, dacă este acceptat de către automat. 

Se cere crearea unei clase AFD (alta decât clasa principală). În funcția principală main se declară un obiect de tip AFD. Apoi se citesc de la tastatură cuvinte (do-while) și pentru fiecare se afișează dacă este acceptat sau nu.

## 👨‍👩‍👧‍👦 Membrii clasei

~ Stari

~ Sigma

~ Delta

~ StareInit

~ Finale 

## ✨ Metode 

(1)  afisare () - afișarea frumoasă a automatului (sub forma de tabel)

(2) accepta(cuvant) - verifică dacă cuvântul dat ca parametru este acceptat de către 
automat și afișează: "accepta" - dacă este cuvânt acceptat, "neacceptat" - dacă nu este accepta , "blocaj" - dacă automatul se blochează pe parcurs.

(3) verifică() – verifică dacă automatul este ok (dacă starea inițială / stările finale se 
găsesc în mulțimea de stări, dacă tranzițiile conțin doar elemente ale automatului) 
