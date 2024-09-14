/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/09/14 11:25:29 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

//# include <cstddef>
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstring>
# include <list>
# include <vector>
# include <algorithm>

template <typename T> T	ok_strtoi(std::string str)
{
	std::stringstream	temp;
	T					num;

	temp << str;
	temp >> num;
	return (num);
}

template <typename T> std::string	ok_itostr(T num)
{
	std::stringstream	temp;
	std::string			str;

	temp << num;
	temp >> str;
	return (str);
}

template <typename T> void	ok_iterPrint(const T &container, const std::string string)
{
	std::cout << string << ": ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ", ";
	std::cout << std::endl;
}

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& copy);
		PmergeMe &operator	= (const PmergeMe &src);
		~PmergeMe(void);
	
		PmergeMe(char *argv[]);
	private:
		std::vector<unsigned int>	vec;
		std::list<unsigned int>		lst;
		std::vector<unsigned int>	vecSorted;
		std::list<unsigned int>		lstSorted;
		unsigned long				vec_stime_start;
		unsigned long				vec_utime_start;
		unsigned long				lst_stime_start;
		unsigned long				lst_utime_start;
		unsigned long				vec_stime_end;
		unsigned long				vec_utime_end;
		unsigned long				lst_stime_end;
		unsigned long				lst_utime_end;
};

#endif