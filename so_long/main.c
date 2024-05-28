#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_param
{
	size_t	fd;
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
	int		count_work;
	char	*mapdata;
	char	*newmap;
	int		cnt_dorong;
	int		cnt_item;
	int		cnt_door;
	int		get_item;
}	t_param;

#define KEY_ESC				65307
#define KEY_W				119
#define KEY_S				115
#define KEY_A				97
#define KEY_D				100

void set_param(t_param *par)
{
	par->mlx = mlx_init();
	par->win = NULL;
	par->dorong = mlx_xpm_file_to_image(par->mlx, "img/dorong.xpm", &par->width, &par->height);
	par->tree = mlx_xpm_file_to_image(par->mlx, "img/tree.xpm", &par->width, &par->height);
	par->tile = mlx_xpm_file_to_image(par->mlx, "img/tile.xpm", &par->width, &par->height);
	par->item = mlx_xpm_file_to_image(par->mlx, "img/item.xpm", &par->width, &par->height);
	par->door = mlx_xpm_file_to_image(par->mlx, "img/door.xpm", &par->width, &par->height);
	// par->fd = open("map/map.ber", O_RDONLY);
	par->x = 0;
	par->y = 0;
	par->where_dorong = 0;
	par->width = 0;
	par->height = 0;
	par->win_width = 0;
	par->win_height = 0;
	par->count_work = 0;
	par->cnt_door = 0;
	par->cnt_dorong = 0;
	par->cnt_item = 0;
	par->get_item = 0;
	par->mapdata = "111111111110P1C01E111011101001100110110111000000011111111111";
}

void find_dorong(t_param *par)
{
	int idx;
	int here;

	idx = 0;
	here = 0;
	while (par->newmap[idx])
	{
		if (par->newmap[idx] == 'P')
		{
			here = idx;
			break;
		}
		idx ++;
	}
	par->where_dorong = here;
}

int ft_strlen(char *newmap)
{
	int len;
	len = 0;
	while (newmap[len])
		len ++;
	return (len);
}

int draw_map(t_param *par)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	mlx_clear_window(par->mlx, par->win);
	while (par->newmap[i])
	{
		x = 0 + (i % 10) * 64;
		y = 0 + (i / 10 * 64);
		if(par->newmap[i] == '1')
			mlx_put_image_to_window(par->mlx, par->win, par->tree, x, y);
		else if (par->newmap[i] == '0')
			mlx_put_image_to_window(par->mlx, par->win, par->tile, x, y);
		else if (par->newmap[i] == 'P')
			mlx_put_image_to_window(par->mlx, par->win, par->dorong, x, y);
		else if (par->newmap[i] == 'C')
			mlx_put_image_to_window(par->mlx, par->win, par->item, x, y);
		else if (par->newmap[i] == 'E')
			mlx_put_image_to_window(par->mlx, par->win, par->door, x, y);
		i ++;
	}
}

void make_map(t_param *par, char *mapdatas)
{
	int idx1;
	int idx2;
	int len;

	idx1 = 0;
	idx2 = 0;
	len = ft_strlen(mapdatas);
	len = len - par->win_height;
	par->newmap = (char *)malloc(sizeof(char) * len + 1);
	while (mapdatas[idx1])
	{
		if (mapdatas[idx1] == '\n')
			idx1 ++;
		par->newmap[idx2] = mapdatas[idx1];
		idx1 ++;
		idx2 ++;
	}
	par->newmap[idx2] = '\0';
	draw_map(par);
}

void read_map(t_param *par)
{
	char *mapdatas = "1111111111\n10P1C01E11\n1011101001\n1001101101\n1100000001\n1111111111";

	int idx;
	int height;
	int width;
	char *newmap;

	idx = 0;
	height = 0;
	width = 0;
	while (mapdatas[idx])
	{
		if (mapdatas[idx] == '\n')
			par->win_height ++;
		idx ++;
	}
	idx = 0;
	while (mapdatas[idx])
	{
		if (mapdatas[idx] == '\n')
			break;
		par->win_width ++;
		idx ++;
	}
	make_map(par, mapdatas);
}

void check_wall(t_param *par)
{
	int idx;

	idx = 0;
	if (par->win_height * par->win_width != ft_strlen(par->newmap))
		write(1, "Not Rectangle.\n", 15);
	if (idx < ft_strlen(par->newmap))
	{
		if (idx < par->win_width)
			if (par->newmap[idx] != '1')
				write(1, "Not Surrounded.\n", 16);
		else if (idx % par->win_width == 0 || idx % par->win_width == par->win_width - 1)
			if (par->newmap[idx] != '1')
				write(1, "Not Surrounded.\n", 16);
		else if (idx > ft_strlen(par->newmap) - par->win_width)
			if (par->newmap[idx] != '1')
				write(1, "Not Surrounded.\n", 16);
		idx ++;
	}
}

void check_map(t_param *par)
{
	int idx;
	int cnt_dorong;
	int cnt_item;
	int cnt_door;

	idx = 0;
	cnt_dorong = 0;
	cnt_item = 0;
	cnt_door = 0;
	while (idx ++ < ft_strlen(par->newmap))
	{
		if (par->newmap[idx] == 'E')
			cnt_door ++;
		else if (par->newmap[idx] == 'P')
			cnt_dorong ++;
		else if (par->newmap[idx] == 'C')
			cnt_item ++;
	}
	if (cnt_door == 0)
		write(1, "No Exit.\n", 9);
	else if (cnt_dorong != 1)
		write(1, "No Player.\n", 11);
	else if (cnt_item == 0)
		write(1, "No Item.\n", 9);
	par->cnt_door = cnt_door;
	par->cnt_dorong = cnt_dorong;
	par->cnt_item = cnt_item;
}

int	exit_btn(t_param *par)
{
	mlx_destroy_window(par->mlx, par->win);
	exit(0);
}

void move_a(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong - 1] == 'E' && par->get_item == par->cnt_item)
	{
		mlx_destroy_window(par->mlx, par->win);
		exit(0);
	}
	else if (par->newmap[par->where_dorong - 1] != '1')
	{
		if (par->newmap[par->where_dorong - 1] == 'C')
			par->get_item = 1;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong - 1] = 'P';
		draw_map(par);
	}
}

void move_d(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong + 1] == 'E' && par->get_item == par->cnt_item)
	{
		mlx_destroy_window(par->mlx, par->win);
		exit(0);
	}
	else if (par->newmap[par->where_dorong + 1] != '1')
	{
		if (par->newmap[par->where_dorong + 1] == 'C')
			par->get_item = 1;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong + 1] = 'P';
		draw_map(par);
	}
}

void move_s(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong + par->win_width] == 'E' && par->get_item == par->cnt_item)
	{
		mlx_destroy_window(par->mlx, par->win);
		exit(0);
	}
	else if (par->newmap[par->where_dorong + par->win_width] != '1')
	{
		if (par->newmap[par->where_dorong + par->win_width] == 'C')
			par->get_item = 1;
		mlx_clear_window(par->mlx, par->win);
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong + par->win_width] = 'P';
		draw_map(par);
	}
}

void move_w(t_param *par)
{
	find_dorong(par);
	if (par->newmap[par->where_dorong - par->win_width] == 'E' && par->get_item == par->cnt_item)
	{
		mlx_destroy_window(par->mlx, par->win);
		exit(0);
	}
	else if (par->newmap[par->where_dorong - par->win_width] != '1')
	{
		if (par->newmap[par->where_dorong - par->win_width] == 'C')
			par->get_item = 1;
		mlx_clear_window(par->mlx, par->win);		
		par->newmap[par->where_dorong] = '0';
		par->newmap[par->where_dorong - par->win_width] = 'P';
		draw_map(par);
	}
}

int closers(int keycode, t_param *par)
{
	if (keycode == KEY_A)
		move_a(par);
	else if (keycode == KEY_D)
		move_d(par);
	else if (keycode == KEY_S)
		move_s(par);
	else if (keycode == KEY_W)
		move_w(par);
	return 0;
}

int main(void)
{
	t_param	par;

	set_param(&par);
	par.win = mlx_new_window(par.mlx, 640, 384, "dorong");
	read_map(&par);
	check_map(&par);
	check_wall(&par);
	mlx_hook(par.win, 2, 1L << 0, &closers, &par);
	mlx_hook(par.win, 17, 1L << 17, &exit_btn, &par);
	mlx_loop(par.mlx);
}