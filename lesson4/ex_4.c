#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("./aaa", O_RDONLY);
    if (fd == -1) {
        printf("errno value is %d\n", errno);
        perror("open");
        return errno;
    }
    
    char buf[11];
    int read_bytes = read(fd, buf, 10);
    if (read_bytes == -1) {
        printf("errno value is %d\n", errno);
        perror("read");
        return errno;
    }

    buf[read_bytes] = '\0';

    printf("read %s, %d bytes\n", buf, read_bytes); 


    if (close(fd) == -1) {
    	printf("errno value is %d\n", errno);
        perror("close");
        return errno;
    }


    return 0;
     
}
