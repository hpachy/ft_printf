/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_app_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 17:40:50 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/23 17:40:51 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE env->tab

static	void	precision_d_i_d(char **str, t_env *env, char c)
{
	if (TYPE.type_add)
	{
		*str = flags_zero_precission_app(*str, env, c);
		if (!env->padding)
			flags_add_app(str, env, c);
	}
	if (TYPE.type_less)
	{
		*str = flags_zero_precission_app(*str, env, c);
		if (!env->padding)
			flags_less_app(*str, env, c);
	}
	if (TYPE.type_blank)
	{
		*str = flags_zero_precission_app(*str, env, c);
		if (!env->padding)
			flags_blank_app(str, env, c);
	}
	if (TYPE.type_0 && env->precision)
		*str = flags_zero_precission_app(*str, env, c);
	else
		*str = flags_zero_precission_app(*str, env, c);
}

static	void	precision_s(char **str, t_env *env)
{
	int		tmp;

	tmp = (int)ft_strlen(*str);
	if (env->precision > tmp || env->precision < 0)
		return ;
	if (env->precision <= tmp && env->precision > 0)
		*str = ft_strsub(*str, 0, env->precision);
}

void			flags_precision_app(char **str, t_env *env, char c)
{
	if (c == 'd' || c == 'i')
	{
		if (TYPE.type_add && TYPE.type_blank)
			TYPE.type_blank = 0;
		if (TYPE.type_less && TYPE.type_0)
			TYPE.type_0 = 0;
		precision_d_i_d(str, env, c);
	}
	else if (c == 'x' || c == 'X' || c == 'o' ||
		c == 'u' || c == 'U' || c == 'O')
	{
		if (TYPE.type_add)
			TYPE.type_add = 0;
		if (TYPE.type_blank)
			TYPE.type_blank = 0;
		if (TYPE.type_add && TYPE.type_blank)
			TYPE.type_blank = 0;
		if (TYPE.type_less && TYPE.type_0)
			TYPE.type_0 = 0;
		*str = flags_zero_precission_app(*str, env, c);
	}
	else if (c == 's')
		precision_s(str, env);
}
