#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>

bool	isPrintableChar(char c)
{
	return (c >= 32 && c <= 126) ? true : false;
}

bool	isDigitChar(char c)
{
	return (c >= '0' && c <= '9') ? true : false;
}

bool	isPseudoLiteral(std::string s)
{
	return (s == "-inff" || s == "+inff" || s == "nanf" ||
			s == "-inf" || s == "+inf" || s == "nan");
}

int 	getPrecision(char *s)
{
	int 	precision = 0;
	int 	len = static_cast<int>(std::strlen(s));
	bool	foundDot = false;

	for (int i = 0 ; i < len ; i++)
	{
		if (s[i] == '.')
		{
			foundDot = true;
			continue ;
		}
		if (!foundDot)
			continue ;
		if (isDigitChar(s[i]))
			precision++;
		else
			return precision;
	}

	return precision;
}

void	printToChar(double toConvert, std::string s)
{
	if (isPseudoLiteral(s) || toConvert < 0 || toConvert > 127)
	{
		std::cout << "char: Impossible" << std::endl;
		return ;
	}

	char converted = static_cast<char>(toConvert);
	
	if (!isPrintableChar(converted))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	
	std::cout << "char: \'" << converted << "\'" << std::endl; 
}

void	printToInt(double toConvert, std::string s)
{
	if (isPseudoLiteral(s) || toConvert > INT_MAX || toConvert < INT_MIN)
	{
		std::cout << "int: Impossible" << std::endl;
		return ;
	}

	int converted = static_cast<int>(toConvert);
	std::cout << "int : " << converted << std::endl;
}

void	printToFloat(double toConvert, int precision)
{
	float converted = static_cast<float>(toConvert);
	precision += !precision ? 1 : 0;
	std::cout << "float : " << std::setprecision(precision) << std::fixed << converted << "f" << std::endl;
}

void	printToDouble(double toConvert, int precision)
{
	precision += !precision ? 1 : 0;
	std::cout << "double : " << std::setprecision(precision) << std::fixed << toConvert << std::endl;
}

int 	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "You must provide a single parameter to this program." << std::endl;
		return 1;
	}

	double toConvert;

	if (std::strlen(av[1]) == 1 && !isDigitChar(av[1][0]) && isPrintableChar(av[1][0]))
		toConvert = av[1][0];
	else
		toConvert = std::atof(av[1]);

	int precision = getPrecision(av[1]);

	printToChar(toConvert, av[1]);
	printToInt(toConvert, av[1]);
	printToFloat(toConvert, precision);
	printToDouble(toConvert, precision);

	return 0;
} 