/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/09/21 15:36:10 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colours.hpp"


//jacobsthal numbers
// 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123



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

// const static unsigned long long	g_j[34] = {3ULL, 5ULL, 11ULL, 21ULL, 43ULL, 85ULL, 171ULL, 341ULL, 683ULL, 1365ULL, 2731ULL, 5461ULL, 10923ULL, 21845ULL, 43691ULL, 87381ULL, 174763ULL, 349525ULL, 699051ULL, 1398101ULL, 2796203ULL, 5592405ULL, 11184811ULL, 22369621ULL, 44739243ULL, 89478485ULL, 178956971ULL, 357913941ULL, 715827883ULL, 1431655765ULL, 2863311531ULL, 5726623061ULL, 11453246123ULL}
const static unsigned long long	g_k[34] = {1ULL, 3ULL,  9ULL, 19ULL, 41ULL, 83ULL, 169ULL, 339ULL, 681ULL, 1363ULL, 2729ULL, 5459ULL, 10921ULL, 21843ULL, 43689ULL, 87379ULL, 174761ULL, 349523ULL, 699049ULL, 1398099ULL, 2796201ULL, 5592403ULL, 11184809ULL, 22369619ULL, 44739241ULL, 89478483ULL, 178956969ULL, 357913939ULL, 715827881ULL, 1431655763ULL, 2863311529ULL, 5726623059ULL, 11453246121ULL};
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
	// ok_iterPrint(lstLeft, "Left list     ");
	// ok_iterPrint(lstRight, "Right list    ");
	lstLeft = ok_mergeSort(lstLeft);
	lstRight = ok_mergeSort(lstRight);
	lstLeft.merge(lstRight);
	// ok_iterPrint(lstLeft, "Merged list   ");
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

static void	ok_mergeSort(std::vector<std::pair<unsigned int, unsigned int> > &vec, unsigned int left, unsigned int right)
{
	if (left >= right || right == (unsigned int)-1)
		return;

	unsigned int mid = left + (right - left) / 2;
	ok_mergeSort(vec, left, mid);
	ok_mergeSort(vec, mid + 1, right);
	ok_mergeVector(vec, left, mid, right);
}

static void ok_insertSort(std::list<unsigned int> &mainChain, std::list<unsigned int> &pendChain)
{
	unsigned long long	insertions = 2; 
	unsigned long long	size = pendChain.size();
	unsigned long long	index = 0;
	unsigned long long	gindex = 0;
	std::list<unsigned int>::iterator	mit; //main iterator
	std::list<unsigned int>::iterator	pit; //pend iterator
	if (1 < size)
	{
		index = 1;
		mit = mainChain.begin();
		pit = pendChain.begin();
		std::advance(mit, 3);
		std::advance(pit, 1);
		mainChain.insert(std::lower_bound(mainChain.begin(), mit, *pit), *pit);
	}
	if (0 < size)
	{
		index = 0;
		mit = mainChain.begin();
		pit = pendChain.begin();
		std::advance(mit, 3);
		std::advance(pit, 0);
		mainChain.insert(std::lower_bound(mainChain.begin(), mit, *pit), *pit);
	}
	index = g_k[gindex + 1];
	while (insertions < size)
	{
		// std::cout << "Size " << size << " | index " << index << " | insertions " << insertions << std::endl;
		if (index < size)
		{
			mit = mainChain.begin();
			pit = pendChain.begin();
			std::advance(mit, std::min((unsigned long long)mainChain.size(), (unsigned long long)std::pow(gindex + 3, 2) - 1));
			std::advance(pit, index);
			// std::cout << "Inserting: " << *pit
			// << " between " << *(mainChain.begin())
			// << " and " << *(std::lower_bound(mainChain.begin(), mit, *pit))
			// << std::endl;
			// ok_iterPrint(mainChain, "Main chain A  ");
			mainChain.insert(std::lower_bound(mainChain.begin(), mit, *pit), *pit);
			// mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.begin() + std::min((unsigned long long)mainChain.size(), (unsigned long long)std::pow(gindex + 3, 2) - 1), pendChain[index]), pendChain[index]);
			// ok_iterPrint(mainChain, "Main chain B  ");
			insertions++;
		}
		index--;
		if(index == g_k[gindex])
		{
			gindex++;
			index = g_k[gindex + 1];
		}
	}
}

// static std::vector<unsigned int>	ok_sort(std::vector<unsigned int> oldVector)
// {
	
// 	//make pairs
// 	//compare pairs
// 	// sort larger values into a sequence
// 	// insert at the start element from the smallest pair
// 	// insert the rest my magic (Ford Johnson stuff)

// 	//main chain
// 	//pend chain
// 	unsigned int	size = oldVector.size();
// 	unsigned int	leftover;
// 	bool			odd = false;
// 	(void) odd;
// 	if (size / 2)
// 		odd = true;
// 	std::vector<std::pair<unsigned int, unsigned int> > pairVector;
// 	std::vector<unsigned int>::iterator it = oldVector.begin();
// 	for (unsigned int i = 0; i < size / 2; i++)
// 	{
// 		unsigned int a = *it++;
// 		unsigned int b = *it++;
// 		std::pair<unsigned int, unsigned int> pair;
// 		(a > b) ? pair = std::make_pair(a, b) : pair = std::make_pair(b, a);
// 		pairVector.push_back(pair);
// 	}
// 	if (odd)
// 		leftover = *it;
// 	ok_mergeSort(pairVector, 0, pairVector.size() - 1);
// 	std::vector<unsigned int> mainChain;
// 	std::vector<unsigned int> pendChain;
// 	std::vector<std::pair<unsigned int, unsigned int> >::iterator iter = pairVector.begin();
// 	if (iter != pairVector.end())
// 	{
// 		mainChain.push_back(iter->second);
// 		mainChain.push_back(iter->first);
// 		iter++;
// 	}
// 	for (; iter != pairVector.end(); iter++)
// 	{
// 		mainChain.push_back(iter->first);
// 		pendChain.push_back(iter->second);
// 	}
// 	if (odd)
// 		pendChain.push_back(leftover);
// 	ok_iterPrint(pairVector, "Pair vector   ");
// 	ok_iterPrint(mainChain, "Main chain    ");
// 	ok_iterPrint(pendChain, "Pend chain    ");
// 	ok_insertSort(mainChain, pendChain);
// 	return(mainChain);
// }

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
	unsigned int	leftover;
	if (size % 2)
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
	if (odd)
		leftover = *it;
	pairList = ok_mergeSort(pairList);
	// ok_iterPrint(pairList, "Pair list     ");
	std::list<unsigned int> mainChain;
	std::list<unsigned int> pendChain;
	std::list<std::pair<unsigned int, unsigned int> >::iterator iter = pairList.begin();
	if (iter != pairList.end())
	{
		mainChain.push_back(iter->second);
		mainChain.push_back(iter->first);
		iter++;
	}
	for (; iter != pairList.end(); iter++)
	{
		mainChain.push_back(iter->first);
		pendChain.push_back(iter->second);
		// ok_iterPrint(mainChain, "Main chain BB  ");
		// ok_iterPrint(pendChain, "Pend chain BB ");
	}
	if (odd)
		pendChain.push_back(leftover);
	// ok_iterPrint(pairList, "Pair list     ");
	// ok_iterPrint(mainChain, "Main chain    ");
	// ok_iterPrint(pendChain, "Pend chain XX ");
	ok_insertSort(mainChain, pendChain);
	return(mainChain);
}
//3 7 15
//2 2 6 10 22 42
									//    4(1), 6(3) 12(9) 22(19)

static void ok_insertSort(std::vector<unsigned int> &mainChain, std::vector<unsigned int> &pendChain)
{
	unsigned long long	insertions = 2; 
	unsigned long long	size = pendChain.size();
	unsigned long long	index = 0;
	unsigned long long	gindex = 0;
	if (1 < size)
	{
		index = 1;
		
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.begin() + 3, pendChain[1]), pendChain[1]);
	}
	if (0 < size)
	{
		index = 0;
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.begin() + 3, pendChain[0]), pendChain[0]);
	}
	index = g_k[gindex + 1];
	while (insertions < size)
	{
		// std::cout << "Size " << size << " | index " << index << " | insertions " << insertions << std::endl;
		if (index < size)
		{
			// std::cout << "Inserting: " << pendChain[index]
			// << " between " << *(mainChain.begin())
			// << " and " << *(std::lower_bound(mainChain.begin(), mainChain.begin() + std::min((unsigned long long)mainChain.size(), (unsigned long long)std::pow(gindex + 3, 2) - 1), pendChain[index]))
			// << std::endl;
			// ok_iterPrint(mainChain, "Main chain A  ");
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.begin() + std::min((unsigned long long)mainChain.size(), (unsigned long long)std::pow(gindex + 3, 2) - 1), pendChain[index]), pendChain[index]);
			// ok_iterPrint(mainChain, "Main chain B  ");
			insertions++;
		}
		index--;
		if(index == g_k[gindex])
		{
			gindex++;
			index = g_k[gindex + 1];
		}
	}
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
	unsigned int	leftover;
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
	if (odd)
		leftover = *it;
	ok_mergeSort(pairVector, 0, pairVector.size() - 1);
	std::vector<unsigned int> mainChain;
	std::vector<unsigned int> pendChain;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator iter = pairVector.begin();
	if (iter != pairVector.end())
	{
		mainChain.push_back(iter->second);
		mainChain.push_back(iter->first);
		iter++;
	}
	for (; iter != pairVector.end(); iter++)
	{
		mainChain.push_back(iter->first);
		pendChain.push_back(iter->second);
	}
	if (odd)
		pendChain.push_back(leftover);
	// ok_iterPrint(pairVector, "Pair vector   ");
	// ok_iterPrint(mainChain, "Main chain    ");
	// ok_iterPrint(pendChain, "Pend chain    ");
	ok_insertSort(mainChain, pendChain);
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

	// std::cout << CLOCKS_PER_SEC << std::endl;
	ok_iterPrint(this->lstSorted, "Sorted list  ");
	ok_iterPrint(this->vecSorted, "Sorted vector");
	//get time in seconds and microseconds
	//time sort in each container
	//print containers
	std::cout << "Time to process a range of " << this->lst.size()
	<< " elements with std::list   : " << std::fixed << std::setprecision (1) << durationLst
	<< " μs" << std::endl;
	
	std::cout << "Time to process a range of " << this->vec.size()
	<< " elements with std::vector : " << std::fixed << std::setprecision (1) << durationVec
	<< " μs" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const std::pair<unsigned int, unsigned int> &pair)
{
	os << "[" << pair.first << ":" << pair.second << "]";
	return os;
}
