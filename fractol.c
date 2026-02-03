/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:39:40 by anihamba          #+#    #+#             */
/*   Updated: 2026/02/03 16:25:22 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	r_valid_params(double num1, double num2)
{
	if ((num1 >= -2.0 && num1 <= 2.0) && (num2 >= -2.0 && num2 <= 2.0))
		return (1);
	return (0);
}

void	init_fractol_mandelbrot(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->mlx, LENGTH, LENGTH, "FRACT-OL");
	fractal->image = mlx_new_image(fractal->mlx, LENGTH, LENGTH);
	fractal->address = mlx_get_data_addr(fractal->image,
			&fractal->bites_per_pixel,
			&fractal->bites_per_line, &fractal->byte_order);
	fractal->zoom = 1.0;
	fractal->colors = 0;
	fractal->julia_mouse = 0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->type = 0;
	fractal->jul_real = 0;
	fractal->jul_imaginary = 0;
	mandelbrot(fractal);
	mlx_hook(fractal->window, 17, 1L << 0, exit_program, fractal);
	mlx_key_hook(fractal->window, on_key_press, fractal);
	mlx_mouse_hook(fractal->window, on_mouse_click, fractal);
	mlx_loop(fractal->mlx);
}

void	init_fractol_julia(t_fractal *fractal, double real, double imaginary)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->window = mlx_new_window(fractal->mlx, LENGTH, LENGTH, "FRACT-OL");
	fractal->image = mlx_new_image(fractal->mlx, LENGTH, LENGTH);
	fractal->address = mlx_get_data_addr(fractal->image,
			&fractal->bites_per_pixel,
			&fractal->bites_per_line, &fractal->byte_order);
	fractal->zoom = 1.0;
	fractal->colors = 0;
	fractal->julia_mouse = 0;
	fractal->x = 0.0;
	fractal->y = 0.0;
	fractal->type = 1;
	fractal->jul_real = real;
	fractal->jul_imaginary = imaginary;
	julia(fractal);
	mlx_hook(fractal->window, 17, 1L << 0, exit_programm, fractal);
	mlx_key_hook(fractal->window, on_key_press, fractal);
	mlx_mouse_hook(fractal->window, on_mouse_click, fractal);
	mlx_loop(fractal->mlx);
	mlx_clear_window(fractal->mlx, fractal->window);
	julia(fractal);
}

void	error(void)
{
	write(2, "Usage:	./fractol	mandelbrot | julia [-2, 2] [-2, 2]\n", 52);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc != 2 && argc != 4)
		error();
	else if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		init_fractol_mandelbrot(&f);
	else if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0
			&& r_valid_params(std(argv[2]),
				std(argv[3])) == 1))
		init_fractol_julia(&f, std(argv[2]), std(argv[3]));
	else
		error();
	return (0);
}
