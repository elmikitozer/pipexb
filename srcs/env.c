/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:12:27 by myevou            #+#    #+#             */
/*   Updated: 2024/01/25 14:50:59 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*pathcmd(char *path, char *cmd)
{
	char	*var;
	size_t	i;
	size_t	count;

	var = ft_calloc(ft_strlen(path) + ft_strlen(cmd) + 2, 1);
	if (!var)
		return (NULL);
	i = -1;
	while (path[++i])
		var[i] = path[i];
	var[i++] = '/';
	count = -1;
	while (cmd[++count])
		var[i + count] = cmd[count];
	var[i + count] = 0;
	return (var);
}

void	get_env(t_args *args, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			args->env = ft_split(envp[i], ':');
			if (!args->env)
			{
				ft_freetab(args->env);
				free(args);
				exit(1);
			}
		}
	}
}

void	chose_exec(t_args *args, int i)
{
	if (ft_strchr(args->cmds[i], '/'))
		execution(args, 0, i);
	else
		execution(args, 1, i);
	exit(127);
}
