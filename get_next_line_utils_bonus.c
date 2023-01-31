/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:46:14 by esobrinh          #+#    #+#             */
/*   Updated: 2022/10/25 15:49:14 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*p;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char *)malloc(len1 + len2 + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		p[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
	{
		p[len1] = s2[i];
		len1++;
	}
	p[len1] = '\0';
	free ((char *)s1);
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	while (str != NULL && (*str != '\0') && (*str != (unsigned char)c))
		str++;
	if (str && *str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
