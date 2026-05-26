/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:41:56 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 17:53:40 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_word_size(const char *s, char c)
{
	int	size;

	size = 0;
	while ((*s != c || size == 0) && *s != 0)
	{
		if (*s != c)
		{
			size++;
		}
		s++;
	}
	if (size > 0)
	{
		size++;
	}
	return (size);
}

static int	get_word_count(const char *s, char c)
{
	int	count;
	int	size;

	size = 0;
	count = 0;
	while (1 == 1)
	{
		if ((*s == c || *s == 0) && size > 0)
		{
			size = 0;
			count++;
		}
		else if (*s != c)
		{
			size++;
		}
		if (*s == 0)
		{
			break ;
		}
		s++;
	}
	return (count);
}

static char	*alloc_word(const char *s, char c)
{
	int		char_count;
	char	*result;

	char_count = get_word_size(s, c);
	if (char_count > 0)
	{
		result = malloc(char_count);
	}
	else
	{
		return (NULL);
	}
	result[char_count - 1] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		char_count;

	result = (malloc((get_word_count(s, c) + 1) * sizeof(char *)));
	word_count = 0;
	result[word_count] = alloc_word(s, c);
	char_count = 0;
	while (*s != 0)
	{
		if (*s == c && char_count > 0)
		{
			word_count++;
			result[word_count] = alloc_word(s, c);
			char_count = 0;
		}
		else if (*s != c)
			result[word_count][char_count++] = *s;
		s++;
	}
	if (char_count > 0)
		word_count++;
	result[word_count] = NULL;
	return (result);
}

/* int	main(void)
{
	// char *str = "these aren't the droids you're looking for";
	// char **lst = ft_split(str, ' ');
	char **lst = ft_split("  tripouille  42  ", ' ');
	int i = 0;
	while (lst[i] != NULL)
	{
		printf("%s\n", lst[i]);
		free(lst[i]);
		i++;
	}
	free(lst);
} */