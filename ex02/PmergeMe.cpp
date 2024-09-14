/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/09/14 11:35:25 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colours.hpp"

PmergeMe::PmergeMe(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the PmergeMe class called.";
	ft_uncolorize();
	std::cout << std::endl;
}


PmergeMe::PmergeMe(const PmergeMe& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the PmergeMe class called.";
	ft_uncolorize();
	std::cout << std::endl;
	*this = copy;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assigment operator of the PmergeMe class called.";
	ft_uncolorize();
	std::cout << std::endl;
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the PmergeMe class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

//corrupted database

//file not open
//not a valid date => bad input
//not a number
//negative value
//too big value

// time_t parseDateTime(const char* datetimeString, const char* format)
// {
// 	struct tm	tmStruct;
// 	char *			err;

// 	std::memset(&tmStruct, 0, sizeof(tm));
// 	err = strptime(datetimeString, format, &tmStruct);
// 	if (!err)
// 		return (-1);
// 	// std::cout << "TM:" << tmStruct.tm_mon << err << std::endl;
// 	return mktime(&tmStruct);
// }
 
// // Function to format a time_t value into a date or time string.
// std::string DateTime(time_t time, const char* format)
// {
// 	char		buffer[90];
// 	struct tm*	timeinfo = localtime(&time);
// 	strftime(buffer, sizeof(buffer), format, timeinfo);
// 	return buffer;
// }

// static unsigned int	ok_strtou(std::string str)
// {
// 	std::stringstream	temp;
// 	unsigned int		num;

// 	temp << str;
// 	temp >> num;
// 	return (num);
// }

// static bool	is_valid_number(const std::string str)
// {
// 	if (str.empty() || str.size() > 14)
// 		return (false);
// 	if (str.size() == 1 && !std::isdigit(str[0]))
// 		return (false);
// 	if (!(str[0] == '+' || std::isdigit(str[0])))
// 		return (false);
// 	for (size_t i = 1; i < str.size(); ++i)
// 		if (!(std::isdigit(str[i]) || (str[i] == '.' && (std::isdigit(str[i - 1]) || std::isdigit(str[i + 1])))))
// 			return (false);
// 	if (std::count(str.begin(), str.end(), '.') > 1)
// 		return (false);
// 	return (true);
// }

static bool	ok_numcheck(char *s)
{
	int		i = 0;
	int		n = 0;
	bool	num = false;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\v' || s[i] == '\n' || s[i] == '\f')
	{
		i++;
	}
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		i++;
		n++;
		num = true;
	}
	if (s[i] || !num || n > 10)
		return (false);
	return (true);
}

PmergeMe::PmergeMe(char *argv[])
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Overloaded array constructor of the PmergeMe class called.";
	ft_uncolorize();
	std::cout << std::endl;
	unsigned long		num;

	//check for duplicates and invalid numbers
	
	for (int i = 1; argv[i]; ++i)
	{
		if (!ok_numcheck(argv[i]))
			throw(std::runtime_error(std::string("Invalid number: ") + argv[i]));
		std::cout << argv[i] << std::endl;
		//check for duplicates and invalid numbers
		num = ok_strtoi<unsigned long>(argv[i]);
		if (num > 4294967295UL)
		// 	throw(std::runtime_error(std::string("Number too big: ") + argv[i]));
		// if (this->vec.find(num) != this->vec.end())
		// 	throw(std::runtime_error(std::string("Number is duplicate: ") + argv[i]));
		//add items to containers
		this->lst.push_back((unsigned int)num);
		this->vec.insert(this->vec.end(), (unsigned int)num);
	}
	std::cout << this->lst.size() << std::endl;
	ok_iterPrint(this->lst, "Original list  ");
	ok_iterPrint(this->vec, "Original vector");
	//get time in seconds and microseconds
	//time sort in each container
	//print containers
}

