/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 02:39:57 by kylian            #+#    #+#             */
/*   Updated: 2023/05/31 13:28:07 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

void map_temp_to_zero3(t_game *game)
{
	int i;
	int j;
	
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			game->map[3][i][j] = 0;
	}
}

void map_temp_to_zero2(t_game *game)
{
	int i;
	int j;
	
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			game->map[2][i][j] = 0;
	}
}

void map_temp_to_zero(t_game *game)
{
	int i;
	int j;
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			game->map[1][i][j] = 0;
	}
}

void map_to_zero(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			game->map[0][i][j] = 0;
	}
	map_temp_to_zero(game);
	map_temp_to_zero2(game);
	map_temp_to_zero3(game);
}

void char_map(t_game *game)
{
	int i;

	i = -1;
	while (++i < 8)
		game->map[0][1][i] = WPAWN; //white pawn(pion) = 7
	i = -1;
	while (++i < 8)
		game->map[0][6][i] = BPAWN; // black pawn(pion) = 1
	game->map[0][0][0] = WROOK; //white rook(tour) = 10
	game->map[0][0][1] = WKNIGHT; //white knight(cavalier) = 9
	game->map[0][0][2] = WBISHO; //white Bisho(fou) = 8
	game->map[0][0][3] = WQUEEN; //white queen(Dame) = 11
	game->map[0][0][4] = WKING; //white king(roi) = 12
	game->map[0][0][5] = WBISHO; //white Bisho(fou) = 8
	game->map[0][0][6] = WKNIGHT; //white knight(cavalier) = 9
	game->map[0][0][7] = WROOK; //white rook(tour) = 10
	//
	game->map[0][7][0] = BROOK; //black rook(tour) = 4
	game->map[0][7][1] = BKNIGHT; //black knight(cavalier) = 3
	game->map[0][7][2] = BBISHO; //black Bisho(fou) = 2
	game->map[0][7][3] = BQUEEN; //black queen(Dame) = 5
	game->map[0][7][4] = BKING; //black king(roi) = 6
	game->map[0][7][5] = BBISHO; //black Bisho(fou) = 2
	game->map[0][7][6] = BKNIGHT; //black knight(cavalier) = 3
	game->map[0][7][7] = BROOK; //black rook(tour) = 4
}

int init_map(t_game *game)
{
	map_to_zero(game);
	char_map(game);
	return (1);
}

int init(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (print_error(ERRCODE_MALLOC_FAIL));
	(*game)->mlx = mlx_init();
	if ((*game)->mlx == NULL)
	{
		free(game);
		return (print_error(ERRCODE_INIT_WIN));
	}
	(*game)->win = mlx_new_window((*game)->mlx, 1920, 1080, "Chess game");
	if ((*game)->win == NULL)
		return (free_window(*game));
	if (init_img(*game) == 0)
		return (print_error(ERRCODE_XPM));
	if (init_map(*game) == 0)
		return (print_error(ERRCODE_MALLOC_FAIL));
	return (1);
}
