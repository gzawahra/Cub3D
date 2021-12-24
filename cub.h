/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gizawahr <gizawahr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 05:46:51 by gizawahr          #+#    #+#             */
/*   Updated: 2021/12/24 05:46:54 by gizawahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define SUCCESS 1
# define ERROR -1
# define NO 2
# define SO 3
# define EA 4
# define WE 5
# define MVS 0.06
# define ROTS 0.06

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define LFT_AR 65361
# define RGT_AR 65363

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

typedef	struct	s_key
{
	int			w;
	int			a;
	int			d;
	int			s;
	int			lft_ar;
	int			rgt_ar;
	int			esc;
}				t_key;

typedef struct	s_img
{
	void		*img_id;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_ray
{
	double		cam_posx;
	double		ray_dir_y;
	double		ray_dir_x;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	double		start_posx;
	double		start_posy;
	double		time;
	double		old_time;
	double		wall_dist;
	double		wall_x;
	int			hit;
	int			side;
	double		dirx;
	double		diry;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		planx;
	double		plany;
	int			tex_x;
	int			tex_y;
	double		*zbuffer;
}				t_ray;

typedef struct	s_position
{
	int		x;
	int		y;
	char	dir;
}				t_position;

typedef struct	s_sprite
{
	int					x;
	int					y;
	struct s_sprite		*next;
}				t_sprite;

typedef struct	s_text
{
	char	*path;
	int		w;
	int		h;
	int		*text_img;
	void	*text_id;
	int		bpp;
	int		size;
	int		endian;
}				t_text;

typedef struct	s_ps
{
	double		sprite_x;
	double		sprite_y;
	double		invdet;
	double		transform_x;
	double		transform_y;
	int			spritescreen_x;
	int			spriteheight;
	int			drawstart_y;
	int			drawend_y;
	int			drawstart_x;
	int			drawend_x;
	int			spritewidth;
	int			tex_x;
	int			tex_y;
	int			color;
}				t_ps;

typedef struct	s_params
{
	int			res_w;
	int			res_h;
	int			map_start;
	t_text		*no_text;
	t_text		*so_text;
	t_text		*we_text;
	t_text		*ea_text;
	t_text		*sprit_text;
	char		**map_tab;
	int			*fl_color;
	int			*ceil_color;
	int			start;
	int			m_size;
	t_position	*player_pos;
	t_sprite	*sprite;
	t_list		*map;
	void		*mlx_id;
	void		*window_id;
	void		*img_id;
	int			endian;
	int			bpp;
	int			line_length;
	char		*addr;
	t_ray		*ray;
	t_key		*key;
	int			save_opt;
	t_ps		*ps;
	char		*line;
}				t_params;

void			ft_init_params(t_params *par);
void			ft_get_params(t_params *par, const char *filepath);
void			ft_settings(t_params *par, char *line);
void			ft_set_res(t_params *par, char *line);
void			ft_set_text(char *line, t_params *par, t_text *text);
void			ft_so_tex(char *line, t_params *par);
void			ft_no_tex(char *line, t_params *par);
void			ft_ea_tex(char *line, t_params *par);
void			ft_we_tex(char *line, t_params *par);
void			ft_sp_tex(char *line, t_params *par);
void			ft_floor_color(t_params *par, const char *line);
void			ft_ceil_color(t_params *par, const char *line);
void			ft_get_spr_pos(t_sprite **begin, int x, int y);
void			ft_init_gen(t_params *par);
void			ft_error_display(char *msg);
void			ft_quit(char *msg, t_params *par);
void			ft_get_map(t_params *par, const char *line);
void			ft_valid_params(t_params *par);
char			**ft_map_tab(t_params *par);
int				ft_is_valid_map(t_params *par);
int				ft_ismap(const char *line, t_params *par);
int				ft_check_inbtween(int x, t_params *par);
int				ft_firstnlast_char(char *line);
int				ft_firstnlast_line(char *line);
int				ft_check_around(int x, int y, char **map);
int				ft_is_valid_char(char *s, char c);
int				ft_is_valid_file(t_params *par, const char *filepath);
int				*ft_get_color(char *trim);
int				ft_chr_char(char *str);
t_position		*ft_set_position(int x, int y, char dir);
t_sprite		*ft_new_spr_pos(int x, int y);
t_text			*ft_init_text(void);
void			ft_check_text(t_params *par, t_text *text);

void			ft_init_mlx(t_params *par);
void			ft_game_starter(t_params *par);
int				ft_exit(int key_code, t_params *par);
int				ft_rgb(int t, int r, int g, int b);
void			cast_scene(t_params *par, t_ray *ray);
void			ft_frame_pixel(t_params *par, int x, int y, int color);
void			ft_init_dir(t_params *par);
int				key_press(int key_code, t_params *par);
int				key_rel(int key_code, t_params *par);
int				ft_movement(t_params *par);
int				save_bmp(t_params *par);
void			ft_raycast_handle(t_params *par);
void			ft_screenshot(t_params *par);
int				ft_get_pixel(t_text *f, int x, int y);
void			sort_sprites(t_sprite *lst, t_params *par);
void			draw_sprites(t_sprite *sprite, t_params *par,
				t_ray *ray, t_ps *ps);
void			ft_cast_flcl(t_params *par);
int				ft_close(t_params *par);
void			ft_step(t_ray *ray);
void			get_wall_dist(t_ray *ray);
t_text			*wich_text(int side, t_params *par);
void			ft_trace_line(t_params *par, int x, int y, int color);
void			free_sprites(t_sprite *sprite);
void			free_map(t_params *par);
void			free_map_list(t_list *map);
void			free_text(t_text *text);
void			ft_check_text(t_params *par, t_text *text);
#endif
