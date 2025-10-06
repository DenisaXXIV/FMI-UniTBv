package database.dao;

import database.DatabaseConnection;
import database.model.StageEntity;
import database.model.TeamEntity;

import javax.persistence.TypedQuery;
import java.util.List;

public class StageDao implements DaoI<StageEntity> {
    DatabaseConnection connection = new DatabaseConnection();

    public StageEntity get(int id) {
        return connection.getEntityManager().find(StageEntity.class, Long.valueOf(id));
    }

    @Override
    public List<StageEntity> getAll() {
        TypedQuery<StageEntity> query = connection.getEntityManager().createQuery("SELECT a FROM StageEntity a", StageEntity.class);
        return query.getResultList();
    }

    @Override
    public StageEntity getByName(String name) {
        TypedQuery<StageEntity> query = connection.getEntityManager().createQuery("SELECT a FROM StageEntity a WHERE a.name='"+name+"'", StageEntity.class);
        return query.getSingleResult();
    }

    public List<String> getAllNames() {
        TypedQuery<String> query = connection.getEntityManager().createQuery("SELECT a.name FROM StageEntity a GROUP BY a.name", String.class);
        return query.getResultList();
    }

    public void create(StageEntity stage) {
        connection.executeTransaction(entityManager -> entityManager.persist(stage));
    }

    public void update(StageEntity stage) {
        connection.executeTransaction(entityManager -> entityManager.merge(stage));
    }

    public void delete(StageEntity stage) {
        connection.executeTransaction(entityManager -> entityManager.remove(stage));
    }
}
