/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:03:10 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/14 14:03:30 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_print_model(void)
{
	const char	*msg1;
	const char	*msg2;

	msg1 = "Error: Insufficient arguments.\n";
	msg2 = "Usage: ./fdf *.fdf\n";
	write(2, msg1, ft_strlen(msg1));
	write(2, msg2, ft_strlen(msg2));
	exit(2);
}