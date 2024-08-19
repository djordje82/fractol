/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:04:03 by dodordev          #+#    #+#             */
/*   Updated: 2024/08/13 14:45:58 by dodordev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_on_error(char *exit_code)
{
	int	i;

	i = 0;
	while (exit_code[i])
		++i;
	write(1, exit_code, i);
	write(1, "\n", 1);
	exit (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

double	ft_atof(const char *str)
{
	double	result;
	double	power;
	char	*dec_point;
	int		sign;
	int		i;

	sign = 1;
	power = 1.0;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	result = (double)ft_atoi(str++);
	dec_point = ft_strchr(str, '.');
	if (dec_point) 
	{
		i = dec_point - str + 1;
		while (ft_isdigit(str[i]))
		{
			result = result * 10.0 + (str[i++] - '0');
			power *= 10.0;
		}
	}
	return (result * sign / power);
}
