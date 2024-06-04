/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/04 17:53:12 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colours.hpp"

RPN::RPN(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the RPN class called.";
	ft_uncolorize();
	std::cout << std::endl;
}


RPN::RPN(const RPN& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the RPN class called.";
	ft_uncolorize();
	std::cout << std::endl;
	*this = copy;
}

RPN &RPN::operator = (const RPN &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assigment operator of the RPN class called.";
	ft_uncolorize();
	std::cout << std::endl;
	(void)src;
	return (*this);
}

RPN::~RPN(void)
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << "Destructor of the RPN class called.";
	// ft_uncolorize();
	// std::cout << std::endl;
}

static bool	is_valid_number(const std::string str)
{
	if (str.empty() || str.size() > 14)
		return (false);
	if (str.size() == 1 && !std::isdigit(str[0]))
		return (false);
	if (!(str[0] == '-' || str[0] == '+' || std::isdigit(str[0])))
		return (false);
	for (size_t i = 1; i < str.size(); ++i)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

static long	ok_strtol(std::string str)
{
	std::stringstream	temp;
	long				num;

	temp << str;
	temp >> num;
	return (num);
}

RPN::RPN(std::string str)
{
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << "Overloaded constructor of the RPN class called.";
	// ft_uncolorize();
	// std::cout << std::endl;

	//error division by zero
	//error unsupported token
	//error number too big
	//error result too big
	//error incorrect syntax
	this->_test = 42;
	if (is_valid_number(str))
		this->_test = ok_strtol(str);
	// put numbers on stack
	// if operand, do the operation with top two numbers on stack
	//std::string::find_first_not_of
	
	this->_answer = 42;
	if (INT_MIN <= this->_test && this->_test <= INT_MAX)
		this->_answer = this->_test;
	std::cout << GREEN_COLOUR << "Final result is <" << this->_answer << ">." << NO_COLOUR << std::endl;
}
