#include <iostream>
#include <string>

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

class FunctionalityController {
public:
    static void openSpecifiedDirectoryInPath(const std::string& path) {
        const std::string script = "osascript -e 'tell application \"Finder\" to open POSIX file \"" + path + "\"'";

        const int result = system(script.c_str());
        if (result == 0)
            std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
        else
            std::cout << RED << "Could not open Finder!" << RESET_COLOR << std::endl;
    }
    static void openSpecifiedFileInVim(const std::string& filename) {
        const std::string script = "vim " + filename;
        system(script.c_str());
    }
    static void openSpecifiedFileInPython(const std::string& filename) {
        const std::string script = "python3 " + filename;
        system(script.c_str());
    }
    static void retrieveRootInTerminal(const std::string& command) {
        const std::string script = "sudo " + command;
        const int result = system(script.c_str());

        if (result == 0)
            std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
        else
            std::cout << RED << "Unknown command: " << RESET_COLOR << command << std::endl;
    }
};