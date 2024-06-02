/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:16 by okraus            #+#    #+#             */
/*   Updated: 2024/06/02 16:30:41 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include "BitcoinExchange.hpp"
#include "colours.hpp"

// #define MAX_VAL 210001

// int	adder_double(unsigned int u)
// {
// 	return (u * 2);
// }

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << ERROR_COLOUR << "Incorrect number of arguments!" << NO_COLOUR << std::endl;
	}
	try
	{
		BitcoinExchange(argv[1]);
	}
	catch
	{
		//more stuff
	}
	return (0);
}