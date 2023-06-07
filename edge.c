/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:51:22 by kylian            #+#    #+#             */
/*   Updated: 2023/05/29 19:16:24 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

void	write_edge_right(t_game *game)
{
	int i;
	int j;

	i = 279;
	while (++i < 800)
	{
		j = 1199;
		while (++j < 1220)
		{
			if (j < 1204 && i > 295 && i < 784)
				mlx_pixel_put(game->mlx, game->win, j, i,  0x00000);
			else
				mlx_pixel_put(game->mlx, game->win, j, i,  0xA96E37);
		}
	}
}

void	write_edge_up(t_game *game)
{
	int i;
	int j;

	i = 279;
	while (++i < 300)
	{
		j = 719;
		while (++j < 1200)
		{
			if (i > 295)
				mlx_pixel_put(game->mlx, game->win, j, i,  0x00000);
			else
				mlx_pixel_put(game->mlx, game->win, j, i,  0xA96E37);
		}
	}
}

void	write_edge_down(t_game *game)
{
	int i;
	int j;
	
	i = 779;
	while (++i < 800)
	{
		j = 699;
		while (++j < 1200)
		{
			if (i < 784 && j > 715)
				mlx_pixel_put(game->mlx, game->win, j, i,  0x00000);
			else
			mlx_pixel_put(game->mlx, game->win, j, i,  0xA96E37);
		}
	}
}

void write_letter(t_game *game)
{
	mlx_string_put(game->mlx, game->win, 745, 292, 0x000000, "A");
	mlx_string_put(game->mlx, game->win, 805, 292, 0x000000, "B");
	mlx_string_put(game->mlx, game->win, 865, 292, 0x000000, "C");
	mlx_string_put(game->mlx, game->win, 925, 292, 0x000000, "D");
	mlx_string_put(game->mlx, game->win, 985, 292, 0x000000, "E");
	mlx_string_put(game->mlx, game->win, 1045, 292, 0x000000, "F");
	mlx_string_put(game->mlx, game->win, 1105, 292, 0x000000, "G");
	mlx_string_put(game->mlx, game->win, 1165, 292, 0x000000, "H");
	//
	mlx_string_put(game->mlx, game->win, 745, 797, 0x000000, "A");
	mlx_string_put(game->mlx, game->win, 805, 797, 0x000000, "B");
	mlx_string_put(game->mlx, game->win, 865, 797, 0x000000, "C");
	mlx_string_put(game->mlx, game->win, 925, 797, 0x000000, "D");
	mlx_string_put(game->mlx, game->win, 985, 797, 0x000000, "E");
	mlx_string_put(game->mlx, game->win, 1045, 797, 0x000000, "F");
	mlx_string_put(game->mlx, game->win, 1105, 797, 0x000000, "G");
	mlx_string_put(game->mlx, game->win, 1165, 797, 0x000000, "H");
}

void write_number(t_game *game)
{
	
	mlx_string_put(game->mlx, game->win, 705, 753, 0x000000, "1");
	mlx_string_put(game->mlx, game->win, 705, 693, 0x000000, "2");
	mlx_string_put(game->mlx, game->win, 705, 633, 0x000000, "3");
	mlx_string_put(game->mlx, game->win, 705, 573, 0x000000, "4");
	mlx_string_put(game->mlx, game->win, 705, 513, 0x000000, "5");
	mlx_string_put(game->mlx, game->win, 705, 453, 0x000000, "6");
	mlx_string_put(game->mlx, game->win, 705, 393, 0x000000, "7");
	mlx_string_put(game->mlx, game->win, 705, 333, 0x000000, "8");
	//
	mlx_string_put(game->mlx, game->win, 1209, 753, 0x000000, "1");
	mlx_string_put(game->mlx, game->win, 1209, 693, 0x000000, "2");
	mlx_string_put(game->mlx, game->win, 1209, 633, 0x000000, "3");
	mlx_string_put(game->mlx, game->win, 1209, 573, 0x000000, "4");
	mlx_string_put(game->mlx, game->win, 1209, 513, 0x000000, "5");
	mlx_string_put(game->mlx, game->win, 1209, 453, 0x000000, "6");
	mlx_string_put(game->mlx, game->win, 1209, 393, 0x000000, "7");
	mlx_string_put(game->mlx, game->win, 1209, 333, 0x000000, "8");
	
}

void	write_edge(t_game *game)
{
	int i;
	int j;

	i = 279;
	while (++i < 800)
	{
		j = 699;
		while (++j < 720)
		{
			if (j > 715 && i > 295 && i < 785)
				mlx_pixel_put(game->mlx, game->win, j, i,  0x00000);
			else
				mlx_pixel_put(game->mlx, game->win, j, i,  0xA96E37);
		}
	}
	write_edge_right(game);
	write_edge_up(game);
	write_edge_down(game);
	write_letter(game);
	write_number(game);
}
