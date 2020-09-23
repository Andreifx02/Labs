#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array\n";
    cin >> n;
    double a[n];
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    {
    double mn = abs(a[0]);
    int num = 0;
    for (int i = 0; i < n; i++)
        if (mn >= abs(a[i])){
            mn = abs(a[i]);
            num = i;
        }
    cout << "Minimum element: " << mn << endl;
    cout << "Position: " << num << endl;
    }

    {
    double sum = 0;
    bool mark = false;
    for (int i = 0; i < n; i++){
        if (mark)
            sum += a[i];
        if (a[i] < 0)
            mark = true;
    }
    if (!mark)
        cout << "There aren't negative numbers\n";
    else
        cout << "Sum of elements after the first negative: " << sum << endl;
    }

    {
    double p;
    cout << "Enter p: \n";
    cin >> p;
    for (int i = 0; i < n; ) {
        if (a[i] == p) {
            for (int j = i; j < n - 1; j++)
                swap(a[j], a[j + 1]);
            a[n - 1] = 0;
        }
        else
            i++;
    }
    cout << "Array without" << p <<": ";
    for (auto c : a)
        cout << c << " ";
    }
    return 0;
}
