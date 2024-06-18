/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutsong <yutsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:56:50 by yutsong           #+#    #+#             */
/*   Updated: 2024/06/18 17:28:54 by yutsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;
	t_stack	*stack_manager_a;
	t_stack	*stack_manager_b;

	// 입력받은 인자 유효한지 확인
	check_args(argc, **argv);
	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	*stack_a = NULL;
	*stack_b = NULL;
	// 구조체 초기화
	init_stack(&stack_a, argc, argv);
	// 입력받은 인자를 구조체에 넣어줌
	// 정렬
	quick_sort();
	// 명령어 최적화
	// 명령어 출력
	print_order();
	return (0);
}