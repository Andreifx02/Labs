#include <gtest/gtest.h>
#include "students.h"

TEST(Student,Element){
    Student N1((char*)"Anna",1,2,123);
    EXPECT_STREQ((char*)"Anna",N1.getName());
    EXPECT_EQ(1,N1.getCourse());
    EXPECT_EQ(2,N1.getGroup());
    EXPECT_EQ(123,N1.getNumZ());
    EXPECT_EQ(1000001,N1.getId());
}

TEST(Student,CopyElement){
    Student N1((char*)"Anna",2,3,225);
    Student N2(N1);
    EXPECT_STREQ((char*)"Anna",N1.getName());
    EXPECT_EQ(2,N1.getCourse());
    EXPECT_EQ(3,N1.getGroup());
    EXPECT_EQ(225,N1.getNumZ());
    EXPECT_EQ(1000002,N1.getId());
}

TEST(Student,SetMethods){
    Student N1((char*)"Anna",3,3,232);
    N1.setName((char*)"Dana");
    N1.setCourse(2);
    N1.setGroup(4);
    EXPECT_STREQ((char*)"Dana",N1.getName());
    EXPECT_EQ(2,N1.getCourse());
    EXPECT_EQ(4,N1.getGroup());
}

TEST(Student,AverageScore){
    Student N1((char*)"Anna", 2, 3, 123);
    EXPECT_EQ(-1,N1.CalcMean());
}

TEST(Student1,Element1){
    Student1 N2((char*)"Vlad",3,1,123,vector <int>{1,2,4,7});
    EXPECT_STREQ((char*)"Vlad",N2.getName());
    EXPECT_EQ(3,N2.getCourse());
    EXPECT_EQ(1,N2.getGroup());
    EXPECT_EQ(123,N2.getNumZ());
    EXPECT_EQ(100001,N2.getId());
    EXPECT_EQ(1,N2.getGrade1(1));
    EXPECT_EQ(2,N2.getGrade1(2));
    EXPECT_EQ(4,N2.getGrade1(3));
    EXPECT_EQ(7,N2.getGrade1(4));
}

TEST(Student1,CopyElement){
    Student1 N2((char*)"Anton",4,2,101,vector <int>{7,6,5,5});
    Student1 N3(N2);
    EXPECT_STREQ((char*)"Anton",N2.getName());
    EXPECT_EQ(4,N2.getCourse());
    EXPECT_EQ(2,N2.getGroup());
    EXPECT_EQ(101,N2.getNumZ());
    EXPECT_EQ(100002,N2.getId());
    EXPECT_EQ(7,N2.getGrade1(1));
    EXPECT_EQ(6,N2.getGrade1(2));
    EXPECT_EQ(5,N2.getGrade1(3));
    EXPECT_EQ(5,N2.getGrade1(4));
}

TEST(Student1,setMethods1){
    Student1 N2((char*)"Slava",4, 5, 453, vector<int>{9,5,4,10});
    N2.setName((char*)"Vladimir");
    N2.setCourse(1);
    N2.setGroup(3);
    N2.setGrade1(1,8);
    N2.setGrade1(2,4);
    N2.setGrade1(3,5);
    N2.setGrade1(4,9);
    EXPECT_STREQ((char*)"Vladimir",N2.getName());
    EXPECT_EQ(1,N2.getCourse());
    EXPECT_EQ(3,N2.getGroup());
    EXPECT_EQ(8,N2.getGrade1(1));
    EXPECT_EQ(4,N2.getGrade1(2));
    EXPECT_EQ(5,N2.getGrade1(3));
    EXPECT_EQ(9,N2.getGrade1(4));
}

TEST(Student1,AverageScore1){
    Student1 N2((char*)"Roma", 3, 2, 333,vector<int>{9,9,8,4});
    double Score = (9 + 9 + 8 + 4) / 4;
    EXPECT_EQ(Score,N2.CalcMean());
}

TEST(Student2,Element2){
    Student2 N3((char*)"Ivan",4,4,565,vector<int>{3,4,6,2},vector<int>{9,6,7,9,9});
    EXPECT_STREQ((char*)"Ivan",N3.getName());
    EXPECT_EQ(4,N3.getCourse());
    EXPECT_EQ(4,N3.getGroup());
    EXPECT_EQ(565,N3.getNumZ());
    EXPECT_EQ(100001,N3.getId());
    EXPECT_EQ(3,N3.getGrade1(1));
    EXPECT_EQ(4,N3.getGrade1(2));
    EXPECT_EQ(6,N3.getGrade1(3));
    EXPECT_EQ(2,N3.getGrade1(4));
    EXPECT_EQ(9,N3.getGrade2(1));
    EXPECT_EQ(6,N3.getGrade2(2));
    EXPECT_EQ(7,N3.getGrade2(3));
    EXPECT_EQ(9,N3.getGrade2(4));
    EXPECT_EQ(9,N3.getGrade2(5));
}

TEST(Student2,CopyElement){
    Student2 N2((char*)"Stas",3,2,143,vector<int>{5,3,7,7},vector<int>{6,5,5,5,5});
    Student2 N3(N2);
    EXPECT_STREQ((char*)"Stas",N3.getName());
    EXPECT_EQ(3,N3.getCourse());
    EXPECT_EQ(2,N3.getGroup());
    EXPECT_EQ(143,N3.getNumZ());
    EXPECT_EQ(100002,N3.getId());
    EXPECT_EQ(5,N3.getGrade1(1));
    EXPECT_EQ(3,N3.getGrade1(2));
    EXPECT_EQ(7,N3.getGrade1(3));
    EXPECT_EQ(7,N3.getGrade1(4));
    EXPECT_EQ(6,N3.getGrade2(1));
    EXPECT_EQ(5,N3.getGrade2(2));
    EXPECT_EQ(5,N3.getGrade2(3));
    EXPECT_EQ(5,N3.getGrade2(4));
    EXPECT_EQ(5,N3.getGrade2(5));
}

TEST(Student2,setMethods2){
    Student2 N2((char*)"Stas",3,2,143,vector<int>{5,3,7,7},vector<int>{6,5,5,5,3});
    N2.setName((char*)"Vlad");
    N2.setCourse(4);
    N2.setGroup(4);
    N2.setGrade1(1,6);
    N2.setGrade1(2,4);
    N2.setGrade1(3,3);
    N2.setGrade1(4,5);
    N2.setGrade2(1,7);
    N2.setGrade2(2,6);
    N2.setGrade2(3,4);
    N2.setGrade2(4,8);
    N2.setGrade2(5,8);
    EXPECT_STREQ((char*)"Vlad",N2.getName());
    EXPECT_EQ(4,N2.getCourse());
    EXPECT_EQ(4,N2.getGroup());
    EXPECT_EQ(143,N2.getNumZ());
    EXPECT_EQ(100001,N2.getId());
    EXPECT_EQ(6,N2.getGrade1(1));
    EXPECT_EQ(4,N2.getGrade1(2));
    EXPECT_EQ(3,N2.getGrade1(3));
    EXPECT_EQ(5,N2.getGrade1(4));
    EXPECT_EQ(7,N2.getGrade2(1));
    EXPECT_EQ(6,N2.getGrade2(2));
    EXPECT_EQ(4,N2.getGrade2(3));
    EXPECT_EQ(3,N2.getGrade2(5));
}

TEST(Student2,AverageScore2){
    Student2 N3((char*)"Maxim",2,3,123,vector<int>{5,6,9,9},vector<int>{8,6,7,9,9});
    double Score = (5 + 6 + 9 + 9) / 4.0 + (8 + 6 + 7 + 9 + 9) / 5.0;
    EXPECT_EQ(Score,N3.CalcMean());
}

TEST(Result,AverageScoreInGroupForStudent1){
    Student1 N1((char*)"Stas", 1, 2, 123, vector <int>{1, 2, 4, 9});
    Student1 N2((char*)"Oleg", 1, 2, 4243, vector <int>{2, 6, 6, 6});
    Student1 N3((char*)"Maxim", 1, 3, 326, vector <int>{6, 5, 7, 2});
    vector <Student1> Students1{ N1, N2, N3 };
    double Score = ((1 + 2 + 4 + 9) / 4.0 + (2 + 6 + 6 + 6) / 4.0) / 2.0;
    EXPECT_EQ(Score,CalcMeanInGroup(Students1,1,2));
}

TEST(Result,AverageScoreInGroupForStudent2){
    Student2 N1((char*)"Anna", 4, 5, 122343, vector <int>{7, 2, 10, 9}, vector <int>{5, 10, 2, 4, 6});
    Student2 N2((char*)"Masha", 1, 2, 14543, vector <int>{2, 8, 1, 10}, vector <int>{5, 6, 2, 2, 3});
    Student2 N3((char*)"Roman", 1, 2, 5433, vector <int>{4, 9, 3, 8}, vector <int>{4, 3, 1, 10, 4});
    vector <Student2> Students2{ N1, N2, N3 };
    double Score = ((((2 + 8 + 1 + 10) / 4.0 + (5 + 6 + 2 + 2 + 3) / 5.0)) / 2.0 + (((4 + 9 + 3 + 8) / 4.0) + (4 + 3 + 1 + 10 + 4) / 5.0) / 2.0) / 2.0;
    EXPECT_EQ(Score,CalcMeanInGroup(Students2,1,2));
}

TEST(Result,AverageScoreForArray){
    Student* N1 = new Student((char*)"David", 1, 3, 1749);
    Student* N2 = new Student1((char*)"Stas", 1, 1, 1, vector<int>{1, 2, 3, 4});
    Student* N3 = new Student2((char*)"Anna", 1, 1, 1, vector<int>{1, 2, 3, 6}, vector<int>{8, 3, 3, 7, 6});
    vector<Student*> students = { N1, N2, N3 };
    double Score = ((1 + 2 + 3 + 4) / 4.0 + ((1 + 2 + 3 + 6) / 4.0 + (8 + 3 + 3 + 7 + 6) / 5.0) / 2.0) / 2.0;
    EXPECT_EQ(Score,CalcMeanForArray(students));
}