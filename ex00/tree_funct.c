/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:29:52 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/16 18:04:24 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int			str_size(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*get_part_before(char *str, int j)
{
	int i;
	char *part;

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
	char *part;
	int j;

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

t_btree		*create_knot(void *data, char sign)
{
	t_btree *new;

	new = malloc(sizeof(t_btree));
	if (new)
	{
		new->left = NULL;
		new->right = NULL;
		if (sign != ' ')
			new->sign = sign;
		if (data != NULL)
		{
			new->item = (char*)malloc(sizeof(data));
			new->item = data;
		}
	}
	return (new);
}

t_btree		*create_knots(char sign, t_btree *curr, int i)
{
	t_btree *new;

	if (sign == '-')
		new = create_knot(NULL, '+');
	else
		new = create_knot(NULL, sign);
	new->left = create_knot(get_part_before(curr->item, i), ' ');
	if (sign == '-')
		new->right = create_knot(get_part_after(curr->item, i), '-');
	else
		new->right = create_knot(get_part_after(curr->item, i), ' ');
	return (new);
}

void		create_tree(t_btree *current, int i)
{
	if (current != NULL)
	{
		printf("recurs, i:  %d,   curren->item: %s\n", i, current->item);
		if ((i = split_oper('+', current->item)) != -1)
		{
			*current = *create_knots('+', current, i);
		}
		else if ((i = split_oper('-', current->item)) != -1)
		{
			*current = *create_knots('-', current, i);
		}
		else if ((i = split_oper('*', current->item)) != -1)
		{
			*current = *create_knots('*', current, i);
		}
		else if ((i = split_oper('/', current->item)) != -1)
		{
			*current = *create_knots('/', current, i);
		}
		else if ((i = split_oper('%', current->item)) != -1)
		{
			*current = *create_knots('%', current, i);
		}
		if (i != -1)
		{
			printf("again\n");
			create_tree(current->left, -1);
			create_tree(current->right, -1);
		}
		else
			printf("not again\n");
	}
}
