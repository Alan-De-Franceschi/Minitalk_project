/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:29:35 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/13 18:29:37 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send_data(t_client *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		ft_char_to_bits(data->str[i], data->bits);
		while (j < 8)
		{
			if (data->bits[j] == 0)
			{
				if (kill(data->serv_pid, SIGUSR1) == -1)
					return (EXIT_FAILURE);
			}
			else
			{
				if (kill(data->serv_pid, SIGUSR2) == -1)
					return (EXIT_FAILURE);
			}
			j++;
			usleep(100);
		}
		i++;
		ft_bzero(data->bits, 8);
	}
	return (EXIT_SUCCESS);
}
