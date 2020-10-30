#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

string ConsoleReader(string msg){
	cout << msg;
	string temp;
	cin >> temp;
	return temp;
}

bool IsNonIncreasingOrder(string& word){
	for (int i = word.size() - 2; i >= 2; i-=2) {
		if (word[i] < word[i - 2])
			return false;
	}
	return true;
}

vector<string> FileReader(string inpute_file){
	vector<string> File;
	ifstream fin(inpute_file);
	string s;
	while (getline(fin, s)) {
		File.push_back(s);
	}
	return File;
}

vector <string> WordParser(vector <string>& File){
	vector <string> Word;
	
	for (int i = 0; i < File.size(); i++) {
		stringstream ss;
		string t;
		ss << File[i];
		while (ss >> t) {
			Word.push_back(t);
		}
	}
	return Word;
}


vector <string> FindItems(vector <string>& File) {
	vector <string> Colection;
	for (int i = 0; i < File.size(); i++) {
		if (IsNonIncreasingOrder(File[i]))
			Colection.push_back(File[i]);
	}
	return Colection;
}

int WordWeight(string& word) {
	int weight = 0;
	for (auto ch : word) {
		int code = (unsigned char)ch;
		if ((code & 20) == 20)
			weight += code;
	}
	return weight;
}

int WordWeight(vector <string>& words) {
	int ans = 0;
	for (auto word : words)
		ans += WordWeight(word);
	return ans;
}

map <string, int> CreateMap(vector <string>& words){
	map <string, int> word_weight_map;
	for (auto word : words)
		word_weight_map[word] = WordWeight(word);
	return word_weight_map;
}
template <typename T>
void FileWriter(map <string, T> &word_weight_map) {
    ofstream fout{"output_file.txt"};
    for (auto p : word_weight_map)
        fout << right << setw(11) << p.first << " " << setw(3) << p.second << "\n";
}

int main(){
	vector <string> lines = FileReader(ConsoleReader("Enter input file name: "));
	vector <string> words = WordParser(lines);
	words = FindItems(words);
	for (auto c : words)
		cout << c << " ";
	map <string, int> word_weight_map = CreateMap(words);
	FileWriter(word_weight_map); 
}