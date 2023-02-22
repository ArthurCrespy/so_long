/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:02 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/22 21:15:14 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *string, int c)
{
	char	*str;

	str = (char *)string;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	if ((size != 0 && nmemb != 0) && ((nmemb * size) / size != nmemb))
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		ft_exit("Error: Malloc failed\n", 1);
	while (i < nmemb * size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}
