// basic_fork.c: simple example of fork

/*
 * MESSAGE is a simple wrapper around printf so that printf call display the
 * PID in front of the message
 * Must have at least 2 arguments, NULL can be used for the empty case
 */
//# define MESSAGE(fmt_, args...) printf("(%u): " fmt_, getpid(), args);
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
void random_fill(int tab[], size_t len) {
    for (int *cur = tab; cur != tab + len; ++cur)
        *cur = random() % 1024;
}

void swap(int *a, int *b) {
    int           c = *a;
    *a = *b;
    *b = c;
}

void sort01(int tab[], size_t len) {
    for (size_t i = 0; i < len; ++i) {
        size_t      min = i;
        for (size_t j = i + 1; j < len; ++j)
            if (tab[j] < tab[min]) min = j;
        swap(tab + i, tab + min);
    }
}

void sort02(int tab[], size_t len) {
    int           move = 1;
    for (size_t i = 0; i < len && move; ++i) {
        move = 0;
        for (size_t j = 0; j < len - i - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                move = 1;
                swap(tab + j, tab + j + 1);
            }
        }
    }
}

int is_sorted(int tab[], size_t len) {
    size_t        j;
    for (j = 1; j < len && tab[j - 1] <= tab[j]; ++j) {}
    return j == len;
}
void array_print(int array[], size_t len)
{
    int line = 0;
    printf("|\n");
    for (size_t i = 0; i < len; ++i) {
         printf(" %*d | ", array[i]);
    }
    printf("|\n");
}
int main(void)
{
    int           fork_ret, x = 0;
    fork_ret = fork();
    if (fork_ret == -1)
    {
        err(1, "Fork failed");
    }
    else if (fork_ret)
    {
        printf("Inside parent %d\n");
        printf("Initial x: %d\n", x);
        x = -42;
    }
    else
    {
        printf("Inside child\n" );
        printf("Initial x: %d\n", x);
        x = 42;
    }
    printf("parent id: %u\n", getppid());
    printf("new x:%d\n", x);
    int tab[5];
    random_fill(tab,5);
    pid_t pid, pid2;
    int status;
    
    pid = fork();
    
    if (pid == 0) { //child process
        pid2 = fork();
        int status2;
        
        if (pid2 == 0) { //child of child process
        }
        else {
            array_print(tab,5);
            sort01(tab,5);
            array_print(tab,5);
            fflush(stdout);
            wait(&status2);
        }
    }
    else { //parent process
        //printf("Hello ");
        array_print(tab,5);
        sort01(tab,5);
        array_print(tab,5);
        fflush(stdout);
        wait(&status);
    }
    /*if(fork()) # parent
        if(fork()) #parent
            else # child2
                else #child1*/
    return 0;
}
