/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:01:00 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/20 21:36:20 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	get_index(const char *s, char c, size_t size)
{
	size_t	i;

	if (!s || size == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (s[i] == c)
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

static void	shift_remainder(char *buff, size_t start, size_t size)
{
	ssize_t	i;

	i = -1;
	while (start + ++i < size)
		buff[i] = buff[start + i];
	ft_memset(&buff[i], 0, size - i);
}

static char	*append_buff(char *s1, char *s2, size_t size)
{
	ssize_t	i;
	size_t	s1_len;
	char	*new;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	new = malloc(s1_len + size + 1);
	if (!new)
		return (NULL);
	i = -1;
	while ((size_t)++i < s1_len && s1[i])
		new[i] = s1[i];
	i = -1;
	while ((size_t)++i < size && s2[i])
		new[s1_len + i] = s2[i];
	new[s1_len + i] = '\0';
	if (s1)
		free(s1);
	if (!ft_strlen(new))
		return (free(new), NULL);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buff[FD_SETSIZE][BUFFER_SIZE];
	int			ix;
	ssize_t		readbytes;
	char		*temp;

	temp = NULL;
	while (1)
	{
		ix = get_index(buff[fd], '\n', BUFFER_SIZE);
		if (ix > -1)
		{
			temp = append_buff(temp, buff[fd], ix + 1);
			shift_remainder(buff[fd], ix + 1, BUFFER_SIZE);
			return (temp);
		}
		temp = append_buff(temp, buff[fd], BUFFER_SIZE);
		ft_memset(buff[fd], 0, BUFFER_SIZE);
		readbytes = read(fd, buff[fd], BUFFER_SIZE);
		if (readbytes == 0)
			return (temp);
		if (readbytes < 0)
			return (NULL);
	}
}
