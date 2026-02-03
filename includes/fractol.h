/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:45:10 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/03 16:44:00 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define LENGTH 800

typedef struct s_fractal
{
	double	x;
	double	y;
	double	zoom;
	double	jul_real;
	double	jul_imaginary;
	void	*mlx;
	void	*image;
	void	*window;
	char	*address;	
	int		type;
	int		colors;
	int		bites_per_line;
	int		bites_per_pixel;
	int		byte_order;
	int		julia_mouse;
}				t_fractal;

typedef struct s_complex_julia
{
	double	real;
	double	imaginary;
}				t_complex_julia;

double	std(char *s);
void	mandelbrot(t_fractal *fractal);
void	julia(t_fractal *fractal);
void	put_pixel(int x, int y, t_fractal *fractal, int color);
void	julia_util(t_fractal *fractal, int x, int y, t_complex_julia c);
int		ft_strcmp(const char *s1, const char *s2);
int		on_key_press(int code, t_fractal *fractal);
void	mandelbrot_util(t_fractal *fractal, int x, int y);
int		on_mouse_click(int button, int x, int y, t_fractal *fractal);
int		exit_program(t_fractal *fractal);
int		calculate_color(int iter_count, int set);
int		exit_programm(t_fractal *fractal);

#endif
