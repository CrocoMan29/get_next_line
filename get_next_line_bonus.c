/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:25:53 by yismaail          #+#    #+#             */
/*   Updated: 2022/11/19 23:42:38 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_str(int fd, char *read_4m_left)
{
	char	*new_str;
	int		bytes_read;

	new_str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(read_4m_left, '\n') && bytes_read)
	{
		bytes_read = read(fd, new_str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_str);
			free(read_4m_left);
			new_str = NULL;
			read_4m_left = NULL;
			return (NULL);
		}
		new_str[bytes_read] = '\0';
		read_4m_left = ft_strjoin(read_4m_left, new_str);
	}
	free(new_str);
	return (read_4m_left);
}

char	*ft_strchr(char *str, int symbole)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	if (symbole == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] && str[i] != symbole)
		i++;
	if (str[i] == symbole)
		return ((char *)&str[i]);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*read_4m_left[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_4m_left[fd] = ft_read_str(fd, read_4m_left[fd]);
	if (!read_4m_left[fd])
		return (NULL);
	line = ft_get_our_line(read_4m_left[fd]);
	read_4m_left[fd] = ft_new_str(read_4m_left[fd]);
	return (line);
}
