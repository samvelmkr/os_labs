#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <format>
#include <cstring>

int list_dir(const std::string& dir_name) {
    DIR* directory;

    directory = opendir(dir_name.c_str());
    if (directory == nullptr) {
    	std::cerr << "Could not open dir." << dir_name << "\n";
	return 1;
    }

    struct dirent* entry;

    while((entry = readdir(directory)) != nullptr) {
	
        std::cout << entry->d_name 
		  << " | "
		  << entry->d_ino
		  << "\n";
    
	if (entry->d_type == DT_DIR && 
	    std::strcmp(entry->d_name, ".") != 0 &&
	    std::strcmp(entry->d_name, "..") != 0 ) {

	    list_dir(std::format("{}/{}", dir_name, entry->d_name));
	}
    }

    if (closedir(directory)) {
    	std::cerr << "Could not close dir.\n";
        return 1;	
    }

    return 0;
}

int main() {
    return list_dir("test_dir");
}
