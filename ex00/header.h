/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:56:10 by tkarri            #+#    #+#             */
/*   Updated: 2019/03/17 16:36:41 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

# include <stdlib.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
	char			sign;
}					t_btree;

void				ft_putchar(char c);

void				ft_putnbr(int num);

int					split_operations(char c, char *str);

t_btree				*create_root(char *str);

void				create_tree(t_btree *current, int i);

void				delete_external_scopes(char *str);

int					calculate_tree(t_btree *current);

int					need_size(char *input);

char				*remove_spaces(char *input);

char				*get_part_before(char *str, int j);

char				*get_part_after(char *str, int i);

int					split_oper(char c, char *str);

int					split_minus(char *str);

#endif
