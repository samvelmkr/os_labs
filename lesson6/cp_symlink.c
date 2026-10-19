#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
    	printf("Wrong argument number\n");
	printf("Usage: %s arg1 arg2\n", argv[0]);
	return 1;
    }
   
    struct stat sb;
    if (lstat(argv[1], &sb) != 0) {
    	perror("stat");
	return 1; 
    }

    if (!S_ISLNK(sb.st_mode)) {
    	printf("%s must be symlink\n", argv[1]);
	return 1;
    }
	

    char path[100];
    int readbytes = readlink(argv[1], path, 100);  
    if (readbytes < 0) {
    	perror("readlink");
	return 1;
    }


    path[readbytes] = '\0';

    printf("The value of %s is %s\n", argv[1], path);

    if(symlink(path, argv[2]) != 0) {
    	perror("symlink");
	return 1;
    }

    return 0;

}
