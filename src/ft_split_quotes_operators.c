/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes_operators.c                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr> */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:00:00 by mario             #+#    #+#             */
/*   Updated: 2026/09/29 00:00:00 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	update_operator_state(char c, int *quote, int *protected)
{
	if (c == 0x1F)
		*protected = !*protected;
	else if (!*protected && (c == '\'' || c == '"'))
	{
		if (*quote == 0)
			*quote = c;
		else if (*quote == c)
			*quote = 0;
	}
}

static size_t	operator_extra(char const *s, size_t *i)
{
	if ((s[*i] == '<' || s[*i] == '>') && s[*i + 1] == s[*i])
	{
		(*i)++;
		return (3);
	}
	return (2);
}

static size_t	operator_length(char const *s)
{
	size_t	i;
	size_t	len;
	int		quote;
	int		protected;

	i = 0;
	len = 0;
	quote = 0;
	protected = 0;
	while (s[i])
	{
		update_operator_state(s[i], &quote, &protected);
		if (!quote && !protected
			&& (s[i] == '|' || s[i] == '<' || s[i] == '>'))
			len += operator_extra(s, &i);
		len++;
		i++;
	}
	return (len);
}

static void	copy_operator(char *dst, size_t *j, char const *s, size_t *i)
{
	dst[(*j)++] = ' ';
	dst[(*j)++] = s[*i];
	if ((s[*i] == '<' || s[*i] == '>') && s[*i + 1] == s[*i])
		dst[(*j)++] = s[++(*i)];
	dst[(*j)++] = ' ';
}

char	*normalize_shell_operators(char const *s)
{
	size_t	i;
	size_t	j;
	int		quote;
	int		protected;
	char	*normalized;

	normalized = ft_calloc(operator_length(s) + 1, sizeof(char));
	if (!normalized)
		return (NULL);
	i = 0;
	j = 0;
	quote = 0;
	protected = 0;
	while (s[i])
	{
		update_operator_state(s[i], &quote, &protected);
		if (!quote && !protected
			&& (s[i] == '|' || s[i] == '<' || s[i] == '>'))
			copy_operator(normalized, &j, s, &i);
		else
			normalized[j++] = s[i];
		i++;
	}
	return (normalized);
}
