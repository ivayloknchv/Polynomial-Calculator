#pragma once
#include <iostream>
#include <vector>

int myAbs(int num);

int myGcd(int a, int b);

int myLcm(int a, int b);

int myPow(int base, int pow);

int myMax(int a, int b);

bool isNum(char ch);

int getNumFromChar(char ch);

int parseNum(const char*& data, char separator);

void generateAllCombinations(std::vector<std::vector<int>>& allCombos, int start, int n, int k, std::vector<int>& currentComb);

std::vector<int> findAllDivisors(int number);