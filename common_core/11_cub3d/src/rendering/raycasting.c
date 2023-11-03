/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:39:12 by Manny             #+#    #+#             */
/*   Updated: 2023/11/03 16:40:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Initializes raycasting information for a single ray.
 * 1. Resets previous ray data using `init_ray`.
 * 2. Calculates the x-coordinate of the ray on the camera plane.
 * (left = -1, center = 0, right = 1)
 * 3. Computes the ray direction based on the player's direction and plane.
 * 4. Stores the player's map position.
 * 5. Calculates distances to the next x and y sides of a map grid cell. */
static void	init_raycasting_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

/* Initializes the DDA algorithm variables for raycasting.
 * 1. Checks the ray direction along the x-axis:
 * - If the direction is negative, sets `step_x` to -1
 * and calculates the initial `side_dist_x`.
 * - If the direction is positive, sets `step_x` to 1
 * and calculates the  initial `side_dist_x`, but using `map_x + 1.0`.
 * 2. Same process for the y-axis, setting `step_y` and `side_dist_y`. */
static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

/* Performs DDA algorithm to find wall intersections.
 * 1. Initializes hit flag to 0, which tracks if a wall is hit.
 * 2. Loops until a wall is hit:
 *    a. Compares side distances to decide the next grid to check.
 *    b. If ray's x-side distance is smaller, updates x-side distance,
 *       moves one step in the x-direction, and sets side flag to 0 (x-side hit).
 *    c. Otherwise, updates y-side distance, moves one step in the y-direction, 
 *       and sets side flag to 1 (y-side hit).
 *    d. Checks if the ray moves out of bounds; if yes, breaks out of the loop.
 *    e. Checks if a wall is hit by checking the map grid value; 
 *       if yes, sets hit flag to 1. */
static void	dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > data->map_info.height - 0.25
			|| ray->map_x > data->map_info.width - 1.25)
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

/* Computes wall slice height and where to draw it on screen.
 * 1. Determines wall distance based on ray hit side. (side = 0 x-side hit)
 * 2. Calculates wall slice height based on window height and wall distance.
 * 3. Determines where to start and end drawing the wall slice on screen.
 * 4. Calculates horizontal wall hit position for texture mapping. */
static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(data->win_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycasting(t_player *player, t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	ray = data->ray;
	while (x < data->win_width)
	{
		init_raycasting_info(x, &ray, player);
		set_dda(&ray, player);
		dda(data, &ray);
		calculate_line_height(&ray, data, player);
		update_texels(data, &data->tex_info, &ray, x);
		x++;
	}
	return (SUCCESS);
}
