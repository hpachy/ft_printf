/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_convertion_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:05:25 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 17:05:26 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char			*conver_string(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	tmp = flags_modif_itoa(str, env, ap);
	if (env->tab.type_point == -1)
		tmp = ft_strnew(1);
	if (env->tab.type_sharp == 1)
		flags_sharps_app(&tmp, env, str[env->index]);
	flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!tmp)
		tmp = "(null)";
	return (tmp);
}

char			*conver_pointer(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	env->tab.type_ll = 1;
	tmp = flags_modif_itoa(str, env, ap);
	if (env->precision)
		flags_precision_app(&tmp, env, 'x');
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, 'x');
	if (!env->padding && !env->precision)
		flags_precision_app(&tmp, env, 'x');
	flags_sharps_app(&tmp, env, 'x');
	if (tmp[ft_strlen(tmp) - 1] == '0' && env->tab.type_point == -1)
		tmp[ft_strlen(tmp) - 1] = 0;
	return (tmp);
}

void			conver_char_less(char *str, t_env *env, char tmp1, char *tmp)
{
	if (env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!env->padding && !env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	fill_tab(env->buff, ft_strlen(tmp), env, tmp);
	fill_tab_char(env, tmp1);
}

void			conver_char_0(char *str, t_env *env, char tmp1, char *tmp)
{
	fill_tab_char(env, tmp1);
	if (env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!env->padding && !env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	fill_tab(env->buff, ft_strlen(tmp), env, tmp);
}

char			*conver_char(char *str, t_env *env, va_list *ap)
{
	char	tmp1;
	char	*tmp;

	(void)str;
	(void)env;
	tmp1 = va_arg(*ap, int);
	tmp = ft_strnew(1);
	env->padding -= 1;
	if (env->tab.type_less == 0)
		conver_char_less(str, env, tmp1, tmp);
	else if (env->tab.type_less)
		conver_char_0(str, env, tmp1, tmp);
	return (NULL);
}
