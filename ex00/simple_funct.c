/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:58:48 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/17 15:50:13 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_btree		*create_root(char *str)
{
	t_btree *root;

	root = malloc(sizeof(t_btree));
	if (root)
	{
		root->left = NULL;
		root->right = NULL;
		root->sign = ' ';
		root->item = str;
	}
	return (root);
}

int			need_size(char *input)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '\n' && input[i] != '\r' && input[i] != '\v'
			&& input[i] != '\f' && input[i] != '\t' && input[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

char		*remove_spaces(char *input)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(need_size(input) + 1);
	while (input[i] != '\0')
	{
		if (input[i] != '\n' && input[i] != '\r' && input[i] != '\v'
			&& input[i] != '\f' && input[i] != '\t' && input[i] != ' ')
		{
			str[j] = input[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
