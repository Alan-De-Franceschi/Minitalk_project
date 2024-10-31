/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:55:31 by ade-fran          #+#    #+#             */
/*   Updated: 2024/05/10 16:55:33 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h" 
# include <sys/types.h>
# include <signal.h>

/* ************************************************************************** */
/*                                  Client                                    */
/* ************************************************************************** */

typedef struct	s_client
{
	pid_t 			serv_pid;
	char			*str;
	unsigned char	bits[8];
}	t_client;

void	ft_init_client_data(t_client *data);
void	ft_exit_client(t_client *data);

int		ft_manage_client(t_client *data, char **argv);
pid_t	ft_get_serv_pid(char **argv, pid_t *serv_pid);
void	ft_char_to_bits(char c, unsigned char bits[8]);
int		ft_send_data(t_client *data);

enum	e_errors
{
	FEW_ARGS = 0,
	MANY_ARGS = 1,
	PID_ERR = 2,
};

void	ft_client_errors(int error);

/* ************************************************************************** */
/*                                  Server                                    */
/* ************************************************************************** */

void	ft_set_sigaction(void);
void	ft_sig_handler(int signal);
int		ft_bits_to_char(unsigned char bits[8]);

#endif
