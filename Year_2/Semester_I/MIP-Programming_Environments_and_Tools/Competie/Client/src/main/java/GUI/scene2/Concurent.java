package GUI.scene2;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.chart.AreaChart;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.NumberAxis;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.control.TitledPane;
import javafx.scene.input.MouseEvent;

public class Concurent {

    @FXML
    private TitledPane accountPane;

    @FXML
    private CategoryAxis caStages;

    @FXML
    private Label concurentUsername;

    @FXML
    private Button dashboardBT;

    @FXML
    private TitledPane dashboardPane;

    @FXML
    private Button exitBt;

    @FXML
    private NumberAxis naPoints;

    @FXML
    private TextField nameField;

    @FXML
    private TextField passwordField;

    @FXML
    private AreaChart<String, Integer> perCompetitor;

    @FXML
    private BarChart<?, ?> perContest;

    @FXML
    private BarChart<?, ?> perStage;

    @FXML
    private Button submitBT;

    @FXML
    private TextField teamField;

    @FXML
    private ListView<?> teamList;

    @FXML
    private TextField usernameField;

    @FXML
    void MyAccount(MouseEvent event) {

    }

    @FXML
    void exit(MouseEvent event) {

    }

    @FXML
    void myAccountBT(ActionEvent event) {

    }

    @FXML
    void openDashboard(MouseEvent event) {

    }

    @FXML
    void updateUser(MouseEvent event) {

    }

}
