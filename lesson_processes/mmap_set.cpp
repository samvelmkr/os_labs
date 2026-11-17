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
	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
		std::cerr << "open: '" << argv[1] << "' "
		          << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	}

	int size = sizeof(Person);
    if (ftruncate(fd, size) != 0) {
		std::cerr << "ftruncate: '" << argv[1] << "' "
		          << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	}

	void* mptr = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mptr == MAP_FAILED) {
		std::cerr << "mmap: " << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);
	}
	close(fd);

	// Person p;
	// p.age = 10;
	// memcpy(mptr, &p, size);

	Person* person = (Person*) mptr;
	person->age = 10;
	std::strcpy(person->name, "John");
	person->name[4] = '\0';

	if(munmap(mptr, size) != 0) {
		std::cerr << "unmmap: " << std::strerror(errno) << "\n";
	}	
	return 0;
}
