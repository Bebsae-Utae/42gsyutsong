/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:25:24 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/11 18:52:03 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_ESC			65307
# define KEY_W				119
# define KEY_S				115
# define KEY_A				97
# define KEY_D				100
# define BUFFER_SIZE		42

typedef struct s_param
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		x;
	int		y;
	void	*dorong;
	void	*tree;
	void	*tile;
	void	*item;
	void	*door;
	int		where_dorong;
	int		width;
	int		height;
	char	*mapdatas;
	char	*newmap;
	int		cnt_dorong;
	int		cnt_item;
	int		cnt_door;
	int		cnt_work;
	int		get_item;
	int		*visited;
}	t_param;

void	set_param(t_param *par);
void	find_dorong(t_param *par);

void	draw_map(t_param *par);
void	make_map(t_param *par);
void	read_map(t_param *par, char *argv);
void	check_wall(t_param *par);
void	check_map(t_param *par);

void	check_map2(t_param *par, int dorong, int item, int door);
void	check_rec(t_param *par);
void	check_mapname(t_param *par, char *filename);
int		dfs(t_param *par, int idx, int width, int height);
int		valid_path(t_param *par);

int		push_btn(int keycode, t_param *par);
void	move_w(t_param *par);
void	move_a(t_param *par);
void	move_s(t_param *par);
void	move_d(t_param *par);

int		exit_btn(t_param *par);
int		clear_game(t_param *par);

int		ft_strlen(char *newmap);
char	*int_to_char(long num);
char	*reverse_str(char *str);
int		num_len(long num);

void	printer(t_param *par);
void	print_error(int codes, t_param *par);

char	*get_next_line(int fd);

char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(char *s);
char	*ft_strnstr(char *big, char *little, int len);

void	*ft_memset(void *dest, int val, int n);

#endif