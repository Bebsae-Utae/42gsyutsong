/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:23:41 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/17 14:21:04 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_argv(int argc, char **argv)
{
	int		idx;
	char	*data;

	idx = 1;
	if (argc == 1)
		print_error();
	while (idx != argc)
	{
		data = argv[idx];
		while (*data)
		{
			if (*data == '-' || *data == '+')
			{
				data ++;
				if (*data < '0' || *data > '9')
					print_error();
			}
			else if (*data != ' ' && (*data < '0' || *data > '9'))
				print_error();
			if (*data)
				data ++;
		}
		idx ++;
	}
}

int	check_space()
{
	
}