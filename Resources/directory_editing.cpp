#include <iostream>
#include <filesystem>
#include <fstream>
#include "../Header files/directory_editing.h"

void goToSpecifiedPath(const std::string& path) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string YELLOW = "\033[33m";

    try {
        if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
            std::filesystem::current_path(path);
        } else {
            std::cout << YELLOW << "Error: " << RESET_COLOR << "path does not exist!" << std::endl;
        }
    } catch (const std::exception& error) {
        std::cout << RED << "An error occured while changing directory: " << RESET_COLOR << error.what() << std::endl;
    }
}

void showCurrentWorkingDirectory() {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string YELLOW = "\033[33m";

    try {
        std::cout << "Current working directory is " << std::filesystem::current_path() << std::endl;
    } catch (const std::exception& error) {
        std::cout << RED << "An error occured while retrieving directory: " << RESET_COLOR << error.what() << std::endl;
    }
}

void showAllFilesAndFoldersInPath() {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string YELLOW = "\033[33m";
    const std::string PATH = std::filesystem::current_path().string();

    try {
        if (std::filesystem::exists(PATH) && std::filesystem::is_directory(PATH))
            for (const auto& entry: std::filesystem::directory_iterator(PATH))
                std::cout << entry.path().filename().string() << std::endl;
        else
            std::cout << RED << "Error: " << RESET_COLOR << "not possible to show files!" << std::endl;
    } catch (const std::exception& error) {
        std::cout << RED << "An error with loading files occured: " << RESET_COLOR << error.what() << std::endl;
    }
}

void makeFileInTheCurrentDirectory(std::string filename) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string YELLOW = "\033[33m";
    const std::string GREEN = "\033[32m";
    const std::filesystem::path PATH = std::filesystem::current_path() / filename;
    std::ofstream file(PATH);

    try {
        if (file.is_open()) {
            file << "";
            file.close();
            std::cout << GREEN << "Success: " << RESET_COLOR << "created " << filename << " in the current directory!" << std::endl;
        } else {
            std::cout << YELLOW << "Error: " << RESET_COLOR << "not possible to create " << filename << std::endl;
        }
    } catch (const std::exception& error) {
        std::cout << RED << "An error while creating " << filename << " in current directory: " << RESET_COLOR << error.what() << std::endl;
    }
}

void removeFileFromCurrentDirectory(std::string filename) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string YELLOW = "\033[33m";
    const std::string GREEN = "\033[32m";
    const std::filesystem::path PATH = std::filesystem::current_path() / filename;

    try {
        if (std::filesystem::exists(PATH) && std::filesystem::is_regular_file(PATH)) {
            std::filesystem::remove(PATH);
            std::cout << GREEN << "Success: " << RESET_COLOR << filename << " has been deleted from " << PATH.string() << std::endl;
        } else
            std::cout << YELLOW << "Error: " << RESET_COLOR << "unable to remove " << filename << " from " << PATH.string() << std::endl;
    } catch (const std::exception& error) {
        std::cout << RED << "An error occured while deleting " << filename << " from the current directory: " << RESET_COLOR << error.what() << std::endl;
    } 
}
