package database;

import java.sql.SQLException;
import java.util.function.Consumer;

import javax.persistence.*;

public class DatabaseConnection {
    private EntityManagerFactory entityManagerFactory;
    private EntityManager entityManager;

    public DatabaseConnection() {
        this.initTransaction();
    }

    public EntityManager getEntityManager() {
        return entityManager;
    }

    public boolean executeTransaction(Consumer<EntityManager> action) {
        EntityTransaction entityTransaction = entityManager.getTransaction();
        try {
            entityTransaction.begin();
            action.accept(entityManager);
            entityTransaction.commit();
        }
//        } catch (RuntimeException e) {
//            System.err.println("Transaction error: " + e.getLocalizedMessage());
//            entityTransaction.rollback();
//            return false;
//        }
            catch (PersistenceException ex) {
            Throwable t = getLastThrowable(ex);  //fetching Internal Exception
            SQLException exSQL = (SQLException) t;  //casting Throwable object to SQL Exception
            System.out.println("!!!!!!!!!!   here is the problem with DB: " + exSQL.getSQLState());
        }
        return true;
    }

    private Throwable getLastThrowable(Exception e) {
        Throwable t = null;
        for(t = e.getCause(); t.getCause() != null; t = t.getCause());
        return t;
    }

        private boolean initTransaction() {
        try {
            entityManagerFactory = Persistence.createEntityManagerFactory("contestPersistence");
            entityManager = entityManagerFactory.createEntityManager();
        } catch (Exception e) {
            System.err.println("Error at initialing DatabaseManager: " + e.getMessage().toString());
            return false;
        }
        System.out.println("\nConexiune db ok\n");
        return true;
    }

}
