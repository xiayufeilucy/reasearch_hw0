#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[]) {
    using namespace std;
    int pipe1[1]; //create pipe
    pid_t p; //fork child process
    int number_of_bounce = 5;
    int buf = 1;

    if (pipe(pipe1)== -1) 
    { 
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    p = fork();
     if (p == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

write(pipe1[0], &buf, 1);
while (number_of_bounce >= 0) {
    if (p == 0) { 
        cout << "Child process starts \n";
        read(pipe1[0], &buf, 1);
        buf++;
        write(pipe1[0], &buf, 1);
        cout << &buf;
    } else {       
        cout << "Parent process starts \n";
        read(pipe1[0], &buf, 1);
        buf++;
        write(pipe1[0], &buf, 1);
        cout << &buf;
    }
    number_of_bounce--;
}
return 0;

}