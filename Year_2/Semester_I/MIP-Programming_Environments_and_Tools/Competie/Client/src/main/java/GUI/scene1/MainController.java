package GUI.scene1;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.text.Text;

public class MainController {

    @FXML
    private Button a_login;

    @FXML
    private PasswordField a_p_field;

    @FXML
    private TextField a_u_field;

    @FXML
    private Text adminWrong;

    @FXML
    private Button c_login;

    @FXML
    private PasswordField c_p_field;

    @FXML
    private TextField c_u_field;

    @FXML
    private Text competitorWrong;

    @FXML
    void loginAdmin(MouseEvent event) {
        Command command=new Command();
    }

    @FXML
    void loginCompetitor(MouseEvent event) {

    }

}
