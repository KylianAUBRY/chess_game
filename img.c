/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:51:45 by kylian            #+#    #+#             */
/*   Updated: 2023/05/30 19:01:42 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

int	init_img(t_game *game)
{
	int	w;
	int	h;

	game->img[0][0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/green.xpm", &w, &h);
	game->img[0][2] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/BlackBishop.xpm", &w, &h);
	game->img[0][6] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/BlackKing.xpm", &w, &h);
	game->img[0][3] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/BlackKnight.xpm", &w, &h);
	game->img[0][1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/BlackPawn.xpm", &w, &h);
	game->img[0][5] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/BlackQueen.xpm", &w, &h);
	game->img[0][4] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/BlackRook.xpm", &w, &h);
	if (!game->img[0][2] || !game->img[0][6]
		|| !game->img[0][3] || !game->img[0][1]
		|| !game->img[0][5] || !game->img[0][4]
		|| !game->img[0][0] || init_img2(game) == 0)
		return (free_game(game));
	return (1);
}

int	init_img2(t_game *game)
{
	int	w;
	int	h;

	game->img[0][8] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/WhiteBishop.xpm", &w, &h);
	game->img[0][12] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/WhiteKing.xpm", &w, &h);
	game->img[0][9] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/WhiteKnight.xpm", &w, &h);
	game->img[0][7] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/WhitePawn.xpm", &w, &h);
	game->img[0][11] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/WhiteQueen.xpm", &w, &h);
	game->img[0][10] = mlx_xpm_file_to_image(game->mlx,
			"./asset/green/WhiteRook.xpm", &w, &h);
	if (!game->img[0][8]  || !game->img[0][12]
		|| !game->img[0][9] || !game->img[0][7]
		|| !game->img[0][11] || !game->img[0][10]
		|| init_img3(game) == 0)
		return (0);
	return (1);
}

int	init_img3(t_game *game)
{
	int	w;
	int	h;

	game->img[1][0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/white.xpm", &w, &h);
	game->img[1][2] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/BlackBishop.xpm", &w, &h);
	game->img[1][6] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/BlackKing.xpm", &w, &h);
	game->img[1][3] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/BlackKnight.xpm", &w, &h);
	game->img[1][1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/BlackPawn.xpm", &w, &h);
	game->img[1][5] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/BlackQueen.xpm", &w, &h);
	game->img[1][4] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/BlackRook.xpm", &w, &h);
	if (!game->img[1][2] || !game->img[1][6]
		|| !game->img[1][3] || !game->img[1][1]
		|| !game->img[1][5] || !game->img[1][4]
		|| !game->img[1][0] || init_img4(game) == 0)
		return (0);
	return (1);
}

int init_img4(t_game *game)
{
	int	w;
	int	h;

	game->img[1][8] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/WhiteBishop.xpm", &w, &h);
	game->img[1][12] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/WhiteKing.xpm", &w, &h);
	game->img[1][9] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/WhiteKnight.xpm", &w, &h);
	game->img[1][7] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/WhitePawn.xpm", &w, &h);
	game->img[1][11] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/WhiteQueen.xpm", &w, &h);
	game->img[1][10] = mlx_xpm_file_to_image(game->mlx,
			"./asset/white/WhiteRook.xpm", &w, &h);
	if (!game->img[1][8] || !game->img[1][12]
		|| !game->img[1][9] || !game->img[1][7]
		|| !game->img[1][11] || !game->img[1][10]
		|| init_img5(game) == 0)
		return (0);
	return (1);
}

int	init_img5(t_game *game)
{
	int	w;
	int	h;

	game->img[2][0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/green.xpm", &w, &h);
	game->img[2][2] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/BlackBishop.xpm", &w, &h);
	game->img[2][6] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/BlackKing.xpm", &w, &h);
	game->img[2][3] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/BlackKnight.xpm", &w, &h);
	game->img[2][1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/BlackPawn.xpm", &w, &h);
	game->img[2][5] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/BlackQueen.xpm", &w, &h);
	game->img[2][4] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/BlackRook.xpm", &w, &h);
	if (!game->img[2][2] || !game->img[2][6]
		|| !game->img[2][3] || !game->img[2][1]
		|| !game->img[2][5] || !game->img[2][4]
		|| !game->img[2][0] || init_img6(game) == 0)
		return (0);
	return (1);
}

int	init_img6(t_game *game)
{
	int	w;
	int	h;

	game->img[2][8] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/WhiteBishop.xpm", &w, &h);
	game->img[2][12] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/WhiteKing.xpm", &w, &h);
	game->img[2][9] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/WhiteKnight.xpm", &w, &h);
	game->img[2][7] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/WhitePawn.xpm", &w, &h);
	game->img[2][11] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/WhiteQueen.xpm", &w, &h);
	game->img[2][10] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/green/WhiteRook.xpm", &w, &h);
	if (!game->img[2][8]  || !game->img[2][12]
		|| !game->img[2][9] || !game->img[2][7]
		|| !game->img[2][11] || !game->img[2][10]
		|| init_img7(game) == 0)
		return (0);
	return (1);
}

int	init_img7(t_game *game)
{
	int	w;
	int	h;

	game->img[3][0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/white.xpm", &w, &h);
	game->img[3][2] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/BlackBishop.xpm", &w, &h);
	game->img[3][6] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/BlackKing.xpm", &w, &h);
	game->img[3][3] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/BlackKnight.xpm", &w, &h);
	game->img[3][1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/BlackPawn.xpm", &w, &h);
	game->img[3][5] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/BlackQueen.xpm", &w, &h);
	game->img[3][4] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/BlackRook.xpm", &w, &h);
	if (!game->img[3][2] || !game->img[3][6]
		|| !game->img[3][3] || !game->img[3][1]
		|| !game->img[3][5] || !game->img[3][4]
		|| !game->img[3][0] || init_img8(game) == 0)
		return (0);
	return (1);
}

int init_img8(t_game *game)
{
	int	w;
	int	h;

	game->img[3][8] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/WhiteBishop.xpm", &w, &h);
	game->img[3][12] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/WhiteKing.xpm", &w, &h);
	game->img[3][9] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/WhiteKnight.xpm", &w, &h);
	game->img[3][7] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/WhitePawn.xpm", &w, &h);
	game->img[3][11] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/WhiteQueen.xpm", &w, &h);
	game->img[3][10] = mlx_xpm_file_to_image(game->mlx,
			"./asset/point/white/WhiteRook.xpm", &w, &h);
	if (!game->img[3][8] || !game->img[3][12]
		|| !game->img[3][9] || !game->img[3][7]
		|| !game->img[3][11] || !game->img[3][10]
		|| init_img9(game) == 0)
		return (0);
	return (1);
}

int	init_img9(t_game *game)
{
	int	w;
	int	h;

	game->img[4][0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/green.xpm", &w, &h);
	game->img[4][2] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/BlackBishop.xpm", &w, &h);
	game->img[4][6] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/BlackKing.xpm", &w, &h);
	game->img[4][3] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/BlackKnight.xpm", &w, &h);
	game->img[4][1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/BlackPawn.xpm", &w, &h);
	game->img[4][5] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/BlackQueen.xpm", &w, &h);
	game->img[4][4] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/BlackRook.xpm", &w, &h);
	if (!game->img[4][2] || !game->img[4][6]
		|| !game->img[4][3] || !game->img[4][1]
		|| !game->img[4][5] || !game->img[4][4]
		|| !game->img[4][0] || init_img10(game) == 0)
		return (0);
	return (1);
}

int	init_img10(t_game *game)
{
	int	w;
	int	h;

	game->img[4][8] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/WhiteBishop.xpm", &w, &h);
	game->img[4][12] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/WhiteKing.xpm", &w, &h);
	game->img[4][9] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/WhiteKnight.xpm", &w, &h);
	game->img[4][7] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/WhitePawn.xpm", &w, &h);
	game->img[4][11] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/WhiteQueen.xpm", &w, &h);
	game->img[4][10] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/green/WhiteRook.xpm", &w, &h);
	if (!game->img[4][8]  || !game->img[4][12]
		|| !game->img[4][9] || !game->img[4][7]
		|| !game->img[4][11] || !game->img[4][10]
		|| init_img11(game) == 0)
		return (0);
	return (1);
}

int	init_img11(t_game *game)
{
	int	w;
	int	h;

	game->img[5][0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/white.xpm", &w, &h);
	game->img[5][2] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/BlackBishop.xpm", &w, &h);
	game->img[5][6] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/BlackKing.xpm", &w, &h);
	game->img[5][3] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/BlackKnight.xpm", &w, &h);
	game->img[5][1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/BlackPawn.xpm", &w, &h);
	game->img[5][5] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/BlackQueen.xpm", &w, &h);
	game->img[5][4] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/BlackRook.xpm", &w, &h);
	if (!game->img[5][2] || !game->img[5][6]
		|| !game->img[5][3] || !game->img[5][1]
		|| !game->img[5][5] || !game->img[5][4]
		|| !game->img[5][0] || init_img12(game) == 0)
		return (0);
	return (1);
}

int init_img12(t_game *game)
{
	int	w;
	int	h;

	game->img[5][8] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/WhiteBishop.xpm", &w, &h);
	game->img[5][12] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/WhiteKing.xpm", &w, &h);
	game->img[5][9] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/WhiteKnight.xpm", &w, &h);
	game->img[5][7] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/WhitePawn.xpm", &w, &h);
	game->img[5][11] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/WhiteQueen.xpm", &w, &h);
	game->img[5][10] = mlx_xpm_file_to_image(game->mlx,
			"./asset/moove/white/WhiteRook.xpm", &w, &h);
	game->img_check[0] = mlx_xpm_file_to_image(game->mlx,
			"./asset/CheckBlackKing.xpm", &w, &h);
	game->img_check[1] = mlx_xpm_file_to_image(game->mlx,
			"./asset/CheckWhiteKing.xpm", &w, &h);
	if (!game->img[5][8] || !game->img[5][12]
		|| !game->img[5][9] || !game->img[5][7]
		|| !game->img[5][11] || !game->img[5][10]
		|| !game->img_check[0] || !game->img_check[1])
		return (0);
	return (1);
}
