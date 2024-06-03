/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/03 11:33:17 by okraus           ###   ########.fr       */
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
	(void)src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Overloaded constructor of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;

	std::cout << "file to open is <" << file << ">." << std::endl;

	std::cout << RED_COLOUR << "RED" << NO_COLOUR << std::endl;
	std::cout << GREEN_COLOUR << "GREEN" << NO_COLOUR << std::endl;
	std::cout << BLUE_COLOUR << "BLUE" << NO_COLOUR << std::endl;
	std::cout << CYAN_COLOUR << "CYAN" << NO_COLOUR << std::endl;
	std::cout << MAGENTA_COLOUR << "MAGENTA" << NO_COLOUR << std::endl;
	std::cout << YELLOW_COLOUR << "YELLOW" << NO_COLOUR << std::endl;
	std::cout << BLACK_COLOUR << "BLACK" << NO_COLOUR << std::endl;
	std::cout << WHITE_COLOUR << "WHITE" << NO_COLOUR << std::endl;
}
