#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int glob = 6;
int main(void) {
	int var; 			/* external variable in initialized data */
	pid_t pid;			/* automatic variable on the stack */
	var = 88;
	printf("before fork\n");
	if ( (pid = fork()) < 0)
		fprintf(stderr, "fork error\n");
	else if (pid == 0) { 		/* ***child*** */
		glob++; 		/* modify variables */
		var++;
		printf("%d\n\n", setpgid(0, 0));

	}
	else
		sleep(2);		/* ***parent***; try to guarantee that child ends first*/
	printf("pid = %d, ppid = %d, gid = %d glob = %d, var = %d\n", getpid(), getppid(), getgid(), glob, var);
	return 0;
}
