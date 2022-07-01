/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:46:27 by llapage           #+#    #+#             */
/*   Updated: 2018/10/23 13:02:35 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*new_tetra(char **array, int width, int height, char value)
{
	t_tetra		*tetra;

	tetra = ft_memalloc(sizeof(t_tetra));
	tetra->table = array;
	tetra->width = width;
	tetra->height = height;
	tetra->letter = value;
	return (tetra);
}

t_coord		*new_coord(int x, int y)
{
	t_coord		*coord;

	coord = ft_memalloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}
