#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>

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

	char* mptr = (char*)mmap(nullptr, msize, PROT_READ, MAP_PRIVATE, fd, 0);
	if (mptr == MAP_FAILED) {
		std::cerr << "mmap: " << std::strerror(errno) << "\n";
		exit(EXIT_FAILURE);	
	}
	close(fd);

	// write(1, mptr, msize);
	for (size_t i = 0; i < msize; i++) {
		std::cout << mptr[i];
	}
	std::cout << "\n";

	if (munmap(mptr, msize) != 0) {
		std::cerr << "munmap: " << std::strerror(errno) << "\n";
	}
	return 0;
}
