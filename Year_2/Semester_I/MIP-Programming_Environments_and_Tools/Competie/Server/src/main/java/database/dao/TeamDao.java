package database.dao;

import database.DatabaseConnection;
import database.model.TeamEntity;

import javax.persistence.TypedQuery;
import java.util.List;

public class TeamDao implements DaoI<TeamEntity>{
    DatabaseConnection connection = new DatabaseConnection();

    // Get value of Team with that id
    public TeamEntity get(int id) {
        return connection.getEntityManager().find(TeamEntity.class, Long.valueOf(id));
    }

    // Update a team
    public void updateTeam(TeamEntity team) {
        TeamEntity modifiedTeam = get(team.getId());
        modifiedTeam.setName(team.getName());
        connection.getEntityManager().getTransaction().commit();
    }

    // Delete a team
    public void deleteTeam(int id) {
        TeamEntity team = get(id);
        connection.getEntityManager().remove(team);
    }

    // Get all objects
    @Override
    public List<TeamEntity> getAll() {
        TypedQuery<TeamEntity> query = connection.getEntityManager().createQuery("SELECT a FROM TeamEntity a", TeamEntity.class);
        return query.getResultList();
    }

    // Get all names of teams
    public List<String> getAllNames() {
        TypedQuery<String> query = connection.getEntityManager().createQuery("SELECT a.name FROM TeamEntity a GROUP BY a.name", String.class);
        return query.getResultList();
    }

    public TeamEntity getByName(String name) {
        TypedQuery<TeamEntity> query = connection.getEntityManager().createQuery("SELECT a FROM TeamEntity a WHERE a.name='"+name+"'", TeamEntity.class);
        return query.getSingleResult();
    }

    // Create a team
    public void create(TeamEntity team) {
        connection.executeTransaction(entityManager -> entityManager.persist(team));
    }
    public void update(TeamEntity team) {
        connection.executeTransaction(entityManager -> entityManager.merge(team));
    }
    public void delete(TeamEntity team) {
        connection.executeTransaction(entityManager -> entityManager.remove(team));
    }
}
