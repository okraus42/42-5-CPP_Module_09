/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/08 17:31:49 by okraus           ###   ########.fr       */
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

static bool	is_valid_operation(const std::string str)
{
	if (str.size() != 1)
		return (false);
	if (str.find_first_of("+-*/%") == std::string::npos)
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
	size_t	start_position;
	size_t	end_position;
	char	operation;
	// ft_colorize(reinterpret_cast<uintptr_t>(this));
	// std::cout << "Overloaded constructor of the RPN class called.";
	// ft_uncolorize();
	// std::cout << std::endl;

	//error division by zero
	//error unsupported token
	//error number too big
	//error result too big
	//error incorrect syntax
	// this->_test = 42;
	// if (is_valid_number(str))
	// 	this->_test = ok_strtol(str);
	// // put numbers on stack
	// // if operand, do the operation with top two numbers on stack
	// //std::string::find_first_not_of
	
	// this->_answer = 42;
	// if (INT_MIN <= this->_test && this->_test <= INT_MAX)
	// 	this->_answer = this->_test;

	while (str.length() > 0)
	{
		start_position = str.find_first_not_of(" \t\n\r\v\f");
		end_position = str.find_first_of(" \t\n\r\v\f");

		if (start_position == std::string::npos)
			throw (IncorrectSyntaxException());
		_token = str.substr(start_position, end_position);
		
		//this is where the magic happens
		if (this->_token.length())
		{
			//std::cout << "Token is <" << this->_token << ">." << std::endl;
			if (is_valid_number(this->_token))
			{
				this->_test = ok_strtol(this->_token);
				if (INT_MIN <= this->_test && this->_test <= INT_MAX)
				{
					this->_numbers.push(this->_test);
				}
				else
					throw (NumberTooBigException());
			}
			else if (is_valid_operation(this->_token))
			{
				if (this->_numbers.size() < 2)
					throw (IncorrectSyntaxException());
				this->_rnum = this->_numbers.top();
				this->_numbers.pop();
				this->_lnum = this->_numbers.top();
				this->_numbers.pop();
				operation = this->_token[0];
				if (operation == '+')
					this->_test = this->_lnum + this->_rnum;
				else if (operation == '-')
					this->_test = this->_lnum - this->_rnum;
				else if (operation == '*')
					this->_test = this->_lnum * this->_rnum;
				else
				{
				if (!this->_rnum)
					throw (DivisionByZeroException());
				if (operation == '/')
					this->_test = this->_lnum / this->_rnum;
				else if (operation == '%')
					this->_test = this->_lnum % this->_rnum;
				}
				if (INT_MIN <= this->_test && this->_test <= INT_MAX)
				{
					this->_numbers.push(this->_test);
				}
				else
					throw (ResultTooBigException());
			}
			else
				throw (UnsupportedTokenException());
		}
		if (end_position == std::string::npos)
			str = "";
		else
			str = str.substr(end_position + 1);
		start_position = str.find_first_not_of(" \t\n\r\v\f");
		if (start_position == std::string::npos)
			str = "";
		else
			str = str.substr(start_position);
	}
	if (this->_numbers.size() != 1)
		throw (IncorrectSyntaxException());
	this->_answer = this->_numbers.top();
	this->_numbers.pop();
	std::cout << GREEN_COLOUR << "Final result is <" << this->_answer << ">." << NO_COLOUR << std::endl;
}


const char*	RPN::DivisionByZeroException::what() const throw()
{
	return (ERROR_COLOUR "Error: Division by zero." NO_COLOUR);
}

const char*	RPN::NumberTooBigException::what() const throw()
{
	return (ERROR_COLOUR "Error: Number too big." NO_COLOUR);
}

const char*	RPN::ResultTooBigException::what() const throw()
{
	return (ERROR_COLOUR "Error: Result too big." NO_COLOUR);
}

const char*	RPN::UnsupportedTokenException::what() const throw()
{
	return (ERROR_COLOUR "Error: Unsupported token." NO_COLOUR);
}

const char*	RPN::IncorrectSyntaxException::what() const throw()
{
	return (ERROR_COLOUR "Error: Incorect syntax." NO_COLOUR);
}
