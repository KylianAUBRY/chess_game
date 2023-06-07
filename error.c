/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylian <kylian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:00:00 by kylian            #+#    #+#             */
/*   Updated: 2023/05/29 19:21:54 by kylian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chess.h"

void write_error(char *src)
{
    int i = -1;

    while (src[++i])
        write(2, &src[i], 1);
}

int print_error(int error_code)
{
    if (error_code == ERRCODE_MALLOC_FAIL)
        write_error("Error :\nMalloc failed to allocate memory.\n");
	else if (error_code == ERRCODE_INIT_WIN)
        write_error("Error :\nInit window failed\n");
    else if (error_code == ERRCODE_CREATE_WIN)
        write_error("Error :\nFailed to create window\n");
	else if (error_code == ERRCODE_XPM)
		write_error("Error :\nAn error occurred while loading the image\n");
    return (0);
}