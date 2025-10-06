package database.dao;

import java.util.List;

public interface DaoI<T> {
    T get(int id);
    List<T> getAll ();
    T getByName(String name);
    List<String> getAllNames();
    void create (T t);
    void update(T t);
    void delete(T t);
}
