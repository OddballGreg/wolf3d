#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h> //DEBUG PURPOSES ONLY


# define FOV 45
# define HFOV FOV / 2
# define HEIGHT 600
# define WIDTH 800

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

# define TORQUE 0.5
# define VELOCITY 0.5

typedef struct			s_player
{
    double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				v; //velocity
	double				t; //torque
}						t_player;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*imgptr;
	int					bpp;
	int					sl;
	int					endian;
	char				map[1024][1024];
	int					maph;
	int					mapw;
	s_player			player;
}						t_env;

/*wolf.c*/
int			run(void *e);

/*game.c*/
void		move(t_env *env);

/*datahandling.c*/
void    	init(t_env *env, char *filename);
int			safe_exit(void *e);
void		set_game(t_env *env);

/*keyhooks.c*/
int			key_press(int key, void *e);
int			key_release(int key, void *e);

/*render.c*/
void		draw(t_env *e);
void		put_pixel(t_env *env, int x, int y, unsigned int colour);

#endif
