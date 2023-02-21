/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:02 by acrespy           #+#    #+#             */
/*   Updated: 2023/02/21 22:15:56 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(char *s, int status)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(status);
}

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
		return (NULL);
	while (i < nmemb * size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i_s1;
	int		i_s2;
	char	*result;

	i_s1 = 0;
	i_s2 = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (s1 && s1[i_s1] && s1[0] != '\0')
	{
		while (s1[i_s1])
		{
			result[i_s1] = s1[i_s1];
			i_s1++;
		}
	}
	while (s2 && s2[i_s2] && s2[0] != '\0')
	{
		result[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	result[i_s1 + i_s2] = '\0';
	return (result);
}
