#include <gtest/gtest.h>
#include "Rational.h"

TEST(Tcheck,NumDen){
    Rational check(3,2);
    EXPECT_EQ(3,check.Numerator());
    EXPECT_EQ(2,check.Denominator());
}

TEST(Tcheck,NegativeNumDen){
    Rational check(-1,2);
    EXPECT_EQ(-1,check.Numerator());
    EXPECT_EQ(2, check.Denominator());
}

TEST(Tcheck,NumNegativeDen){
    Rational check(5, -3);
    EXPECT_EQ(-5, check.Numerator());
    EXPECT_EQ(3,check.Denominator());
}

TEST(Tcheck,ZeroNumDen){
    Rational check(0, 1);
    EXPECT_EQ(0, check.Numerator());
    EXPECT_EQ(1,check.Denominator());
}

TEST(Tcheck,NumDen1){
    Rational check(18, 18);
    EXPECT_EQ(1,check.Numerator());
    EXPECT_EQ(1,check.Denominator());
}

TEST(Tcheck,ZeroInDen){
    EXPECT_THROW(Rational(1,0),invalid_argument);
}

TEST(Tcheck, Addition){
    Rational check1(5,2),check2(4,3);
    Rational check3(0,1);
    check3 = add(check1,check2);
    EXPECT_EQ(19,check3.Numerator());
    EXPECT_EQ(6,check3.Denominator());
}

TEST(Tcheck, AdditionWithNegativeNum){
    Rational check1(-9,2),check2(4,3);
    Rational check3(0,1);
    check3 = add(check1,check2);
    EXPECT_EQ(-19,check3.Numerator());
    EXPECT_EQ(6,check3.Denominator());
}

TEST(Tcheck, AdditionWith2NegativeNum){
    Rational check1(-5,2),check2(-4,2);
    Rational check3(0,1);
    check3 = add(check1,check2);
    EXPECT_EQ(-9,check3.Numerator());
    EXPECT_EQ(2,check3.Denominator());
}

TEST(Tcheck, AdditionWith2NegativeDen){
    Rational check1(-5,2),check2(-4,2);
    Rational check3(0,1);
    check3 = add(check1,check2);
    EXPECT_EQ(-9,check3.Numerator());
    EXPECT_EQ(2,check3.Denominator());
}

TEST(Tcheck, AdditionWith2NegativeNumDen){
    Rational check1(-5,-2),check2(-4,-5);
    Rational check3(0,1);
    check3 = add(check1,check2);
    EXPECT_EQ(33,check3.Numerator());
    EXPECT_EQ(10,check3.Denominator());
}

TEST(Tcheck, Multiplication){
    Rational check1(6,5),check2(5,8);
    Rational check3(0,1);
    check3 = multip(check1,check2);
    EXPECT_EQ(3,check3.Numerator());
    EXPECT_EQ(4,check3.Denominator());
}

TEST(Tcheck, MultiplicationWithNegativeNum){
    Rational check1(-3,5),check2(5,4);
    Rational check3(0,1);
    check3 = multip(check1,check2);
    EXPECT_EQ(-3,check3.Numerator());
    EXPECT_EQ(4,check3.Denominator());
}

TEST(Tcheck, MultiplicationWith2NegativeNum){
    Rational check1(-1,2),check2(-5,3);
    Rational check3(0,1);
    check3 = multip(check1,check2);
    EXPECT_EQ(5,check3.Numerator());
    EXPECT_EQ(6,check3.Denominator());
}

TEST(Tcheck, MultiplicationWithNegativeNumDen){
    Rational check1(-3,2),check2(5,-2);
    Rational check3(0,1);
    check3 = multip(check1,check2);
    EXPECT_EQ(15,check3.Numerator());
    EXPECT_EQ(4,check3.Denominator());
}

TEST(Tcheck, MultiplicationWithNegativeAll){
    Rational check1(-7,-3),check2(-5,-6);
    Rational check3(0,1);
    check3 = multip(check1,check2);
    EXPECT_EQ(35,check3.Numerator());
    EXPECT_EQ(18,check3.Denominator());
}

TEST(Tcheck, MultiplicationWithZeroInNum){
    Rational check1(0,1),check2(2,3);
    Rational check3(0,1);
    check3 = multip(check1,check2);
    EXPECT_EQ(0,check3.Numerator());
    EXPECT_EQ(1,check3.Denominator());
}

TEST(Tcheck, Division){
    Rational check1(6,5),check2(6,2);
    Rational check3(0,1);
    check3 = div(check1,check2);
    EXPECT_EQ(2,check3.Numerator());
    EXPECT_EQ(5,check3.Denominator());
}

TEST(Tcheck, DivisionWithNegativeNum){
    Rational check1(-9,4),check2(3,5);
    Rational check3(0,1);
    check3 = div(check1,check2);
    EXPECT_EQ(-15,check3.Numerator());
    EXPECT_EQ(4,check3.Denominator());
}

TEST(Tcheck, DivisionWith2NegativeNum){
    Rational check1(-1,4),check2(-1,3);
    Rational check3(0,1);
    check3 = div(check1,check2);
    EXPECT_EQ(3,check3.Numerator());
    EXPECT_EQ(4,check3.Denominator());
}

TEST(Tcheck, DivisionWith2NegativeDen){
    Rational check1(2,-3),check2(1,-3);
    Rational check3(0,1);
    check3 = div(check1,check2);
    EXPECT_EQ(2,check3.Numerator());
    EXPECT_EQ(1,check3.Denominator());
}

TEST(check, DivisionWithNegativeNumDen){
    Rational check1(-2,3),check2(5,-6);
    Rational check3(0,1);
    check3 = div(check1,check2);
    EXPECT_EQ(4,check3.Numerator());
    EXPECT_EQ(5,check3.Denominator());
}

