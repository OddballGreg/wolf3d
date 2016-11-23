#include <wolf.h>

void			move(t_env *env)
{
	if (env->player.t > 0)
		env->player.dir += TORQUE;
	else if (env->player.t < 0)
		env->player.dir -= TORQUE;
	while (env->player.dir > 360)
		env->player.dir -= 360;
	while (env->player.dir < 0)
		env->player.dir += 360;
	if (env->player.v > 0)
	{
		env->player.pos_y += VELOCITY * sin(env->player.dir);
		env->player.pos_x += VELOCITY * cos(env->player.dir);
	}
	else if (env->player.v < 0)
	{
		env->player.pos_y -= VELOCITY * sin(env->player.dir);
		env->player.pos_x -= VELOCITY * cos(env->player.dir);
	}
}
