/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:51:04 by llapage           #+#    #+#             */
/*   Updated: 2018/10/23 13:51:57 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve(t_map *map, t_list *list)
{
	t_tetra		*tetra;
	int			height;
	int			width;

	if (list == NULL)
		return (1);
	height = 0;
	tetra = (t_tetra *)list->content;
	while (height < map->side_length - tetra->height + 1)
	{
		width = 0;
		while (width < map->side_length - tetra->width + 1)
		{
			if (check_if_placeable(tetra, map, width, height))
			{
				if (solve(map, list->next))
					return (1);
				width++;
			}
		}
		height++;
	}
	return (0);
}

int		calc_side_length(int nb)
{
	int		size;

	size = 2;
	while (size * size < nb)
		size++;
	return (size);
}

t_map	*algo(t_list *list)
{
	t_map	*map;
	int		side_length;

	side_length = calc_side_length(ft_lstcount(list) * 4);
	map = new_map(side_length);
	while (!solve(map, list))
	{
		side_length++;
		map = new_map(side_length);
	}
	return (map);
}
