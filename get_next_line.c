/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:45 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/24 16:59:44 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getnextline.h"

char	**buf_to_tab(int fd)
{
	static char		*new_str[INT_MAX];
	int				reead;

	reead = read(fd, *new_str, BUFF_SIZE);
	while (reead > 0)
	{
		
	}
	int	i = -1;

	while (new_str[++i])
		printf("%s", new_str[i]);
	return (new_str);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**line;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	line = buf_to_tab(fd);
	return (0);
}
