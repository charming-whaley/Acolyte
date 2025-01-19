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
    static void displayCurrentWorkingDirectory() {
        try {
            std::cout << std::filesystem::current_path() << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when getting directory: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void showPathContent();
    static void createFileInCurrentWorkingDirectory(const std::string& filename) {
        const std::filesystem::path PATH = std::filesystem::current_path() / filename;
        std::ofstream file(PATH);

        try {
            if (file.is_open()) {
                file << "";
                file.close();
                std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
            } else
                std::cout << RED << "Error: " << RESET_COLOR << "not possible to create " << filename << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when creating file: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void removeFileFromCurrentWorkingDirectory(const std::string& filename) {
        const std::filesystem::path PATH = std::filesystem::current_path() / filename;

        try {
            if (std::filesystem::exists(PATH) && std::filesystem::is_regular_file(PATH)) {
                std::filesystem::remove(PATH);
                std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
            } else
                std::cout << RED << "Error:" << RESET_COLOR << " unable to remove" << filename << " from " << PATH.string() << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when removing file: " << RESET_COLOR << error.what() << std::endl;
        }
    }
private:
    static int retrieveTerminalSize() {
        struct winsize win {};
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
        return win.ws_col;
    }
};
