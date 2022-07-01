/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:17:15 by llapage           #+#    #+#             */
/*   Updated: 2018/10/23 14:33:23 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*new_map(int side_length)
{
	t_map	*map;
	int		width;
	int		height;

	width = 0;
	height = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->table = (char **)ft_memalloc(sizeof(t_map) * side_length);
	map->side_length = side_length;
	while (height < side_length)
	{
		width = 0;
		map->table[height] = ft_strnew(map->side_length);
		while (width < side_length)
			map->table[height][width++] = '.';
		height++;
	}
	return (map);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->side_length)
	{
			ft_putstr(map->table[i]);
			i++;
	}
}

int		check_if_placeable(t_tetra *tetra, t_map *map, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < tetra->width)
	{
		while (j < tetra->height)
		{
			if (tetra->table[j][i] == '#' && map->table[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	insert_tetra(tetra, map, new_coord(x, y), tetra->letter);
	return (1);
}

void	insert_tetra(t_tetra *tetra, t_map *map, t_coord *coord, char letter)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < tetra->height)
	{
		i = 0;
		while (i < tetra->width)
		{
			if (tetra->table[j][i] == '#')
				map->table[coord->y + j][coord->x + i] = '#';
			i++;
		}
		j++;
	}
	ft_memdel((void**)coord);
}
