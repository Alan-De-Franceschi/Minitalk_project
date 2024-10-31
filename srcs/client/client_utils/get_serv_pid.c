/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_serv_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:58:37 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/13 16:58:39 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_get_serv_pid(char **argv, pid_t *serv_pid)
{
	int 	err;

	err = 0;
	*serv_pid = ft_atoi(argv[1], &err);
	if (err)
		return (ft_client_errors(PID_ERR), EXIT_FAILURE);
	*serv_pid = ft_abs(*serv_pid);
	return (EXIT_SUCCESS);
}
