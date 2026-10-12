#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int ret = creat("./aaa", 0644);
    if (ret == -1) {
    	printf("errno value is %d\n", errno);
	perror("create");
	return errno;
    }

    printf("success creat\n");

    int fd = open("./aaa", O_RDONLY | O_CREAT, 0664);
    if (fd == -1) {
        printf("errno value is %d\n", errno);
        perror("open");
        return errno;
    }


    if (close(fd) == -1) {
    	printf("errno value is %d\n", errno);
        perror("close");
        return errno;
    }


    return 0;
     
}
