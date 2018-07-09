/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 20:57:21 by pkumar            #+#    #+#             */
/*   Updated: 2018/07/01 20:57:23 by pkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 1024
# define BOX_SIZE 21
# define MAX_FILLIT_SIZE 545
# define VALID_CHAR(x) (x == '.' || x == '#' ? 0 : 1)
# define VAL_MACRO int new_lines = 0, pieces = 0, dot = 0, i = 0;
# define MOVE_X_Y int x; int y;
# define MAP_MACRO char **map = NULL; int x = 0; int y; int i = -1;
# define PIECE_MACRO2 int cx = 0, a = 0, cy;
# define PIECE_MACRO int **crds = NULL; int x = -1, y; CHAR_MACRO;
# define CHAR_MACRO char l = 'A' + box_num; int current[3];
# define CURRENT_MACRO current[0] = x; current[1] = y; current[2] = size;
# define MV_LEFT while (++q < piece_count) coords[q] = ft_move_left(coords[q]);
# define CRDS_MACRO int **crds = NULL; int x = -1; int y = 0;
# define FORMAT_MACRO int w = -1, piece_count = ft_piece_count(str); FORMAT_2
# define FORMAT_2 char ***coords = ft_malloc_coords(piece_count); int q = -1;
# define PARSE_MACRO int piecenum = 0, i = 0, row, c;
# define PARSE_CHECKER PC1; piecenum++;
# define PC1 if (str[i] == '\n' && piecenum != piece_count - 1) i++; PC2;
# define PC2 else if (piecenum == piece_count - 1) break ; else ft_exit(1);
# define SPACE if (str[i] == '\n' && SPACE2);
# define SPACE2 (i + 1) % BOX_SIZE != 0 && VALID_CHAR(str[i + 1]);

void		ft_placer(char ***coords, int piece_count);
int			ft_validate_piece(char **str);
void		ft_print_map(char **map);
int			**ft_getpiece(char **box);
void		ft_strdel(char **as);
char		**ft_make_map(int p);
char		**ft_move_left(char **box);
void		ft_exit(int i);
int			ft_sqrt_up(int n);

#endif
