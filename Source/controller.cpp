#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <filesystem>
#include <fstream>

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Controller {
public:
    static void goToSpecifiedDirectory(const std::string& directory) {
        try {
            if (std::filesystem::exists(directory) && std::filesystem::is_directory(directory))
                std::filesystem::current_path(directory);
            else
                std::cout << RED << "Error: " << RESET_COLOR << "path does not exist!" << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when changing directory: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void displayCurrentWorkingDirectory();
    static void showPathContent();
    static void createFileInCurrentWorkingDirectory(const std::string& filename);
    static void removeFileFromCurrentWorkingDirectory(const std::string& filename);
};
