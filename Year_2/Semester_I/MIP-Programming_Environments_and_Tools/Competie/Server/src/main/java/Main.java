import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {
//    public static void main(String[] args) {
//        StageDao stageDao= new StageDao();
//        StageEntity stage=new StageEntity();
//        stage.setName("etapa1");
//        stageDao.create(stage);
//
//    }

    public static final int PORT = 6544;

    public static void main(String[] args) {
        new Thread(() -> {
            try {
                ServerSocket serverSocket = new ServerSocket(PORT);
                Socket clientSocket = null;
                boolean isClose = false;

                System.out.println("Server is running");
                while (!isClose) {
                    clientSocket = serverSocket.accept(); // Keeps the program running until it gets a connection
                    new Thread(new ServerThread(clientSocket)).start();
                }
                if(isClose) {
                    serverSocket.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }
}
