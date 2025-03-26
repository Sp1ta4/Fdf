/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:12:13 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/26 20:28:47 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_correct_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	return (ft_strncmp(&file[len - 4], ".fdf", 4) == 0);
}

int	valid_arguments(int argc, char **argv)
{
	if (argc != 2 || !argv)
		exit_print_model();
	if (!is_correct_file(argv[1]))
		exit_invalid_file();
	return (1);
}
