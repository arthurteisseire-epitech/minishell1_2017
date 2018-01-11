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
	pid_t pid = fork();
	char *cmd = "";

	if (ac != 1) {
		my_puterror("The program must take two and only two argument\n");
		return (84);
	}
	if (pid == 0) {
		execve(cmd, av, env);
		if (cmd != NULL) {
			execve(cmd, av, env);
			free(cmd);
		}
	} else if (pid > 0) {
		while (my_strcmp(cmd, "exit") != 0) {
			cmd = get_next_line(0);
			if (cmd != NULL) {
				execve(cmd, av, env);
				free(cmd);
			}
		}
	} else {
		my_puterror("A problem ocurred during the creation of shell\n");
		return (84);
	}
	return (0);
}
