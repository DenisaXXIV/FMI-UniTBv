public enum Request {
    REGISTRATION("1"),
    VALIDATION("2"),
    TRANSMISSION ("3"),
    UPDATE("4"),
    DELETE ("5"),
    SOMETHING_ELSE("6"),
    LOGIN("7"),
    EXIT_THREAD("8");

    private String action;

    // getter method
    public String getAction()
    {
        return this.action;
    }

    private Request(String action)
    {
        this.action = action;
    }
}


