/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:28:06 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/04 10:00:13 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical Form

Span::~Span()
{
	delete[] this->_values;
}

// Custom Constructors

Span::Span(unsigned int max_size) : _size(0), _max_size(max_size)
{
	this->_values = new int[max_size]();
}

// Member functions

void Span::addNumber(int number)
{
	if (this->_size == this->_max_size)
		throw MaxSizeReachedException();
	this->_values[this->_size] = number;
	this->_size++;
}

unsigned int Span::shortestSpan() const
{
	unsigned long shortest = -1;

	if (this->_size <= 1)
		throw NoSpanCanBeFoundException();
	for (size_t i = 0; i < this->_size; i++)
		for (size_t j = i + 1; j < this->_size; j++)
		{
			unsigned int minus = std::min(this->_values[i], this->_values[j]);
			unsigned int maxus = std::max(this->_values[i], this->_values[j]);
			unsigned int diff = maxus - minus;
			if (diff < shortest)
				shortest = diff;
		}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	unsigned long longest = 0;
	if (this->_size <= 1)
		throw NoSpanCanBeFoundException();
	for (size_t i = 0; i < this->_size; i++)
		for (size_t j = i + 1; j < this->_size; j++)
		{
			unsigned int minus = std::min(this->_values[i], this->_values[j]);
			unsigned int maxus = std::max(this->_values[i], this->_values[j]);
			unsigned int diff = maxus - minus;
			if (diff > longest)
				longest = diff;
		}

	return longest;
}

// Internal Exceptions

const char *Span::MaxSizeReachedException::what() const throw()
{
	return "Max size has been reached and new number can't be added.";
}

const char *Span::NoSpanCanBeFoundException::what() const throw()
{
	return "No span can be found, no number stored or only one.";
}
