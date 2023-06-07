/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wpawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:12:12 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void	wtaken_in_passing(t_game *game, int j, int i)
{
	if (i == 4 && j - 1 >= 0 && j - 1 == game->moov_pion)
	{
		if (game->map[0][4][j - 1] == BPAWN && game->map[0][i + 1][j - 1] == 0 && game->map[0][i + 2][j - 1] == 0)
		{
			game->map[0][i + 1][j - 1] = 1;
			game->map[0][i][j - 1] = 0;
			if (look_check(game, WHITE) == 1)
			{
				game->map[1][4][j - 1] = -2;
				game->map[1][i][j] = WPAWN;
				game->map[1][i + 1][j - 1] = -1;
			}
			game->map[0][i + 1][j - 1] = 0;
			game->map[0][i][j - 1] = BPAWN;
		}
	}
	if (i == 4 && j + 1 < 8 && j + 1 == game->moov_pion)
	{
		if (game->map[0][4][j + 1] == BPAWN && game->map[0][i + 1][j + 1] == 0 && game->map[0][i + 2][j + 1] == 0)
		{
			game->map[0][i + 1][j + 1] = 1;
			game->map[0][i][j + 1] = 0;
			if (look_check(game, WHITE) == 1)
			{
				game->map[1][4][j + 1] = -2;
				game->map[1][i][j] = WPAWN;
				game->map[1][i + 1][j + 1] = -1;
			}
			game->map[0][i + 1][j + 1] = 0;
			game->map[0][i][j + 1] = BPAWN;
		}
	}
}

void	wpawn_prise(t_game *game, int j, int i)
{
	int	temp;

	if (i + 1 < 8 && j + 1 < 8 && game->map[0][i + 1][j + 1] < 7 && game->map[0][i + 1][j + 1] > 0)
	{
		temp = game->map[0][i + 1][j + 1];
		game->map[0][i + 1][j + 1] = 1;
		if (look_check(game, WHITE) == 1)
		{
			game->map[1][i][j] = WPAWN;
			game->map[1][i + 1][j + 1] = -1;
		}
		game->map[0][i + 1][j + 1] = temp;
	}
	if (i + 1 < 8 && j - 1 >= 0 && game->map[0][i + 1][j - 1] < 7 && game->map[0][i + 1][j - 1] > 0)
	{
		temp = game->map[0][i + 1][j - 1];
		game->map[0][i + 1][j - 1] = 1;
		if (look_check(game, WHITE) == 1)
		{
			game->map[1][i][j] = WPAWN;
			game->map[1][i + 1][j - 1] = -1;
		}
		game->map[0][i + 1][j - 1] = temp;
	}
	wtaken_in_passing(game, j, i);
}

void	wpawn_push(t_game *game, int j, int i)
{
	if (i + 1 < 8 && game->map[0][i + 1][j] == 0)
	{
		game->map[0][i + 1][j] = WPAWN;
		if (look_check(game, WHITE) == 1)
		{
			game->map[1][i][j] = WPAWN;
			game->map[1][i + 1][j] = -1;
		}
		game->map[0][i + 1][j] = 0;
	}
	if (i == 1 && i + 2 < 8 && game->map[0][i + 2][j] == 0 && game->map[0][i + 1][j] == 0)
	{
		game->map[0][i + 2][j] = WPAWN;
		if (look_check(game, WHITE) == 1)
		{
			game->map[1][i][j] = WPAWN;
			game->map[1][i + 2][j] = -1;
		}
		game->map[0][i + 2][j] = 0;
	}
}

int	wpawn(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == BLACK)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		wpawn_push(game, j, i);
		wpawn_prise(game, j, i);
		game->map[0][i][j] = WPAWN;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		wpawn_push(game, j, i);
		wpawn_prise(game, j, i);
		game->map[0][i][j] = WPAWN;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
