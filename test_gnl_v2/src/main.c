/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:21:32 by vkuksa            #+#    #+#             */
/*   Updated: 2017/12/10 21:21:37 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.tmp_dir/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

mode_t mode = S_IRUSR | S_IWUSR;



void	free_line(char **line)
{
	free(*line);
	*line = NULL;
}



int		main(int ac, char **av)
{

	int		fd;
	int		fd_res;
	int		times;
	int		i;

	int		gnl_ret;
	char	*line = NULL;

	char	testfile_path[200];
	char	resfile_path[200];

	if (ac < 2 && ac > 3)
	{
		printf("%s\n", "Usage: ./test_gnl [name of test] [times to be read, if abscent or 0 - reads til the EOF]");
		return (0);
	}

	bzero(testfile_path, 200);
	strcat(testfile_path, "./tests/");
	strcat(testfile_path, av[1]);
	strcat(resfile_path, "./.tmp_dir/");
	strcat(resfile_path, av[1]);
	strcat(resfile_path, "_res");

	times = 0;
	if (av[2])
	{
		times = atoi(av[2]);
	}

	if (!av[3])
		fd = open(testfile_path, O_RDONLY);
	else
		fd = 0;
	fd_res = open(resfile_path,  O_RDWR | O_CREAT | O_APPEND, mode);
	if (times == 0)
	{
		while ((gnl_ret = get_next_line(fd, &line)) > 0)
		{
			if (gnl_ret > 0)
			{
				write(fd_res, line, strlen(line));
				free_line(&line);
			}
		}
	}
	else
	{
		i = 0;
		while (i < times && (gnl_ret = get_next_line(fd, &line)) >= 0)
		{
			if (gnl_ret > 0)
			{
				write(fd_res, line, strlen(line));
				free_line(&line);
			}
			i++;
		}
		if (gnl_ret < 0)
			printf("%s\n", "gnl return == -1");
	}
	// printf("gnl_ret: %d\n", gnl_ret);

	close(fd);
	close(fd_res);

	//system("leaks test_gnl");
	system("if [[ $(leaks test_gnl | grep \" leaked \") = \"Process \"*\": 0 leaks for 0 total leaked bytes.\" ]];\nthen echo $(tput setaf 2)\"No Memory Leaks\"$(tput sgr0)\nelse echo $(tput setaf 1)\"Memory Leaks Detected\"$(tput sgr0)\nleaks test_gnl | grep \" leaked \"\nfi");
	return (0);
}
