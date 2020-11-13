#include <iostream>
#include <vector>

#include "students.h"

using namespace std;

int main() {
	Student1 s1((char*)"Stas", 1, 2, 123, vector <int>{1, 2, 4, 9});
	Student1 s2((char*)"Oleg", 1, 2, 4243, vector <int>{2, 6, 6, 6});
	Student1 s3((char*)"Maxim", 1, 3, 326, vector <int>{6, 5, 7, 2});


	vector <Student1> Students1{ s1, s2, s3 };

	cout << CalcMeanInGroup(Students1, 1, 2) << endl;

	Student2 s4((char*)"Anna", 4, 5, 122343, vector <int>{7, 2, 10, 9}, vector <int>{5, 10, 2, 4, 6});
	Student2 s5((char*)"Masha", 1, 2, 14543, vector <int>{2, 8, 1, 10}, vector <int>{5, 6, 2, 2, 3});
	Student2 s6((char*)"Roman", 1, 2, 5433, vector <int>{4, 9, 3, 8}, vector <int>{4, 3, 1, 10, 4});

	vector <Student2> Students2{ s4, s5, s6 };

	cout << CalcMeanInGroup(Students2, 1, 2) << endl;

	Student* a = new Student((char*)"David", 1, 3, 1749);
	Student* b = new Student1((char*)"sadsa", 1, 1, 1, vector<int>{1, 2, 3, 4});
	Student* c = new Student2((char*)"sadsa", 1, 1, 1, vector<int>{1, 2, 3, 6}, vector<int>{1, 2, 3, 45});

	vector<Student*> students = { a, b, c };

	cout << CalcMeanForArray(students) << endl;


}