package list;

public class Nod<T> {
    T info;
    Nod<T> urmatorulNod;

    public T getInfo() {
        return info;
    }

    public void setInfo(T info) {
        this.info = info;
    }

    public Nod<T> getUrmatorulNod() {
        return urmatorulNod;
    }

    public void setUrmatorulNod(Nod<T> urmatorulNod) {
        this.urmatorulNod = urmatorulNod;
    }

    public Nod(T info) {
        this.info = info;
        this.urmatorulNod = null;
    }
}
