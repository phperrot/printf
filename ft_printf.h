/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:59:39 by phperrot          #+#    #+#             */
/*   Updated: 2020/02/01 14:59:30 by phperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef __FT_PRINTF_H
#	define __FT_PRINTF_H
#	include <unistd.h>
#	include <fcntl.h>
#	include <stdlib.h>
#	include <stdarg.h>
#	include "libft/libft.h"

typedef struct		s_struct
{
	char			*flag;
	int				min_width;
	int				pound_flag;
	char			*prec;
	char			type;
	char			*content;
}					t_struct;

typedef struct		s_struct1
{
	int				marker1;
	int				marker2;
	int				len_arg;
	int				pound_flag;
	int				double_percent;
}					t_dstruct;

unsigned long		convbase(unsigned long n, t_struct *param,
					int i, char **str);
char				**ft_printf_args(int nb, const char *s, ...);
int					ft_test_presence_char(char c, char *set);
t_dstruct			*ft_read_string(char *str, va_list arguments, int i);
int					ft_test_presence_str(char *s, char *set);
t_struct			*ft_sstructnew(char *content);
t_dstruct			*ft_dstructnew(int content);
int					ft_printf(const char *s, ...);
int					ft_test_presence_str(char *s, char *set);
char				*ft_add_char(char *str, char c);
char				*ft_precision(char *argv, t_struct *param);
void				ft_width(char **precision_str, t_struct *param);
int					ft_display(t_struct *param, char *argv);
char				*ft_strdup_char(char c);
char				*ft_add_char(char *str, char c);
char				*ft_strreplace(char *str, char old, char new);
char				*ft_ctoa(char c);
char				*ft_get_arg(va_list arguments, t_struct **param);
int					ft_abs(int n);
char				*ft_strjoin_free(char const *s1, char const *s2, int param);
int					check_double_percent(char *str, int *i);
int					check_flag(char *str, int i, t_struct **param);
int					check_width(char *str, int i, t_struct **param);
int					check_prec_type(char *s, int i, t_struct **par);

#	endif
#	ifndef SET_FLAG
#	define SET_FLAG "0-#"
#	endif
#	ifndef SET_CONVERSION
#	define SET_CONVERSION "cspdiuxXo%"
#	endif
#	ifndef SET_BASE
#	define SET_BASE "oxX"
#	endif
#	ifndef SET_CHAR
#	define SET_CHAR "cs"
#	endif
#	ifndef INVISI_CHAR
#	define INVISI_CHAR "\t\v\r\f"
#	endif
