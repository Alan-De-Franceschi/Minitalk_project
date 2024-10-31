/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:44:46 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/10 17:44:47 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client_errors(int error)
{
	if (error == FEW_ARGS)
		ft_printf("minitalk: too few arguments", 2);
	if (error == MANY_ARGS)
		ft_printf("minitalk: too many arguments", 2);
	if (error == PID_ERR)
		ft_printf("minitalk: invalid server PID", 2);

}
