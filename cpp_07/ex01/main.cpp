/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 11:30:34 by zael-mou          #+#    #+#             */
/*   Updated: 2026/07/12 11:30:37 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &x)
{
	std::cout << x << " ";
}

template <typename T>
void increment(T &x)
{
	x++;
}

int main()
{
	std::cout << "========== INT ARRAY ==========" << std::endl;

	int numbers[] = {1, 2, 3, 4, 5};

	iter(numbers, 5, print<int>);
	std::cout << std::endl;

	iter(numbers, 5, increment<int>);

	iter(numbers, 5, print<int>);
	std::cout << std::endl << std::endl;

	std::cout << "========== CHAR ARRAY ==========" << std::endl;

	char letters[] = {'A', 'B', 'C', 'D'};

	iter(letters, 4, print<char>);
	std::cout << std::endl << std::endl;

	std::cout << "========== STRING ARRAY ==========" << std::endl;

	std::string names[] =
	{
		"Zakaria",
		"Ali",
		"Sara"
	};

	iter(names, 3, print<std::string>);
	std::cout << std::endl << std::endl;

	std::cout << "========== CONST ARRAY ==========" << std::endl;

	const int values[] = {10, 20, 30};

	iter(values, 3, print<int>);
	std::cout << std::endl;

	return (0);
}