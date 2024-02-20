#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid, my_ppid;
	
	my_ppid = getppid();
	my_pid = getpid();
	printf("PPID: %u\nPID: %u\n", my_ppid, my_pid);
	return (0);
}
