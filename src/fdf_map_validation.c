/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:29:45 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/18 11:30:41 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int	*convert_to_int_array(char **split, int expected_count)
{
	int	*arr;
	int	i;

	if (count_words(split) != expected_count)
	{
		free_split(split);
		err_invalid_map(1);
	}
	arr = malloc(sizeof(int) * expected_count);
	if (!arr)
	{
		free_split(split);
		err_invalid_map(0);
	}
	i = 0;
	while (i < expected_count)
	{
		arr[i] = ft_atoi(split[i]);
		i++;
	}
	return (arr);
}

static int	count_lines(const char *map_file)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		err_exit("open", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			close(fd);
			err_invalid_map(2);
		}
		free(line);
		lines++;
		line = get_next_line(fd);
	}
	close(fd);
	if (lines == 0)
		err_invalid_map(1);
	return (lines);
}

static int	**create_map(int map_fd, int width, int height, int *first_line)
{
	char	**split;
	int		**map;
	int		row;

	map = malloc(sizeof(int *) * height);
	if (!map)
		err_invalid_map(0);
	map[0] = first_line;
	row = 1;
	while (row < height)
	{
		split = get_splitted_line(map_fd);
		if (!split)
		{
			free_map(map, row);
			err_invalid_map(1);
		}
		map[row] = convert_to_int_array(split, width);
		free_split(split);
		row++;
	}
	return (map);
}

int	**check_and_create_map(char *map_file, int *width, int *height)
{
	int		map_fd;
	char	**first_line_str;
	int		**map;
	int		*first_line;

	*height = count_lines(map_file);
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		err_exit("open", 1);
	first_line_str = get_splitted_line(map_fd);
	if (!first_line_str)
	{
		close(map_fd);
		err_invalid_map(1);
	}
	*width = count_words(first_line_str);
	first_line = convert_to_int_array(first_line_str, *width);
	free_split(first_line_str);
	map = create_map(map_fd, *width, *height, first_line);
	close(map_fd);
	return (map);
}
