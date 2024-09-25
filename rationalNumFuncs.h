#pragma once
#include <iostream>

typedef std::pair<int, int> rationalNumber;

void canonForm(rationalNumber& ratiomnalNum);

rationalNumber parseRationalFromString(const char* data);

rationalNumber createRational(int a, int b = 1);

rationalNumber add(const rationalNumber& lhs, const rationalNumber& rhs);

rationalNumber subtract(const rationalNumber& lhs, const rationalNumber& rhs);

rationalNumber multiply(const rationalNumber& lhs, const rationalNumber& rhs);

rationalNumber divide(const rationalNumber& lhs, const rationalNumber& rhs);

rationalNumber pow(const rationalNumber rationalNum, int pow);

bool isZero(const rationalNumber& rationalNum);

bool areEqual(const rationalNumber& lhs, const rationalNumber& rhs);

void printRationalNum(const rationalNumber& rationalNum);