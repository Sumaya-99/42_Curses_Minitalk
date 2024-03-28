/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:04 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/26 10:22:49 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recieve_bits(int sig, siginfo_t *info, void *context)
{
	static int	bit_count;
	static char	bits;

	(void)context;
	bits |= (sig & 1) << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &bits, 1);
		if (bits == 0)
			kill(info->si_pid, SIGUSR2);
		if (!bits)
			ft_putchar('\n');
		bit_count = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = recieve_bits;
	write(1, "The Server's PID: ", 18);
	ft_putnbr(getpid());
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause();
	}
}
