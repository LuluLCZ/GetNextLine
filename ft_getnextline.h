/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:24:25 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/23 21:28:06 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 12

int		get_next_line(const int fd, char **line);

#endif
