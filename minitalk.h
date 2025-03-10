/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:49:18 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* ************************************************************************** */
/*                                Librarys                                    */
/* ************************************************************************** */

# include "./libft/libft.h"
# include <signal.h>

/* ************************************************************************** */
/*                                 Server                                     */
/* ************************************************************************** */

char	*ft_append_free(char *text_str, char *str);
char	*joining_chars(char *text, char c);
void	signal_handler(int x);
void	signal_controller(int signal);

/* ************************************************************************** */
/*                                 Client                                     */
/* ************************************************************************** */

void	signal_sender(int pid, unsigned char c);

#endif