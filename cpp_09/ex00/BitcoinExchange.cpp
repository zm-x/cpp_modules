#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
    LoadDb();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
    : data_base(copy.data_base) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        data_base = copy.data_base;
    return *this;
}

const char *BitcoinExchange::OpenFileException::what() const throw()
{
    return "could not open file";
}

_map &BitcoinExchange::GetDb() {return data_base;}


bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (day < 1 || day > days[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, const std::string &line)
{
    bool dot = false;
    bool negative = false;
    bool digit = false;

    for (size_t i = 0; i < value.length(); i++)
    {
        if (value[i] == ' ')
            continue;

        if (std::isdigit(value[i]))
        {
            digit = true;
            continue;
        }

        if (value[i] == '.')
        {
            if (dot)
                return false;
            dot = true;
            continue;
        }

        if (value[i] == '-')
        {
            if (negative || digit || dot)
                return false;
            negative = true;
            continue;
        }

        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    if (!digit)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }
    double number = std::atof(value.c_str());
    if (number < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (number > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::ReadInput(const std::string &file)
{
    std::string line;
    std::ifstream input(file.c_str());
    if (!input)
        throw OpenFileException();
    std::getline(input, line);
    if (line != "date | value")
    {
        std::cout << "Error: bad input file." << std::endl;
        return;
    }
    while (std::getline(input, line))
    {
        if (line.empty())
            continue;
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos - 1);
        std::string value = line.substr(pos + 1);
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidValue(value, line))
            continue;
        double amount = std::atof(value.c_str());
        std::map<std::string, double>::iterator it = data_base.lower_bound(date);
        if (it == data_base.end())
            --it;
        else if (it->first != date)
        {
            if (it == data_base.begin())
            {
                std::cout << "Error: no exchange rate available." << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date
                << " => "
                << amount
                << " = "
                << amount * it->second
                  << std::endl;
    }
}

void BitcoinExchange::LoadDb()
{
    std::string line;
    std::ifstream input("data.csv");
    if (!input)
        throw OpenFileException();
    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t pos = line.find(',');
        std::string date = line.substr(0, pos);
        double price = std::atof(line.substr(pos + 1).c_str());
        data_base.insert(std::make_pair(date, price));
    }
}