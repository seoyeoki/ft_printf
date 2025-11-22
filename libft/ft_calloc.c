/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:38:59 by seoykim           #+#    #+#             */
/*   Updated: 2025/04/24 23:54:53 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		msize;

	msize = nmemb * size;
	if (nmemb > 0 && size != msize / nmemb)
		return (NULL);
	ptr = malloc(msize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, msize);
	return (ptr);
}
