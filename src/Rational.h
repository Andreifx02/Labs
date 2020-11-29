#include <iostream>
#include <sstream>
#include <cmath>
#include <cassert>


#pragma once
using namespace std;

class Rational {
public:
    Rational(const Rational& a);
    Rational(int numerator, int denominator);

    int Numerator();
    int Denominator();


private:
    int num, den;
    Rational() {};
    int Nod(int a, int b);
};

Rational add(Rational& lhs, Rational& rhs);
Rational multip(Rational& lhs, Rational& rhs);
Rational div(Rational& lhs, Rational& rhs);

