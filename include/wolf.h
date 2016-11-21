#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h> //DEBUG PURPOSES ONLY


# define FOV 45
# define HEIGHT 600
# define WIDTH 800

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

typedef struct			s_players
{
	float				x;
	float				y;
	float				dir;
	float				v; //velocity
	float				t; //torque
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
	t_player			player;
}						t_env;

/*wolf.c*/
void    	init(t_env *env, char *filename);
int			safe_exit(void *e);
int			key_press(int key, void *e);
int			key_release(int key, void *e);
int			run(void *e);
void		draw(t_env *e);
void		put_pixel(t_env *env, int x, int y, unsigned int colour);
void		move(t_env *env);

/*hooks.c*/
void		ps_fw(void *env);
void		ps_bw(void *env);
void		ps_l(void *env);
void		ps_r(void *env);
void		ps_esc(void *env);

#endif
