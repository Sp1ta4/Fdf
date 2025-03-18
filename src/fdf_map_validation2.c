/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_validation2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:46 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/18 11:32:30 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void err_exit(char *err_msg, int exit_status)
{
	perror(err_msg);
	exit(exit_status);	
}

void	err_invalid_map(int code)
{
	if (code == 0)
		ft_putstr_fd("Error: memory allocation failed\n", 2);	
	else if (code == 1)
		ft_putstr_fd("Error: invalid map (inconsistent row length or empty line)\n", 2);
	else if (code == 2)
		ft_putstr_fd("Error: empty line in map\n", 2);
	else
		ft_putstr_fd("Error: unknown error\n", 2);
	exit(1);
}

void	free_map(int **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(map[i++]);
	free(map);
}

char	**get_splitted_line(int fd)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[0] == '\n' || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	split = ft_split(line, ' ');
	free(line);
	if (!split)
		err_invalid_map(0);
	return (split);
}