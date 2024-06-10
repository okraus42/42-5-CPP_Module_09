/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/10 13:28:24 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

//# include <cstddef>
# include <iostream>
# include <fstream>
# include <sstream>
# include <ctime>
# include <cstring>
# include <map>
# include <algorithm>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange &operator	= (const BitcoinExchange &src);
		~BitcoinExchange(void);
	
		BitcoinExchange(std::string file);
	private:
		std::map <int, float>	history;
		int						first_time;
		int						last_time;
};

#endif