/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:56:10 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/16 16:45:11 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

# include <stdlib.h>

#include <stdio.h> //delete me

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
	char			sign;
}					t_btree;

void				ft_putchar(char c);

void				ft_putstr(char *str);

void				ft_putnbr(int num);

int					split_operations(char c, char *str);

t_btree				*create_root(char *str);

void				create_tree(t_btree *current, int i);

#endif
