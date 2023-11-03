/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:34:01 by Manny             #+#    #+#             */
/*   Updated: 2023/11/03 15:24:29 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Sets the color of a specific pixel in an image.
 * 1. Calculates the index of the pixel in the image data array:
 *    - Converts the line length from bytes to pixels by dividing by 4.
 *    - Computes the starting index of the specified row (y) by multiplying
 *      the row number by the number of pixels per line.
 *    - Adds the column number (x) to get the final pixel index.
 * 2. Sets the color of the specified pixel to the provided color value. */
void	set_image_pixel(t_img *img, int x, int y, int color)
{
	int	pixel;

	pixel = y * (img->line_len / 4) + x;
	img->addr[pixel] = color;
}
