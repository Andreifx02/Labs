#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main() {
	ifstream fin{ "z2.txt" };

	char c;
	map <char, int> m;

	vector <char> ans; int r = 0;
	vector <char> s;
	while (fin >> noskipws >> c) {
		if (c == ' ') {
			int mx = 0;
			for (auto c : m)
				mx = max(c.second, mx);

			if (mx > r) {
				r = mx;
				ans = s;
			}

			m.clear();
			s.clear();
			continue;
		}
		m[c]++;
		s.push_back(c);
	}

	int mx = 0;
	for (auto c : m)
		mx = max(c.second, mx);

	if (mx > r) {
		r = mx;
		ans = s;
	}

	for (auto c : ans)
		cout << c;

}

