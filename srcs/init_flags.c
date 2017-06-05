/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 11:26:30 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/20 11:26:32 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_flags(t_env *env)
{
	if (env->tab.type_sharp == 1)
		env->tab.type_sharp = 0;
	else if (env->tab.type_add == 1)
		env->tab.type_add = 0;
	else if (env->tab.type_less == 1)
		env->tab.type_less = 0;
	else if (env->tab.type_blank == 1)
		env->tab.type_blank = 0;
	else if (env->tab.type_l == 1)
		env->tab.type_l = 0;
	else if (env->tab.type_ll == 1)
		env->tab.type_ll = 0;
	else if (env->tab.type_h == 1)
		env->tab.type_h = 0;
	else if (env->tab.type_hh == 1)
		env->tab.type_hh = 0;
	else if (env->tab.type_0 == 1)
		env->tab.type_0 = 0;
	else if (env->tab.type_j == 1)
		env->tab.type_j = 0;
	else if (env->tab.type_z == 1)
		env->tab.type_z = 0;
}

void			init_env(t_env *env)
{
	env->index = 0;
	env->index_buff = 0;
	env->padding = 0;
	env->tab_return = 0;
	env->precision = 0;
	ft_bzero(&env->tab, sizeof(t_flags_parser));
}
