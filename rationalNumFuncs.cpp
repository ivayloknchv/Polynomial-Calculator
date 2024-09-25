#include "rationalNumFuncs.h"
#include "helperFuncs.h"

void canonForm(rationalNumber& rationalNum)
{
  
    if (rationalNum.first * rationalNum.second <= 0)
    {
        rationalNum.first = -myAbs(rationalNum.first);
        rationalNum.second = myAbs(rationalNum.second);
    }
    else if (rationalNum.second < 0)
    {
        rationalNum.first *= -1;
        rationalNum.second *= -1;
    }

    int gcd = myGcd(rationalNum.first, rationalNum.second);

    rationalNum.first /= gcd;
    rationalNum.second /= gcd;
}

rationalNumber parseRationalFromString(const char* data)
{
    int numerator = 0;
    int denominator = 1;

    numerator = parseNum(data,'/');
    ++data;
    denominator = parseNum(data, '/');

    if (denominator == 0)
    {
        denominator = 1;

    }
    return createRational(numerator, denominator);
}

rationalNumber createRational(int a, int b)
{
    rationalNumber result;
    result.first = a;
    result.second = b;

    canonForm(result);

    return result;
}

rationalNumber add(const rationalNumber& lhs, const rationalNumber& rhs)
{
    rationalNumber result;
    result.first = lhs.first * rhs.second + rhs.first * lhs.second;
    result.second = lhs.second * rhs.second;

    canonForm(result);

    return result;
}

rationalNumber subtract(const rationalNumber& lhs, const rationalNumber& rhs)
{
    rationalNumber result;
    result.first = lhs.first * rhs.second - rhs.first * lhs.second;
    result.second = lhs.second * rhs.second;

    canonForm(result);

    return result;
}

rationalNumber multiply(const rationalNumber& lhs, const rationalNumber& rhs)
{
    rationalNumber result;
    result.first = lhs.first * rhs.first;
    result.second = lhs.second * rhs.second;

    canonForm(result);

    return result;
}

rationalNumber divide(const rationalNumber& lhs, const rationalNumber& rhs)
{
    rationalNumber result;
    result.first = lhs.first * rhs.second;
    result.second = lhs.second * rhs.first;

    canonForm(result);

    return result;
}

rationalNumber pow(const rationalNumber rationalNum, int pow)
{
    rationalNumber result;

    result.first = myPow(rationalNum.first, pow);
    result.second = myPow(rationalNum.second, pow);

    canonForm(result);

    return result;
}

bool isZero(const rationalNumber& rationalNum)
{
    return rationalNum.first == 0;
}

bool areEqual(const rationalNumber& lhs, const rationalNumber& rhs)
{
    return (lhs.first*rhs.second==lhs.second*rhs.first);
}

void printRationalNum(const rationalNumber& rationalNum)
{
    
    std::cout << rationalNum.first;
    if (rationalNum.second != 1)
    {
       std::cout << '/' << rationalNum.second;
    }
}

