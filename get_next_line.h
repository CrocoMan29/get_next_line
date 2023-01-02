/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:05:13 by yismaail          #+#    #+#             */
/*   Updated: 2022/11/19 23:32:37 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *read_4m_left);
char	*ft_strchr(char *str, int symbole);
char	*ft_strjoin(char *old_str, char *current_str);
size_t	ft_strlen(char *str);
char	*ft_get_our_line(char *read_4m_left);
char	*ft_new_str(char *read_4m_left);
char	*ft_free(char *p);

#endif