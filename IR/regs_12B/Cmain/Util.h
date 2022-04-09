#pragma once

#include <vector>
#include <string>

void FileWrite(std::string filePath, std::string cnt);

void ListFiles(std::string cateDir, std::vector<std::string>& files);

bool isFileExist(std::string file);

int stringStartsWith(std::string s, std::string sub);





