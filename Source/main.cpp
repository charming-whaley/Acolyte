#include <iostream>
#include <unistd.h>
#include <filesystem>
#include <cstdlib>
#include <string>
#include <vector>
#include "filemanager_tools.cpp"
#include "filesystem_manager.cpp"
#include "terminal_functionality.cpp"

int main(int argc, const char * argv[]) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const char* USERNAME = std::getenv("USER");

    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    
    FilesystemManager manager = FilesystemManager();
    FilemanagerTools filemanager_tools = FilemanagerTools();
    TerminalFunctionality terminalFunctionality = TerminalFunctionality();

    std::vector<std::string> commands_stack;
    
    filemanager_tools.displayLogo();
    
    std::string userInput;
    while (userInput != "exit()" and userInput != "exit") {
        std::cout << USERNAME << "@" << hostname << " " << std::filesystem::current_path().string() << " > ";
        std::getline(std::cin, userInput);
        commands_stack.push_back(userInput);

        if (userInput == "help")
            filemanager_tools.displayDocumentation();
        else if (userInput == "clear")
            filemanager_tools.clearCurrentSession();
        else if (userInput == "version")
            filemanager_tools.displayCurrentVersion();
        else if (userInput == "history")
            filemanager_tools.showCommandsHistory(commands_stack);
        else if (userInput == "path")
            manager.showCurrentWorkingDirectory();
        else if (userInput == "ls")
            manager.showPathContent();
        else if (userInput[0] == 'g' && userInput[1] == 'o') {
            std::string path;
            for (int i = 3; userInput[i] != '\0'; ++i)
                path.push_back(userInput[i]);
            manager.goToSpecifiedPath(path);
        } else if (userInput[0] == 'm' && userInput[1] == 'a' && userInput[2] == 'k' && userInput[3] == 'e') {
            std::string filename;
            for (int i = 5; userInput[i] != '\0'; ++i)
                filename.push_back(userInput[i]);
            manager.makeFileInCurrentWorkingDirectory(filename);
        } else if (userInput[0] == 'r' && userInput[1] == 'e' && userInput[2] == 'm' && userInput[3] == 'o' && userInput[4] == 'v' && userInput[5] == 'e') {
            std::string filename;
            for (int i = 7; userInput[i] != '\0'; ++i)
                filename.push_back(userInput[i]);
            manager.removeFileFromCurrentWorkingDirectory(filename);
        } else if (userInput[0] == 'e' && userInput[1] == 'c' && userInput[2] == 'h' && userInput[3] == 'o') {
            std::string message;
            for (int i = 5; userInput[i] != '\0'; ++i)
                message.push_back(userInput[i]);
            filemanager_tools.echoMessage(message);
        } else if (userInput[0] == 'o' && userInput[1] == 'p' && userInput[2] == 'e' && userInput[3] == 'n') {
            std::string path;
            for (int i = 5; userInput[i] != '\0'; ++i)
                path.push_back(userInput[i]);
            terminalFunctionality.openSpecifiedPathOrFileInFinder(path);
        } else if (userInput[0] == 'v' && userInput[1] == 'i' && userInput[2] == 'm') {
            std::string filename;
            for (int i = 4; userInput[i] != '\0'; ++i)
                filename.push_back(userInput[i]);
            terminalFunctionality.openSpecifiedFileInVim(filename);
        } else if (userInput[0] == 'p' && userInput[1] == 'y' && userInput[2] == 't' && userInput[3] == 'h' && userInput[4] == 'o' && userInput[5] == 'n') {
            std::string filename;
            for (int i = 7; userInput[i] != '\0'; ++i)
                filename.push_back(userInput[i]);
            terminalFunctionality.openSpecifiedFileInPython(filename);
        } else if (userInput[0] == 's' && userInput[1] == 'u' && userInput[2] == 'd' && userInput[3] == 'o') {
            std::string command;
            for (int i = 5; userInput[i] != '\0'; ++i)
                command.push_back(userInput[i]);
            terminalFunctionality.retrieveRootInTerminal(command.empty() ? command : " " + command);
        } else
            if (userInput != "exit()" and userInput != "exit")
                std::cout << RED << "Error" << RESET_COLOR << ": no such command " << userInput << std::endl;
    }
    
    return 0;
}
