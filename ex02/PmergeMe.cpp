/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/09/17 15:05:30 by okraus           ###   ########.fr       */
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

// static std::list<std::pair<unsigned int, unsigned int> > ok_mergeList(std::list<std::pair<unsigned int, unsigned int> > lstL, std::list<std::pair<unsigned int, unsigned int> > lstR)
// {
// 	lstL.merge(lstR);
// 	ok_iterPrint(lstL, "Merged list   ");
// 	return (lstL);
// }

static std::list<std::pair<unsigned int, unsigned int> >	ok_mergeSort(std::list<std::pair<unsigned int, unsigned int> > &lst)
{
	unsigned int mid = lst.size();
	if (mid < 2)
		return (lst);

	mid /= 2;
	std::list<std::pair<unsigned int, unsigned int> >::iterator middle = lst.begin();
	std::advance(middle, mid);
	std::list<std::pair<unsigned int, unsigned int> > lstLeft(lst.begin(), middle);
	std::list<std::pair<unsigned int, unsigned int> > lstRight(middle, lst.end());
	ok_iterPrint(lstLeft, "Left list     ");
	ok_iterPrint(lstRight, "Right list    ");
	lstLeft = ok_mergeSort(lstLeft);
	lstRight = ok_mergeSort(lstRight);
	lstLeft.merge(lstRight);
	ok_iterPrint(lstLeft, "Merged list   ");
	return (lstLeft);
}


// static std::vector<std::pair<unsigned int, unsigned int> >	ok_mergeSort(std::vector<std::pair<unsigned int, unsigned int> > &vec)
// {
// 	unsigned int mid = vec.size();
// 	if (mid < 2)
// 		return (vec);

// 	mid /= 2;
// 	std::vector<std::pair<unsigned int, unsigned int> >::iterator middle = vec.begin();
// 	std::advance(middle, mid);
// 	std::vector<std::pair<unsigned int, unsigned int> > vecLeft(vec.begin(), middle);
// 	std::vector<std::pair<unsigned int, unsigned int> > vecRight(middle, vec.end());
// 	ok_iterPrint(vecLeft, "Left vector   ");
// 	ok_iterPrint(vecRight, "Right vector  ");
// 	vecLeft = ok_mergeSort(vecLeft);
// 	vecRight = ok_mergeSort(vecRight);
// 	vecLeft.merge(vecRight);
// 	ok_iterPrint(vecLeft, "Merged vector ");
// 	return (vecLeft);
// }


//https://www.geeksforgeeks.org/merge-sort/
static void ok_mergeVector(std::vector<std::pair<unsigned int, unsigned int> >& arr, unsigned int left, unsigned int mid, unsigned int right)
{
	unsigned int n1 = mid - left + 1;
	unsigned int n2 = right - mid;

	// Create temp vectors
	std::vector<std::pair<unsigned int, unsigned int> > L(n1), R(n2);

	// Copy data to temp vectors L[] and R[]
	for (unsigned int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (unsigned int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	unsigned int i = 0, j = 0;
	unsigned int k = left;

	// Merge the temp vectors back 
	// into arr[left..right]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], 
	// if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], 
	// if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void	ok_mergeSort(std::vector<std::pair<unsigned int, unsigned int> > &vec, unsigned int left, unsigned int right)
{
	if (left >= right)
		return;

	unsigned int mid = left + (right - left) / 2;
	ok_mergeSort(vec, left, mid);
	ok_mergeSort(vec, mid + 1, right);
	ok_mergeVector(vec, left, mid, right);
}

static std::list<unsigned int>	ok_sort(std::list<unsigned int> oldList)
{
	
	//make pairs
	//compare pairs
	// sort larger values into a sequence
	// insert at the start element from the smallest pair
	// insert the rest my magic (Ford Johnson stuff)

	//main chain
	//pend chain
	unsigned int	size = oldList.size();
	bool			odd = false;
	(void) odd;
	if (size / 2)
		odd = true;
	std::list<std::pair<unsigned int, unsigned int> > pairList;
	std::list<unsigned int>::iterator it = oldList.begin();
	for (unsigned int i = 0; i < size / 2; i++)
	{
		unsigned int a = *it++;
		unsigned int b = *it++;
		std::pair<unsigned int, unsigned int> pair;
		(a > b) ? pair = std::make_pair(a, b) : pair = std::make_pair(b, a);
		pairList.push_back(pair);
	}
	pairList = ok_mergeSort(pairList);
	std::list<unsigned int> mainChain;
	ok_iterPrint(pairList, "Pair list     ");
	return(mainChain);
}

static std::vector<unsigned int>	ok_sort(std::vector<unsigned int> oldVector)
{
	
	//make pairs
	//compare pairs
	// sort larger values into a sequence
	// insert at the start element from the smallest pair
	// insert the rest my magic (Ford Johnson stuff)

	//main chain
	//pend chain
	unsigned int	size = oldVector.size();
	bool			odd = false;
	(void) odd;
	if (size / 2)
		odd = true;
	std::vector<std::pair<unsigned int, unsigned int> > pairVector;
	std::vector<unsigned int>::iterator it = oldVector.begin();
	for (unsigned int i = 0; i < size / 2; i++)
	{
		unsigned int a = *it++;
		unsigned int b = *it++;
		std::pair<unsigned int, unsigned int> pair;
		(a > b) ? pair = std::make_pair(a, b) : pair = std::make_pair(b, a);
		pairVector.push_back(pair);
	}
	ok_mergeSort(pairVector, 0, pairVector.size() - 1);
	std::vector<unsigned int> mainChain;
	ok_iterPrint(pairVector, "Pair vector   ");
	return(mainChain);
}


PmergeMe::PmergeMe(char *argv[])
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Overloaded array constructor of the PmergeMe class called.";
	ft_uncolorize();
	std::cout << std::endl;
	std::clock_t		startVec;
	double				durationVec;
	std::clock_t		startLst;
	double				durationLst;
	unsigned long		num;

	//check for duplicates and invalid numbers
	
	for (int i = 1; argv[i]; ++i)
	{
		if (!ok_numcheck(argv[i]))
			throw(std::runtime_error(std::string("Invalid number: ") + argv[i]));
		//std::cout << argv[i] << std::endl;
		//check for duplicates and invalid numbers
		num = ok_strtoi<unsigned long>(argv[i]);
		if (num > 4294967295UL)
			throw(std::runtime_error(std::string("Number too big: ") + argv[i]));
		for (std::vector<unsigned int>::iterator it = this->vec.begin(); it != this->vec.end(); ++it)
			if (num == *it)
				throw(std::runtime_error(std::string("Number is duplicate: ") + argv[i]));
		//add items to containers
		this->lst.push_back((unsigned int)num);
		this->vec.insert(this->vec.end(), (unsigned int)num);
	}
	ok_iterPrint(this->lst, "Original list  ");
	ok_iterPrint(this->vec, "Original vector");
	startLst = std::clock();
	//sort list
	this->lstSorted = ok_sort(this->lst);
	durationLst = (double)( std::clock() - startLst ) * 1000000. / (double) CLOCKS_PER_SEC;
	startVec = std::clock();
	//sort vec
	this->vecSorted = ok_sort(this->vec);
	durationVec = (double)( std::clock() - startVec ) * 1000000. / (double) CLOCKS_PER_SEC;

	std::cout << CLOCKS_PER_SEC << std::endl;
	ok_iterPrint(this->lstSorted, "Sorted list  ");
	ok_iterPrint(this->vecSorted, "Sorted vector");
	//get time in seconds and microseconds
	//time sort in each container
	//print containers
	std::cout << "Time to process a range of " << this->lst.size()
	<< " elements with std::list   : " << std::fixed << std::setprecision (5) << durationLst
	<< " μs" << std::endl;
	
	std::cout << "Time to process a range of " << this->vec.size()
	<< " elements with std::vector : " << std::fixed << std::setprecision (5) << durationVec
	<< " μs" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const std::pair<unsigned int, unsigned int> &pair)
{
	os << "[" << pair.first << ":" << pair.second << "]";
	return os;
}
