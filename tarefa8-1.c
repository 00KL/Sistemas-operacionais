#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    int N;
    int pid;
    scanf("%d", &N);

    printf("Meu pid e: %d\n", getpid());

    for(int i = 1;  i < N; i++){
        if((pid = fork()) == 0 ){
            printf("Meu pid e: %d Meu pai e: %d Meu N e: %d \n", getpid(), getppid(), i);
            break;
        }
        printf("Meu pid e: %d Meu pai e: %d Meu N e: %d \n", getpid(), getppid(), i);
    }

    sleep(5);
    return 0;
}