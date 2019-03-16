/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:58:48 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/16 16:35:13 by tkarri           ###   ########.fr       */
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
		root->item = str;
	}
	return (root);
}
