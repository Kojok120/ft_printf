/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:24:56 by kokamoto          #+#    #+#             */
/*   Updated: 2024/06/01 22:29:59 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *, ...)
{
    a;
    
    return (0);
    
}

int main(void)
{
    printf("original: %c\n", "c");
    ft_printf("ft: %c\n", "c");
    printf("original: %s\n", "hello world");
    ft_printf("ft: %s\n", "hello world");
    printf("original: %p\n", NULL);
    ft_printf("ft: %p\n", NULL);
    printf("original: %d\n", 123);
    ft_printf("ft: %d\n", 123);
}