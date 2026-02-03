/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:04:11 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/03 16:25:49 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_isspace(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

double	int_part(char **s, double *sign)
{
	double	i;

	i = 0.0;
	while (ft_isspace (**s) == 1)
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1.0;
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		i = i * 10.0 + (**s - '0');
		(*s)++;
	}
	return (i);
}

double	frac_part(char **s)
{
	double	frac;
	double	div;

	div = 1.0;
	frac = 0.0;
	if (**s == '.')
	{
		(*s)++;
		while (**s >= '0' && **s <= '9')
		{
			frac = frac * 10.0 + (**s - '0');
			(*s)++;
			div *= 10.0;
		}
	}
	return (frac / div);
}

double	std(char *s)
{
	double	sign;
	double	i;
	double	frac;

	sign = 1.0;
	i = int_part(&s, &sign);
	frac = frac_part(&s);
	i += frac;
	i *= sign;
	return (i);
}
