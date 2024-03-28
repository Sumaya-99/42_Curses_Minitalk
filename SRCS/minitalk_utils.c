/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:58:36 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/26 10:36:06 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	conv_num(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	if ((check_error(str)))
	{
		printf("Wrong PID");
		exit(1);
	}
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return ((result * sign));
}

size_t	ft_strlen(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar (n + '0');
	else
	{
		ft_putnbr (n / 10);
		ft_putchar (n % 10 + '0');
	}
}
