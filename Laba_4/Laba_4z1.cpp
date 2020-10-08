#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int strToInt(string s) {
	int ans = 0;
	for (auto ch : s) {
		ans *= 10;
		int c = (unsigned char)ch - (unsigned char)'0';
		ans += c;
		if (c < 0 || c > 9)
			return 0;
	}
	return ans;
}

int main() {

	ifstream fin{ "z1.txt" };

	string s;
	while (fin >> s) {
		cout << strToInt(s) << "\n";
	}
}