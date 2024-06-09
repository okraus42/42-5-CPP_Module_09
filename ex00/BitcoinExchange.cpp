/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/09 17:50:50 by okraus           ###   ########.fr       */
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

//corrupted database

//file not open
//not a valid date => bad input
//not a number
//negative value
//too big value

time_t parseDateTime(const char* datetimeString, const char* format)
{
	struct tm	tmStruct;
	char *			err;

	std::memset(&tmStruct, 0, sizeof(tm));
	err = strptime(datetimeString, format, &tmStruct);
	if (!err)
		return (-1);
	std::cout << "TM:" << tmStruct.tm_mon << err << std::endl;
	return mktime(&tmStruct);
}
 
// Function to format a time_t value into a date or time string.
std::string DateTime(time_t time, const char* format)
{
	char		buffer[90];
	struct tm*	timeinfo = localtime(&time);
	strftime(buffer, sizeof(buffer), format, timeinfo);
	return buffer;
}

static float	ok_strtof(std::string str)
{
	std::stringstream	temp;
	float				num;

	temp << str;
	temp >> num;
	return (num);
}


BitcoinExchange::BitcoinExchange(std::string filename)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Overloaded constructor of the BitcoinExchange class called.";
	ft_uncolorize();
	std::cout << std::endl;
	const int seconds_in_day = 86400;
	//open csv
	
	std::string	datetime;
	const char* timeString_append = "00:00:00";
	std::string date;
	date = "2021-22-13";
	datetime = date + timeString_append;
	const char* format_input = "%Y-%m-%d %H:%M:%S";
	const char* format_output = "%Y-%m-%d";
	time_t parsedTime = parseDateTime(datetime.c_str(), format_input);
	std::string formattedTime = DateTime(parsedTime, format_output);
	std::cout << "Parsed Time--> " << parsedTime << std::endl;
	std::cout << "Formatted Time--> " << formattedTime << std::endl;
	
	int			day;
	std::string	value_string;
	float		value;
	// Opening the csv
	std::string	databasename = "minidata.csv";
	std::ifstream	database (databasename.c_str());
	std::string	line;
	std::cout << YELLOW_COLOUR << " Opening the database <" << databasename << "> " << NO_COLOUR << std::endl;
	if (database.is_open())
	{
		if (!getline (database, line))
		{
			std::cerr << ERROR_COLOUR << " Database is empty " << NO_COLOUR << std::endl;
			return ;
		}
		while (getline (database, line))
		{
			std::cout << line << std::endl;
			date = line.substr(0,10);
			//get time from line
			std::cout << date << std::endl;
			datetime = date + timeString_append;
			parsedTime = parseDateTime(datetime.c_str(), format_input);
			if (parsedTime < 0)
			{
				std::cerr << ERROR_COLOUR << " Error: Database corrupted " << NO_COLOUR << std::endl;
				return ;
			}
			std::cout << parsedTime << std::endl;
			//get day from line
			day = parsedTime / seconds_in_day;
			std::cout << day << std::endl;
			//get value from line
			value_string = line.substr(11,-1);
			std::cout << value_string << std::endl;
			value = ok_strtof(value_string);
			std::cout << value << std::endl;
			history.insert(std::pair<int, float>(day, value));
			//update the first and last times
		}
		database.close();
	}
	else
	{
		std::cerr << ERROR_COLOUR << " Unable to open the database " << NO_COLOUR << std::endl;
		return ;
	}
	std::ifstream	file_stream (filename.c_str());
	std::cout << MAGENTA_COLOUR << " Opening the file <" << filename << "> " << NO_COLOUR << std::endl;
	if (file_stream.is_open())
	{
		getline (file_stream, line);
		while (getline (file_stream, line))
		{
			std::cout << line << std::endl;
		}
		file_stream.close();
	}
	else
	{
		std::cerr << ERROR_COLOUR << " Unable to open the file " << NO_COLOUR << std::endl;
		return ;
	}
	//check valid dates
	//check valid values
	//process csv
	//open file
	//process file
	//compare line by line with data in csv
	
	

	// std::cout << RED_COLOUR << "RED" << NO_COLOUR << std::endl;
	// std::cout << GREEN_COLOUR << "GREEN" << NO_COLOUR << std::endl;
	// std::cout << BLUE_COLOUR << "BLUE" << NO_COLOUR << std::endl;
	// std::cout << CYAN_COLOUR << "CYAN" << NO_COLOUR << std::endl;
	// std::cout << MAGENTA_COLOUR << "MAGENTA" << NO_COLOUR << std::endl;
	// std::cout << YELLOW_COLOUR << "YELLOW" << NO_COLOUR << std::endl;
	// std::cout << BLACK_COLOUR << "BLACK" << NO_COLOUR << std::endl;
	// std::cout << WHITE_COLOUR << "WHITE" << NO_COLOUR << std::endl;
}
