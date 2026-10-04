#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, double> _rates;
	bool _databaseLoaded;

	static std::string trim(const std::string& value);
	static bool parseDate(const std::string& date);
	static bool parseRate(const std::string& text, double& value);
	static bool isLeapYear(int year);
	static bool parseInteger(const std::string& text, int& value);
	bool loadDatabase(const std::string& filename);
	void processLine(const std::string& line) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	bool loadInput(const std::string& filename) const;
};

#endif
