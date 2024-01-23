/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:43:24 by myevou            #+#    #+#             */
/*   Updated: 2024/01/23 16:05:49 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

 typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;
t_list	*ft_lstlast(t_list *stash);
void	extract_line(t_list *stash, char **line);
size_t		ft_strlen(const char *str);
int		found_line(t_list *stash);
void	generate_line(t_list *stash, char **line);
void	add_to_stash(t_list **stash, char *buff, int read_count);
void	read_and_stash(int fd, t_list **stash);
void	clean_stash(t_list **stash);
void	free_stash(t_list *stash);
char	*get_next_line(int fd, int state);

#endif
