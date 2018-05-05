/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:34:36 by aziabkin          #+#    #+#             */
/*   Updated: 2018/05/04 15:37:53 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h> //DELETE

static int			write_to_line(char **line, t_gnl *cur) /////
{
	char		*tmp;

	if (*(cur->str))
	{
		if (ft_strchr(cur->str, '\n'))
		{
			*line = ft_strsub(cur->str, 0, \
				ft_strchr(cur->str, '\n') - cur->str);
			// printf(" vfvf %s\n", ft_strchr(cur->str, '\n'));
			
			// printf(" %li\n", ft_strchr(cur->str, '\n') - cur->str);
			// printf("//// %s\n", *line);
			tmp = cur->str;
			cur->str = ft_strdup(cur->str + \
				(ft_strchr(cur->str, '\n') - cur->str) + 1);
			// printf(" 11%s\n", cur->str);
			// printf(" %li\n", ft_strchr(cur->str, '\n') - cur->str);
			ft_strdel(&tmp);
		}
		else
		{
			*line = cur->str;
			cur->str = ft_strnew(0);
		}
		return (1);
	}
	return (0);
}

static void			reader_and_save(int fd, char *buf, t_gnl *cur) //////
{
	int			bytes;
	char		*tmp;

	while (!(ft_strchr(cur->str, '\n')) \
		&& (bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = cur->str;
		buf[bytes] = '\0';
		cur->str = ft_strjoin(cur->str, buf);
		//printf("//// %s\n", cur->str);
		ft_strdel(&tmp);
	}
}

static t_gnl		*check_fd(t_gnl **lst, int fd)
{
	t_gnl			*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_gnl *)malloc(sizeof(*temp))))
		return (NULL);
	temp->str = ft_strnew(0);
	temp->fd = fd;
	temp->next = *lst;
	*lst = temp;
	return (temp);
}

int get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_gnl			*cur;
	static t_gnl	*lstsave;

	if (read(fd, buf, 0) < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	cur = check_fd(&lstsave, fd);
	reader_and_save(fd, buf, cur); ////
	return (write_to_line(line, cur)); //////
}

int main(int argc, char const **argv)
{
	char	*str = NULL;
	int		fd;
	int		fd2;
	int		fd3;

	if (argc >= 2)
 	{
 		if ((fd = open(argv[1], O_RDONLY)) == -1)
 		{
 			ft_putendl("error");
 			return (0);
 		}
 		if ((fd2 = open(argv[2], O_RDONLY)) == -1)
 		{
 			ft_putendl("error");
 			return (0);
 		}
 		if ((fd3 = open(argv[3], O_RDONLY)) == -1)
 		{
 			ft_putendl("error");
 			return (0);
 		}
 	// while (get_next_line(fd, &str) > 0)
 	// {
 	// 	printf("%s\n", str);
		// ft_strdel(&str);
 	// }
	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	get_next_line(fd2, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	get_next_line(fd3, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	get_next_line(fd2, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	get_next_line(fd, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	get_next_line(fd3, &str);
	printf("%s\n", str);
	ft_strdel(&str);

	system("leaks gnl");
}
 	return (0);
}
