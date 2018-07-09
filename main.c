/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 22:44:22 by pkumar            #+#    #+#             */
/*   Updated: 2018/07/01 22:44:23 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_piece_count(char *str)
{
	VAL_MACRO;
	if (!*str)
		ft_exit(1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			new_lines++;
		else if (str[i] == '#')
			pieces++;
		else if (str[i] == '.')
			dot++;
		i++;
	}
	if (new_lines == 4 && pieces == 4)
		return (1);
	else if (pieces * 3 == dot && pieces != 4 &&
	new_lines == pieces + (pieces / 4) - 1)
		pieces = pieces / 4;
	else
		ft_exit(1);
	return (pieces);
}

static char	***ft_malloc_coords(int a)
{
	char	***coords;
	int		b;
	int		c;

	b = 0;
	if (!(coords = (char ***)malloc(sizeof(char **) * a + 1)))
		return (NULL);
	while (b <= a)
	{
		coords[b] = (char **)malloc(sizeof(char *) * 4 + 1);
		c = 0;
		while (c <= 5)
		{
			coords[b][c] = (char*)malloc(sizeof(char) * 4 + 1);
			c++;
		}
		b++;
	}
	return (coords);
}

static char	***parse_tetriminos(char ***coords, char *str, int piece_count)
{
	PARSE_MACRO;
	while (str[i] != '\0')
	{
		while (piecenum < piece_count)
		{
			row = 0;
			while (row < 4 && (i + 1) % BOX_SIZE != 0)
			{
				c = 0;
				while (c < 4 && (i + 1) % BOX_SIZE != 0)
				{
					coords[piecenum][row][c++] = str[i++];
					if (str[i] == '\n' && (i + 1) % BOX_SIZE != 0)
					{
						coords[piecenum][row++][c] = '\0';
						c = 0;
						i++;
					}
				}
			}
			coords[piecenum][row] = NULL;
			PARSE_CHECKER;
		}
	}
	return (coords);
}

static char	***format_tetriminos(char *str)
{
	FORMAT_MACRO;
	coords = parse_tetriminos(coords, str, piece_count);
	coords[piece_count] = NULL;
	while (coords[++w])
		ft_validate_piece(coords[w]);
	MV_LEFT;
	ft_placer(coords, piece_count);
	return (coords);
}

int			main(int ac, char **av)
{
	char	*filename;
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];

	filename = av[1];
	if (ac != 2)
		ft_exit(0);
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_exit(0);
	if (!(ret = read(fd, buf, BUFF_SIZE)))
		ft_exit(1);
	if (ret > MAX_FILLIT_SIZE)
		ft_exit(1);
	buf[ret] = '\0';
	if (ret < BOX_SIZE - 1 || buf[ret - 1] != '\n' || VALID_CHAR(buf[ret - 2]))
		ft_exit(1);
	format_tetriminos(buf);
	close(fd);
	return (0);
}
