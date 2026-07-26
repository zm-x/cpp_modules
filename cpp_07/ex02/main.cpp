/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 16:22:24 by zael-mou          #+#    #+#             */
/*   Updated: 2026/07/12 16:22:25 by zael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << "========== EMPTY ARRAY ==========\n";
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	std::cout << "\n========== INT ARRAY ==========\n";
	Array<int> numbers(5);

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== COPY CONSTRUCTOR ==========\n";
	Array<int> copy(numbers);

	numbers[0] = 999;

	std::cout << "Original : ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << "\nCopy     : ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== ASSIGNMENT ==========\n";
	Array<int> assign;
	assign = numbers;

	numbers[1] = 555;

	std::cout << "Original : ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";

	std::cout << "\nAssigned : ";
	for (unsigned int i = 0; i < assign.size(); i++)
		std::cout << assign[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== STRING ARRAY ==========\n";
	Array<std::string> names(3);

	names[0] = "Zakaria";
	names[1] = "Ali";
	names[2] = "Sara";

	for (unsigned int i = 0; i < names.size(); i++)
		std::cout << names[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== OUT OF BOUNDS ==========\n";
	try
	{
		std::cout << numbers[100] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== CONST ARRAY ==========\n";
	const Array<int> constArray(copy);

	for (unsigned int i = 0; i < constArray.size(); i++)
		std::cout << constArray[i] << " ";
	std::cout << std::endl;

}
