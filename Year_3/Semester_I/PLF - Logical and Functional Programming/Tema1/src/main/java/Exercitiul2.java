//                                      ╔══
//                                      ╠  m                        ,l=[]
// func(l1,l2,....,ln,m1,m1,...,mn)    ═╠   []                       ,l=[],m[]
//                                      ╠   l1 U func(l2,l3,...,ln,m1,m2,...,mn) ,altfel
//                                      ╚══

import list.List;
import list.Nod;

public class Exercitiul2 {

    public void adaugareListaLaFinal(List<Integer> lista, List<Integer> lista2, List<Integer> listaFinala) {

        List<Integer> lista1 = new List<>();

        if(lista.esteGoala() && lista2.esteGoala()) {
            listaFinala = new List<>();
        }
        else {
            if(lista.esteGoala() && !lista2.esteGoala()) {
                System.out.println(lista2);
            }
            else {
                Exercitiul1 exercitiul1 = new Exercitiul1();
                listaFinala = lista;


                while(!lista2.esteGoala()) {
                    Integer val = lista2.getCapulListei().getInfo();
                    if(lista2.getCapulListei().getUrmatorulNod() == null) {
                        lista2 = new List<>();
                    }else {
                        lista2.setCapulListei(lista2.getCapulListei().getUrmatorulNod());
                    }

                    exercitiul1.adaugareElementLaFinal(listaFinala,val,lista1);
                    listaFinala=lista1;
            }
                System.out.println(listaFinala.toString());
            }
        }
    }
}
