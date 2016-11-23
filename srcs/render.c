#include <wolf.h>

void			draw(t_env *env)
{
	int x = -1;
	while (++x < WIDTH) //This loop is what produces the red line across the screen.
		put_pixel(env, x, 12, 0xFF0000);


	/*
		Calculate direction of ray relative to position of player and camera coords
	*/

	env->camera.pos_x = 2 * x / double(WIDTH) - 1;
	env->ray.pos_x = env->player.pos_x;
	env->ray.pos_y = env->player.pos_y;
	env->ray.dir_x = env->player.dir_x + env->player.plane_x * env->camera.pos_x;
	env->ray.dir_y = env->player.dir_y + env->player.plane_y * env->camera.pos_x;


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