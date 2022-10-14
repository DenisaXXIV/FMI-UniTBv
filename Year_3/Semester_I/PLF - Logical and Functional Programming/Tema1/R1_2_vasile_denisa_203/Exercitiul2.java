//                                      ╔══
//                                      ╠   l=m                        ,l=[]
// func(l1,l2,....,ln,m1,m1,...,mn)    ═╠   null                       ,l=[],m[]
//                                      ╠   l1 U func(l2,l3,...,ln,m1,m2,...,mn) ,altfel
//                                      ╚══

import list.List;
import list.Nod;

public class Exercitiul2 {

    public List<Integer> adaugareListaLaFinal(List<Integer> lista, List<Integer> lista2) {

        if(lista.esteGoala() && lista2.esteGoala()) {
            return new List<Integer>();
        }
        else {
            if(lista.esteGoala() && !lista2.esteGoala()) {
                Nod<Integer> nodCurent = lista2.getCapulListei();
                nodCurent.setUrmatorulNod(null);

                lista2.setCapulListei(lista2.getCapulListei().getUrmatorulNod());

                return adaugareListaLaFinal(lista,lista2).adaugaLaInceput(nodCurent);
            }
            else {
                Nod<Integer> nodCurent = lista2.getCapulListei();

                lista.setCapulListei(lista.getCapulListei().getUrmatorulNod());

                return adaugareListaLaFinal(lista,lista2).adaugaLaInceput(nodCurent);
            }
        }
    }
}
