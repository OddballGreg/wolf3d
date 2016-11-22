#include <wolf.h>

void			move(t_env *env)
{
	if (env->player.v > 0)
		env->player.y += VELOCITY;
	else if (env->player.v < 0)
		env->player.y -= VELOCITY;
	if (env->player.t > 0)
		env->player.dir += TORQUE;
	else if (env->player.t < 0)
		env->player.dir -= TORQUE;
	while (env->player.dir > 360)
		env->player.dir -= 360;
	while (env->player.dir < 0)
		env->player.dir += 360;
}