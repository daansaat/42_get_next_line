/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 12:33:33 by dsaat         #+#    #+#                 */
/*   Updated: 2021/12/13 12:33:34 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char *save, char *buff);
char	*ft_substr(char *save, unsigned int start, size_t len, int extra);

#endif
