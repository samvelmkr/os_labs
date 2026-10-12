#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main() {
    int ret = creat("./aaa", 0755);
    if (ret == -1) {
    	printf("errno value is %d\n", errno);
	perror("create");
	return errno;
    }

    return 0;
     
}
