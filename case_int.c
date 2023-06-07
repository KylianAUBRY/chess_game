/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:15:40 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/05 12:22:11 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	case_int_void(t_game *game)
{
	map_temp_to_zero(game);
	write_piece(game);
	return (1);
}

void special_pawns(t_game *game, int j, int i, int y, int x)
{
	if (game->moov_pion >= 0 && (game->map[0][i][j] == WPAWN || game->map[0][i][j] == BPAWN))
	{
		if (game->map[1][3][j] == -2)
			game->map[0][3][j] = 0;
		if (game->map[1][4][j] == -2)
			game->map[0][4][j] = 0;
	}
	if ((game->map[0][i][j] == BPAWN && y == 6 && i == 4 && game->map[1][6][x] == BPAWN) || (game->map[0][i][j] == WPAWN && y == 1 && i == 3 && game->map[1][1][x] == WPAWN))
		game->moov_pion = x;
	else
		game->moov_pion = -1;
	if (game->map[0][i][j] == WPAWN && i == 7)
		promotion(game, j, i, WPAWN);
	else if (game->map[0][i][j] == BPAWN && i == 0)
		promotion(game, j, i, BPAWN);
}

void other(t_game *game, int j, int i, int y, int x)
{
	game->map[0][i][j] = game->map[1][y][x];
	game->map[0][y][x] = 0;
	special_pawns(game, j, i, y, x);
}

int change_status(t_game *game, int j, int i)
{
	if (game->map[0][i][j] > 6)
	{
		game->side = BLACK;
		if (look_check(game, BLACK) == 1)
			game->status = GOOD;
	}
	else
	{
		game->side = WHITE;
		if (look_check(game, WHITE) == 1)
			game->status = GOOD;
	}
	if (game->status == CHECK)
	{
		game->status = TESTCHECKMATE;
		if (look_checkmate(game) == 1)
		{
			printf("Checkmate\n");
			return (0);
		}
		else
			game->status = CHECK;
	}
	else
	{
		game->status = TESTCHECKMATE;
		if (look_checkmate(game) == 1)
		{
			printf("Null by pat\n");
			return (0);
		}
		else
			game->status = GOOD;
	}
	return (1);
}

void king_rook(t_game *game, int j, int i, int y, int x, int piece)
{
	if (piece == BROCK)
	{
		if (j == 6 && i == 7)
		{
			game->map[0][7][7] = 0;
			game->map[0][7][6] = BKING;
			game->map[0][7][5] = BROOK;
			game->map[0][7][4] = 0;
			return ;
		}
		else if (j == 2 && i == 7)
		{
			game->map[0][7][0] = 0;
			game->map[0][7][2] = BKING;
			game->map[0][7][3] = BROOK;
			game->map[0][7][4] = 0;
			return ;
		}
		game->map[1][y][x] = BKING;
	}	
	else if (piece == WROCK)
	{
		if (j == 6 && i == 0)
		{
			game->map[0][0][7] = 0;
			game->map[0][0][6] = WKING;
			game->map[0][0][5] = WROOK;
			game->map[0][0][4] = 0;
			return ;
		}
		else if (j == 2 && i == 0)
		{
			game->map[0][0][0] = 0;
			game->map[0][0][2] = WKING;
			game->map[0][0][3] = WROOK;
			game->map[0][0][4] = 0;
			return ;
		}
		game->map[1][y][x] = WKING;
	}
	other(game, j, i, y, x);
}

int moov(t_game *game, int j, int i)
{
	int x;
	int y;
	int indice;

	y = -1;
	indice = 1;
	while (indice == 1 && ++y < 8)
	{
		x = -1;
		while (indice == 1 && ++x < 8)
			if (game->map[1][y][x] > 0)
				indice = 0;
	}
	map_temp_to_zero3(game);
	game->map[3][i][j] = game->map[1][y][x];
	game->map[3][y][x] = -1;
	if (game->map[1][y][x] == BROCK || game->map[1][y][x] == WROCK)
	{
		king_rook(game, j, i, y, x, game->map[1][y][x]);
	}
	else
		other(game, j, i, y, x);
	case_int_void(game);
	game->map[2][i][j] += 1;
	if (change_status(game, j, i) == 0)
		return (free_game(game));
	case_int_void(game);
	return (1);
}

int	case_int(t_game *game, int j, int i)
{
	if (game->map[1][i][j] == -1)
		return (moov(game, j, i));
	else if (game->map[0][i][j] == BPAWN)
		return (bpawn(game, j, i));
	else if (game->map[0][i][j] == BBISHO)
		return (bbisho(game, j, i));
	else if (game->map[0][i][j] == BKNIGHT)
		return (bknight(game, j, i));
	else if (game->map[0][i][j] == BROOK)
		return (brook(game, j, i));
	else if (game->map[0][i][j] == BQUEEN)
		return (bqueen(game, j, i));
	else if (game->map[0][i][j] == BKING)
		return (bking(game, j, i));
	else if (game->map[0][i][j] == WPAWN)
		return (wpawn(game, j, i));
	else if (game->map[0][i][j] == WBISHO)
		return (wbisho(game, j, i));
	else if (game->map[0][i][j] == WKNIGHT)
		return (wknight(game, j, i));
	else if (game->map[0][i][j] == WROOK)
		return (wrook(game, j, i));
	else if (game->map[0][i][j] == WQUEEN)
		return (wqueen(game, j, i));
	else if (game->map[0][i][j] == WKING)
		return (wking(game, j, i));
	else
		return (case_int_void(game));
}
