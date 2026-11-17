#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main(int argc, char* argv[]) {    
    pid_t cpid = fork();
    
    if (cpid < 0) {
    	perror("fork");
		exit(1);
    } else if (cpid == 0) {
    	// child
		// execl("/usr/bin/ls", "/usr/bin/ls", "-l", "-a", NULL);
		execlp("ls", "ls", "-l", "-a", NULL);
		perror("exec");
		exit(2);
    } else {
    	// parent
   		wait(nullptr);
		cout << "ls was executed\n";
    }

    return 0;
}
