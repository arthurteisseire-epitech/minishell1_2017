/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"

int main(int ac, char **av, char **env)
{
	pid_t pid = getpid();
	char *cmd = "";
	char *args[3] = {"/bin/ls", "-l", NULL};

	if (ac != 1) {
		my_puterror(av[0]);
		my_puterror(": The program must take two and only two argument\n");
		return (84);
	}
	if (pid > 0) {
		while (my_strcmp(cmd, "exit") != 0) {
			cmd = get_next_line(0);
			pid = fork();
			if (pid == 0) {
				if (cmd != NULL) {
					execve(cmd, args, env);
				}
			} 
		}
	}
	return (0);
}
