/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_flags_modificateur3.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:39:59 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 11:40:00 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPE env->tab
#define C str[env->index]

static	void	*flags_itoa_o_x_x_1(char *str, t_env *env, va_list *ap)
{
	int		base;

	base = 10;
	if (C == 'o' || C == 'O')
		base = 8;
	else if (C == 'X' || C == 'x' || C == 'p')
		base = 16;
	else if (C == 'u' || C == 'U')
		base = 10;
	if (TYPE.type_j)
		return (ft_itoa_base(va_arg(*ap, uintmax_t), base));
	else if (TYPE.type_ll)
		return (ft_itoa_ulong_long(va_arg(*ap, unsigned long long int), base));
	return (NULL);
}

static	void	*flags_itoa_o_x_x_2(char *str, t_env *env, va_list *ap)
{
	int		base;

	base = 10;
	if (C == 'o' || C == 'O')
		base = 8;
	else if (C == 'X' || C == 'x' || C == 'p')
		base = 16;
	else if (C == 'u' || C == 'U')
		base = 10;
	if (TYPE.type_l)
		return (ft_itoa_ulong(va_arg(*ap, unsigned long), base));
	else if (TYPE.type_z)
		return (ft_itoa_base_size(va_arg(*ap, size_t), base));
	return (NULL);
}

static	void	*flags_itoa_o_x_x_3(char *str, t_env *env, va_list *ap)
{
	int		base;

	base = 10;
	if (C == 'o' || C == 'O')
		base = 8;
	else if (C == 'X' || C == 'x' || C == 'p')
		base = 16;
	else if (C == 'u' || C == 'U')
		base = 10;
	if (TYPE.type_h)
		return (ft_itoa_base_short((unsigned short int)va_arg(*ap, int), base));
	else if (TYPE.type_hh)
		return (ft_itoa_base_uchar((unsigned char)va_arg(*ap, int), base));
	else
		return (ft_itoa_ulong_long(va_arg(*ap, unsigned int), base));
	return (NULL);
}

char			*flags_itoa_o_x_x(char *str, t_env *env, va_list *ap)
{
	char		*tmp;

	tmp = flags_itoa_o_x_x_1(str, env, ap);
	if (tmp != NULL)
		return (tmp);
	free(tmp);
	tmp = flags_itoa_o_x_x_2(str, env, ap);
	if (tmp != NULL)
		return (tmp);
	free(tmp);
	tmp = flags_itoa_o_x_x_3(str, env, ap);
	if (tmp != NULL)
		return (tmp);
	free(tmp);
	return (NULL);
}
