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
		char* args[] = { "ls", "-l", "-a", NULL };
		// execv("/usr/bin/ls", args);
		execvp("ls", args);
		perror("exec");
		exit(2);
    } else {
    	// parent
   		wait(nullptr);
		cout << "ls was executed\n";
    }
    return 0;
}
