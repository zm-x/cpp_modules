#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <exception>
#include <stdlib.h>

typedef std::map<std::string, double> _map;
class BitcoinExchange
{
    private:
        _map data_base;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();

        BitcoinExchange &operator=(const BitcoinExchange &to_copy);

        _map &GetDb();
        void LoadDb();
        void ReadInput(const std::string &file);


        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value, const std::string &line);
        // void IfValidLine(std::string &line);
        // _map &ParseDb(_map &file_map);
        // std::string GetResult(_map &file_value);

        class OpenFileException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif