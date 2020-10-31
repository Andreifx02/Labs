#include "Methods.h"
#include "Rational.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

istream& operator>>(istream& stream, Rational& r)
{
    int num, den;
    if (stream >> num && stream.ignore(1, '/') >> den)
        r = { num, den };
    return stream;
}

ostream& operator <<(ostream& stream, Rational& r)
{
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
}


int main(){
    int Numerator1, Denominator1, Numerator2, Denominator2;
    cin >> Numerator1 >> Denominator1 >> Numerator2 >> Denominator2;
    Rational r1(Numerator1, Denominator1), r2(Numerator2, Denominator2);
    char operation_code;
    cin >> r1 >> operation_code >> r2;
    if (operation_code == '+') {
        Rational r3 = add(r1,r2);
        cout << r3;
    }

    else if (operation_code == '*') {
        Rational r3 = multip(r1, r2);
        cout << r3;
    }

    else if (operation_code == '/') {
        Rational r3 = div(r1, r2);
        cout << r3;
    }
    else {
        cout << "Wrong operation!" << endl;
        return 1;
    } 

    return 0;
}