/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:16:07 by obouhrir          #+#    #+#             */
/*   Updated: 2023/10/08 17:29:00 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "parse/p_cub3d.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "/Users/obouhrir/MLX42/include/MLX42/MLX42.h"
# include "gnl/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 550
# endif

# define HEIGHT 1080
# define WIDTH 1920

# define PIXEL_SIZE 50
# define PIXEL_SIZE_P 3
# define SPEED 3
# define ROTATE 0.03
# define FOV 60
# define TAIL 50

# define M_PIXEL_SIZE 10
# define M_PIXEL_SIZE_P 2

typedef struct s_hor
{
	float	xstep;
	float	ystep;
	float	x_hor;
	float	y_hor;
	float	xinc;
	float	yinc;
}t_hor;
typedef struct s_ver
{
	float	xstep;
	float	ystep;
	float	x_ver;
	float	y_ver;
	float	xinc;
	float	yinc;
}t_ver;

typedef struct s_txt
{
	mlx_texture_t	*no_txt;
	mlx_texture_t	*ea_txt;
	mlx_texture_t	*we_txt;
	mlx_texture_t	*so_txt;
	mlx_texture_t	*wall_txt;
}t_txt;
typedef struct s_mouse
{
	int	dx;
	int	dy;
	int	mtmp;
}t_mouse;
typedef struct s_data
{
	int				counter;
	mlx_image_t		*image;
	mlx_t			*mlx;
	int				width;
	int				height;
	int				zoom;
	float			x;
	float			y;
	struct s_colors	*rgb;
	char			**cub;
	char			**map;
	char			*northpath;
	char			*southpath;
	char			*westpath;
	char			*eastpath;
	char			*florcolor;
	char			*skycolor;
	int				p;
	struct s_hor	hor;
	struct s_ver	ver;
	struct s_colors	*color;
	struct s_player	*player;
	struct s_txt	pnj;
	struct s_mouse	mouse;
}t_data;

typedef struct s_colors
{
	int	sr;
	int	sg;
	int	sb;
	int	fr;
	int	fg;
	int	fb;
}t_colors;

typedef struct s_player
{
	double	wall_height;
	double	intersection_x;
	double	intersection_y;
	double	dis;
	double	ray;
	double	view;
	double	x;
	double	y;
	double	proj_dis;
	float	tmpy;
	float	tmpx;
}	t_player; 
typedef struct s_help
{
	int		i;
	float	dis;
	float	wallhight;
	double	ystart;
	double	yend;
	int		color;
	double	txtsize;
	double	txtheight;
	int		j;
	int		fd;
	int		counter;
	char	*backup;
}t_help;
// parsing part
void		parse(int ac, char **av, t_data *utils, t_colors *rgb);
int			count_lines_map(char *s);
int			is_not_empty(char *s);
int			check_wall(t_data *map, double y, double x);
void		free_doublearr(char **tab);
void		error(char *str, t_data *utils);
void		freeall(t_data *utils);
void		f_name_check(char *name);
void		checknl(t_data *utils);
void		files_exist(t_data *utils);
void		files_exist2(t_data *utils);
void		colors_data_checks(t_data *utils);
void		colors_data_err(t_data *utils);
void		colors_data_sky(t_data *utils);
void		colors_data_floor(t_data *utils);
void		check_rgb_sky(t_colors *rgb);
void		check_rgb_floor(t_colors *rgb);
void		map_checker(t_data *utils, int lines);
void		map_checker2(t_data *utils);
void		player_checks(t_data *utils);
void		fillcoordinates(t_data *utils);
void		fillcoordinates2(t_data *utils, int i);
void		fillmap(t_data *utils, char *s, int lines);
void		fillinfo(t_data *utils, char *s);
void		fill_rgb(t_data *utils, t_colors *rgb);
void		fill_f(char **backup, t_colors *rgb);
void		fill_s(char **backup, t_colors *rgb);
void		checktab(t_data *utils);
void		checktab2(t_data *utils);
void		rgbs_checks(char **s);
int			ft_nbrlen(int n);
void		north(t_data *utils, int i);
void		west(t_data *utils, int i);
void		east(t_data *utils, int i);
void		south(t_data *utils, int i);
int			check_space(t_data *utils, int i, int j);
// exec part
void		cub3d(t_data *map, int ray_i);
void		draw(void *mlx);
void		mini_map(t_data *map);
void		hook( void *hook);
void		ceiling(t_data *map);
void		flooor(t_data *map);
void		render_wall(t_data *map, double *wallhit, int ray_i, int check);
uint32_t	get_vercolor(t_data *map, double txthight, double *hitwall);
uint32_t	get_horcolor(t_data *map, double txthight, double *hitwall);
// void	render_ver(t_data *map, double *wallhit, int ray_i, int color);
char		*get_next_line(int fd);
size_t		lenth(char *str);
char		*ft_join(char *arc, char *buff);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		cub3d(t_data *map, int ray_i);
void		hor_steps(t_data *map);
void		ver_steps(t_data *map);
void		get_ver(t_data *map, double *wall);
void		get_hor(t_data *map, double *wall);
double		rad(int angle);
void		map_length(t_data *map);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void		get_player_position(t_data *map);
void		draw_player(t_data *map, int y, int x, int color);
void		init(t_data *map);
int			check_hit(t_data *map, double y, double x);
void		fixed_view(t_data *map);
void		rotation(t_data *map);
void		fixed_view(t_data *map);
void		mouse(double x, double __unused y, void *param);
#endif