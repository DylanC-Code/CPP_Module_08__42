/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:11:38 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/03 11:58:04 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Trouve: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "Trouve: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
