#include "Util.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <direct.h>
#include <io.h>
#else
#include <unistd.h>
#include <dirent.h>
#endif

void FileWrite(std::string filePath, std::string cnt)
{
	std::ofstream fout;
	fout.open(filePath);
	fout << cnt.c_str() << std::endl;
	fout.close();
}

bool isFileExist(std::string file)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    int ret = _access(file.c_str(), 0);
#else
	int ret = access(file.c_str(), 0);
#endif
	if (ret == 0) {
		return true;
	}
	else {
		return false;
	}
}

int stringStartsWith(std::string s, std::string sub) 
{
	return s.find(sub) == 0 ? 1 : 0;
}

void ListFiles(std::string cateDir, std::vector<std::string>& files)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	struct _finddata_t file;
	long lf = -1;
	std::string p;
	if ((lf = _findfirst(p.assign(cateDir).append("/*").c_str(), &file)) != -1) {
		do {
			if (strcmp(file.name, ".") != 0 && strcmp(file.name, "..") != 0)
			{
				files.push_back(file.name);
			}
		} while (_findnext(lf, &file) == 0);
		// for debug point use. 
		files.size();
	}
	_findclose(lf);
#else
	DIR * dir;
	struct dirent *ptr;

	if ((dir = opendir(cateDir.c_str())) == nullptr)
	{
		return;
	}

	while ((ptr = readdir(dir)) != nullptr)
	{
		if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {    ///current dir OR parrent dir
			continue;
		}
		else if (ptr->d_type == 8) {    ///file
		 //printf("d_name:%s/%s\n",basePath,ptr->d_name);
			files.push_back(ptr->d_name);
		}
		else if (ptr->d_type == 10) {    ///link file
		 //printf("d_name:%s/%s\n",basePath,ptr->d_name);
			continue;
		}
		else if (ptr->d_type == 4) {
			///dir
			files.push_back(ptr->d_name);
		}
	}
	closedir(dir);
#endif
}

