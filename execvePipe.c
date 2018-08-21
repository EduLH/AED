#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	char *cmd1[] = {"/bin/ls", "-la", NULL};
	char *cmd2[] = {"/bin/grep", "h", NULL};
	int fd[2];
	pid_t pid;

	if (pipe(fd)<0){
		perror("pipe()");
		return -1;
	}
	pid = fork();
	if (pid == 0) {//filho: grep
		close(fd[1]);
		close(STDIN_FILENO);
		dup(fd[0]);
		close(fd[0]);
		execve(cmd2[0], cmd2, NULL);
		return 0;
	} else { // pai: ls
		close(fd[0]);
		close(STDOUT_FILENO);
		dup(fd[1]); // dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(cmd1[0], cmd1, NULL);
		waitpid(-1, NULL, 0);
	}
	return 0;
}
