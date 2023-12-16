/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 07:05:31 by hael-mou          #+#    #+#             */
/*   Updated: 2023/11/27 10:42:06 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*##############################################################################
#       *  Constructor & Destructor	:                                          #
##############################################################################*/

//=== Default Constructor : ====================================================
BtcExchange::BtcExchange(const char *dataBase) {
	std::cout << "   _                _                    " << std::endl;
	std::cout << "  /_)._/__  _  ._  /_`  _  /_ _  _  _  _ " << std::endl;
	std::cout << " /_)/ / /_ /_/// //_,></_ / //_|/ //_//_'" << std::endl;
	std::cout << "===================================_/====" << std::endl;
	this->setDataBase(dataBase);
}

//=== Copy Constructor : =======================================================
BtcExchange::BtcExchange(const BtcExchange &copy)
{
	std::cout << "   _                _                    " << std::endl;
	std::cout << "  /_)._/__  _  ._  /_`  _  /_ _  _  _  _ " << std::endl;
	std::cout << " /_)/ / /_ /_/// //_,></_ / //_|/ //_//_'" << std::endl;
	std::cout << "===================================_/====" << std::endl;
	this->mDataBase = copy.mDataBase;
}

//=== Destructor : =============================================================
BtcExchange::~BtcExchange(void) {
	std::cout << "=========================================" << std::endl;
}

/*##############################################################################
#       *  Constructor & Destructor	:                                          #
##############################################################################*/

BtcExchange &BtcExchange::operator=(const BtcExchange &other)
{
	if (this != &other) {
		this->mDataBase = other.mDataBase;
	}
	return (*this);
}

/*##############################################################################
#       * Method :                                                             #
##############################################################################*/

//=== setDataBase : ============================================================
void	BtcExchange::setDataBase(const char *dataBase)
{
	std::ifstream	datafile(dataBase);

	std::cout << "* set DataBase ===" << std::endl;
	if (datafile.is_open() == false) {
		std::cerr << "Error : opening file => " << dataBase << std::endl;
	}
	else {
		this->mDataBase.clear();
		uploadDataBase(this->mDataBase, datafile);
		datafile.close();
	}
}

//=== showDataBase : ===========================================================
void BtcExchange::showDataBase(void)
{
	std::cout << "* DataBase =======" << std::endl;
	BtcExchange::iterator it = mDataBase.begin();
	while (it != mDataBase.end())
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
}

//=== uploadDataBase : =========================================================
void	BtcExchange::uploadDataBase(base_type& dtb, std::ifstream& file)
{
	string		line;
	uint		lineNumber = 1;

	while (std::getline(file, line))
	{
		if (lineNumber == 1 && ++lineNumber)
			continue ;
		try {
			dtb.insert(parse_pair(line, ",", OFF));
		}
		catch(const std::exception& e) {
			handleException(line, lineNumber, e.what());
		}
		lineNumber++;
	}
}

//=== parse_pair : =============================================================
BtcExchange::pair BtcExchange::parse_pair(string& line, const char *delim, int max)
{
	size_t	pos 		= line.find(delim);

	if (pos == string::npos || line.length() < pos + 2) {
		throw (std::invalid_argument("bad input"));
	}
	string	date	= checkDate(line.substr(0, pos));
	double	value	= checkValue(line.substr(pos + 1), max);
	return (pair(date, value));
}

//=== checkDate : ==============================================================
std::string BtcExchange::checkDate(string date)
{
	std::stringstream	ss(date);
	int			year, month, day;
	char		delim;

	if (date.length() == 11 && date[10] == ' ')
		date.erase(date.length() - 1);
	if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
		throw (std::invalid_argument("invalid date [yyyy-mm-dd]"));
	}
	if (date.find_first_not_of("0123456789-") != string::npos){
		throw (std::invalid_argument("invalid date [0..9]"));
	}
	ss >> year  >> delim;
	ss >> month >> delim;
	ss >> day;
	if (year < 0 || month > 12 || month < 1 || day > 31 || day < 1) {
		throw (std::invalid_argument("invalid date [invalid value]"));
	}
	return (date);
}

//=== checkValue : =============================================================
double	BtcExchange::checkValue(string valueStr, int max)
{
	char	*ptrEnd;
	double	value	 = std::strtod(valueStr.c_str(), &ptrEnd); 
	if (std::strlen(ptrEnd) != 0)
		throw (std::invalid_argument("invalid value"));
	if (value < 0)
		throw (std::invalid_argument("Not a positive number"));
	if (max > 0 && value > max)
		throw (std::invalid_argument("Too large a number"));
	return (value);
}

//=== exchange : ===============================================================
void	BtcExchange::exchange(const char * filename)
{
	string			line;
	pair			btc_pair;
	uint			lineNumber = 1;
	std::ifstream	infile(filename);

	std::cout << "* Exchange =======" << std::endl;
	if (infile.is_open() == false) {
		std::cerr << "Error : opening file => " << filename << std::endl;
	}
	else {
		while (mDataBase.size() != 0 && std::getline(infile, line))
		{
			if (lineNumber == 1 && ++lineNumber)
				continue ;
			try {
				btc_pair = parse_pair(line, "|", 1000);
				std::cout << btc_pair.first << " => " << btc_pair.second;
				std::cout << " = " << (getValueFromDataBase(btc_pair.first) * btc_pair.second) << std::endl;
			}
			catch(const std::exception& e) {
				handleException(line, lineNumber, e.what());
			}
			lineNumber++;
		}
		infile.close();
	}
}

//=== getValueFromDataBase : ===================================================
double	BtcExchange::getValueFromDataBase(const string& date)
{
	if (mDataBase.count(date) == 1)
		return (mDataBase[date]);
	return ((--mDataBase.upper_bound(date))->second);
}

//=== handleException : ========================================================
void BtcExchange::handleException(string line, uint lineNumber, const char *msg)
{
	std::cerr << "Error line " << lineNumber << ": " << msg;
	std::cerr << " => \033[3;91m" << line << "\033[0m" << std::endl;
}
