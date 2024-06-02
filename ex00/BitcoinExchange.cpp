/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/02 16:27:26 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colours.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assigment operator of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;
	if (this != &src)
	{
		//something
	}
	return (*this);
}
BitcoinExchange::~BitcoinExchange(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;
}
