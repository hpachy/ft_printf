/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_padding_app.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:02:14 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/25 17:02:15 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE env->tab

void			ft_padding(char *str, t_env *env)
{
	int		padding;

	padding = 0;
	env->padding = 0;
	if (str[env->index - 1] != '.')
	{
		while (str[env->index] >= 48 && str[env->index] <= 57)
		{
			padding = padding * 10;
			padding = padding + str[env->index] - 48;
			env->index++;
		}
		env->padding = padding;
	}
	else
		env->padding = 0;
}

void			padding_x_x_o(char **str, t_env *env, char c)
{
	if (TYPE.type_less == 1 && TYPE.type_0 == 1)
		*str = flags_less_app(*str, env, c);
	if (TYPE.type_less == 0 && TYPE.type_0 == 1)
		*str = flags_zero_app(*str, env, c);
	if (TYPE.type_less == 1 && TYPE.type_0 == 0)
		*str = flags_less_app(*str, env, c);
	if (TYPE.type_less == 0 && TYPE.type_0 == 0)
		*str = flags_padd_app(*str, env, c);
}

static	void	padding_i_d_d_2(char **str, t_env *env, char c)
{
	if (TYPE.type_blank)
	{
		env->padding -= 1;
		if (!env->tab.type_0)
			*str = flags_padd_app(*str, env, c);
		else
			*str = flags_zero_padding_app(*str, env, c);
		flags_blank_app(str, env, c);
	}
	if (TYPE.type_0)
		*str = flags_zero_padding_app(*str, env, c);
	if (TYPE.type_less == 0 && TYPE.type_0 == 0)
	{
		if (env->signe == '-')
			env->padding += 1;
		*str = flags_padd_app(*str, env, c);
	}
}

void			padding_i_d_d(char **str, t_env *env, char c)
{
	if (TYPE.type_add && TYPE.type_0)
	{
		env->padding -= 1;
		env->tab.type_add = 0;
		env->tab.type_0 = 0;
		*str = flags_zero_padding_app(*str, env, c);
		flags_add_app(str, env, c);
	}
	if (TYPE.type_add)
	{
		flags_add_app(str, env, c);
		if (TYPE.type_less == 0)
			*str = flags_padd_app(*str, env, c);
	}
	if (TYPE.type_less)
		*str = flags_less_app(*str, env, c);
	padding_i_d_d_2(str, env, c);
}

void			padding_c_s(char **str, t_env *env, char c)
{
	int		tmp;

	tmp = (int)ft_strlen(*str);
	tmp = env->padding - tmp;
	if (tmp < 0)
		tmp = 0;
	if (TYPE.type_less == 1 && TYPE.type_0 == 1)
		TYPE.type_0 = 0;
	if (c == 's' || c == 'c')
	{
		if (TYPE.type_0 == 1)
			*str = ft_strjoin(ft_c_strnew(tmp, '0'), *str);
		else if (TYPE.type_less == 1)
			*str = ft_strjoin(*str, ft_c_strnew(tmp, ' '));
		else
			*str = ft_strjoin(ft_c_strnew(tmp, ' '), *str);
	}
}
