package database.model;

import javax.persistence.*;

@Entity
@Table(name = "participation")
public class ParticipationEntity {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id_participation", nullable = false)
    private Integer id;

    @ManyToOne(optional = false)
    @JoinColumn(name = "id_stage", nullable = false)
    private StageEntity idStage;

    @ManyToOne(optional = false)
    @JoinColumn(name = "username", nullable = false)
    private UserEntity username;

    @Column(name = "score")
    private Integer score;

    public Integer getScore() {
        return score;
    }

    public void setScore(Integer score) {
        this.score = score;
    }

    public UserEntity getUsername() {
        return username;
    }

    public void setUsername(UserEntity username) {
        this.username = username;
    }

    public StageEntity getIdStage() {
        return idStage;
    }

    public void setIdStage(StageEntity idStage) {
        this.idStage = idStage;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }
}