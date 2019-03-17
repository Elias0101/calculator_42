/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:29:52 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/17 17:54:10 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			str_size(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			find_first_scope(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '(')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*' || str[i] == '/'
			|| str[i] == '+' || str[i] == '-' || str[i] == '%')
		{
			i = -1;
			break ;
		}
		i++;
	}
	return (i);
}

void		delete_external_scopes(char *str)
{
	int		i;
	int		start;

	i = 0;
	i = find_first_scope(str);
	if (str[i] != '\0' && i != -1)
	{
		start = i;
		i = str_size(str);
		while (i != 0 && str[i] != ')')
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*'
				|| str[i] == '/' || str[i] == '+' || str[i] == '-'
				|| str[i] == '%')
				return ;
			i--;
		}
		if (i != 0)
		{
			str[start] = ' ';
			str[i] = ' ';
		}
	}
}

int			split_oper(char c, char *str)
{
	int count_scope;
	int i;

	i = 0;
	count_scope = 0;
	while (str[i] != '\0' && (str[i] != c || count_scope != 0))
	{
		if (str[i] == '(')
			count_scope++;
		else if (str[i] == ')')
			count_scope--;
		i++;
	}
	if (str[i] != '\0')
		return (i);
	else
		return (-1);
}

int			split_minus(char *str)
{
	int i;
	int j;
	int count_scope;

	count_scope = 0;
	j = split_oper('-', str);
	if (str[j] == '\0')
		return (-1);
	i = j + 1;
	while (str[i] != '\0' && (str[i] != '-' || count_scope != 0))
	{
		if (str[i] == '(')
			count_scope++;
		else if (str[i] == ')')
			count_scope--;
		i++;
	}
	if (str[i] == '\0')
		return (j);
	else
		return (i);
}
