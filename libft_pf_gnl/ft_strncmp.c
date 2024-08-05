/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:08 by htharrau          #+#    #+#             */
/*   Updated: 2024/07/21 15:16:00 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pf_gnl.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && (i < (n - 1)))
			i++;
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	}
}
