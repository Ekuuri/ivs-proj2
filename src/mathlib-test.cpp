/****************************************************************** 
* Project name: IVS 2 project
* Date: 20.3.2025
* Last change: 20.3.2024
* Team: audentes Fortuna iuvat 
* Author: Vojtěch Jedlička
* Brief: Test for test driven development of math library 
*****************************************************************
/**
* @file mathlib-test.cpp
*
* @brief Test for test driven development of math library
* @author Vojtěch Jedlička
*/

#include "gtest/gtest.h"
#include "mathlib_code.h"

using namespace:: testing;


TEST(addition, positiveNumbers){
    EXPECT_EQ(12, addition(5, 7));
    EXPECT_EQ(3012, addition(2950, 72));
}

TEST(addition, negativeNumbers){
    EXPECT_EQ(-25, addition(-32, 12));
    EXPECT_EQ(2, addtion(-255, 257));
    EXPECT_EQ(0, addition(-32, 32));
}

TEST(addition, problematicInputs){
    EXPECT_EQ(2, addition(12, addition(-32, 20)));
    EXPECT_EQ(-4, addition(-4, 0));
    EXPECT_EQ(addition(12,4), additon(4, 12));
    EXPECT_EQ(28.13, addition(23.98, 4.15));
    EXPECT_EQ(12505224, addition(12462310, 42914));
    EXPECT_EQ(-3.82, addition(0, -3.82));
    EXPECT_DOUBLE_EQ(369.54627659, addition(301.18897659, 68.3573));
}

TEST(subtraction, positiveNumbers){
    EXPECT_EQ(6, subtraction(63, 57));
    EXPECT_EQ(8819, subtraction(12782, 3963));
}

TEST(subtraction, negativeNumbers){
    EXPECT_EQ(-102, subtraction(-58, 44));
    EXPECT_EQ(-1315, subtraction(-584, 731));
    EXPECT_EQ(0, subtraction(32, 32));
}

TEST(subtraction, problematicInputs){
    EXPECT_EQ(-4, subtraction(-4, 0));
    EXPECT_EQ(subtraction(468,987), subtraction(987, 468));
    EXPECT_EQ(1846,33, subtraction(1854.98, 8.65));
    EXPECT_EQ(6972560, subtraction(54814875, 47842315));
    EXPECT_EQ(-54.878, subtraction(0, -54.878));
    EXPECT_DOUBLE_EQ(442748.21001, subtraction(447355, 4606.78999));
}

TEST(multiplication, normalInputs){
    EXPECT_EQ(12, multiplication(3, 4));
    EXPECT_EQ(-1728, multiplication(-36, 48));
    EXPECT_EQ(234651280, multiplication(415312, 565));
}

TEST(multiplication, problematicInputs){
    EXPECT_EQ(52, multiplication(-13, -4));
    EXPECT_EQ(multiplication(-899, 151), multiplication(151, -899));
    EXPECT_EQ(0, multiplication(0, 4458984545));
    EXPECT_EQ(0, multiplication(45154878, 0));
    EXPECT_EQ(180, multiplication(0.25, 720));
    EXPECT_DOUBLE_EQ(46212.21045256, multiplication(88.5656, 521.7851));
}

TEST(division, normalInputs){
    EXPECT_EQ(9, division(63, 7));
    EXPECT_EQ(1165, division(1149855, 987));
    EXPECT_EQ(-47, division(-39668, 844));
    EXPECT_EQ(123, division(-11808, -123));
}

TEST(division, problematicInputs){
    EXPECT_EQ(0, division(0, 684));
    EXPECT_EQ(0, division(0, -846));
    EXPECT_ANY_THROW(division(99771, 0));
    EXPECT_NE(divison(14,7), division(7,14));
    EXPECT_DOUBLE_EQ(10626.98412698413, division(6695, 0.63));
    EXPECT_DOUBLE_EQ(3.709954307870418, division(541.568, 145.977));
}

TEST(factorial, normalInputs){
    EXPECT_EQ(6, factorial(3));
    EXPECT_EQ(39916800, factorial(11));
    EXPECT_EQ( 121645100408832000 ,factorial(19));
}

TEST(factorial, problematicInputs){
    EXPECT_EQ(1, factorial(0));
    EXPECT_ANY_THROW(factorial(-1));
    EXPECT_ANY_THROW(factorial(-38));
}

TEST(exponentiation, normalInputs){
    EXPECT_EQ(32, exponentiation(2, 5));
    EXPECT_EQ(7529536, exponentiation(14,6));
    EXPECT_EQ(815730721, exponentiation(169, 4));
    EXPECT_DOUBLE_EQ(0.0180143985, exponentiation(0.8, 18));
    EXPECT_EQ(-371293, exponentiation(-13, 5));
}

TEST(exponentiation, problematicInputs){
    EXPECT_EQ(1, exponentiation(1632, 0));
    EXPECT_EQ(0, exponentiation(0, 64614));
    EXPECT_EQ(1, exponentiation(0.34, 0));
    EXPECT_EQ(-282429536481, exponentiation(-81, 6));
    EXPECT_ANY_THROW(exponentiation(7845, -78));
    EXPECT_ANY_THROW(exponentiation(4656, 0.540));
}

TEST(nthRoot, normalInputs){
    EXPECT_EQ(2, nthRoot(64, 6));
    EXPECT_DOUBLE_EQ(0,736008935 ,nthRoot(0.4, 3));
    EXPECT_DOUBLE_EQ(11.44699, nthRoot(2250654, 6));
    EXPECT_DOUBLE_EQ(0.00024414,nthRoot(16, -3));
}

TEST(nthRoot, problematicInputs){
    EXPECT_EQ(-5, nthRoot(-125, 3));
    EXPECT_EQ(0, nthRoot(0, 13));
    EXPECT_DOUBLE_EQ(0.7937005259840998, nthRoot(0.25, 6));
    EXPECT_ANY_THROW(nthRoot(-35, 2));
}



int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*** End of file mathlib-test.cpp ***/