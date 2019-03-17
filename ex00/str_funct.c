/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:11:25 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/17 16:06:41 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		if (num < 0)
		{
			ft_putchar('-');
			num = num * (-1);
		}
		if (num > 10)
			ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
}

char		*get_part_before(char *str, int j)
{
	int		i;
	char	*part;

	i = 0;
	part = malloc(sizeof(char) * (j + 1));
	if (part)
	{
		while (i < j)
		{
			part[i] = str[i];
			i++;
		}
	}
	return (part);
}

char		*get_part_after(char *str, int i)
{
	char	*part;
	int		j;

	i += 1;
	j = 0;
	part = malloc(sizeof(char) * (str_size(str) - i));
	if (part)
	{
		while (str[i] != '\0')
		{
			part[j] = str[i];
			j++;
			i++;
		}
	}
	return (part);
}
