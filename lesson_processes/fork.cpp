#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
    cout << "Before fork\n";
    fork();
    fork();
    fork();
    cout << "After fork\n";
    return 0;
}
