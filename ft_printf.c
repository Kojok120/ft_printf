/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:24:56 by kokamoto          #+#    #+#             */
/*   Updated: 2024/06/15 15:27:31 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char **start, const char **format, int *n)
{
	while (**format && **format != '%')
	{
		ft_putchar_fd(1, **format);
		(*format)++;
		(*n)++;
	}
	*start = *format;
}

int	ft_strchr_n(const char *s, int c)
{
	int	i;

	i = 0;
    if (c == 0)
        return (-1);
	while (*(s + i) && *(s + i) != c)
        i++;
	if (*(s + i) == c)
			return (i);
	return (-1);
}

int	ft_substr_num(const char **format, va_list *args, int mode, t_flags *flags)
{
	int	num;

	num = -1;
	if (**format == '*')
	{
		num = va_arg(*args, int); //引数を取得
		if (num < 0 && !mode) //フィールドの場合は負の値を無視する
		{
			num *= -1;
			flags->flag[1] = 1; //フィールドが負の値の場合は左寄せにする
		}
		else if (num < 0)//精度の場合はnumを-1にする
			num = -1;
		(*format)++;
	}
	else if (mode || ft_isdigit(**format)) //精度の場合は0が来る場合もあるのでmodeで判定. modeの意味は精度かどうかのフラグ
	{
		num = 0;
		while (ft_isdigit(**format))
			num = num * 10 + (*((*format)++) - '0'); //(*((*format)++)は複雑だが、一つ一つ説明すると、formatの指す先の値を取得してformatを一つ進める。
	}
	return (num);
}

void	ft_init_flag(t_flags *flags, int n)
{
	flags->flag[0] = 0; // flag[0]の意味は#かどうかのフラグ
	flags->flag[1] = 0; // flag[1]の意味は左寄せかどうかのフラグ
	flags->field = -1;  // fieldやaccuracyは0が来る場青もあるので-1で初期化。0だと0が来たときに区別がつかない。
	flags->accuracy = -1;
	flags->putnum = (n < 0 ? 0 : n); // putnumはnが負の値の場合は0にする。
	flags->putlen = 0;
}
void	ft_process(const char **start, const char **format, int *n,
		va_list args)
{
	int		num;
	t_flags	flags;

	(*format)++;
	ft_init_flag(&flags, *n);
	while ((num = ft_strchr_n("#0", **format)) >= 0) //フラグの処理 
		//フラグが来る場合はフラグを立てる
	{
		flags.flag[num] = 1;
		(*format)++;
	}
	flags.field = ft_substr_num(format, args, 0, &flags); //フィールドの処理
	if (**format == '.')                                  //精度の処理
	{
		(*format)++;
		flags.accuracy = ft_substr_num(format, args, 1, &flags);
	}
	flags.specifier = ft_strchr_n("diuxXefgcspn", **format); //変換指定子の処理
    *n = ((*n == 0 || num >= 0) ? num : *n); //フラグが来る場合はnをnumにする
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			n;
	const char	*start;

	n = 0;
	va_start(args, format);
	if (format == NULL)
		n = -1;
	while (n >= 0 && *format)
	{
		start = format;
		if (*start != '%')
			ft_print_str(&start, &format, &n);
		else
			ft_process(&start, &format, &n, args);
	}
	va_end(args);
	return (n);
}

// int ft_printf(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);
//     int len = 0;
//     while (*format)
//     {
//         if (*format == '%')
//         {
//             format++;
//             if (*format == 'c')
//             {
//                 char c = va_arg(args, int);
//                 len += ft_putchar(c);
//             }
//             else if (*format == 's')
//             {
//                 char *str = va_arg(args, char *);
//                 len += ft_putstr(str);
//             }
//             else if (*format == 'd' || *format == 'i')
//             {
//                 int n = va_arg(args, int);
//                 len += ft_putnbr(n);
//             }
//             else
//             {
//                 ft_putchar('%');
//                 len++;
//             }
//         }
//         else
//         {
//             len += ft_putchar(*format);
//         }
//         format++;
//     }
//     va_end(args);
//     return (len);
// }

int	main(void)
{
	// compare various printf and ft_printf that use the same string or integer. print the function name before the output.
	printf("printf: %d\n", 42);
	ft_printf("ft_printf: %d\n", 42);
	printf("printf: %s\n", "Hello, World!");
	ft_printf("ft_printf: %s\n", "Hello, World!");
	printf("printf: %c\n", 'c');
	ft_printf("ft_printf: %c\n", 'c');
	printf("printf: %p\n", "Hello, World!");
	ft_printf("ft_printf: %p\n", "Hello, World!");
	printf("printf: %x\n", 42);
	ft_printf("ft_printf: %x\n", 42);
	printf("printf: %X\n", 42);
	ft_printf("ft_printf: %X\n", 42);
	printf("printf: %u\n", 42);
	ft_printf("ft_printf: %u\n", 42);
	printf("printf: %i\n", 42);
	ft_printf("ft_printf: %i\n", 42);
	printf("printf: %d\n", 42);
	ft_printf("ft_printf: %d\n", 42);

	return (0);
}