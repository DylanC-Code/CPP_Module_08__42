/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:38:08 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/04 11:07:14 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

static void test_mutantstack()
{
	std::cout << "=== MutantStack ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl; // 17

	mstack.pop();

	std::cout << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Compatibilité avec std::stack
	std::stack<int> s(mstack);
}

static void test_list()
{
	std::cout << "=== std::list ===" << std::endl;

	std::list<int> lst;

	// équivalents de stack::push/top/pop/size
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl; // 17

	lst.pop_back();

	std::cout << lst.size() << std::endl; // 1

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	test_mutantstack();
	test_list();
	return 0;
}
