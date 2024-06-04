/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:16 by okraus            #+#    #+#             */
/*   Updated: 2024/06/04 17:05:44 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include "RPN.hpp"
#include "colours.hpp"

// #define MAX_VAL 210001

// int	adder_double(unsigned int u)
// {
// 	return (u * 2);
// }

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << ERROR_COLOUR << "No argument provided" << NO_COLOUR << std::endl;
		return (1);
	}
	for (int i = 1; argv[i]; ++i)
	{
		try
		{
			std::cout << YELLOW_COLOUR << "Processing <" << argv[i] << ">" << NO_COLOUR << std::endl;
			RPN rpn(argv[i]);
			if (argv[i + 1])
				std::cout << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << RED_COLOUR << e.what() << NO_COLOUR << std::endl;
			if (argv[i + 1])
				std::cout << std::endl;
		}
	}
	return (0);
}