/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:29:42 by ghavenga          #+#    #+#             */
/*   Updated: 2016/11/29 13:29:45 by ghavenga         ###   ########.fr       */
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
	MAP.sizex = size[0];
	MAP.sizey = size[1];
	free(size);
	free(line);
}

void	readmap(t_env *e, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * MAP.sizex);
	if (worldmap == NULL)
	{
		perror("Could not read map!!!");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
		free(line);
	}
	MAP.map = worldmap;
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
