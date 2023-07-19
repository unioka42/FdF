/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokada <kokada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:38:42 by kokada            #+#    #+#             */
/*   Updated: 2023/05/17 18:16:45 by kokada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	lower_alpha;
	int	upper_alpha;

	lower_alpha = (c >= 'a' && c <= 'z');
	upper_alpha = (c >= 'A' && c <= 'Z');
	return (lower_alpha || upper_alpha);
}
