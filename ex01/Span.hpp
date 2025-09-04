/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:59:47 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/04 09:54:19 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class Span
{
private:
	int *_values;
	unsigned int _size;
	unsigned int _max_size;

	class MaxSizeReachedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NoSpanCanBeFoundException : public std::exception
	{
		virtual const char *what() const throw();
	};

public:
	// Canonical Form
	~Span();

	// Custom Constructors
	Span(unsigned int max_size);

	// Member Functions
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};
