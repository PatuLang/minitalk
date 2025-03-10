/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:11:51 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

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

void	signal_handler(int signal, siginfo_t *info, void *param)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static char				*text;

	(void)param;
	if (!text)
		text = ft_strdup("");
	if (signal == SIGUSR1)
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
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("Server running, PID: %d\n", pid);
	sa.__sigaction_u.__sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
