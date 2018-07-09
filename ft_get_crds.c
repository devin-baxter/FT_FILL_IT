/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_crds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:15:27 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/20 17:23:32 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_left(char **box)
{
	int x;
	int n;

	x = 0;
	n = 0;
	while (x < 4)
	{
		if (box[x][0] == '.')
			n++;
		else
			return (0);
		x++;
	}
	if (n == 4)
		return (1);
	return (0);
}

static int	ft_check_up(char **box)
{
	int y;
	int n;

	y = 0;
	n = 0;
	while (y < 4)
	{
		if (box[0][y] == '.')
			n++;
		else
			return (0);
		y++;
	}
	if (n == 4)
		return (1);
	return (0);
}

char		**ft_move_left(char **box)
{
	MOVE_X_Y;
	while (ft_check_left(box) == 1)
	{
		x = 0;
		while (x < 4)
		{
			y = -1;
			while (++y < 3)
				box[x][y] = box[x][y + 1];
			box[x++][y] = '.';
		}
	}
	while (ft_check_up(box) == 1)
	{
		y = 0;
		while (y < 4)
		{
			x = -1;
			while (++x < 3)
				box[x][y] = box[x + 1][y];
			box[x][y++] = '.';
		}
	}
	return (box);
}

static int	**ft_while_crds(char **box, int **crds, int x, int y)
{
	while (box[x][y])
	{
		if (box[x][y] == '#' && crds[0][0] < 0)
		{
			crds[0][0] = x;
			crds[0][1] = y++;
		}
		if (box[x][y] == '#' && crds[1][0] < 0)
		{
			crds[1][0] = x;
			crds[1][1] = y++;
		}
		if (box[x][y] == '#' && crds[2][0] < 0)
		{
			crds[2][0] = x;
			crds[2][1] = y++;
		}
		if (box[x][y] == '#' && crds[3][0] < 0)
		{
			crds[3][0] = x;
			crds[3][1] = y++;
		}
		y++;
	}
	return (crds);
}

int			**ft_getpiece(char **box)
{
	CRDS_MACRO;
	crds = (int **)malloc(sizeof(int *) * 4 + 1);
	while (++x < 4)
		crds[x] = (int *)malloc(sizeof(int) * 2 + 1);
	x = -1;
	while (++x < 4)
	{
		y = 0;
		while (y < 2)
			crds[x][y++] = -1;
	}
	x = 0;
	while (box[x])
	{
		y = 0;
		crds = ft_while_crds(box, crds, x, y);
		x++;
	}
	return (crds);
}
