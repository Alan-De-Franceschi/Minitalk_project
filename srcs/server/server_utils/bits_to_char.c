/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:42:52 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/14 15:42:53 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_bits_to_char(unsigned char bits[8])
{
	int	result;
	int	power;
	int	i;

	power = 1;
	i = 7;
	result = 0;
	while (i >= 0)
	{
		result += bits[i] * power;
		power *= 2;
		i--;
	}
	return (result);
}
