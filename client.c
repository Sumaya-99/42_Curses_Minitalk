/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:58:08 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/26 13:48:38 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_char_binary(int pid, char *str, size_t length)
{
	int		bits;
	int		bits_count;
	size_t	a;

	a = 0;
	while (a <= length)
	{
		bits_count = 0;
		while (bits_count < 8)
		{
			bits = ((str[a] >> bits_count) & 1);
			if (bits == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
			bits_count++;
		}
		a++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
	{
		write(1, "Please provide a PID and a string to be sent\n", 46);
		exit(1);
	}
	pid = conv_num(av[1]);
	str = av[2];
	convert_char_binary(pid, str, ft_strlen(av[2]));
}
