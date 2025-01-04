#ifndef directory_editing_h
#define directory_editing_h

void goToSpecifiedPath(const std::string& path);
void showCurrentWorkingDirectory();
void showAllFilesAndFoldersInPath();
void makeFileInTheCurrentDirectory(std::string filename);
void removeFileFromCurrentDirectory(std::string filename);

#endif