#include <iostream>
#include <sstream>
#include "calculator.h"

using namespace std;

int main() {
    Calculator a;
    cout << a.calculate("(2 + 2 * 2)^2");
}

