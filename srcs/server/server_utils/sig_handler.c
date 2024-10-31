/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:50 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/14 15:47:54 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sig_handler(int signal)
{
	static int				index = 0;
	static unsigned char	bits[8];
	char					c;

	if (signal == SIGUSR1)
	{
		bits[index] = 0;
		index++;
	}
	else if ( signal == SIGUSR2)
	{
		bits[index] = 1;
		index++;
	}
	if (index == 8)
	{
		c = ft_bits_to_char(bits);
		ft_printf("%c", 1, c);
		index = 0;
		ft_bzero(bits, 8);
	}
}
