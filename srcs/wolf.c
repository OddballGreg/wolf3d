#include <wolf.h>

int				main(int argc, char **argv)
{
	t_env		env;

	if (argc < 2)
		ft_puterror("Please pass a valid mapfile as an arguement.");
	env.mlx = mlx_init();
	init(&env, argv[1]);
	env.player.x = 0; //Db
	env.player.y = 0; //db
	env.player.dir = 0; //db
	mlx_do_key_autorepeatoff(env.mlx);
	mlx_hook(env.win, 2, 1, &key_press, (void *)&env);
	mlx_hook(env.win, 3, 2, &key_release, (void *)&env);
	mlx_hook(env.win, 17, 0L, safe_exit, (void *)&env);
	mlx_loop_hook(env.mlx, run, (void *)&env);
	mlx_loop(env.mlx);
}

int				run(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	move(env);
	draw(env);
	return (0);
}

void			move(t_env *env)
{
	if (env->player.v > 0)
		env->player.y += 0.5;
	else if (env->player.v < 0)
		env->player.y -= 0.5;
	if (env->player.t > 0)
		env->player.dir += 0.5;
	else if (env->player.t < 0)
		env->player.dir -= 0.5;
	while (env->player.dir > 360)
		env->player.dir -= 360;
	while (env->player.dir < 0)
		env->player.dir += 360;
}

void			draw(t_env *env)
{
	int x = -1;
	while (++x < WIDTH)
		put_pixel(env, x, 12, 0xFF0000);
	put_pixel(env, 13, 12, 0xFF0000);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}

void			put_pixel(t_env *env, int x, int y, unsigned int colour)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	
	r = (colour & 0xFF0000) >> 16;
	g = (colour & 0x00FF00) >> 8;
	b = (colour & 0x0000FF);
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{ 
		env->imgptr[((y * WIDTH * env->bpp) >> 3) 
			+ ((env->bpp >> 3) * x)] = b;
		env->imgptr[((y * WIDTH * env->bpp) >> 3) 
			+ ((env->bpp >> 3) * x) + 1] = g;
		env->imgptr[((y * WIDTH * env->bpp) >> 3) 
			+ ((env->bpp >> 3) * x) + 2] = r;
	}
}

int 			key_press(int key, void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (key == KEY_UP)
		env->player.v = 0.5;
	else if (key == KEY_DOWN)
		env->player.v = -0.5;
	else if (key == KEY_LEFT)
		env->player.t = -0.5;
	else if (key == KEY_RIGHT)
		env->player.t = 0.5;
	else if (key == KEY_ESC)
		safe_exit(e);
	printf("x: %f, y: %f, dir: %f\n", env->player.x, env->player.y, env->player.dir);
	return (0);
}

int 			key_release(int key, void *e)
{
	t_env	*env;

	env = (t_env *)e;
	if (key == KEY_UP || key == KEY_DOWN)
		env->player.v = 0;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		env->player.t = 0;
	printf("x: %f, y: %f, dir: %f\n", env->player.x, env->player.y, env->player.dir);
	return (0);
}

void			init(t_env *env, char *filename)
{
	int			fd;
	int			x;
	char		*line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_puterror("Cannot open file.");
	env->maph = -1;
	while (get_next_line(fd, &line) != 0)
	{
		x = -1;
		env->maph++;
		while (line[++x] != '\0')
		{
			env->map[env->maph][x] = line[x];
			if (env->map[env->maph][x] == '*')
			{
				env->player.x = x;
				env->player.y = env->maph;
			}
			if (env->mapw < x)
				env->mapw = x;
		}
	}
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->imgptr = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
}

int			safe_exit(void *e)
{
	t_env	*env;

	env = (t_env *)e;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}