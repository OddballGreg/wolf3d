#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h> //DEBUG PURPOSES ONLY


# define FOV 45
# define HEIGHT 400
# define WIDTH 600

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				map[1024][1024];
	int					maph;
	int					mapw;
	t_point				player;
	int					vdir;
}						t_env;

/*wolf.c*/
void    	init(t_env *env, char *filename);
int			safe_exit(void *env);

#endif
