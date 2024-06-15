/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 06:45:37 by kokamoto          #+#    #+#             */
/*   Updated: 2024/06/05 21:41:56 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"

typedef struct s_flags
{
    int flag[2];//flag[0]は#かどうかのフラグ、flag[1]は左寄せかどうかのフラグ
    int field;
    int accuracy;
    int specifier;
    int putnum;
    int putlen;
} t_flags;

int ft_printf(const char *format, ...);

#endif