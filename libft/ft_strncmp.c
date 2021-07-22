/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:45:01 by akliek            #+#    #+#             */
/*   Updated: 2021/06/24 18:10:27 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] || (unsigned char)s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}
