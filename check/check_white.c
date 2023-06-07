/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_white.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:50:19 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/05 12:37:46 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

int direct_check_white6(t_game *game, int j, int i)
{
	int tempi;
	int tempj;

	tempi = i - 1;
	tempj = j + 1;
	if (tempi >= 0  && tempj < 8 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempj = j;
	if (tempi >= 0 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempj = j - 1;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempi = i;
	if (tempj >= 0 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempi = i + 1;
	if (tempj >= 0 && tempi < 8 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempj = j;
	if (tempi < 8 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempj = j + 1;
	if (tempj < 8 && tempi < 8 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	tempi = i;
	if (tempj < 8 && (game->map[0][tempi][tempj] == BKING || game->map[0][tempi][tempj] == BQUEEN))
		return (check(game));
	return (1);
}

int	direct_check_white5(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i - 2;
	tempj = j - 1;
	if (tempj >= 0 && tempi >= 0 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	tempj = j + 1;
	if (tempj < 8 && tempi >= 0 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	tempi = i + 2;
	if (tempj < 8 && tempi < 8 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	tempj = j - 1;
	if (tempj >= 0 && tempi < 8 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	//
	tempi = i - 1;
	tempj = j - 2;
	if (tempj >= 0 && tempi >= 0 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	tempi = i + 1;
	if (tempj >= 0 && tempi < 8 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	tempj = j + 2;
	if (tempj < 8 && tempi < 8 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	tempi = i - 1;
	if (tempj < 8 && tempi >= 0 && game->map[0][tempi][tempj] == BKNIGHT)
		return (check(game));
	return (direct_check_white6(game, j, i));
}

int	direct_check_white4(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i;
	tempj = j;
	while (++tempi < 8 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi < 8 && tempj >= 0 && (game->map[0][tempi][tempj] == BQUEEN
		|| game->map[0][tempi][tempj] == BBISHO
		|| (game->map[0][tempi][tempj] == BPAWN && tempi - 1 == i && tempj + 1 == j)))
		return (check(game));
	tempi = i;
	tempj = j;
	while (++tempi < 8 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi < 8 && tempj < 8 && (game->map[0][tempi][tempj] == BQUEEN
		|| game->map[0][tempi][tempj] == BBISHO
		|| (game->map[0][tempi][tempj] == BPAWN && tempi - 1 == i && tempj - 1 == j)))
		return (check(game));
	return (direct_check_white5(game, j, i));
}

int	direct_check_white3(t_game *game, int j, int i)
{
	int	tempi;
	int	tempj;

	tempi = i;
	tempj = j;
	while (--tempi >= 0 && --tempj >= 0 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi >= 0 && tempj >= 0 && (game->map[0][tempi][tempj] == BQUEEN
		|| game->map[0][tempi][tempj] == BBISHO))
		return (check(game));
	tempi = i;
	tempj = j;
	while (--tempi >= 0 && ++tempj < 8 && game->map[0][tempi][tempj] == 0)
		;
	if (tempi >= 0 && tempj < 8 && (game->map[0][tempi][tempj] == BQUEEN
		|| game->map[0][tempi][tempj] == BBISHO))
		return (check(game));
	return (direct_check_white4(game, j, i));
}

int	direct_check_white2(t_game *game, int j, int i)
{
	int	tempi;

	tempi = i;
	while (--tempi >= 0 && game->map[0][tempi][j] == 0)
		;
	if (tempi >= 0 && (game->map[0][tempi][j] == BQUEEN
			|| game->map[0][tempi][j] == BROOK))
		return (check(game));
	tempi = i;
	while (++tempi < 8 && game->map[0][tempi][j] == 0)
		;
	if (tempi < 8 && (game->map[0][tempi][j] == BQUEEN
			|| game->map[0][tempi][j] == BROOK))
		return (check(game));
	return (direct_check_white3(game, j, i));
}

int	direct_check_white(t_game *game, int j, int i)
{
	int	tempj;

	tempj = j;
	while (--tempj >= 0 && game->map[0][i][tempj] == 0)
		;
	if (tempj >= 0 && (game->map[0][i][tempj] == BQUEEN
			|| game->map[0][i][tempj] == BROOK))
		return (check(game));
	tempj = j;
	while (++tempj < 8 && game->map[0][i][tempj] == 0)
		;
	if (tempj < 8 && (game->map[0][i][tempj] == BQUEEN
			|| game->map[0][i][tempj] == BROOK))
		return (check(game));
	return (direct_check_white2(game, j, i));
}
