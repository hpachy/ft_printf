/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prinft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:22:59 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/05 15:23:00 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# define BUFF_SIZE 4096

typedef	struct		s_flags_parser
{
	int				type_sharp;
	int				type_add;
	int				type_less;
	int				type_blank;
	int				type_l;
	int				type_ll;
	int				type_h;
	int				type_hh;
	int				type_0;
	int				type_j;
	int				type_z;
	int				type_point;
}					t_flags_parser;

typedef	struct		s_env
{
	int				index;
	int				precision;
	char			signe;
	int				padding;
	char			buff[4096];
	int				index_buff;
	int				tab_return;
	t_flags_parser	tab;
}					t_env;

typedef struct		s_flags
{
	char			c;
	int				(*flags)(char *str, t_env *env);
}					t_flags;

typedef struct		s_conv
{
	char			c;
	char			*(*conv)(char *str, t_env *env, va_list *ap);
}					t_conv;

int					parser(char *str, t_env *env, va_list *ap);
void				print_tab(t_env *env);
void				fill_tab(char *tab, int size, t_env *env, const char *str);
int					flags_sharps(char *str, t_env *env);
int					flags_zero(char *str, t_env *env);
int					flags_less(char *str, t_env *env);
int					flags_add(char *str, t_env *env);
int					flags_blank(char *str, t_env *env);
int					flags_h_hh(char *str, t_env *env);
int					flags_l_ll(char *str, t_env *env);
int					flags_j(char *str, t_env *env);
int					flags_z(char *str, t_env *env);
void				init_flags(t_env *env);
char				*conver_string(char *str, t_env *env, va_list *ap);
char				*conver_unicode_string(char *str, t_env *env, va_list *ap);
char				*conver_unicode_char(char *str, t_env *env, va_list *ap);
char				*conver_pointer(char *str, t_env *env, va_list *ap);
char				*conver_int(char *str, t_env *env, va_list *ap);
char				*conver_octet(char *str, t_env *env, va_list *ap);
char				*conver_octet(char *str, t_env *env, va_list *ap);
char				*conver_unsignedint(char *str, t_env *env, va_list *ap);
char				*conver_hexa(char *str, t_env *env, va_list *ap);
char				*conver_char(char *str, t_env *env, va_list *ap);
char				*conver_unsignedlongint(char *str, t_env *env, va_list *ap);
void				flags_sharps_app(char **str, t_env *env, char c);
char				*flags_zero_app(char *str, t_env *env, char c);
char				*flags_less_app(char *str, t_env *env, char c);
void				flags_add_app(char **str, t_env *env, char c);
void				flags_blank_app(char **str, t_env *env, char c);
void				flags_padding_app(char **str, t_env *env, char c);
char				*flags_padd_app(char *str, t_env *env, char c);
int					flags_precision(char *str, t_env *env);
void				flags_precision_app(char **str, t_env *env, char c);
char				*flags_zero_precission_app(char *str, t_env *env, char c);
void				padding_x_x_o(char **str, t_env *env, char c);
void				padding_i_d_d(char **str, t_env *env, char c);
char				*conver_d(char *str, t_env *env, va_list *ap);
char				*conver_u(char *str, t_env *env, va_list *ap);
char				*conver_o(char *str, t_env *env, va_list *ap);
char				*conver_lu(char *str, t_env *env, va_list *ap);
char				*flags_modif_itoa(char *str, t_env *env, va_list *ap);
char				*flags_itoa_d_i(t_env *env, va_list *ap);
char				*flags_itoa_o_x_x(char *str, t_env *env, va_list *ap);
void				padding_c_s(char **str, t_env *env, char c);
void				fill_tab_char(t_env *env, char str);
void				ft_padding(char *str, t_env *env);
char				*conver_pourcent(char *str, t_env *env, va_list *ap);
char				*flags_zero_padding_app(char *str, t_env *env, char c);
void				init_env(t_env *env);

#endif
