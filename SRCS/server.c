/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:58:17 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/26 10:13:12 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_bits(int sig)
{
	static int	bit_count;
	static char	bits;

	bits |= (sig & 1) << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		write (1, &bits, 1);
		if (!bits)
			ft_putchar('\n');
		bit_count = 0;
		bits = 0;
	}
}

int	main(void)
{
	write (1, "The Server's PID: ", 18);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR2, recieve_bits);
		signal(SIGUSR1, recieve_bits);
		pause();
	}
}
