package list;

public class List<T> {
    Nod<T> capulListei;

    public List() {
    }

    public List(T capulListei) {
        this.capulListei = new Nod<T>(capulListei);
    }

    public Nod<T> getCapulListei() {
        return capulListei;
    }

    public void setCapulListei(Nod<T> capulListei) {
        this.capulListei = capulListei;
    }

    public boolean esteGoala() {
        return capulListei == null;
    }

    public List<T> adaugaLaInceput(Nod<T> nodNou) {
        nodNou.setUrmatorulNod(capulListei.getUrmatorulNod());
        capulListei.setUrmatorulNod(nodNou);
        return this;
    }

    public int getLungimeLista() {
        if(esteGoala()) {
            System.out.println("\nLista este goala.\n");
            return 0;
        }
        else {
            Nod<T> nodCurent = capulListei;
            int nrElem = 1;

            while (nodCurent.getUrmatorulNod() != null)
            {
                nodCurent = nodCurent.getUrmatorulNod();
                nrElem++;
            }

            return nrElem;
        }
    }

    public void stergeNod(Nod<T> nodSters) {
        if(esteGoala()) {
            System.out.println("\nLista este goala.\n");
            return;
        }

        if (nodSters == capulListei)
        {
            capulListei = capulListei.getUrmatorulNod();
            return;
        } else {

            Nod<T> nodCurent = capulListei;

            while (nodCurent.getUrmatorulNod() != nodSters) {
                nodCurent = nodCurent.getUrmatorulNod();
            }

            if (nodCurent.getUrmatorulNod() == nodSters) {
                nodCurent.setUrmatorulNod(nodSters.getUrmatorulNod());
            }
        }
    }

    public Nod<T> ultimulNod() {
        Nod<T> nodCurent = capulListei;

        while(nodCurent.urmatorulNod != null) {
            nodCurent=nodCurent.urmatorulNod;
        }

        return nodCurent;
    }

    @Override
    public String toString() {
        Nod<T> nodCurent = this.capulListei;

        StringBuilder stringBuilder = new StringBuilder("List{ \n" +
                "capulListei=" + capulListei.info.toString() + "\n");

        while(nodCurent.urmatorulNod != null) {
            nodCurent = nodCurent.getUrmatorulNod();
            stringBuilder.append(nodCurent.info.toString()).append("\n");
        }

        return stringBuilder.toString();
    }
}
