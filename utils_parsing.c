/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:33:53 by matt              #+#    #+#             */
/*   Updated: 2022/02/26 15:32:20 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == (char)c))
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int	ft_size_col2(char **str, int p)
{
	int	j;

	j = 0;
	if (!str[j][p])
		return (0);
	while (str[j] && str[j][p])
		j++;
	return (j);
}

int	ft_size_row2(char **str, int p)
{
	int	i;

	i = 0;
	if (!str[p][i])
		return (0);
	while (str[p] && str[p][i])
		i++;
	return (i);
}

int	ft_size_row(char **str)
{
	int	j;

	j = 0;
	if (!str[0])
		return (0);
	while (str[j])
		j++;
	return (j);
}

int	ft_size_col(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
