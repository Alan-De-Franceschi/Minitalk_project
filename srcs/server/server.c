/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:04:27 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/10 17:04:29 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_printf("minitalk: server pid: %d\n", 1, pid);
	ft_set_sigaction();
	while (1)
	{
		continue ;
	}
	return (0);
}
