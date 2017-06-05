/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_convertion3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:51:06 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/26 11:51:08 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conver_d(char *str, t_env *env, va_list *ap)
{
	env->tab.type_l = 1;
	return (conver_int(str, env, ap));
}

char	*conver_o(char *str, t_env *env, va_list *ap)
{
	env->tab.type_l = 1;
	return (conver_octet(str, env, ap));
}

char	*conver_lu(char *str, t_env *env, va_list *ap)
{
	env->tab.type_l = 1;
	return (conver_u(str, env, ap));
}

char	*conver_u(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	tmp = flags_modif_itoa(str, env, ap);
	if (env->tab.type_sharp == 1)
		flags_sharps_app(&tmp, env, str[env->index]);
	if (env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!env->precision && !env->padding)
		flags_precision_app(&tmp, env, str[env->index]);
	if (tmp[ft_strlen(tmp) - 1] == '0' && env->tab.type_point == -1)
		tmp[ft_strlen(tmp) - 1] = 0;
	return (tmp);
}

char	*conver_octet(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	tmp = flags_modif_itoa(str, env, ap);
	if (!env->tab.type_sharp &&
		tmp[ft_strlen(tmp) - 1] == '0' && env->tab.type_point == -1)
		tmp[0] = '\0';
	if (env->tab.type_sharp == 1)
		flags_sharps_app(&tmp, env, str[env->index]);
	if (env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (env->padding > env->precision)
		flags_padding_app(&tmp, env, str[env->index]);
	if (!env->padding && !env->precision)
		flags_precision_app(&tmp, env, str[env->index]);
	if (ft_strcmp(tmp, "00") == 0)
		return ("0");
	return (tmp);
}
