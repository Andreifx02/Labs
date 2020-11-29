#include <sstream>
#include <iostream>
#include "Rational.h"

#pragma once
using namespace std;

Rational::Rational(const Rational& a)
{
    num = a.num;
    den = a.den;
}

Rational::Rational(int numerator, int denominator) {
    if (denominator != 0) {
        if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            } else {
                denominator = abs(denominator);
                numerator -= 2 * numerator;
            }
        }
        if (numerator == 0)
            denominator = 1;
        num = numerator / Nod(abs(numerator), abs(denominator));
        den = denominator / Nod(abs(numerator), abs(denominator));
    }
    else {
        throw invalid_argument("Error");
    }
}
int Rational::Numerator() {
    return num;
}

int Rational::Denominator() {
    return den;
}

int Rational::Nod(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

Rational add(Rational& lhs, Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator())
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    else
        return Rational(
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator());
}

Rational multip(Rational& lhs, Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational div(Rational& lhs, Rational& rhs) {
    if (rhs.Numerator() == 0) {
        stringstream ss;
        ss << "Division by zero";
        throw runtime_error(ss.str());
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}