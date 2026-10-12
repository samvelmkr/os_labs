#include <sys/types.h>
#include <dirent.h>
#include <iostream>
int main() {
    DIR* directory;

    directory = opendir(".");
    if (directory == nullptr) {
    	std::cerr << "Could not open dir." << "\n";
	return 1;
    }

    struct dirent* entry;

    while((entry = readdir(directory)) != nullptr) {

        std::cout << entry->d_name << " | " << entry->d_ino << "\n";
    }

    if (closedir(directory)) {
    	std::cerr << "Could not close dir.\n";
        return 1;	
    }

    return 0;
}
