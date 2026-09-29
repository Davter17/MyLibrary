/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:16:53 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/05 12:41:13 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_and_replace(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (free(s1), NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (free(s1), NULL);
	len1 = -1;
	while (s1[++len1])
		new_str[len1] = s1[len1];
	len2 = -1;
	while (s2[++len2])
		new_str[len1 + len2] = s2[len2];
	new_str[len1 + len2] = '\0';
	return (free(s1), new_str);
}
