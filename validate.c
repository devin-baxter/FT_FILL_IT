/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:35:43 by pkumar            #+#    #+#             */
/*   Updated: 2018/06/10 18:35:44 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_first_part(char **str, int i, int v, int j)
{
	if (i == 0 && j == 0)
	{
		if (str[i + 1][j] == '#')
			v++;
		if (str[i][j + 1] == '#')
			v++;
	}
	if (i == 0 && j > 0)
	{
		if (str[i][j - 1] == '#')
			v++;
		if (str[i + 1][j] == '#')
			v++;
		if (j != 3)
			if (str[i][j + 1] == '#')
				v++;
	}
	return (v);
}

static int	ft_second_part(char **str, int i, int v, int j)
{
	if (i == 1 || i == 2)
	{
		if (str[i - 1][j] == '#')
			v++;
		if (str[i + 1][j] == '#')
			v++;
		if (j != 0)
			if (str[i][j - 1] == '#')
				v++;
		if (j != 3)
			if (str[i][j + 1] == '#')
				v++;
	}
	return (v);
}

static int	ft_last_part(char **str, int i, int v, int j)
{
	if (i == 3)
	{
		if (str[i - 1][j] == '#')
			v++;
		if (j != 0)
			if (str[i][j - 1] == '#')
				v++;
		if (j != 3)
			if (str[i][j + 1] == '#')
				v++;
	}
	return (v);
}

static int	ft_while_stat(char **str)
{
	int i;
	int j;
	int v;

	i = 0;
	v = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				v = ft_first_part(str, i, v, j);
				v = ft_second_part(str, i, v, j);
				v = ft_last_part(str, i, v, j);
			}
			j++;
		}
		i++;
	}
	return (v);
}

int			ft_validate_piece(char **str)
{
	int		v;

	v = 0;
	if (!*str)
		return (0);
	v = ft_while_stat(str);
	if (v == 6 || v == 8)
		return (1);
	else
		ft_exit(1);
	return (0);
}
