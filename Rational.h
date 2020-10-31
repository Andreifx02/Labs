#include <iostream>
#include <sstream>
#include <cmath>
#include <cassert>

#pragma once
using namespace std;

class Rational {
public:

    Rational(const Rational& a)
    {
        num = a.num;
        den = a.den;
    }

    Rational(int numerator, int denominator) {
        assert(denominator != 0);
        if(denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else {
                denominator = abs(denominator);
                numerator -= 2 * numerator;
            }
        }
        if (numerator == 0)
            denominator = 1;

        num = numerator / Nod(abs(numerator), abs(denominator));
        den = denominator / Nod(abs(numerator), abs(denominator));
    }

    int Numerator() {
        return num;
    }

    int Denominator() {
        return den;
    }

private:
    int num, den;
    Rational() {};
    int Nod(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b)
                a %= b;
            else
                b %= a;
        }
        return a + b;
    }
};

