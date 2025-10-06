import database.dao.*;
import database.model.*;
import org.json.JSONObject;

import javax.xml.registry.infomodel.User;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.List;

public class ServerThread extends Thread{
    private Socket socket = null;
    private ObjectInputStream in = null;
    private ObjectOutputStream out = null;
    private boolean isClosed = false;

    public ServerThread(Socket socket) {
        this.socket = socket;
        try {
            //For receiving and sending data
            this.in = new ObjectInputStream(socket.getInputStream());
            this.out = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        try {
            Packet receivePacket = (Packet) this.in.readObject();
            System.out.println("Received: " + receivePacket.message);
            execute(receivePacket.message);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void execute(String message) {
        Packet packet = null;
        JSONObject json = new JSONObject(message);
        Request req= Request.valueOf(json.get("Request").toString());
        RequestType reqType=RequestType.valueOf(json.get("Request_Type").toString());

        switch (req){
            // user registration
            case REGISTRATION:
                switch(reqType) {
                    case USER:
                        userRegistration(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("User registered");
                        break;

                    case TEAM:
                        teamRegistration(json);
                        json=new JSONObject();
                        json.put("Message","OK");
                        System.out.println(json.toString());
                        packet = new Packet(json.toString());
                        System.out.println("Team Registered");
                        break;

                    case STAGE:
                        stageRegistration(json);
                        json=new JSONObject();
                        json.put("Message","OK");
                        System.out.println(json.toString());
                        packet = new Packet(json.toString());
                        System.out.println("Team Registered");
                        break;

                    case PARTICIPATION:
                        scoreRecording(json);
                        json=new JSONObject();
                        json.put("Message","OK");
                        packet = new Packet(json.toString());
                        System.out.println("Score send");
                        break;
                }
                break;

            // team validation
            case VALIDATION:
                switch(reqType) {
                    case TEAM:
                        json=teamVerification(json);
                        packet = new Packet(json.toString());
                        System.out.println("Team Verified: "+json.getString("Message").toString());
                        break;

                    case USER:
                        json=userVerification(json);
                        packet = new Packet(json.toString());
                        System.out.println("User Verified: "+json.getString("Message").toString());
                        break;

                    case STAGE:
                        json=stageVerification(json);
                        packet = new Packet(json.toString());
                        System.out.println("Stage Verified: "+json.getString("Message").toString());
                        break;

                    case PARTICIPATION:
                        json=participationVerification(json);
                        packet = new Packet(json.toString());
                        System.out.println("Participatione Verified: "+json.getString("Message").toString());
                        break;
                }
                break;


            // send score per stage
            case TRANSMISSION:
                switch(reqType){
                    case TEAM:
                        json=getMembersOfTeam(json);
                        packet = new Packet(json.toString());
                        System.out.println("Send");
                        break;
                    case USER:

                    case STAGE:

                    case PARTICIPATION:
                        ParticipationDao participationDao=new ParticipationDao();

                        System.out.println("Sending score...");
                        packet = new Packet(json.toString());
                        System.out.println("Done!");
                        break;
                }
                break;

            case UPDATE:
                switch(reqType) {
                    case TEAM:
                        updateTeam(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("Team updated");
                        break;

                    case USER:
                        updateUser(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("User updated");
                        break;

                    case STAGE:
                        updateStage(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("Stage updated");
                        break;

                    case PARTICIPATION:
                        updateParticipation(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("Participation updated");
                        break;
                }
                break;
            case DELETE:
                switch(reqType) {
                    case TEAM:
                        deleteTeam(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("Team deleted");
                        break;

                    case USER:
                        deleteUser(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("User deleted");
                        break;

                    case STAGE:
                        deleteStage(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("Stage deleted");
                        break;

                    case PARTICIPATION:
                        deleteParticipation(json);
                        json = new JSONObject();
                        json.put("Message", "OK");
                        packet = new Packet(json.toString());
                        System.out.println("Participation deleted");
                        break;
                }
                break;
            case SOMETHING_ELSE:

                // login
            case LOGIN:
                json=login(json);
                packet = new Packet(json.toString());
                System.out.println("Message sent: "+json.getString("Message").toString());
                break;

            // EXIT
            case EXIT_THREAD:
                this.isClosed=true;

            default:
                packet = new Packet("Can't understand you :/");
        }

        try {
            this.out.writeObject(packet);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private JSONObject login(JSONObject json) {
        UserDao userDao=new UserDao();

        if(userDao.isUser(json.getString("Username").toString(), json.getString("Password").toString())){
            UserEntity user = userDao.getByUsername(json.getString("Username").toString());
            json=new JSONObject();

            json.put("Message","Successful Login");
            json.put("Username",user.getId());
            json.put("Password",user.getPassword());
            json.put("Team",user.getIdTeam().getName());
            json.put("Name",user.getName());
            json.put("Admin_Role",user.getAdminRole().toString());
        }
        else{
            json=new JSONObject();
            json.put("Message","incorrect password or username");
        }


        return json;
    }

    private void stageRegistration(JSONObject json) {
        StageDao stageDao= new StageDao();
        StageEntity stage=new StageEntity();
        stage.setName(json.getString("Stage_Name"));
        stageDao.create(stage);
    }

    private void userRegistration(JSONObject json){
        UserDao userDao= new UserDao();
        TeamDao teamDao=new TeamDao();
        UserEntity user=new UserEntity();
        user.setId(json.getString("Username"));
        user.setPassword(json.getString("Password"));
        TeamEntity team=teamDao.getByName("No Team");
        user.setIdTeam(team);
        user.setName(json.getString("Name"));
        if(json.getString("AdminRole")=="true") {
            user.setAdminRole(true);
        }
        else{
            user.setAdminRole(false);
        }
        userDao.create(user);
    }

    private void teamRegistration(JSONObject json){
        TeamDao teamDao= new TeamDao();
        TeamEntity team=new TeamEntity();
        team.setName(json.getString("Team_Name"));
        teamDao.create(team);
    }

    private void scoreRecording(JSONObject json){
        ParticipationDao participationDao=new ParticipationDao();
        UserDao userDao=new UserDao();
        StageDao stageDao=new StageDao();

        ParticipationEntity participation=new ParticipationEntity();
        UserEntity user=userDao.getByUsername(json.getString("Username").toString());
        StageEntity stage=stageDao.getByName(json.getString("Stage").toString());

        participation.setUsername(user);
        participation.setScore(Integer.getInteger(json.getString("Score")));
        participation.setIdStage(stage);
        participationDao.create(participation);
    }

    private JSONObject teamVerification(JSONObject json){
        TeamDao teamDao=new TeamDao();

        List<String> list = teamDao.getAllNames();

        boolean ok=true;       // the team is valid yet

        for(String teamName : list){
            if(teamName.equals(json.getString("Team_Name"))){
                ok=false;
            }
        }

        json=new JSONObject();

        if(ok){
            json.put("Message","OK");
        }
        else{
            json.put("Message","!!!     NOT ok    !!!");
        }

        return json;
    }

    private JSONObject userVerification(JSONObject json){
        UserDao userDao=new UserDao();
        TeamDao teamDao = new TeamDao();

        TeamEntity team= teamDao.getByName(json.getString("Team").toString());

        boolean ok=true;

        if(userDao.getNrInTeam(team)>=5){
            ok=false;
        }

        if(ok){
            json.put("Message","OK");
        }
        else{
            json.put("Message","!!!     NOT ok    !!!");
        }

        return json;
    }

    private JSONObject stageVerification(JSONObject json){
        StageDao stageDao=new StageDao();
        List<String> list = stageDao.getAllNames();
        boolean ok=true;       // the stage is valid yet

        for(String stageName : list){
            if(stageName.equals(json.getString("Stage_Name"))){
                ok=false;
            }
        }

        json=new JSONObject();

        if(ok){
            json.put("Message","OK");
        }
        else{
            json.put("Message","!!!     NOT ok    !!!");
        }

        return json;
    }

    private JSONObject participationVerification(JSONObject json){
        ParticipationDao participationDao=new ParticipationDao();
        UserDao userDao=new UserDao();
        StageDao stageDao=new StageDao();

        UserEntity user=userDao.getByUsername(json.getString("Username").toString());
        StageEntity stage=stageDao.getByName(json.getString("Stage").toString());

        int ok=0;       // the participation is valid yet

        if(userDao.getNrInTeam(user.getIdTeam())>=2 && userDao.getNrInTeam(user.getIdTeam())<=5){
            ok=1;

            if(participationDao.getScore(user,stage)!=null){
                ok=2;
            }
        }

        json=new JSONObject();

        switch(ok){
            case 0:
                json.put("Message","OK");
                break;
            case 1:
                json.put("Message","ONLY team ok");
                break;
            case 2:
                json.put("Message","!!!     NOT ok    !!!");
                break;
        }

        return json;
    }

    private JSONObject getMembersOfTeam(JSONObject json){
        UserDao userDao=new UserDao();
        TeamDao teamDao=new TeamDao();

        TeamEntity team=teamDao.getByName(json.getString("Team_Name").toString());

        List<UserEntity> list=userDao.getMembers(team);
        int index=1;

        json=new JSONObject();

        json.put("Number_Of_Members",String.valueOf(list.size()));

        for(UserEntity user:list){
            json.put("Member "+index,user.getName());
            index++;
        }

        return json;
    }

    private void deleteTeam(JSONObject json){
        TeamDao teamDao=new TeamDao();

        TeamEntity team=teamDao.getByName(json.getString("Team_Name").toString());

        teamDao.deleteTeam(team.getId());
    }

    private void deleteUser(JSONObject json){
        UserDao userDao=new UserDao();

        UserEntity user=userDao.getByName(json.getString("Username").toString());

        userDao.delete(user);
    }

    private void deleteStage(JSONObject json){
        StageDao stageDao=new StageDao();

        StageEntity stage=stageDao.getByName(json.getString("Stage_Name").toString());

        stageDao.delete(stage);
    }

    private void deleteParticipation(JSONObject json){
        ParticipationDao participationDao=new ParticipationDao();
        UserDao userDao=new UserDao();
        StageDao stageDao=new StageDao();

        UserEntity user=userDao.getByUsername(json.getString("User").toString());
        StageEntity stage=stageDao.getByName(json.getString("Stage").toString());

        ParticipationEntity participation=participationDao.getByUserAndStage(user,stage);

        participationDao.delete(participation);
    }

    private void updateTeam(JSONObject json){
        TeamDao teamDao=new TeamDao();

        TeamEntity team=teamDao.getByName(json.getString("Old_Name").toString());
        TeamEntity newTeam=new TeamEntity();

        newTeam.setName(json.getString("New_name").toString());
        newTeam.setId(team.getId());

        teamDao.update(newTeam);

        teamDao.deleteTeam(team.getId());
    }

    private void updateStage(JSONObject json){
        StageDao stageDao=new StageDao();

        StageEntity stage=stageDao.getByName(json.getString("Old_Name").toString());
        StageEntity newStage=new StageEntity();

        newStage.setName(json.getString("New_name").toString());
        newStage.setId(stage.getId());

        stageDao.update(stage);
    }

    private void updateUser(JSONObject json){
        UserDao userDao=new UserDao();
        TeamDao teamDao=new TeamDao();

        UserEntity user=userDao.getByUsername(json.getString("Old_Username").toString());
        TeamEntity team=teamDao.getByName(json.getString("New_team").toString());

        user.setId(json.getString("New_Username").toString());
        user.setName(json.getString("New_Name").toString());
        user.setPassword(json.getString("New_Password").toString());
        user.setIdTeam(team);
        if(json.getString("New_Role").toString().equals("true")) {
            user.setAdminRole(true);
        }
        else{
            user.setAdminRole(false);
        }

        userDao.update(user);
    }

    private void updateParticipation(JSONObject json){
        ParticipationDao participationDao=new ParticipationDao();
        UserDao userDao=new UserDao();
        StageDao stageDao=new StageDao();

        UserEntity user=userDao.getByUsername(json.getString("Username").toString());
        StageEntity stage=stageDao.getByName(json.get("Stage").toString());
        ParticipationEntity participation=participationDao.getByUserAndStage(user,stage);

        participation.setIdStage(stage);
        participation.setUsername(user);
        participation.setScore(Integer.getInteger(json.getString("Score").toString()));

        participationDao.update(participation);
    }
}
