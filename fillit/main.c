/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 15:32:12 by llapage           #+#    #+#             */
/*   Updated: 2018/10/23 14:34:25 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list *list;
	t_map *map;

	if (argc != 2)
	{
		ft_putstr("usage : fillit file_name");
		ft_putchar('\n');
		return (1);
	}
	if ((list = read_tetra(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error");
		return (1);
	}
	map = algo(list);
	print_map(map);
	return (0);
}
