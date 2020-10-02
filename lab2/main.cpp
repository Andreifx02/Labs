#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    double a[n];
    int temp;
    cout << "How do you want to enter numbers?\n";
    cout << "    1 - random numbers\n    2 - I'll enter myself\n";
    cout << "Enter (1 / 2): ";
    cin >> temp;
    if (temp == 1){
        int x;
        cout << "Enter max number: ";
        cin >> x;
        for (int i = 0; i < n; i++)
            a[i] = (rand() % (x + 1)) * (int) pow(-1, rand() % 2);
        cout << "Array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

    }
    else
    {
        cout << "Enter " << n << " elements: \n";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }
    {
    double mn = a[0];

    int num = 0;
    for (int i = 0; i < n; i++)
        if (abs(mn) >= abs(a[i])){
            mn = a[i];
            num = i;
        }
    cout << "Minimum element (abs): " << mn << endl;
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
    cout << "Enter p: ";
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
    cout << "Array without " << p <<": ";
    for (auto c : a)
        cout << c << " ";
    }
    return 0;
}
