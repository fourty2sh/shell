/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:23:52 by cnkosi            #+#    #+#             */
/*   Updated: 2017/06/08 04:10:11 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void*)malloc(sizeof(void) * size);
	if (!memory || size == 0)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
