#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	string t = s;
	reverse(s.begin(), s.end());
	return t == s;
}

int main() {

	cout << "Opening file \"input.txt\"....\n";
	ifstream fin{ "input.txt" };
	if (fin.is_open())
		cout << "   successfully opened\n";
	else {
		cout << "   error opening file\n";
		return 0;
	}

	cout << "\n";

	cout << "Do you want to print the content of the file to the console? (print yes/no): ";
	string ans;
	cin >> ans;
	cout << "\n";

	string s;
	vector <string> p1, p0;
	while (getline(fin, s)) {
		if (ans == "yes")
			cout << s << "\n";
		stringstream ss(s);

		int cnt = 0;
		string t;
		while (ss >> t)
			if (isPalindrome(t))
				cnt++;

		if (cnt == 1)
			p1.push_back(s);
		else if (cnt == 0)
			p0.push_back(s);
	}

	if (ans == "yes") cout << "\n";

	cout << "Create file \"one palindrome.txt\"....\n";
	ofstream one{ "one palindrome.txt" };
	if (one.is_open())
		cout << "   successfully\n";
	else {
		cout << "   error creating file\n";
		return 0;
	}

	cout << "Create file \"zero palindromes.txt\"....\n";
	ofstream zero{ "zero palidromes.txt" };
	if (zero.is_open())
		cout << "   successfully\n";
	else {
		cout << "   error creating file\n";
		return 0;
	}

	if (ans == "yes") {
		cout << "\none palindrome.txt: \n";
	}
	for (auto c : p1) {
		one << c << "\n";
		if (ans == "yes")
			cout << c << " ";
	}
	if (ans == "yes") {
		cout << endl;
		cout << "\nzero palidromes.txt: \n";
	}
	for (auto c : p0) {
		zero << c << "\n";
		if (ans == "yes")
			cout << c << " ";
	}
}