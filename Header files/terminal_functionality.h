#ifndef terminal_functionality_h
#define terminal_functionality_h

class TerminalFunctionality {
    private:
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    public:
    void openSpecifiedPathOrFileInFinder(const std::string& path);
    void openSpecifiedFileInVim(const std::string& filename);
    void openSpecifiedFileInPython(const std::string& filename);
};

#endif