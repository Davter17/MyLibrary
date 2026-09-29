/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:37 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:02:38 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		result[i] = s2[i - s1_len];
		i++;
	}
	result[i] = '\0';
	return (result);
}
