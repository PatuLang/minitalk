/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:49:22 by plang             #+#    #+#             */
/*   Updated: 2024/03/21 13:58:46 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_append_free(char *text_str, char *str)
{
	char	*temp;

	temp = ft_strjoin(text_str, str);
	if (!temp)
	{
		free(text_str);
		ft_putstr_fd("Malloc failed in strjoin\n", 2);
		exit(1);
	}
	free(text_str);
	return (temp);
}

char	*joining_chars(char *text, char c)
{
	char	add_chr[2];
	char	*full_message;

	if (!text)
	{
		ft_putstr_fd("Malloc failed in strdup\n", 2);
		exit(1);
	}
	add_chr[0] = c;
	add_chr[1] = '\0';
	full_message = ft_append_free(text, add_chr);
	return (full_message);
}

void	signal_handler(int x)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static char				*text;

	if (!text)
		text = ft_strdup("");
	if (x == 1)
		c += 1 << i;
	else
		c += 0 << i;
	i++;
	if (i == 8)
	{
		text = joining_chars(text, c);
		if (c == '\0')
		{
			ft_printf("Client: %s\n", text);
			free(text);
			text = NULL;
		}
		i = 0;
		c = 0;
	}
}

void	signal_controller(int signal)
{
	if (signal == SIGUSR1)
		signal_handler(1);
	else
		signal_handler(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server running, PID: %d\n", pid);
	signal(SIGUSR1, signal_controller);
	signal(SIGUSR2, signal_controller);
	while (1)
	{
		pause();
	}
	return (0);
}
