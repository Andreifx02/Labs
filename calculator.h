#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>
#include "stack.h"
using namespace std;

class Calculator {
private:
    string polish_notation;
    map <char, int> priority{
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'^', 3}
    };
    bool isDigit(const char& c);
    bool isOperation(const char& c);
    enum class Token {
        NUMBER, OPEN_BRACKET, CLOSE_BRACKET, OPERATION, NONE
    };
public:
    bool isValidExpr(string s);
    double polishNotationCalc();
    double calculate(const string& expr);
};