/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:38:21 by yismaail          #+#    #+#             */
/*   Updated: 2022/11/19 23:37:50 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(char *p)
{
	free(p);
	return (NULL);
}

char	*ft_strjoin(char *old_str, char *current_str)
{
	size_t		arr[2];
	char		*new_str;

	if (!old_str)
	{
		old_str = malloc(1 * sizeof(char));
		old_str[0] = '\0';
	}
	if (!old_str || !current_str)
		return (ft_free(old_str));
	new_str = malloc(ft_strlen(old_str) + ft_strlen(current_str) + 1);
	if (!new_str)
		return (NULL);
	arr[0] = -1;
	if (old_str)
		while (old_str[++arr[0]] != '\0')
			new_str[arr[0]] = old_str[arr[0]];
	arr[1] = 0;
	while (current_str[arr[1]] != '\0')
		new_str[arr[0]++] = current_str[arr[1]++];
	new_str[ft_strlen(old_str) + ft_strlen(current_str)] = '\0';
	free(old_str);
	return (new_str);
}

char	*ft_get_our_line(char *read_4m_left)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!read_4m_left[i])
		return (NULL);
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	new_str = malloc((i + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	if (read_4m_left[i] == '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_new_str(char *read_4m_left)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	if (!read_4m_left[i])
	{
		free(read_4m_left);
		return (NULL);
	}
	new_line = malloc((ft_strlen(read_4m_left) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (read_4m_left[i])
		new_line[j++] = read_4m_left[i++];
	new_line[j] = '\0';
	free(read_4m_left);
	return (new_line);
}
