/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:09:49 by plang             #+#    #+#             */
/*   Updated: 2024/03/20 16:23:00 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	signal_reciver(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Server: Roger!\n");
		exit(0);
	}
}

void	signal_sender(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **av)
{
	struct sigaction	sender;
	int					pid;
	int					i;

	sender.__sigaction_u.__sa_handler = signal_reciver;
	sigemptyset(&sender.sa_mask);
	sigaction(SIGUSR1, &sender, NULL);
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			signal_sender(pid, av[2][i]);
			i++;
		}
		signal_sender(pid, '\0');
		pause();
	}
	else
	{
		ft_printf("%s\n", "Error: Incorrect amount of arguments");
		return (0);
	}
}
