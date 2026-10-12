#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int ret = creat("./aaa", 0644);
    if (ret == -1) {
    	printf("errno value is %d\n", errno);
	perror("create");
	return errno;
    }

    printf("success creat\n");

    int fd = open("./aaa", O_WRONLY);
    if (fd == -1) {
        printf("errno value is %d\n", errno);
        perror("open");
        return errno;
    }
    
    const char* str = "Hello!";

    int written_bytes = write(fd, str, strlen(str));
    if (written_bytes == -1) {
        printf("errno value is %d\n", errno);
        perror("write");
        return errno;
    }

    write(1, str, strlen(str));
    printf("wrote %d bytes\n", written_bytes); 


    if (close(fd) == -1) {
    	printf("errno value is %d\n", errno);
        perror("close");
        return errno;
    }


    return 0;
     
}
