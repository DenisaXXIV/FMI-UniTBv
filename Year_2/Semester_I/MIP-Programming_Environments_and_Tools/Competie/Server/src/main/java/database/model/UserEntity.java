package database.model;

import javax.persistence.*;

@Entity
@Table(name = "\"user\"")
public class UserEntity {
    @Id
    @Lob
    @Column(name = "username", nullable = false)
    private String id;

    @Lob
    @Column(name = "password", nullable = false)
    private String password;

    @Lob
    @Column(name = "name")
    private String name;

    @ManyToOne
    @JoinColumn(name = "id_team")
    private TeamEntity idTeam;

    @Column(name = "admin_role", nullable = false)
    private Boolean adminRole = false;

    public Boolean getAdminRole() {
        return adminRole;
    }

    public void setAdminRole(Boolean adminRole) {
        this.adminRole = adminRole;
    }

    public TeamEntity getIdTeam() {
        return idTeam;
    }

    public void setIdTeam(TeamEntity idTeam) {
        this.idTeam = idTeam;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }
}