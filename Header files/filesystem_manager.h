#ifndef filesystem_manager_h
#define filesystem_manager_h

class FilesystemManager {
    public:
    void goToSpecifiedPath(const std::string& path);
    void showCurrentWorkingDirectory();
    void showPathContent();
    void makeFileInCurrentWorkingDirectory(const std::string& filename);
    void removeFileFromCurrentWorkingDirectory(const std::string& filename);
    private:
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string BLUE = "\033[34m";
    const std::string GREEN = "\033[32m";
    int retrieveTerminalSize();
};

#endif