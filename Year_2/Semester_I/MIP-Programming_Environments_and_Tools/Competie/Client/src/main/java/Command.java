import org.json.JSONObject;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Objects;
import java.util.Scanner;

public class Command {
    public static final int PORT = 6544;

    Command(){

        System.out.println("Say something: ");
        Socket socket = null;

        //For receiving and sending data
        boolean isClose = false;
        while (!isClose) {
            try {
                socket = new Socket("localhost", PORT);
            } catch (IOException e) {
                e.printStackTrace();
            }

            ObjectOutputStream outputStream = null;
            try {
                outputStream = new ObjectOutputStream(socket.getOutputStream());
            } catch (IOException e) {
                e.printStackTrace();
            }
            ObjectInputStream inputStream = null;
            try {
                inputStream = new ObjectInputStream(socket.getInputStream());
            } catch (IOException e) {
                e.printStackTrace();
            }

            Scanner scanner = new Scanner(System.in);
            String requestType=scanner.nextLine();

            switch(requestType){

                case "1":
                    try {
                        userRegistration(outputStream, inputStream);
                    } catch (IOException | ClassNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case "2":
                    try {
                        teamRegistration(outputStream, inputStream);
                    } catch (IOException | ClassNotFoundException e) {
                        e.printStackTrace();
                    }
                    break;
                case "3":
                    break;
                case "4":
                    scoreRecording(outputStream, inputStream);
                case "5":
                    break;
                case "6":
                    break;
                case "7":
                    login(outputStream, inputStream);
                    break;
                case "8":
                    isClose = true;
                    Packet packet = null;
                    JSONObject json = new JSONObject();

                    json.put("message","STOP");

                    packet = new Packet(json.toString());
                    try {
                        outputStream.writeObject(packet);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
            }

            JSONObject receivePacket = null;
            try {
                try {
                    receivePacket = new JSONObject(inputStream.readObject().toString());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

        try {
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

//        launch(args);
    }

    private static void userRegistration(ObjectOutputStream outputStream, ObjectInputStream inputStream) throws IOException, ClassNotFoundException {
        Packet packet = null;
//        Scanner scanner = new Scanner(System.in);
//        String username=scanner.nextLine();
//        String password=scanner.nextLine();
//        String name=scanner.nextLine();
//        String team=scanner.nextLine();
//        String adminRole=scanner.nextLine();
        String username = "Denisa2";
        String password = "uyigjh2112";
        String name = "Dan Denisa";
        String team="CSU Ploiesti";
        String adminRole="false";

        JSONObject json = new JSONObject();

        json.put("Request", Request.REGISTRATION.toString());
        json.put("Request_Type",RequestType.USER.toString());
        json.put("Username",username);
        json.put("Password",password);
        json.put("Name",name);
        json.put("AdminRole",adminRole);

        packet = new Packet(json.toString());
        outputStream.writeObject(packet);

        JSONObject receivedData = new JSONObject(inputStream.readObject());

        try {
            outputStream.writeObject(packet);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void teamRegistration(ObjectOutputStream outputStream, ObjectInputStream inputStream) throws IOException, ClassNotFoundException {
        Packet packet = null;
        boolean accepted = false;

        while(!accepted){

            Scanner scanner = new Scanner(System.in);
            String name=scanner.nextLine();
            String name2 = "CSU Brasov2";

            JSONObject json = new JSONObject();

            json.put("Request", Request.REGISTRATION.toString());
            json.put("Request_Type", RequestType.TEAM.toString());
            json.put("Team_Name",name);

            packet = new Packet(json.toString());
            outputStream.writeObject(packet);



            Packet receivePacket = (Packet) inputStream.readObject();
            JSONObject receivedData = new JSONObject(receivePacket.message);
            System.out.println(receivePacket.message);

            if(Objects.equals(receivedData.getString("Message"), "OK")){
                accepted=true;
                System.out.println("a zis OK !!!");
            }

            if(!accepted){
                // reintroducerea datelor
            }

        }
        try {
            outputStream.writeObject(packet);
        } catch (IOException e) {
            System.out.println("here");
            e.printStackTrace();
        }
    }

    private static void scoreRecording(ObjectOutputStream outputStream, ObjectInputStream inputStream) {
        Packet packet = null;
        boolean accepted = false;

        while(!accepted){
            String username = "me";
            String score="5";
            String stage="5";

            JSONObject json = new JSONObject();

            json.put("Request","4");
            json.put("Username",username);
            json.put("Score",score);
            json.put("Stage",5);

            packet = new Packet(json.toString());
            try {
                outputStream.writeObject(packet);
            } catch (IOException e) {
                e.printStackTrace();
            }


            Packet receivePacket = null;
            try {
                receivePacket = (Packet) inputStream.readObject();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
            JSONObject receivedData = new JSONObject(receivePacket.message);
            System.out.println(receivePacket.message);

            if(Objects.equals(receivedData.getString("Message"), "OK")){
                accepted=true;
                System.out.println("a zis OK !!!");
            }

            if(!accepted){
                // reintroducerea datelor
            }

        }
        try {
            outputStream.writeObject(packet);
        } catch (IOException e) {
            System.out.println("here");
            e.printStackTrace();
        }
    }

    private static void login(ObjectOutputStream outputStream, ObjectInputStream inputStream){
        Packet packet = null;
        boolean accepted = false;

        while(!accepted){

            Scanner scanner = new Scanner(System.in);
            String name=scanner.nextLine();
            String name2 = "CSU Brasov2";

            JSONObject json = new JSONObject();

            json.put("Request", Request.LOGIN.toString());
            json.put("Request_Type", RequestType.USER.toString());
            json.put("Username","Denisa");
            json.put("Password","uyigjh2112");

            packet = new Packet(json.toString());
            try {
                outputStream.writeObject(packet);
            } catch (IOException e) {
                e.printStackTrace();
            }


            Packet receivePacket = null;
            try {
                receivePacket = (Packet) inputStream.readObject();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
            JSONObject receivedData = new JSONObject(receivePacket.message);
            System.out.println(receivePacket.message);

            if(receivedData.getString("Message")=="OK"){
                accepted=true;
                System.out.println("a zis OK !!!");
            }

            if(!accepted){
                // reintroducerea datelor
            }

        }
        try {
            outputStream.writeObject(packet);
        } catch (IOException e) {
            System.out.println("here");
            e.printStackTrace();
        }
    }
}
