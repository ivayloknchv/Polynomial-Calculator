#include "helperFuncs.h"

int myAbs(int num)
{
	return (num >= 0) ? num : -num;
}

int myGcd(int a, int b)
{
	a = myAbs(a);
	b = myAbs(b);
	if (b == 0)
		return a;

	return myGcd(b, a % b);
}

int myLcm(int a, int b)
{
	a = myAbs(a);
	b = myAbs(b);

	return (a * b) / myGcd(a, b);
}

int myPow(int base, int pow)
{
	if (pow == 0)
	{
		return 1;
	}

	if (pow % 2 == 0)
	{
		return myPow(base * base, pow / 2);
	}
	else
	{
		return base * myPow(base, pow - 1);
	}
}

int myMax(int a, int b)
{
	return (a>b) ? a : b;
}

bool isNum(char ch)
{
	return ch >= '0' && ch <= '9';
}

int getNumFromChar(char ch)
{
	return ch - '0';
}

int parseNum(const char*& data, char separator)
{
	if (!data)
	{
		return 0;
	}
	int result = 0;
	bool isNegative = false;

	while (*data != '\0' && *data != separator)
	{
		if (*data == '-')
		{
			isNegative = true;
		}
		else if (isNum(*data))
		{
			result *= 10;
			result += getNumFromChar(*data);
		}
		data++;
	}

	if (isNegative)
	{
		result *= -1;
	}

	return result;
}

void generateAllCombinations(std::vector<std::vector<int>>& allCombos, int start, int n, int k, std::vector<int>& currentComb)
{
	if (k == currentComb.size())
	{
		allCombos.push_back(currentComb);
		return;
	}

	for (int i = start; i <= n; i++)
	{
		currentComb.push_back(i);
		generateAllCombinations(allCombos, i + 1, n, k, currentComb);
		currentComb.pop_back();
	}
}

std::vector<int> findAllDivisors(int number)
{
	std::vector<int> divisors;
	number = myAbs(number);

	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0)
		{
			divisors.push_back(i);
		}
	}

	return divisors;
}



