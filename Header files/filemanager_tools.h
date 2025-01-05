#ifndef filemanager_tools_h
#define filemanager_tools_h

class FilemanagerTools {
    public:
    void displayLogo();
    void displayDocumentation();
    void displayCurrentVersion();
    void clearCurrentSession();
    void showCommandsHistory(std::vector<std::string> commands_stack);
    void echoMessage(const std::string& message);
    private:
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
};

#endif