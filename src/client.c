/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:49:26 by plang             #+#    #+#             */
/*   Updated: 2024/03/18 14:59:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
	int	pid;
	int	i;

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
	}
	else
	{
		ft_printf("%s\n", "Error: Incorrect amount of arguments");
		return (0);
	}
}
