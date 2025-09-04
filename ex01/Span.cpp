/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:28:06 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/04 10:33:23 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical Form

Span::~Span() {};

// Custom Constructors

Span::Span(unsigned int max_size) : _max_size(max_size)
{
	this->_values.reserve(max_size);
}

// Member functions

void Span::addNumber(int number)
{
	if (this->_values.size() >= this->_max_size)
		throw MaxSizeReachedException();
	this->_values.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (this->_values.size() < 2)
		throw NoSpanCanBeFoundException();

	std::vector<int> tmp = this->_values;
	std::sort(tmp.begin(), tmp.end());

	long best = std::numeric_limits<long>::max();
	for (std::size_t i = 1; i < tmp.size(); ++i)
	{
		long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
		if (diff < best)
			best = diff;
	}
	return best;
}

unsigned int Span::longestSpan() const
{
	if (this->_values.size() < 2)
		throw NoSpanCanBeFoundException();
	std::vector<int>::const_iterator minIt = std::min_element(_values.begin(), _values.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_values.begin(), _values.end());

	return *maxIt - *minIt;
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
