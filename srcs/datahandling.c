/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datahandling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sallen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:35:15 by sallen            #+#    #+#             */
/*   Updated: 2016/11/29 10:35:17 by sallen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	readsize(t_env *e, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 1)
	{
		perror("Could not read map size!!!");
		exit(EXIT_FAILURE);
	}
	size = ft_strsplittoint(line, ' ');
	e->map.sizex = size[0];
	e->map.sizey = size[1];
}

void	readmap(t_env *e, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * e->map.sizex);
	if (worldmap == NULL)
	{
		perror("Could not read map!!!");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	e->map.map = worldmap;
}

void	readfile(t_env *e, char *input)
{
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(input, O_RDONLY)) == -1)
	{
		perror("Map missing!!!");
		exit(EXIT_FAILURE);
	}
	readsize(e, fd);
	readmap(e, fd);
	close(fd);
}
