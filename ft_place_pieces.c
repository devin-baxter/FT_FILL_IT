/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:34:27 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/21 15:34:28 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_place_one(char **map, int **crds, int *c, char l)
{
	PIECE_MACRO2;
	while (a < 4)
	{
		cx = crds[a][0];
		cy = crds[a][1];
		map[c[0] + cx][c[1] + cy] = l;
		a++;
	}
}

static void		ft_remove_piece(char **map, int **crds, int *c)
{
	PIECE_MACRO2;
	while (a < 4)
	{
		cx = crds[a][0];
		cy = crds[a][1];
		map[c[0] + cx][c[1] + cy] = '.';
		a++;
	}
}

static int		ft_can_place(char **map, int **crds, int *c)
{
	PIECE_MACRO2;
	while (a < 4)
	{
		cx = crds[a][0];
		cy = crds[a][1];
		if (c[0] + cx < c[2] && c[1] + cy < c[2])
		{
			if (map[c[0] + cx][c[1] + cy] != '.')
				return (0);
		}
		else
			return (0);
		a++;
	}
	return (1);
}

static int		ft_place(char ***coords, char **map, int box_num, int size)
{
	PIECE_MACRO;
	crds = ft_getpiece(coords[box_num]);
	while (++x < size)
	{
		y = -1;
		while (++y < size)
		{
			CURRENT_MACRO;
			if (ft_can_place(map, crds, current) == 1 && coords[box_num + 1])
			{
				ft_place_one(map, crds, current, l);
				if (ft_place(coords, map, box_num + 1, size))
					return (1);
				ft_remove_piece(map, crds, current);
			}
			else if (ft_can_place(map, crds, current) == 1)
			{
				ft_place_one(map, crds, current, l);
				return (1);
			}
		}
	}
	return (0);
}

void			ft_placer(char ***coords, int piece_count)
{
	int		b;
	int		i;
	char	**map;
	int		size;

	b = 0;
	size = ft_sqrt_up(piece_count);
	while (!b)
	{
		map = ft_make_map(size);
		b = ft_place(coords, map, 0, size);
		if (b)
			ft_print_map(map);
		i = -1;
		while (++i < size)
			ft_strdel(&map[i]);
		size++;
	}
}
