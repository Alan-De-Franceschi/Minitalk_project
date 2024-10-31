/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:55:04 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/10 16:55:07 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	t_client	data;

	ft_init_client_data(&data);
	if (argc < 3)
		ft_client_errors(FEW_ARGS);
	else if (argc > 3)
		ft_client_errors(MANY_ARGS);
	else
	{
		if (ft_manage_client(&data, argv) == EXIT_FAILURE)
			ft_exit_client(&data);
	}
	free(data.str);
	return (0);
}
