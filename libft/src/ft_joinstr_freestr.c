/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstr_freestr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:45:58 by plang             #+#    #+#             */
/*   Updated: 2024/03/15 17:00:32 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_joinstr_freestr(char *joined_str, char *str)
{
	char	*temp;

	temp = ft_strjoin(joined_str, str);
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	free(joined_str);
	return (temp);
}
