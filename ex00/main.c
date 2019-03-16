/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:04:35 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/16 18:25:06 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		need_size(char *input)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if (input[i] !='\n' &&input[i] != '\r' && input[i] !='\v'
			&& input[i] != '\f' && input[i] != '\t' && input[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

char	*remove_spaces(char *input)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0; //Checking ".....(12+3-4+5).." --> remove such scope
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

int		eval_expr(char *input)
{
	t_btree *root;
	char *str;

	str = remove_spaces(input);
	printf("%s-\n\n", str);
	root = create_root(str);
	create_tree(root, -1);
	printf("%c\n", root->sign);
	printf("%s\n", (root->left)->item);
	printf("%c\n", (root->right)->sign);
	printf("%s\n", ((root->right)->right)->item);
	printf("%c\n", ((root->right)->right)->sign);
	printf("%s\n", ((root->right)->right)->item);
	return (0); //DELETE
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
