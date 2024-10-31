/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:52:22 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/13 16:52:24 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_manage_client(t_client *data, char **argv)
{
	data->str = ft_strdup(argv[2]);
	if (!data->str)
		return (EXIT_FAILURE);
	if (ft_get_serv_pid(argv, &data->serv_pid) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_send_data(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
