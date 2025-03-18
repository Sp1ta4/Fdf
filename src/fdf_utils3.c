/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:03:10 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/18 11:40:52 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_print_model(void)
{
	char	*msg1;
	char	*msg2;

	msg1 = "Error: Insufficient arguments.\n";
	msg2 = "Usage: ./fdf *.fdf\n";
	ft_putstr_fd(msg1, 2);
	ft_putstr_fd(msg2, 2);
	exit(2);
}
void	exit_invalid_file(void)
{
	char	*msg1;

	msg1 = "Error: your file need to be *.fdf\n";
	ft_putstr_fd(msg1, 2);
	exit(2);
}