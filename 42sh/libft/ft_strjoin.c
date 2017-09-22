/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:48:30 by cnkosi            #+#    #+#             */
/*   Updated: 2017/07/22 11:44:57 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*strnew;

	if (!s1 || !s2)
		return (NULL);
	strnew = NULL;
	len = ft_strlen(s1) + ft_strlen(s2);
	strnew = (char *)malloc(sizeof(char *) * (len + 1));
	if (strnew == NULL)
		return (NULL);
	ft_bzero((void*)strnew, len);
	ft_strcpy(strnew, s1);
	ft_strcat(strnew, s2);
	return (strnew);
}
