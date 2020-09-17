#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double x, i, a , b = 1 ,s;
    int k;
    cout << "x , k: ";
    cin >> x >> k;
    s = 0;
    a = x;
    do {
        i = a / b;
        s += i;
        a *= x * x;
        b += 2;
    } while (i > pow (10, -k));
    s *= 2;
    cout << "Taylor series computation: ";
    cout << setprecision (30) << s << endl;
    cout << "Calculation by standard functions: ";
    cout << setprecision (30) << log ((1 + x) / (1 - x));

    return 0;
}

