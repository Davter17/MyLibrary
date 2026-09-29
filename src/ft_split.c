/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:48 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/01/14 17:02:50 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_result(char **result, size_t count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_alloc_word(char const *s, char c, size_t *i)
{
	char	*word;
	size_t	len;
	size_t	j;

	len = 0;
	while (s[*i + len] && s[*i + len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[*i + j];
		j++;
	}
	word[j] = '\0';
	*i += len;
	return (word);
}

static char	**ft_split_parse(char const *s, char c, char **r, size_t w)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (k < w)
	{
		while (s[i] == c)
			i++;
		r[k] = ft_alloc_word(s, c, &i);
		if (!r[k])
			return (ft_free_result(r, k));
		k++;
	}
	r[k] = NULL;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (ft_split_parse(s, c, result, words));
}
