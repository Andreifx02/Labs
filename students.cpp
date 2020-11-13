#include "students.h"

double CalcMeanInGroup(vector<Student2> v, int group) {
	int sum;
	int cnt;
	for(int i = 0; i < v.size(); i++)
		if (v[i].getGroup() == group) {
			sum += v[i].CalcMean();
			cnt++;
		}
	return sum / cnt;
}

double CalcMeanForArray(vector<Student*> students) {
	double sum = 0;
	int cnt = 0;

	for (Student* student : students) {
		double current = student->CalcMean();
		if (current != -1) {
			sum += current;
			++cnt;
		}
	}

	return sum / cnt;
}


Student::Student(const Student& a) :
	id(g_id++), name(a.name), course(a.course), group(a.group), numz(a.numz) {
}

Student::Student(char* Name, int Course, int Group, int NumZ) :
	id(g_id++), numz(NumZ), name(Name), course(Course), group(Group) {
}

ostream& operator<< (ostream& os, const Student& a) {
	os << a.id << " " << a.name << " " << a.course << " " << a.group << " " << a.numz;
	return os;
}

Student1::Student1(const Student1& a)
	: Student(a.name, a.course, a.group, a.numz)
	, grade1(a.grade1) {
}

Student1::Student1(char* Name, int Course, int Group, int NumZ, vector<int> new_grade1)
	: Student(Name, Course, Group, NumZ)
	, grade1(new_grade1) {
}
ostream& operator<< (ostream& os, const Student1& a) {
	os << a.id << " " << a.name << " " << a.course << " " << a.group << " " << a.numz << " ";
	os << "Grades: ";
	for (int m : a.grade1) {
		os << m << " ";
	}

	return os;
}

Student2::Student2(const Student2& a)
	: Student1(a.name, a.course, a.group, a.numz, a.grade1)
	, grade2(a.grade2) {
}

Student2::Student2(char* Name, int Course, int Group, int NumZ, vector<int> new_grade1, vector<int> new_grade2)
	: Student1(Name, Course, Group, NumZ, new_grade1)
	, grade2(new_grade2) {
}

