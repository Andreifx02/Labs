#include <iostream>
#include <vector>

#include "students.h"

using namespace std;

int main() {
	Student* a = new Student((char*)"David", 1, 3, 1749);
	Student* b = new Student1((char*)"sadsa", 1, 1, 1, vector<int>{1, 2, 3, 4}); 
	Student* c = new Student2((char*)"sadsa", 1, 1, 1, vector<int>{1, 2, 3, 6}, vector<int>{1, 2, 3, 45}); 

	vector<Student*> students = { a, b, c };

	cout << CalcMeanForArray(students) << endl;
	cout << *a << endl;
	return 0;
}