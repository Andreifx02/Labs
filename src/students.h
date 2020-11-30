#pragma once

#include <iostream>
#include <vector>

using namespace std;

static int g_id = 1000000;

class Student {
public:
	Student(const Student& a);

	Student(char* Name, int Course, int Group, int NumZ);

	int getId() { return id; }
	int getNumZ() { return numz; }
	int getCourse() { return course; }
	int getGroup() { return group; }
	char* getName() { return name; }

	void setGroup(int new_group) { group = new_group; }
	void setName(char* new_name) { name = new_name; }
	void setCourse(int new_course) { course = new_course; }

	friend ostream& operator<< (ostream& os, const Student& a);

	virtual double CalcMean() {
		return -1;
	}

protected:
	const int id = 0;
	const int numz = 0;
	char* name;
	int course;
	int group;

	Student() {}
};

class Student1 : public Student {
public:
	Student1(const Student1& a);

	Student1(char* Name, int Course, int Group, int NumZ, vector<int> new_grade1);

	double CalcMean() override {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			sum += grade1[i];
			cnt++;
		}
		return sum / cnt;
	}

	int getGrade1(int number) { return grade1[number - 1]; }
	void setGrade1(int number, int new_grade) { grade1[number - 1] = new_grade; }

	friend ostream& operator<< (ostream& os, const Student1& a);

protected:
	vector<int> grade1;
	Student1() {}
};

class Student2 : public Student1 {
public:
	Student2(const Student2& a);

	Student2(char* Name, int Course, int Group, int NumZ, vector<int> new_grade1, vector<int> new_grade2);

	double CalcMean() override {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			sum += grade2[i];
			cnt++;
		}
		return sum / cnt;
	}

	int getGrade2(int number) { return grade2[number - 1]; }
	void setGrade2(int number, int new_grade) { grade2[number - 1] = new_grade; }
private:
	vector<int> grade2;
	Student2() {}
};
double CalcMeanInGroup(vector<Student1> v, int course, int group);
double CalcMeanInGroup(vector<Student2> v, int course, int group);

double CalcMeanForArray(vector<Student*> students);