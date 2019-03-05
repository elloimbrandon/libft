/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:23:28 by brfeltz           #+#    #+#             */
/*   Updated: 2019/03/04 14:02:01 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_place_words(char const *s, char c, int *index)
{
	int		i;
	char	*word;
	int		start;

	i = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	start = *index;
	while (s[*index] != c && s[*index])
		(*index)++;
	if (!(word = ft_strnew(*index - start)))
		return (NULL);
	while (start < *index)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**sentence;
	int		i;
	int		count;
	int		k;

	k = 0;
	count = 0;
	i = 0;
	if (s && c)
		while (s[i++])
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				count++;
	i = 0;
	if (!(sentence = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	if (sentence)
		while (i < count)
			sentence[i++] = ft_place_words((char*)s, c, &k);
	sentence[i] = 0;
	return (sentence);
}
