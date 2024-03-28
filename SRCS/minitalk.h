/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:58:40 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/26 10:37:38 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		conv_num(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putstr_fd(char *s);
void	print_error(void);
void	ft_putnbr(int n);
int		check_error(const char *str);

#endif
