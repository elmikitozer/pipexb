/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:29:04 by myevou            #+#    #+#             */
/*   Updated: 2024/01/30 15:11:06 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	redirection_files(t_args *args, int index)
{
	int	fd;

	if (index == 0)
		fd = open(args->in, O_RDONLY);
	if (index == args->nbcmds - 1)
		fd = open(args->out, O_RDWR | args->flag | O_CREAT, 0666);
	if (fd < 0)
	{
		fprintf(stderr, "error: %s\n", strerror(errno));
		exit(1);
	}
	dup2(fd, index == args->nbcmds - 1);
	close(fd);
}

void	redirection_pipes(t_args *args, int index)
{
	if (index != args->nbcmds - 1)
		dup2(args->fd[1], STDOUT_FILENO);
	if (index != 0)
	{
		dup2(args->old_pipes, STDIN_FILENO);
		close(args->old_pipes);
	}
	close(args->fd[0]);
	close(args->fd[1]);
}

void	*execution(t_args *args, int bool, int i)
{
	char	**cmd;

	cmd = ft_split(args->cmds[i], ' ');
	if (!cmd || !*cmd)
		return (ft_freetab(cmd), exit(1), NULL);
	if (bool)
	{
		while (args->env[++i])
			execve(pathcmd(args->env[i], cmd[0]), cmd, NULL);
		ft_printf("pipex: %s: command not found\n", cmd[0]);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL))
			ft_printf("pipex: %s: command not found\n", cmd[0]);
	}
	ft_freetab(cmd);
	return (NULL);
}

void	proccesses(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nbcmds)
	{
		pipe(args->fd);
		args->pid[i] = fork();
		if (args->pid[i] == 0)
		{
			free(args->pid);
			redirection_pipes(args, i);
			if (i == 0 || i == args->nbcmds - 1)
				redirection_files(args, i);
			chose_exec(args, i);
		}
		else
		{
			close(args->fd[1]);
			if (i)
				close(args->old_pipes);
			args->old_pipes = args->fd[0];
		}
	}
	close(args->fd[0]);
	ft_freetab(args->env);
}

int	main(int ac, char **av, char **env)
{
	static t_args	args = {0};

	if (ac < 5)
	{
		return (ft_printf("must be\
		./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2"));
		exit(1);
	}
	initargs(&args, av, env, ac);
	get_env(&args, env);
	if (!ft_strcmp(av[1], "here_doc"))
		here_doc(&args, ft_strjoin(av[2], "\n"));
	args.pid = malloc(sizeof(pid_t) * args.nbcmds);
	if (!args.pid)
		exit(1);
	proccesses(&args);
	waitprocess(&args);
	free(args.pid);
}
