/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstr_freestr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:45:58 by plang             #+#    #+#             */
/*   Updated: 2024/08/05 14:50:03 by plang            ###   ########.fr       */
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
