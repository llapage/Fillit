/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llapage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:15:17 by llapage           #+#    #+#             */
/*   Updated: 2018/10/22 20:43:59 by llapage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		first_last(char *str, t_coord *first, t_coord *last)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < first->y)
				first->y = i / 5;
			if (i / 5 > last->y)
				last->y = i / 5;
			if (i % 5 < first->x)
				first->x = i % 5;
			if (i % 5 > last->x)
				last->x = i % 5;
		}
		i++;
	}
}

t_tetra		*get_tetra(char *str, char letter)
{
	t_coord		*first;
	t_coord		*last;
	char		**table;
	int			i;
	t_tetra		*tetra;

	first = new_coord(3, 3);
	last = new_coord(0, 0);
	first_last(str, first, last);
	table = ft_memalloc(sizeof(char *) * (last->y - first->y + 1));
	i = 0;
	while (i < last->y - first->y + 1)
	{
		table[i] = ft_strnew(last->x - first->x + 1);
		ft_strncpy(table[i], str + (first->x) + (i + first->y) * 5,
last->x - first->x + 1);
		i++;
	}
	tetra = new_tetra(table, last->x - first->x + 1, last->y - first->y + 1,
letter);
	ft_memdel((void **)&first);
	ft_memdel((void **)&last);
	return (tetra);
}

/*
** Checks if the tetra has at least 6 links and is linked by at least one bloc
*/

int			check_links(char *str)
{
	int blocs;
	int i;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				blocs++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				blocs++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				blocs++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				blocs++;
		}
		i++;
	}
	if (blocs >= 6)
		return (0);
	return (1);
}

int			check_blocs(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (4);
	if (check_links(str) != 0)
		return (5);
	return (0);
}

/*
** Reads tetraminoes of 20-21 characters in the buffer
** Adds every tetraminoes in "t_tetra" list and in the linked list "t_list"
*/

t_list		*read_tetra(int fd)
{
	char	*buffer;
	int		count;
	t_list	*list;
	t_tetra	*tetra;
	char	letter;

	buffer = ft_strnew(21);
	list = NULL;
	letter = 'A';
	while ((count = read(fd, buffer, 21)) >= 20)
	{
		if (check_blocs(buffer, count) != 0
			|| (tetra = get_tetra(buffer, letter++)) == NULL || count != 0)
		{
			ft_memdel((void **)&buffer);
			return (0);
		}
		ft_lstadd(&list, ft_lstnew(tetra, sizeof(t_tetra)));
		ft_memdel((void **)&tetra);
	}
	ft_memdel((void **)&buffer);
	return (list);
}
