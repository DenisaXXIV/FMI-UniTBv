package database.dao;

import database.DatabaseConnection;
import database.model.ParticipationEntity;
import database.model.StageEntity;
import database.model.UserEntity;

import javax.persistence.TypedQuery;
import java.util.List;

public class ParticipationDao implements DaoI<ParticipationEntity> {
    DatabaseConnection connection = new DatabaseConnection();

    public ParticipationEntity get(int id) {
        return connection.getEntityManager().find(ParticipationEntity.class, Long.valueOf(id));
    }

    @Override
    public List<ParticipationEntity> getAll() {
        TypedQuery<ParticipationEntity> query = connection.getEntityManager().createQuery("SELECT a FROM ParticipationEntity a", ParticipationEntity.class);
        return query.getResultList();
    }

    @Override
    public ParticipationEntity getByName(String name) {
        return null;
    }

    @Override
    public List<String> getAllNames() {
        return null;
    }

    public List<Integer> getByUser(UserEntity user){
        TypedQuery<Integer> query = connection.getEntityManager().createQuery("SELECT a FROM ParticipationEntity a WHERE a.username='"+user+"'", Integer.class);
        return query.getResultList();
    }

    public List<Integer> getByStage(StageEntity stage){
        TypedQuery<Integer> query = connection.getEntityManager().createQuery("SELECT a FROM ParticipationEntity a WHERE a.idStage='"+stage+"'", Integer.class);
        return query.getResultList();
    }

    public Integer getScore(UserEntity user,StageEntity stage){
        TypedQuery<Integer> query = connection.getEntityManager().createQuery("SELECT a FROM ParticipationEntity a WHERE a.username='"+user+"' AND a.idStage='"+stage+"'", Integer.class);
        return query.getSingleResult();
    }

    public ParticipationEntity getByUserAndStage(UserEntity user,StageEntity stage){
        TypedQuery<ParticipationEntity> query = connection.getEntityManager().createQuery("SELECT a FROM ParticipationEntity a WHERE a.username='"+user+"' AND a.idStage='"+stage+"'", ParticipationEntity.class);
        return query.getSingleResult();
    }

    public List<String> getAllScores() {
        TypedQuery<String> query = connection.getEntityManager().createQuery("SELECT a.score FROM ParticipationEntity a GROUP BY a.score", String.class);
        return query.getResultList();
    }

    public void create(ParticipationEntity participation) {
        connection.executeTransaction(entityManager -> entityManager.persist(participation));
    }

    public void update(ParticipationEntity participation) {
        connection.executeTransaction(entityManager -> entityManager.merge(participation));
    }

    public void delete(ParticipationEntity participation) {
        connection.executeTransaction(entityManager -> entityManager.remove(participation));
    }
}
