#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
    	printf("Wrong argument number\n");
	return 1;
    }
    

    if(mkdir(argv[1], 0755) != 0 && errno != EEXIST) {
    	printf("failed creating directory %s\n", argv[1]);
	return 1;
    }

    return 0;
}
