#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cctype>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

enum LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

static bool isSpecialFloat(const std::string &s)
{
	return (s == "-inff" || s == "+inff" || s == "inff" || s == "nanf");
}

static bool isSpecialDouble(const std::string &s)
{
	return (s == "-inf" || s == "+inf" || s == "inf" || s == "nan");
}

static LiteralType detectType(const std::string &literal)
{
	if (isSpecialFloat(literal))
		return FLOAT;
	if (isSpecialDouble(literal))
		return DOUBLE;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return CHAR;

	bool hasDigit = false;
	bool hasDot = false;
	bool hasF = false;
	size_t i = 0;
	size_t len = literal.length();

	if (len == 0)
		return INVALID;

	if (literal[0] == '+' || literal[0] == '-')
		i = 1;

	for (; i < len; ++i)
	{
		if (std::isdigit(literal[i]))
			hasDigit = true;
		else if (literal[i] == '.' && !hasDot)
			hasDot = true;
		else if (literal[i] == 'f' && i == len - 1 && hasDigit)
			hasF = true;
		else
			return INVALID;
	}

	if (!hasDigit)
		return INVALID;

	if (hasF)
		return FLOAT;
	if (hasDot)
		return DOUBLE;
	return INT;
}

static void printFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printFromInt(int n)
{
	if (n < 0 || n > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(n))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

template <typename T>
static void printFromFloating(T value, bool isFloatOrigin)
{
	(void)isFloatOrigin;
	// char
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 255)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (std::isnan(value) || std::isinf(value) ||
		value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
	std::cout << std::endl;

	// double
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value);
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	LiteralType type = detectType(literal);

	switch (type)
	{
		case CHAR:
		{
			printFromChar(literal[0]);
			break;
		}
		case INT:
		{
			long n = std::strtol(literal.c_str(), NULL, 10);
			if (n > INT_MAX || n < INT_MIN)
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			else
				printFromInt(static_cast<int>(n));
			break;
		}
		case FLOAT:
		{
			float f;
			if (isSpecialFloat(literal))
			{
				if (literal == "-inff")
					f = -std::numeric_limits<float>::infinity();
				else if (literal == "nanf")
					f = std::numeric_limits<float>::quiet_NaN();
				else
					f = std::numeric_limits<float>::infinity();
			}
			else
				f = std::strtof(literal.c_str(), NULL);
			printFromFloating<float>(f, true);
			break;
		}
		case DOUBLE:
		{
			double d;
			if (isSpecialDouble(literal))
			{
				if (literal == "-inf")
					d = -std::numeric_limits<double>::infinity();
				else if (literal == "nan")
					d = std::numeric_limits<double>::quiet_NaN();
				else
					d = std::numeric_limits<double>::infinity();
			}
			else
				d = std::strtod(literal.c_str(), NULL);
			printFromFloating<double>(d, false);
			break;
		}
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}
