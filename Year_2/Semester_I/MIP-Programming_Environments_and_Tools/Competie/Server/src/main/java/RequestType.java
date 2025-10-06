public enum RequestType {
    TEAM("1"),
    USER("2"),
    STAGE("3"),
    PARTICIPATION("4");

    private String action;

    // getter method
    public String getAction()
    {
        return this.action;
    }

    private RequestType(String action)
    {
        this.action = action;
    }
}
