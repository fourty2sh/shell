/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:45:55 by cnkosi            #+#    #+#             */
/*   Updated: 2017/09/19 10:21:51 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isempty(char *s)
{
	int		i;

	i = 0;
	if (ft_isspace(s[i]))
		while (ft_isspace(s[i]))
			i++;
	return ((i == (int)ft_strlen(s)) ? 1 : 0);
}

