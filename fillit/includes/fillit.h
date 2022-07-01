/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:11:19 by llapage           #+#    #+#             */
/*   Updated: 2018/10/23 14:34:54 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct	s_tetra
{
	char		**table;
	int			width;
	int			height;
	char		letter;
}				t_tetra;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_map
{
	int			side_length;
	char		**table;
}				t_map;

t_list			*read_tetra(int fd);
t_coord			*new_coord(int x, int y);
t_tetra			*new_tetra(char **tetra_array, int width, int height,
char letter);
int				calc_size_length(int nb);
t_map			*new_map(int side_length);
t_map			*algo(t_list *list);
void			insert_tetra(t_tetra *tetra, t_map *map, t_coord *coord
, char letter);
void			print_map(t_map *map);

#endif
