/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:26:23 by zael-mou          #+#    #+#             */
/*   Updated: 2026/07/12 11:27:05 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T_arr, typename T_func>
void iter(T_arr *array, const size_t len, T_func function)
{
    for (size_t i = 0; i < len; i++)
        function(array[i]);
}

#endif