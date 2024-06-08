/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/08 16:56:50 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

//# include <cstddef>
# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <climits>

class RPN
{
	public:
		
		RPN(const RPN& copy);
		RPN &operator	= (const RPN &src);
		~RPN(void);
	
		RPN(std::string str);
	private:
		RPN(void);
		int				_answer;
		int				_lnum;
		int				_rnum;
		long			_test;
		std::string		_token;
		std::stack<int>	_numbers;

		class DivisionByZeroException : public std::exception
		{
			public:
				const char*		what() const throw();
		};

		class NumberTooBigException : public std::exception
		{
			public:
				const char*		what() const throw();
		};

		class ResultTooBigException : public std::exception
		{
			public:
				const char*		what() const throw();
		};

		class UnsupportedTokenException : public std::exception
		{
			public:
				const char*		what() const throw();
		};

		class IncorrectSyntaxException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
		//error division by zero
	//error unsupported token
	//error number too big
	//error result too big
	//error incorrect syntax

};

#endif