#include "commandFuncs.h"

void pressAnyKey()
{
	char ch;
	std::cout << "Press any key to continue... ";
	std::cin >> ch;
}

void displayCommands()
{
	std::cout << "Choose one of the following functionalities: \n";
	std::cout << "1) Add polynomials\n";
	std::cout << "2) Subract polynomials\n";
	std::cout << "3) Multiply polynomials\n";
	std::cout << "4) Divide polynomials\n";
	std::cout << "5) Multiply polynomial by scalar\n";
	std::cout << "6) Find value of polynomial at a given number\n";
	std::cout << "7) Find GCD of two polynomials \n";
	std::cout << "8) Display Vieta's formulas for a given polynomial\n";
	std::cout << "9) Represent a polynomial in powers of (x+a)\n";
	std::cout << "10) Factor polynomial and find its rational roots\n";
	std::cout << "11) Quit program\n\n";
}

void run()
{
	std::cout << "Welcome to Polynomail Calculator - a mini project aimed to work with polynomials with rational coefficents\n\n";

	int option = 0;

	while (true)
	{
		displayCommands();
		std::cout << "Enter your option here>> ";
		std::cin >> option;

		switch (option)
		{
		case 1: 
			addFunctionality();
			break;
		case 2:
			subractFunctionality();
			break;
		case 3: 
			multiplyFunctionality();
			break;
		case 4: 
			divideFuctionality();
				break;
		case 5:
			multiplyByScalarFunctionality();
			break;
		case 6: 
			valueAtFunctionality();
			break;
		case 7: 
			gcdFunctionality();
			break;
		case 8: 
			vietaFunctionality();
			break;
		case 9:
			representPolynomialFunctionality();
			break;
		case 10: 
			rootsFunctionality();
			break;
		case 11:
			std::cout << "Thank you for using Polynomail Calculator! See you next time! \n";
			return;
		default:
			std::cout << "Invalid command!\n";
			pressAnyKey();
			break;
		}

		system("cls");
	}
}

void addFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter Polynomial Q(x)\n";
	Polynomial q = readPolynomial();

	std::cout << "\nQ(x) = ";
	printPolynomial(q);
	std::cout << "\n\n";

	std::cout << "\nP(x)+Q(x)=";
	printPolynomial(addPolynomials(p, q));
	std::cout << "\n\n";

	pressAnyKey();
}

void subractFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter Polynomial Q(x)\n";
	Polynomial q = readPolynomial();

	std::cout << "\nQ(x) = ";
	printPolynomial(q);
	std::cout << "\n\n";

	std::cout << "\nP(x)-Q(x)=";
	printPolynomial(subtractPolynomials(p, q));
	std::cout << "\n\n";

	pressAnyKey();
}

void multiplyFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter Polynomial Q(x)\n";
	Polynomial q = readPolynomial();

	std::cout << "\nQ(x) = ";
	printPolynomial(q);
	std::cout << "\n\n";

	std::cout << "\nP(x)*Q(x)=";
	printPolynomial(multiplyPolynomials(p, q));
	std::cout << "\n\n";

	pressAnyKey();
}

void divideFuctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial A(x)\n";
	Polynomial a = readPolynomial();

	std::cout << "\nA(x) = ";
	printPolynomial(a);
	std::cout << "\n\n";

	std::cout << "Enter Polynomial B(x)\n";
	Polynomial b = readPolynomial();

	std::cout << "\nB(x) = ";
	printPolynomial(b);
	std::cout << "\n\n";

	if (a.size() < b.size())
	{
		std::cout << "Divisor B(x) is higher degree than divident A(X)!\n";
		pressAnyKey();
		return;
	}
	else if ((b.size() == 1) && (isZero(b[0])))
	{
		std::cout << "Divisor B(x) is zero!\n";
		pressAnyKey();
		return;
	}

	std::pair<Polynomial, Polynomial> result=dividePolynomials(a,b);

	std::cout << "Quotient Q(x)=";
	printPolynomial(result.first);
	std::cout << "\n\n";

	std::cout << "Remainder R(x)=";
	printPolynomial(result.second);
	std::cout << "\n\n";

	pressAnyKey();
}

void multiplyByScalarFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter rational number>> ";
	char buff[20];
	std::cin >> buff;
	std::cin.ignore();
	rationalNumber scalar = parseRationalFromString(buff);

	std::cout << '\n';
	printPolynomial(multiplyByScalar(p, scalar));

	pressAnyKey();
}

void valueAtFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter rational number>> ";
	char buff[20];
	std::cin >> buff;
	std::cin.ignore();
	rationalNumber scalar = parseRationalFromString(buff);

	std::cout << "\n\nP(";
	printRationalNum(scalar);
	std::cout << ") = ";
	printRationalNum(valuetAt(p, scalar));
	std::cout << '\n';

	pressAnyKey();
}

void gcdFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter Polynomial Q(x)\n";
	Polynomial q = readPolynomial();

	std::cout << "\nQ(x) = ";
	printPolynomial(q);
	std::cout << "\n\n";


	Polynomial gcd;

	if (p.size() < q.size())
	{
		gcd = polynomialGCD(q, p);
	}
	else
	{
		gcd = polynomialGCD(p, q);
	}

	std::cout << "gcd(P,Q) = ";
	printPolynomial(polynomialGCD(p, q));
	std::cout << '\n';

	pressAnyKey();
}

void vietaFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\n\n";

	vietaFormulas(p);

	pressAnyKey();
}

void representPolynomialFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	std::cout << "Enter rational number a>> ";
	char buff[20];
	std::cin >> buff;
	std::cin.ignore();
	rationalNumber a = parseRationalFromString(buff);

	if (isZero(a))
	{
		std::cout << "The result is the same polynomial!\n";
		pressAnyKey();
		return;
	}

	Polynomial result = factorByDegreesOfExpr(p, multiply({ -1,1 }, a));
	std::cout << "P";
	printExpr(1, a);
	std::cout << " = ";
	printPolynomial(result,a);
	std::cout << '\n';

	pressAnyKey();
}

void rootsFunctionality()
{
	std::cout << "\n";
	std::cout << "Enter Polynomial P(x)\n";
	Polynomial p = readPolynomial();

	std::cout << "\nP(x) = ";
	printPolynomial(p);
	std::cout << "\n\n";

	findRationalRoots(p);

	pressAnyKey();
}
	
