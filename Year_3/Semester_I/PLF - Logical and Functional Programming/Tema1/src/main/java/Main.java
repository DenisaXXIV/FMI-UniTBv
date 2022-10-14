import list.List;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        List<Integer> lista = new List<>(8);
        List<Integer> listaFinala = new List<>();
        List<Integer> lista2 = new List<>(5);

        System.out.println("Selecteaza exercitiul:\n");
        System.out.println("[ 1 ] Adaugati un element la sfarsitul unei liste.");
        System.out.println("[ 2 ] Concatenati doua liste.");

        Scanner scanner = new Scanner(System.in);

        int optiune = scanner.nextInt();

        switch (optiune) {
            case 1:
                Exercitiul1 exercitiul1 = new Exercitiul1();

                exercitiul1.adaugareElementLaFinal(lista,8,listaFinala);
                exercitiul1.adaugareElementLaFinal(lista,2, listaFinala);
                exercitiul1.adaugareElementLaFinal(lista,25, listaFinala);
                exercitiul1.adaugareElementLaFinal(lista,500, listaFinala);
                System.out.println(listaFinala.toString());
                break;
            case 2:
                Exercitiul2 exercitiul2 = new Exercitiul2();

                exercitiul2.adaugareListaLaFinal(lista,lista2,listaFinala);


                break;
        }
    }
}
