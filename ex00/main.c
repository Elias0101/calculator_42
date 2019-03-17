/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:04:35 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/17 16:00:25 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_btree		*create_knot(void *data, char sign)
{
	t_btree *new;

	new = malloc(sizeof(t_btree));
	if (new)
	{
		new->left = NULL;
		new->right = NULL;
		new->sign = sign;
		if (data != NULL)
		{
			new->item = (char*)malloc(sizeof(data));
			new->item = data;
		}
		else
			new->item = NULL;
	}
	return (new);
}

t_btree		*create_knots(char sign, t_btree *curr, int i)
{
	t_btree *new;

	if (sign == '-')
		new = create_knot("-", '+');
	else
		new = create_knot(NULL, sign);
	new->left = create_knot(get_part_before(curr->item, i), ' ');
	new->right = create_knot(get_part_after(curr->item, i), ' ');
	return (new);
}

void		create_tree(t_btree *current, int i)
{
	if (current != NULL)
	{
		delete_external_scopes(current->item);
		if ((i = split_oper('+', current->item)) != -1)
			*current = *create_knots('+', current, i);
		else if ((i = split_minus(current->item)) != -1)
			*current = *create_knots('-', current, i);
		else if ((i = split_oper('*', current->item)) != -1)
			*current = *create_knots('*', current, i);
		else if ((i = split_oper('/', current->item)) != -1)
			*current = *create_knots('/', current, i);
		else if ((i = split_oper('%', current->item)) != -1)
			*current = *create_knots('%', current, i);
		if (i != -1)
		{
			create_tree(current->left, -1);
			create_tree(current->right, -1);
		}
	}
}

int			eval_expr(char *input)
{
	t_btree		*root;
	char		*str;

	str = remove_spaces(input);
	delete_external_scopes(str);
	root = create_root(str);
	create_tree(root, -1);
	return (calculate_tree(root));
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
