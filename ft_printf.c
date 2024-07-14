/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kokamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:24:56 by kokamoto          #+#    #+#             */
/*   Updated: 2024/07/14 14:55:34 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(const char **start, const char **format, int *n)
{
	while (**format && **format != '%')
	{
		ft_putchar_fd(**format, 1);
		(*format)++;
		(*n)++;
	}
	*start = *format;
}

void	ft_process_not_number(int *n, va_list args, char spe)
{
	char	*str;

	if (spe == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*n)++;
	}
	if (spe == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, 1);
		(*n) += ft_strlen(str);
	}
	if (spe == 'p')
		(*n) += ft_putpointer_fd(va_arg(args, void *), 1);
	if (spe == '%')
	{
		ft_putchar_fd('%', 1);
		(*n)++;
	}
}

void	ft_process_number(int *n, va_list args, char spe)
{
	long long	num;

	num = va_arg(args, long long);
	if (spe == 'd' || spe == 'i')
	{
		num = (int)num;
		ft_putint_fd(num, 1);
	}
	else if (spe == 'u' || spe == 'x' || spe == 'X')
		num = (unsigned int)num;
	if (spe == 'u')
		ft_putunsignedint_fd(num, 1);
	if (spe == 'x')
		ft_put_uint_hex_fd(num, 1, 'x');
	if (spe == 'X')
		ft_put_uint_hex_fd(num, 1, 'X');
	if (spe == 'd' || spe == 'i' || spe == 'u')
		(*n) += ft_numlen(num);
	else
		(*n) += ft_hexlen(num);
}

void	ft_process(const char **start, const char **format, int *n,
		va_list args)
{
	char	spe;

	(*format)++;
	spe = ft_strchr_n("cspdiuxX%", **format);
	if (spe == -1)
	{
		(*start) = *format;
		return ;
	}
	if (spe == 'c' || spe == 's' || spe == 'p' || spe == '%')
		ft_process_not_number(n, args, spe);
	else
		ft_process_number(n, args, spe);
	(*format)++;
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
	if (n == -1)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	return (n);
}

// int	main(void)
// {
// 	printf("変換指定子がない場合\n");
// 	printf(" %d\n", printf("hello"));
// 	printf(" %d\n\n", ft_printf("hello"));

// 	printf("変換指定子がcの場合\n");
// 	printf(" %d\n", printf("c = %c", 'a'));
// 	printf(" %d\n\n", ft_printf("c = %c", 'a'));

// 	printf("変換指定子がsの場合\n");
// 	printf(" %d\n", printf("s = %s", "hello"));
// 	printf(" %d\n\n", ft_printf("s = %s", "hello"));

// 	printf("変換指定子がpの場合\n");
// 	printf(" %d\n", printf("p = %p\n", "hello"));
// 	printf(" %d\n\n", ft_printf("p = %p\n", "hello"));

// 	printf("変換指定子がdの場合\n");
// 	printf(" %d\n", printf("d = %d", 42));
// 	printf(" %d\n\n", ft_printf("d = %d", 42));

// 	printf("変換指定子がiの場合\n");
// 	printf(" %d\n", printf("i = %i", 42));
// 	printf(" %d\n\n", ft_printf("i = %i", 42));

// 	printf("変換指定子がuの場合\n");
// 	printf(" %d\n", printf("u = %u", 42));
// 	printf(" %d\n\n", ft_printf("u = %u", 42));

// 	printf("変換指定子がxの場合\n");
// 	printf(" %d\n", printf("x = %x", 42));
// 	printf(" %d\n\n", ft_printf("x = %x", 42));

// 	printf("変換指定子がXの場合\n");
// 	printf(" %d\n", printf("X = %X", 42));
// 	printf(" %d\n\n", ft_printf("X = %X", 42));

// 	printf("変換指定子が%%の場合\n");
// 	printf(" %d\n", printf("%%"));
// 	printf(" %d\n\n", ft_printf("%%"));
// 	return (0);
