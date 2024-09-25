#pragma once
#include "rationalNumFuncs.h"
#include <vector>

typedef std::vector<std::pair<int, int>> Polynomial;

typedef std::vector<std::vector<std::pair<int, int>>> Grid;

size_t getLeadingZerosCount(const Polynomial& poly);

void removeLeadingZeros(Polynomial& poly);

void setAllCoeffsToZero(Polynomial& poly);

Polynomial readPolynomial();

Grid createHornerGrid(const Polynomial& poly);

void printX(int power);

void printExpr(int power, const  rationalNumber& ratNum);

void printPolynomial(const Polynomial& polynomial);

void printPolynomial(const Polynomial& polynomial, const rationalNumber& ratNum);

rationalNumber valuetAt(const Polynomial& poly, const std::pair<int, int>& rationalNum);

Polynomial multiplyByScalar(const Polynomial& poly, const std::pair<int, int>& scalar);

Polynomial addPolynomials(const Polynomial& lhs, const Polynomial& rhs);

Polynomial subtractPolynomials(const Polynomial& lhs, const Polynomial& rhs);

Polynomial multiplyPolynomials(const Polynomial& lhs, const Polynomial& rhs);

std::pair<Polynomial, Polynomial> dividePolynomials(const Polynomial& dividend, const Polynomial& divisor);
//returns quotient and remainder

Polynomial factorByDegreesOfExpr(const Polynomial& poly, const rationalNumber& ratNum);

void displayCurrentVietaFormula(const Polynomial& poly, int k);

void vietaFormulas(const Polynomial& poly);

Polynomial polynomialGCD(const Polynomial& poly1, const Polynomial& poly2);

void findRationalRoots(const Polynomial& poly);

void removeRightmostZeros(Polynomial& poly, std::vector<std::pair<rationalNumber, size_t>>& rootsInfo);

int findLCMofDenominators(const Polynomial& poly);

void simplifyPolynomial(Polynomial& poly); // finds GCD of all coefss and then makes all the numerators 1

bool containsRational(const rationalNumber& rational, const std::vector<rationalNumber> potentialRoots);

void findPotentialRoots(std::vector<rationalNumber>& potentialRoots, const Polynomial& poly);

void analyseRoot(Polynomial& factoredPoly, const rationalNumber& ratNum, std::vector<std::pair<rationalNumber, size_t>>& rootsInfo);

void displayFactoredPolynomialInfo(const Polynomial& poly, const Polynomial& factored, const std::vector<std::pair<rationalNumber, size_t>>& rootsInfo);

void displayRootsInfo(const std::vector<std::pair<rationalNumber, size_t>>& rootsInfo);