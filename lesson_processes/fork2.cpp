#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main() {
    cout << "Before fork\n";
    
    pid_t cpid = fork();
    
    if (cpid < 0) {
    	perror("fork");
	    exit(1);
    } else if (cpid == 0) {
    	// child
    	cout << "Hello from child\n";
    } else {
    	// parent
	    cout << "Hello from parent\n";
    }

    cout << "After fork\n";

    if (cpid > 0) {
   	    if (wait(nullptr) == -1) {
            perror("wait");
            exit(1);
        }
    }
    return 0;
}
