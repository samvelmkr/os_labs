#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

/*
0 - in
1 - out.log (file)
2 - out.log (file)
3 - out (term)

-> out.log (1)

Hello
     |


*/



int main() {
    int savedOut = dup(1);
    if(savedOut < 0) {
    	perror("dup");
	return 1;
    }

    close(1);

    int fd = open("out.log", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0) {
    	perror("open");
	return 1;
    }
    
    std::cout << "Hello\n"; // write(1, "Hello", ...)

    if (dup2(1, 2) < 0) {
    	perror("dup2");
	return 1;
    }

    write(savedOut, "World\n", 6);
    std::cerr << "Some error message\n"; // write(2, ...)

    return 0;
}
