#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cstdlib>
#include <iostream>
#include <cstring>

struct Person {
	int age;
	char name[10];
};

int main(int argc, char* argv[]) {
    if (argc != 2) { exit(EXIT_FAILURE); }
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		std::cerr << "open: '" << argv[1] << "' "
		          << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	}

	struct stat sb {};
	if (fstat(fd, &sb) != 0) {
		std::cerr << "fstat: '" << argv[1] << "' "
		          << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	}

	size_t msize = sb.st_size;
	
	void* mptr = mmap(nullptr, msize, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mptr == MAP_FAILED) {
		std::cerr << "mmap: " << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	}
	close(fd);

	Person* person = (Person*) mptr;
	std::cout << person->age << "<-age\n" << person->name << "<-name\n";
	
	if (munmap(mptr, msize) != 0) {
		std::cerr << "munmap: " << std::strerror(errno) << "\n";
	}
	return 0;
}
