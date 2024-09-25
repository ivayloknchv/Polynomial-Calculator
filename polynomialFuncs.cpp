#include "polynomialFuncs.h"
#include "helperFuncs.h"

size_t getLeadingZerosCount(const Polynomial& poly)
{
	size_t counter = 0;

	while (counter < poly.size() && isZero(poly[counter]))
	{
		counter++;
	}

	return counter;
}

void removeLeadingZeros(Polynomial& poly)
{
	size_t counter = getLeadingZerosCount(poly);

	if (counter == 0)
	{
		return;
	}

	if (counter == poly.size())
	{
		poly = Polynomial(1);
		setAllCoeffsToZero(poly);
		return;
	}

	Polynomial noZeros(poly.size() - counter);
	int noZeroCounter = 0;

	for (size_t i = counter; i < poly.size(); i++)
	{
		noZeros[noZeroCounter++]=(poly[i]);
	}

	poly = noZeros;
}

void setAllCoeffsToZero(Polynomial& poly)
{
	for (size_t i = 0; i < poly.size(); i++)
	{
		poly[i].first = 0;
		poly[i].second = 1;
	}
}

void printX(int power)
{
	if (power == 1)
	{
		std::cout << "x";
		return;
	}
	if (power == 0)
	{
		return;
	}
	std::cout << "x^" << power;
}

void printExpr(int power, const rationalNumber& ratNum)
{
	if (power >= 2)
	{
		std::cout << "(x";

		if (ratNum.first > 0)
		{
			std::cout << "+";
		}
		printRationalNum(ratNum);
		std::cout << ")^" << power;
	}

	else if (power == 1)
	{
		std::cout << "(x";

		if (ratNum.first > 0)
		{
			std::cout << "+";
		}
		printRationalNum(ratNum);
		std::cout << ")";
	}
}

Polynomial readPolynomial()
{
	size_t deg = 0;
	std::cout << "Enter degree of your polynomial>> ";
	std::cin >> deg;

	std::cout << "\n";
	std::vector<std::pair<int, int>> poly(deg + 1);

	std::cin.ignore();
	

	for (size_t i = 0; i <= deg; i++)
	{
		char buff[32]{};
		std::cout << "Enter coefficent before x^" << deg - i << ">> ";
		std::cin >> buff;

		poly[i] = parseRationalFromString(buff);
	}

	removeLeadingZeros(poly);

	return poly;
}

Grid createHornerGrid(const Polynomial& poly)
{
	Grid horner;
	horner.resize(poly.size() + 1);

	horner[0] = poly;

	for (size_t i = 1; i < horner.size(); i++)
	{
		horner[i].resize(poly.size());
		setAllCoeffsToZero(horner[i]);
	}

	return horner;
}

void printPolynomial(const Polynomial& polynomial)
{
	printRationalNum(polynomial[0]);

	printX(polynomial.size() - 1);

	for(size_t i = 1; i <polynomial.size(); i++)
	{
		if (!isZero(polynomial[i]))
		{
			if (polynomial[i].first > 0)
			{
				std::cout << "+";
			}
			printRationalNum(polynomial[i]);
			printX(polynomial.size() - 1-i);
		}
	}
}

void printPolynomial(const Polynomial& polynomial, const rationalNumber& ratNum)
{
	if (polynomial[0].first == -1 && polynomial[0].second == 1)
	{
		printRationalNum(polynomial[0]);

	}
	else if (polynomial[0].first != 1 && polynomial[0].second == 1)
	{
		printRationalNum(polynomial[0]);
	}
	printExpr(polynomial.size() - 1, ratNum);

	for (size_t i = 1; i < polynomial.size(); i++)
	{
		if (!isZero(polynomial[i]))
		{
			if (polynomial[i].first > 0)
			{
				std::cout << "+";
			}
			printRationalNum(polynomial[i]);
			printExpr(polynomial.size() - 1 - i, ratNum);
		}
	}
}

rationalNumber valuetAt(const Polynomial& poly, const std::pair<int, int>& rationalNum)
{
	rationalNumber result = poly[0];

	//Applying Horner's rule

	for (size_t i = 1; i < poly.size(); i++)
	{
		result=multiply(rationalNum,result);
		result = add(result, poly[i]);
	}

	return result;
}

Polynomial multiplyByScalar(const Polynomial& poly, const std::pair<int, int>& scalar)
{
	Polynomial result(poly.size());

	for (size_t i = 0; i < poly.size(); i++)
	{
		result[i] = multiply(scalar, poly[i]);
	}

	return result;
}

Polynomial addPolynomials(const Polynomial& lhs, const Polynomial& rhs)
{
	int resultSize = myMax(lhs.size(), rhs.size());
	Polynomial result(resultSize);

	setAllCoeffsToZero(result);

	int indexShift = myAbs(lhs.size() - resultSize);

	for (size_t i = 0; i < lhs.size(); i++)
	{
		int resultIdx = i + indexShift;
		result[resultIdx] = add(result[resultIdx], lhs[i]);
	}


	indexShift = myAbs(rhs.size() - resultSize);
	for (size_t i = 0; i < rhs.size(); i++)
	{
		int resultIdx = i + indexShift;
		result[resultIdx] = add(result[resultIdx], rhs[i]);
	}

	removeLeadingZeros(result);

	return result;
}

Polynomial subtractPolynomials(const Polynomial& lhs, const Polynomial& rhs)
{
	int resultSize = myMax(lhs.size(), rhs.size());
	Polynomial result(resultSize);

	setAllCoeffsToZero(result);

	int indexShift = myAbs(lhs.size() - resultSize);

	for (size_t i = 0; i < lhs.size(); i++)
	{
		int resultIdx = i + indexShift;
		result[resultIdx] = add(result[resultIdx], lhs[i]);
	}


	indexShift = myAbs(rhs.size() - resultSize);
	for (size_t i = 0; i < rhs.size(); i++)
	{
		int resultIdx = i + indexShift;
		result[resultIdx] = subtract(result[resultIdx], rhs[i]);
	}

	removeLeadingZeros(result);

	return result;
}

Polynomial multiplyPolynomials(const Polynomial& lhs, const Polynomial& rhs)
{
	Polynomial result(lhs.size() + rhs.size() - 1);
	setAllCoeffsToZero(result);

	for (size_t i = 0; i < lhs.size(); i++)
	{
		size_t lhsDeg = lhs.size() - i - 1;
		for (size_t j = 0; j < rhs.size(); j++)
		{
			
			size_t rhsDeg = rhs.size() - j - 1;

			size_t resultDeg = lhsDeg + rhsDeg;

			result[result.size()-1-resultDeg] = add(result[result.size() - 1 - resultDeg], multiply(lhs[i], rhs[j]));
		}
	}

	removeLeadingZeros(result);
	return result;
}

std::pair<Polynomial, Polynomial> dividePolynomials(const Polynomial& dividend, const Polynomial& divisor)
{
	size_t degDivident = dividend.size() - 1;
	size_t degDivisor = divisor.size() - 1;

	size_t quotientDeg = degDivident - degDivisor;
	std::pair<Polynomial, Polynomial> toReturn;
	toReturn.first=Polynomial(quotientDeg + 1); //quotient
	setAllCoeffsToZero(toReturn.first);
	toReturn.second = dividend; //remainder


	while (toReturn.second.size() >= divisor.size())
	{
		size_t degRemainder = toReturn.second.size() - 1;
		size_t degCurrentQuotient = degRemainder - degDivisor;
		size_t currentQuotientIdx = toReturn.first.size() - degCurrentQuotient - 1;
		toReturn.first[currentQuotientIdx] = divide(toReturn.second[0],divisor[0]);


		if (divisor.size() == 1)
		{
			toReturn.second.resize(1);
			setAllCoeffsToZero(toReturn.second);

			for (size_t i = 0; i < toReturn.first.size(); i++)
			{
				toReturn.first[i] = divide(dividend[i], divisor[0]);
			}

			return toReturn;
		}
		
		for (size_t i = 0; i <= degDivisor; i++) 
		{
			size_t currentDivisorDeg = divisor.size()-i - 1;
			size_t currentRemainderDeg = currentDivisorDeg + degCurrentQuotient;

			size_t currentRemainderIdx = toReturn.second.size() - currentRemainderDeg - 1;

			toReturn.second[currentRemainderIdx] = subtract(toReturn.second[currentRemainderIdx], multiply(toReturn.first[currentQuotientIdx], divisor[i]));
		}

		removeLeadingZeros(toReturn.second);

		if (toReturn.second.size() == 0)
		{
			toReturn.second=Polynomial(1);
			setAllCoeffsToZero(toReturn.second);
		}
	}

	removeLeadingZeros(toReturn.second);
	return toReturn;
}

Polynomial factorByDegreesOfExpr(const Polynomial& poly, const rationalNumber& value)
{
	Polynomial result = Polynomial(poly.size());

	Grid horner = createHornerGrid(poly);

	for (size_t i = 1; i < horner.size(); i++)
	{
		horner[i][0] = horner[0][0];
		for (size_t j = 1; j < horner.size() - i ; j++)
		{
			horner[i][j] = add(horner[i - 1][j], multiply(value, horner[i][j - 1]));
		}
	}

	size_t counter = poly.size()-1;
	for (size_t i = 1; i <= poly.size(); i++)
	{
		size_t resIdx = poly.size() - i;
		const rationalNumber& num= horner[i][counter--];
		result[resIdx] = num;
	}
	
	return result;
}

void displayCurrentVietaFormula(const Polynomial& poly, int k)
{
	std::vector<std::vector<int>> allCombos;
	std::vector<int> tempCombo;

	generateAllCombinations(allCombos,1,poly.size()-1,k, tempCombo);

	for (size_t i = 0; i < allCombos.size(); i++)
	{
		for (size_t j = 0; j < allCombos[i].size(); j++)
		{
			std::cout << "x" << allCombos[i][j];
		}
		
		if (i != allCombos.size() - 1)
		{
			std::cout << " + ";
		}
	}

	std::cout << " = ";

	rationalNumber result = divide(poly[k], poly[0]);

	if (k % 2 == 1)
	{
		result = multiply({ -1,1 }, result);
	}

	printRationalNum(result);
}

void vietaFormulas(const Polynomial& poly)
{
	std::cout << "\n\n";
	std::cout << "Vieta's Formulas for polynomial: ";
	printPolynomial(poly);
	std::cout << "\n\n";

	for (size_t i = 1; i < poly.size(); i++)
	{
		displayCurrentVietaFormula(poly, i);
		std::cout << '\n';
	}
}

Polynomial polynomialGCD(const Polynomial& poly1, const Polynomial& poly2)
{
	if (poly2.size() == 1 && isZero(poly2[0]))
	{
		return poly1;
	}

	Polynomial remainder = dividePolynomials(poly1, poly2).second;
	return polynomialGCD(poly2, remainder);
}

void findRationalRoots(const Polynomial& poly)
{
	std::vector<std::pair<rationalNumber, size_t>> rootsInfo; //keeps every root and how many times it is repeated

	Polynomial factoredPoly = poly;

	removeRightmostZeros(factoredPoly, rootsInfo);

	simplifyPolynomial(factoredPoly);

	std::vector<rationalNumber> potentialRoots;

	findPotentialRoots(potentialRoots, factoredPoly);

	for (size_t i = 0; i < potentialRoots.size(); i++)
	{
		analyseRoot(factoredPoly,potentialRoots[i],rootsInfo);
	}

	for (size_t i = 0; i < factoredPoly.size(); i++)
	{
		factoredPoly[i].first /= factoredPoly[0].first;
	}

	displayFactoredPolynomialInfo(poly, factoredPoly, rootsInfo);
}

void removeRightmostZeros(Polynomial& poly, std::vector<std::pair<rationalNumber, size_t>>& rootsInfo)
{
	size_t counter = 0;
	while (isZero(poly[poly.size()-1]))
	{
		poly.pop_back();
		counter++;
	}
	

	if (counter != 0)
	{
		rootsInfo.push_back({ { 0,1 }, counter });
	}
}

int findLCMofDenominators(const Polynomial& poly)
{
	int lcm = poly[0].second;

	for (size_t i = 1; i < poly.size(); i++)
	{
		lcm = myLcm(lcm, poly[i].second);
	}

	return lcm;
}

void simplifyPolynomial(Polynomial& poly)
{
	int lcm = findLCMofDenominators(poly);

	for (size_t i = 0; i < poly.size(); i++)
	{
		int multiplier = lcm / poly[i].second;
		poly[i].first *= multiplier;
		poly[i].second = 1;

	}
}

bool containsRational(const rationalNumber& rational, const std::vector<rationalNumber> potentialRoots)
{
	for (size_t i = 0; i < potentialRoots.size(); i++)
	{
		if (areEqual(rational, potentialRoots[i]))
		{
			return true;
		}
	}
	return false;
}

void findPotentialRoots(std::vector<rationalNumber>& potentialRoots, const Polynomial& poly)
{
	std::vector<int> constantDivisors = findAllDivisors(poly[poly.size() - 1].first);
	std::vector<int> leadingDivisors = findAllDivisors(poly[0].first);
	

	for (size_t i = 0; i < constantDivisors.size(); i++)
	{
		for (size_t j = 0; j < leadingDivisors.size(); j++)
		{
			rationalNumber currentNum = createRational(myAbs(constantDivisors[i]), myAbs(leadingDivisors[j]));

			if (!containsRational(currentNum, potentialRoots))
			{
				potentialRoots.push_back(currentNum);
			}

			currentNum = multiply({ -1,1 }, currentNum); // check and the opposite num

			if (!containsRational(currentNum, potentialRoots))
			{
				potentialRoots.push_back(currentNum);
			}
		}
	}
}

void analyseRoot(Polynomial& factoredPoly, const rationalNumber& ratNum, std::vector<std::pair<rationalNumber, size_t>>& rootsInfo)
{
	int repeatedCounter = 0;

	Grid horner = createHornerGrid(factoredPoly);

	for (size_t i = 1; i < horner.size(); i++)
	{
		size_t j;
		horner[i][0] = horner[0][0];
		for (j = 1; j < horner.size() - i; j++)
		{
			horner[i][j] = add(horner[i - 1][j], multiply(ratNum, horner[i][j - 1]));
		}

		if (isZero(horner[i][j-1]))
		{
			repeatedCounter++;
		}

		else
		{
			factoredPoly = horner[i - 1];

			for (int i = 0; i < repeatedCounter; i++)
			{
				factoredPoly.pop_back();
			}

			if (repeatedCounter > 0)
			{
				rootsInfo.push_back({ ratNum, repeatedCounter });
			}

			return;
		}
	}
}

void displayFactoredPolynomialInfo(const Polynomial& poly, const Polynomial& factored, const std::vector<std::pair<rationalNumber, size_t>>& rootsInfo)
{
	std::cout << '\n';

	if (rootsInfo.size() == 0)
	{
		std::cout << "Polynomial doesn't have rational roots!\n";
		return;
	}

	if (!areEqual(poly[0], { 1,1 }))
	{
		if (poly[0].first == -1)
		{
			std::cout << "-";
		}
		else
		{
			printRationalNum(poly[0]);
		}
	}

	for (size_t i = 0; i < rootsInfo.size(); i++)
	{
		if (isZero(rootsInfo[i].first))
		{
			printX(rootsInfo[i].second);
		}
		else
		{
			printExpr(rootsInfo[i].second, multiply({ -1,1 }, rootsInfo[i].first));
		}
	}

	if (factored.size() > 1)
	{
		std::cout << '(';
		printPolynomial(factored);
		std::cout << ')';
	}

	std::cout << " = 0\n\n";

	displayRootsInfo(rootsInfo);
}

void displayRootsInfo(const std::vector<std::pair<rationalNumber, size_t>>& rootsInfo)
{
	std::cout << "RATIONAL ROOTS:\n";
	for (size_t i = 0; i < rootsInfo.size(); i++)
	{
		std::cout << "x = ";
		printRationalNum(rootsInfo[i].first);
		std::cout << " - ";
		std::cout << rootsInfo[i].second << "-fold root\n";
	}
}
