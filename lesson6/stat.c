#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
    	printf("Wrong argument number\n");
	return 1;
    }
    
    struct stat sb;
    if (stat(argv[1], &sb) != 0) {
    	perror("stat");
	return 1; 
    }

    printf("I-node number: %ju\n",  sb.st_ino);
    printf("Mode:          %jo (octal)\n", sb.st_mode & 0777);
    

    if(chmod(argv[1], 0777) != 0) {
    	perror("chmod");
	return 1; 
    }

    return 0;
}
