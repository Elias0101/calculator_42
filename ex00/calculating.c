/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 13:29:03 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/17 16:29:21 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int		is_minus_sign(char *str)
{
	if (str[0] == '-')
		return (1);
	else
		return (0);
}

int		calc_operation(int a, t_btree *current, int b)
{
	if (current->item != NULL && is_minus_sign(current->item) == 1)
		b = b * (-1);
	if (current->sign == '+')
		return (a + b);
	else if (current->sign == '-')
		return (a - b);
	else if (current->sign == '*')
		return (a * b);
	else if (current->sign == '/')
		return (a / b);
	else
		return (a % b);
}

void	add_result(t_btree *current, void *data)
{
	current->item = NULL;
	current->item = malloc(sizeof(int));
	current->item = data;
}

int		calculate_tree(t_btree *current)
{
	int res;

	if (current->left == NULL && current->right == NULL)
	{
		if (current->sign == '-')
			return (ft_atoi((char*)(current->item)) * (-1));
		else
			return (ft_atoi((char*)(current->item)));
	}
	res = calc_operation(calculate_tree(current->left),
					current, calculate_tree(current->right));
	return (res);
}
