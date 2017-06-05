/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_modificateur2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:27:36 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 11:27:37 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE env->tab

static	void	*flags_itoa_d_i_1(intmax_t nb, t_env *env, va_list *ap)
{
	if (TYPE.type_j)
	{
		nb = va_arg(*ap, intmax_t);
		return (ft_itoa_intmax_t((intmax_t)nb));
	}
	else if (TYPE.type_ll)
	{
		nb = va_arg(*ap, long long int);
		return (ft_itoa_long_long((long long int)nb));
	}
	else if (TYPE.type_l)
	{
		nb = va_arg(*ap, long);
		return (ft_itoa_long((long)nb));
	}
	else if (TYPE.type_z)
	{
		nb = va_arg(*ap, size_t);
		return (ft_itoa_long_long((size_t)nb));
	}
	return (NULL);
}

static	void	*flags_itoa_d_i_2(intmax_t nb, t_env *env, va_list *ap)
{
	if (TYPE.type_h)
	{
		nb = va_arg(*ap, int);
		return (ft_itoa_short((short int)nb));
	}
	else if (TYPE.type_hh)
	{
		nb = va_arg(*ap, int);
		return (ft_itoa_signed_char((signed char)nb));
	}
	else
	{
		nb = va_arg(*ap, int);
		return ((char *)ft_itoa((int)nb));
	}
	return (NULL);
}

char			*flags_itoa_d_i(t_env *env, va_list *ap)
{
	intmax_t	nb;
	char		*tmp;

	nb = 0;
	tmp = flags_itoa_d_i_1(nb, env, ap);
	if (tmp != NULL)
		return (tmp);
	tmp = flags_itoa_d_i_2(nb, env, ap);
	if (tmp != NULL)
		return (tmp);
	return (NULL);
}
