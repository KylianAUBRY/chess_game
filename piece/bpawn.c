/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:19:27 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void	btaken_in_passing(t_game *game, int j, int i)
{
	if (i == 3 && j - 1 >= 0 && j - 1 == game->moov_pion)
	{
		if (game->map[0][3][j - 1] == WPAWN && game->map[0][i - 1][j - 1] == 0 && game->map[0][i - 2][j - 1] == 0)
		{
			game->map[0][i - 1][j - 1] = 1;
			game->map[0][i][j - 1] = 0;
			if (look_check(game, BLACK) == 1)
			{
				game->map[1][3][j - 1] = -2;
				game->map[1][i][j] = BPAWN;
				game->map[1][i - 1][j - 1] = -1;
			}
			game->map[0][i - 1][j - 1] = 0;
			game->map[0][i][j - 1] = WPAWN;
		}
	}
	if (i == 3 && j + 1 < 8 && j + 1 == game->moov_pion)
	{
		if (game->map[0][3][j + 1] == WPAWN && game->map[0][i - 1][j + 1] == 0 && game->map[0][i - 2][j + 1] == 0)
		{
			game->map[0][i - 1][j + 1] = 1;
			game->map[0][i][j + 1] = 0;
			if (look_check(game, BLACK) == 1)
			{
				game->map[1][3][j + 1] = -2;
				game->map[1][i][j] = BPAWN;
				game->map[1][i - 1][j + 1] = -1;
			}
			game->map[0][i - 1][j + 1] = 0;
			game->map[0][i][j + 1] = WPAWN;
		}
	}
}

void	bpawn_prise(t_game *game, int j, int i)
{
	int	temp;

	if (i - 1 >= 0 && j - 1 >= 0 && game->map[0][i - 1][j - 1] >= 7)
	{
		temp = game->map[0][i - 1][j - 1];
		game->map[0][i - 1][j - 1] = 1;
		if (look_check(game, BLACK) == 1)
		{
			game->map[1][i][j] = BPAWN;
			game->map[1][i - 1][j - 1] = -1;
		}
		game->map[0][i - 1][j - 1] = temp;
	}
	if (i - 1 >= 0 && j + 1 < 8 && (game->map[0][i - 1][j + 1] >= 7))
	{
		temp = game->map[0][i - 1][j + 1];
		game->map[0][i - 1][j + 1] = 1;
		if (look_check(game, BLACK) == 1)
		{
			game->map[1][i][j] = BPAWN;
			game->map[1][i - 1][j + 1] = -1;
		}
		game->map[0][i - 1][j + 1] = temp;
	}
	btaken_in_passing(game, j, i);
}

void	bpawn_push(t_game *game, int j, int i)
{
	if (i - 1 >= 0 && game->map[0][i - 1][j] == 0)
	{
		game->map[0][i - 1][j] = BPAWN;
		if (look_check(game, BLACK) == 1)
		{
			game->map[1][i][j] = BPAWN;
			game->map[1][i - 1][j] = -1;
		}
		game->map[0][i - 1][j] = 0;
	}
	if (i == 6 && i - 2 >= 0 && game->map[0][i - 2][j] == 0 && game->map[0][i - 1][j] == 0)
	{
		game->map[0][i - 2][j] = BPAWN;
		if (look_check(game, BLACK) == 1)
		{
			game->map[1][i][j] = BPAWN;
			game->map[1][i - 2][j] = -1;
		}
		game->map[0][i - 2][j] = 0;
	}
}

int	bpawn(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == WHITE)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		bpawn_push(game, j, i);
		bpawn_prise(game, j, i);
		game->map[0][i][j] = BPAWN;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		bpawn_push(game, j, i);
		bpawn_prise(game, j, i);
		game->map[0][i][j] = BPAWN;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
