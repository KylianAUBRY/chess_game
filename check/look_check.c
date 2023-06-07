/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:52:56 by kyaubry           #+#    #+#             */
/*   Updated: 2023/06/03 16:21:16 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../chess.h"

void	btest(t_game *game, int i, int j, int tempj, int tempi, int piece)
{
	int	tps;

	tps = game->map[0][tempi][tempj];
	game->map[0][tempi][tempj] = piece;
	if (look_check(game, BLACK) == 1)
	{
		game->map[1][i][j] = piece;
		game->map[1][tempi][tempj] = -1;
	}
	game->map[0][tempi][tempj] = tps;
}

void	wtest(t_game *game, int i, int j, int tempj, int tempi, int piece)
{
	int	tps;

	tps = game->map[0][tempi][tempj];
	game->map[0][tempi][tempj] = piece;
	if (look_check(game, WHITE) == 1)
	{
		game->map[1][i][j] = piece;
		game->map[1][tempi][tempj] = -1;
	}
	game->map[0][tempi][tempj] = tps;
}

int	check(t_game *game)
{
	if (game->status != TESTCHECKMATE)
		game->status = CHECK;
	return (0);
}

int	look_check(t_game *game, int color)
{
	int	leave;
	int	i;
	int	j;
	int	c;

	leave = 1;
	if (color == WHITE)
		c = WKING;
	else
		c = BKING;
	i = -1;
	while (leave == 1 && ++i < 8)
	{
		j = -1;
		while (leave == 1 && ++j < 8)
			if (game->map[0][i][j] == c)
			{
				leave = 0;
				break ;
			}
		if (leave == 0)
			break ;
	}
	if (c == WKING)
		return (direct_check_white(game, j, i));
	else
		return (direct_check_black(game, j, i));
	return (1);
}

int	ft_look_temp_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < 8)
			if (game->map[1][i][j] != 0)
				return (0);
	}
	return (1);
}

int	test_checkmate_black(t_game *game, int j, int i, int piece)
{
	if (piece == BPAWN)
		bpawn(game, j, i);
	else if (piece == BBISHO)
		bbisho(game, j, i);
	else if (piece == BKNIGHT)
		bknight(game, j, i);
	else if (piece == BROOK)
		brook(game, j, i);
	else if (piece == BQUEEN)
		bqueen(game, j, i);
	else if (piece == BKING)
		bking(game, j, i);
	if (ft_look_temp_map(game) == 0)
		return (0);
	return (1);
}

int	test_checkmate_white(t_game *game, int j, int i, int piece)
{
	if (piece == WPAWN)
		wpawn(game, j, i);
	else if (piece == WBISHO)
		wbisho(game, j, i);
	else if (piece == WKNIGHT)
		wknight(game, j, i);
	else if (piece == WROOK)
		wrook(game, j, i);
	else if (piece == WQUEEN)
		wqueen(game, j, i);
	else if (piece == WKING)
		wking(game, j, i);
	if (ft_look_temp_map(game) == 0)
		return (0);
	return (1);
}

int	look_checkmate(t_game *game)
{
	int i;
	int j;

	i = -1;
	game->status = TESTCHECKMATE;
	if (game->side == WHITE)
	{
		while (++i < 8)
		{
			j = -1;
			while (++j < 8)
			{
				if (game->map[0][i][j] > 6)
					if (test_checkmate_white(game, j, i, game->map[0][i][j]) == 0) // ERREUR ICI
						return (0);
			}
		}
	}
	else
	{
		while (++i < 8)
		{
			j = -1;
			while (++j < 8)
			{
				if (game->map[0][i][j] < 7 && game->map[0][i][j] > 0)
					if (test_checkmate_black(game, j, i, game->map[0][i][j]) == 0)
						return (0);
			}
		}
	}
	return (1);
}