#include <iostream> 
#include <vector> 
#include <ctime> 
#include <iomanip> 
#include <cmath> 
 
using namespace std; 
 
int Rand(int m) { 
    return (rand() % (m + 1)) * (int) pow(-1, rand() % 2); 
} 
 
int elementOnIndex(int i, int j, vector <vector <int> > &a, vector <int> &num, int anm) { 
    if ((num[j] + i) % 2) 
        return a[j][i - (i + 1) / 2]; 
    return anm; 
} 
 
void printMatrix(int n, int m, vector <vector <int> > &a, vector <int> &num, int anm) { 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) 
            cout << setw(3) << elementOnIndex(i, j, a, num, anm) << " "; 
        cout << "\n"; 
    } 
} 
 
int main() { 
 
    srand(time(0)); 
 
    int n, m; 
    do { 
        cout << "Enter n and m ( <= 10 ): "; 
        cin >> n >> m; 
        if (n <= 10 && m <= 10) 
            break; 
        cout << "Wrong input. Try again ;)\n\n"; 
    } while (true); 
    cout << "\n"; 
 
    cout << "RANDOM MATRIX a[i,j] = a[n,m], (i + j) % 2 == 0\n"; 
 
    vector <vector <int> > a(m); 
 
    int anm; 
    int mx; 
    cout << "Enter max number in matrix: "; 
    cin >> mx; 
    anm = Rand(mx); 
 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if ((i + j) % 2) { 
                if (i == n - 1 && j == m - 1) 
                    a[j].push_back(anm); 
                else 
                    a[j].push_back(Rand(mx)); 
            } 
 
    vector <int> num(m); 
    for (int i = 0; i < m; i++) 
        num[i] = i; 
 
    cout << "\na[n,m] = " << anm << "\n"; 
    cout << "Matrix:\n"; 
    printMatrix(n, m, a, num, anm); 
 
    vector <int> characteristic(m); 
 
    for (int i = 0; i < m; i++) { 
        for (auto c : a[i]) 
            if (c < 0 && abs(c) % 2) 
                characteristic[i] += abs(c); 
        if (anm < 0 && abs(anm) % 2) 
            characteristic[i] += abs(anm) * (n - a[i].size()); 
    } 
 
    cout << "Characteristics:\n"; 
    for (auto c : characteristic) 
        cout << setw(3) << c << " "; 
    cout << "\n"; 
 
    for (int i = 0; i < characteristic.size(); i++) { 
        for (int j = i; j < characteristic.size(); j++) { 
            if (characteristic[i] > characteristic[j]) { 
                swap(characteristic[i], characteristic[j]); 
                swap(a[i], a[j]); 
                swap(num[i], num[j]); 
            } 
        } 
    } 
 
    cout << "\nMatrix after sorting columns:\n"; 
    printMatrix(n, m, a, num, anm); 
 
    cout << "Characteristics:\n"; 
    for (auto c : characteristic) 
        cout << setw(3) << c << " "; 
    cout << "\n\n"; 
 
    cout << "sum in columns\n"; 
    for (int i = 0; i < m; i++) { 
        cout << "column " << i + 1 << ": "; 
        bool mark = false; 
        int sum = 0; 
        if (anm < 0) 
            mark = true; 
        for (auto c : a[i]) { 
            sum += c; 
            if (c < 0) 
                mark = true; 
        } 
        if (mark) { 
            sum += anm * (n - a[i].size()); 
            cout << sum << "\n"; 
            continue; 
        } 
        cout << "don't have negative numbers\n"; 
    } 
} 

