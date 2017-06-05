/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_flags_modificateur1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 12:54:37 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/26 12:54:37 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE env->tab
#define C str[env->index]

static char		*flags_s(va_list *ap)
{
	char	*tmp;

	tmp = va_arg(*ap, char *);
	return (tmp);
}

char			*flags_modif_itoa(char *str, t_env *env, va_list *ap)
{
	if (C == 'd' || C == 'i' || C == 'D')
		return (flags_itoa_d_i(env, ap));
	else if (C == 'o' || C == 'x' || C == 'X' || C == 'u'
		|| C == 'U' || C == 'p' || C == 'O')
		return (flags_itoa_o_x_x(str, env, ap));
	else if (C == 's')
		return (flags_s(ap));
	return (NULL);
}
