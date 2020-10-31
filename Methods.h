#include <sstream>
#include <iostream>
#include "Rational.h"

#pragma once
using namespace std;

Rational add(Rational& lhs, Rational& rhs) {
    if (lhs.Denominator() == rhs.Denominator())
        return Rational(lhs.Numerator() + rhs.Numerator(), lhs.Denominator());
    else
        return Rational(
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * rhs.Denominator(),
            lhs.Denominator() * lhs.Denominator());
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