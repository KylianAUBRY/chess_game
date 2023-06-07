/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brook.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:44:28 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 21:30:09 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void	brook_push(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i;
	tempj = j;
	while (--tempj >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BROOK);
	if (tempj >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BROOK);
	tempj = j;
	while (++tempj < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BROOK);
	if (tempj < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BROOK);
	tempj = j;
	while (++tempi < 8 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BROOK);
	if (tempi < 8 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BROOK);
	tempi = i;
	while (--tempi >= 0 && game->map[0][tempi][tempj] == 0)
		btest(game, i, j, tempj, tempi, BROOK);
	if (tempi >= 0 && game->map[0][tempi][tempj] > 6)
		btest(game, i, j, tempj, tempi, BROOK);
}

int	brook(t_game *game, int j, int i)
{
	map_temp_to_zero(game);
	if (game->side == WHITE)
		return (0);
	if (game->status == GOOD)
	{
		game->map[0][i][j] = 0;
		brook_push(game, j, i);
		game->map[0][i][j] = BROOK;
		game->status = GOOD;
	}
	else
	{
		game->map[0][i][j] = 0;
		brook_push(game, j, i);
		game->map[0][i][j] = BROOK;
	}
	if (game->status != TESTCHECKMATE)
		write_piece(game);
	return (1);
}
