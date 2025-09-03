/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:11:59 by dcastor           #+#    #+#             */
/*   Updated: 2025/09/03 11:54:51 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "algorithm"
#include "stdexcept"

template <typename T>
typename T::iterator easyfind(T &container, unsigned int occ)
{
	typename T::iterator it = std::find(container.begin(), container.end(), occ);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return it;
}
