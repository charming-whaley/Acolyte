#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include "controller.cpp"
#include "tools.cpp"
#include "functionality_controller.cpp"

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int main() {
    const char* USERNAME = std::getenv("USER");
    std::vector<std::string> commandsHistory;
    std::filesystem::current_path("/Users/" + std::string(USERNAME));

    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        const auto suffix = ".local";
        const size_t hostnameLength = strlen(hostname);
        const size_t suffixLength = strlen(suffix);

        if (hostnameLength > suffixLength && strcmp(hostname + hostnameLength - suffixLength, suffix) == 0)
            hostname[hostnameLength - suffixLength] = '\0';
    }

    Tools::displayProductLogo();
    std::string input;
    while (true) {
        std::cout << GREEN << USERNAME << CYAN << "@" << GREEN << hostname << RESET_COLOR << " >" << std::endl;
        std::getline(std::cin, input);
        commandsHistory.push_back(input);

        if (input == "help")
            Tools::displayProductDocumentation();
        else if (input == "clear")
            Tools::clearCurrentSession();
        else if (input == "version")
            Tools::displayProductCurrentVersion();
        else if (input == "history")
            Tools::showCommandsHistory(commandsHistory);
        else if (input[0] == 'e' and input[1] == 'c' and input[2] == 'h' and input[3] == 'o') {
            std::string message;
            for (int i = 5; input[i] != '\0'; ++i)
                message.push_back(input[i]);
            Tools::echoMessage(message);
        } else if (input == "path")
            Controller::displayCurrentWorkingDirectory();
        else if (input == "ls")
            Controller::showPathContent();
        else if (input[0] == 'g' and input[1] == 'o') {
            std::string path;
            for (int i = 3; input[i] != '\0'; ++i)
                path.push_back(input[i]);
            Controller::goToSpecifiedDirectory(path);
        } else if (input[0] == 'm' and input[1] == 'a' and input[2] == 'a' and input[3] == 'e') {
            std::string filename;
            for (int i = 5; input[i] != '\0'; ++i)
                filename.push_back(input[i]);
            Controller::createFileInCurrentWorkingDirectory(filename);
        } else if (input[0] == 'r' and input[1] == 'e' and input[2] == 'm' and input[3] == 'o' and input[4] == 'v' and input[5] == 'e') {
            std::string filename;
            for (int i = 7; input[i] != '\0'; ++i)
                filename.push_back(input[i]);
            Controller::removeFileFromCurrentWorkingDirectory(filename);
        } else if (input[0] == 'o' and input[1] == 'p' and input[2] == 'e' and input[3] == 'n') {
            std::string directory;
            for (int i = 5; input[i] != '\0'; ++i)
                directory.push_back(input[i]);
            FunctionalityController::openSpecifiedDirectoryInPath(directory);
        } else if (input[0] == 'v' and input[1] == 'i' and input[2] == 'm') {
            std::string filename;
            for (int i = 4; input[i] != '\0'; ++i)
                filename.push_back(input[i]);
            FunctionalityController::openSpecifiedFileInVim(filename);
        } else if (input[0] == 'p' and input[1] == 'y' and input[2] == 't' and input[3] == 'h' and input[4] == 'o' and input[5] == 'n') {
            std::string filename;
            for (int i = 7; input[i] != '\0'; ++i)
                filename.push_back(input[i]);
            FunctionalityController::openSpecifiedFileInPython(filename);
        } else if (input[0] == 's' and input[1] == 'u' and input[2] == 'd' and input[3] == 'o') {
            std::string command;
            for (int i = 5; input[i] != '\0'; ++i)
                command.push_back(input[i]);
            FunctionalityController::retrieveRootInTerminal(command);
        } else if (input == "exit")
            break;
        else
            std::cout << RED << "Error: " << RESET_COLOR << "no such command!" << std::endl;

    }
    return 0;
}