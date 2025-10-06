package database.dao;

import database.DatabaseConnection;
import database.model.TeamEntity;
import database.model.UserEntity;

import javax.persistence.NoResultException;
import javax.persistence.TypedQuery;
import java.util.List;

public class UserDao implements DaoI<UserEntity>{
    DatabaseConnection connection = new DatabaseConnection();

    public UserEntity getByUsername(String username) {
            return connection.getEntityManager().find(UserEntity.class, String.valueOf(username));
    }

    public boolean isUser(String username, String password){
        TypedQuery<UserEntity> query = connection.getEntityManager().createQuery(String.format("SELECT a FROM UserEntity a WHERE a.id='%s' AND a.password='%s'", username, password), UserEntity.class);

        try{
        query.getSingleResult();

        }catch (NoResultException e){
            return false;
        }

        return true;
    }

    @Override
    public UserEntity get(int id) {
        return null;
    }

    @Override
    public List<UserEntity> getAll() {
        TypedQuery<UserEntity> query = connection.getEntityManager().createQuery("SELECT a FROM UserEntity a", UserEntity.class);
        return query.getResultList();
    }

    public List<UserEntity> getMembers(TeamEntity team) {
        TypedQuery<UserEntity> query = connection.getEntityManager().createQuery("SELECT a FROM UserEntity a WHERE a.idTeam='"+team+"'", UserEntity.class);
        return query.getResultList();
    }

    @Override
    public UserEntity getByName(String name) {
        TypedQuery<UserEntity> query = connection.getEntityManager().createQuery("SELECT a FROM UserEntity a WHERE a.name='"+name+"'", UserEntity.class);
        return query.getSingleResult();
    }

    public Integer getNrInTeam(TeamEntity team){
        TypedQuery<Integer> query = connection.getEntityManager().createQuery("SELECT COUNT(a) FROM UserEntity a WHERE a.idTeam='"+team+"'", Integer.class);
        return query.getSingleResult();
    }

    @Override
    public List<String> getAllNames() {
        TypedQuery<String> query = connection.getEntityManager().createQuery("SELECT a.name FROM UserEntity a GROUP BY a.name", String.class);
        return query.getResultList();
    }

    public void create(UserEntity user) {
        connection.executeTransaction(entityManager -> entityManager.persist(user));
    }

    public void update(UserEntity user) {
        connection.executeTransaction(entityManager -> entityManager.merge(user));
    }

    public void delete(UserEntity user) {
        connection.executeTransaction(entityManager -> entityManager.remove(user));
    }
}
