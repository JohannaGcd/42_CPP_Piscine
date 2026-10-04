#include "BitcoinExchange.hpp"

#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>

BitcoinExchange::BitcoinExchange()
	: _databaseLoaded(false)
{
	_databaseLoaded = loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _rates(other._rates), _databaseLoaded(other._databaseLoaded)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_rates = other._rates;
		_databaseLoaded = other._databaseLoaded;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string& value)
{
	std::string::size_type first = 0;
	std::string::size_type last = value.size();

	while (first < last && (value[first] == ' ' || value[first] == '\t'
			|| value[first] == '\r'))
		++first;
	while (last > first && (value[last - 1] == ' ' || value[last - 1] == '\t'
			|| value[last - 1] == '\r'))
		--last;
	return value.substr(first, last - first);
}

bool BitcoinExchange::isLeapYear(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

bool BitcoinExchange::parseInteger(const std::string& text, int& value)
{
	char* end = 0;
	long parsed;

	if (text.empty())
		return false;
	errno = 0;
	parsed = std::strtol(text.c_str(), &end, 10);
	if (errno == ERANGE || end == text.c_str() || *end != '\0'
		|| parsed < 0 || parsed > std::numeric_limits<int>::max())
		return false;
	value = static_cast<int>(parsed);
	return true;
}

bool BitcoinExchange::parseDate(const std::string& date)
{
	int year;
	int month;
	int day;
	std::string::size_type index;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (index = 0; index < date.size(); ++index)
	{
		if (index == 4 || index == 7)
			continue;
		if (date[index] < '0' || date[index] > '9')
			return false;
	}
	if (!parseInteger(date.substr(0, 4), year)
		|| !parseInteger(date.substr(5, 2), month)
		|| !parseInteger(date.substr(8, 2), day))
		return false;
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;
	if (month == 2)
		return day <= (isLeapYear(year) ? 29 : 28);
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return day <= 30;
	return day <= 31;
}

bool BitcoinExchange::parseRate(const std::string& text, double& value)
{
	char* end = 0;
	double parsed;

	if (text.empty())
		return false;
	errno = 0;
	parsed = std::strtod(text.c_str(), &end);
	if (errno == ERANGE || end == text.c_str() || *end != '\0'
		|| parsed != parsed)
		return false;
	value = parsed;
	return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream database(filename.c_str());
	std::string line;
	bool hasHeader = false;

	if (!database.is_open())
		return false;
	if (!std::getline(database, line) || trim(line) != "date,exchange_rate")
		return false;
	hasHeader = true;
	while (std::getline(database, line))
	{
		std::string::size_type separator = line.find(',');
		double rate;
		std::string date;

		if (separator == std::string::npos)
			continue;
		date = trim(line.substr(0, separator));
		if (!parseDate(date) || !parseRate(trim(line.substr(separator + 1)), rate)
			|| rate < 0)
			continue;
		_rates[date] = rate;
	}
	return hasHeader && !_rates.empty();
}

void BitcoinExchange::processLine(const std::string& line) const
{
	std::string::size_type separator = line.find('|');
	std::string date;
	std::string valueText;
	double value;
	std::map<std::string, double>::const_iterator rate;

	if (separator == std::string::npos || line.find('|', separator + 1)
		!= std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	date = trim(line.substr(0, separator));
	valueText = trim(line.substr(separator + 1));
	if (!parseDate(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	if (!parseRate(valueText, value))
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}
	rate = _rates.lower_bound(date);
	if (rate == _rates.end() || rate->first != date)
	{
		if (rate == _rates.begin())
		{
			std::cerr << "Error: no rate available for date." << std::endl;
			return;
		}
		--rate;
	}
	std::cout << date << " => " << valueText << " = "
		<< value * rate->second << std::endl;
}

bool BitcoinExchange::loadInput(const std::string& filename) const
{
	std::ifstream input(filename.c_str());
	std::string line;

	if (!_databaseLoaded || !input.is_open())
		return false;
	if (!std::getline(input, line) || trim(line) != "date | value")
	{
		std::cerr << "Error: bad input => "
			<< (line.empty() ? "missing header" : line) << std::endl;
		return true;
	}
	while (std::getline(input, line))
		processLine(line);
	return true;
}
