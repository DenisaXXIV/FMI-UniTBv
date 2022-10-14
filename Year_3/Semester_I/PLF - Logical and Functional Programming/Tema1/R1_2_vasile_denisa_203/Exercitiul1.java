//                          ╔══
//                          ╠   [val]                        ,l=[]
// func(l1,l2,....,ln,val) ═╠
//                          ╠   l1 U func(l2,l3,...,ln,val) ,altfel
//                          ╚══

import list.List;
import list.Nod;

public class Exercitiul1 {

    public void adaugareElementLaFinal(List<Integer> lista, Integer val, List<Integer> listaFinala) {
        Nod<Integer> nodNou = new Nod<>(val);

        if(lista.esteGoala()) {
            if(listaFinala.esteGoala()) {
                listaFinala.setCapulListei(nodNou);
            }
            else {
                listaFinala.ultimulNod().setUrmatorulNod(nodNou);
            }
        }
        else {
            if(!listaFinala.esteGoala()) {
                listaFinala.ultimulNod().setUrmatorulNod(lista.getCapulListei());

                lista.stergeNod(lista.getCapulListei());

                adaugareElementLaFinal(lista, val, listaFinala);
            }
            else {
                listaFinala.setCapulListei(lista.getCapulListei());
                lista.stergeNod(lista.getCapulListei());

                adaugareElementLaFinal(lista, val, listaFinala);
            }
        }
    }
}
