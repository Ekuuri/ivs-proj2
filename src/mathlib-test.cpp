/****************************************************************** 
* Project name: IVS 2 project
* Date: 20.3.2025
* Last change: 22.4.2025
* Team: audentes Fortuna iuvat 
* Author: Vojtěch Jedlička
* Brief: Test for test driven development of math library 
******************************************************************/
/**
* @file mathlib-test.cpp
*
* @brief Tests for math library operations
* @author Vojtěch Jedlička
*/

#include <gtest/gtest.h>
#include "mathlib-code.h"

using namespace testing;

/**
 * Test suites are named after mathematical functions that they test.
 * Functions are tested for standard inputs which is one collection of tests
 * and for inputs that can be somehow problematic (because of sign, 0 etc.) 
 * which is another collection of tests.
 */

/** 
 * @brief Test of function addition() with positive numbers
 * 
 * @see addition(double, double)
 */
TEST(addition, positiveNumbers){
    EXPECT_EQ(12, addition(5, 7));
    EXPECT_EQ(3022, addition(2950, 72));
}

/** 
 * @brief Test of function addition() with negative numbers
 * 
 * @see addition(double, double)
 */
TEST(addition, negativeNumbers){
    EXPECT_EQ(-20, addition(-32, 12));
    EXPECT_EQ(2, addition(-255, 257));
    EXPECT_EQ(0, addition(-32, 32));
}

/** 
 * @brief Test of function addition() with problematic inputs
 * 
 * @see addition(double, double)
 */
TEST(addition, problematicInputs){
    EXPECT_EQ(0, addition(12, addition(-32, 20)));
    EXPECT_EQ(-4, addition(-4, 0));
    EXPECT_EQ(addition(12,4), addition(4, 12));
    EXPECT_DOUBLE_EQ(28.13, addition(23.98, 4.15));
    EXPECT_EQ(12505224, addition(12462310, 42914));
    EXPECT_DOUBLE_EQ(-3.82, addition(0, -3.82));
    EXPECT_DOUBLE_EQ(369.54627659, addition(301.18897659, 68.3573));
}

/** 
 * @brief Test of function substraction() with positive numbers
 * 
 * @see substraction(double, double)
 */
TEST(subtraction, positiveNumbers){
    EXPECT_EQ(6, subtraction(63, 57));
    EXPECT_EQ(8819, subtraction(12782, 3963));
}

/** 
 * @brief Test of function substraction() with negative numbers
 * 
 * @see subtraction(double, double)
 */
TEST(subtraction, negativeNumbers){
    EXPECT_EQ(-102, subtraction(-58, 44));
    EXPECT_EQ(-1315, subtraction(-584, 731));
    EXPECT_EQ(0, subtraction(32, 32));
}

/** 
 * @brief Test of function substraction() with problematic inputs
 * 
 * @see subtraction(double, double)
 */
TEST(subtraction, problematicInputs){
    EXPECT_EQ(-4, subtraction(-4, 0));
    EXPECT_NE(subtraction(468,987), subtraction(987, 468));
    EXPECT_DOUBLE_EQ(1846.33, subtraction(1854.98, 8.65));
    EXPECT_EQ(6972560, subtraction(54814875, 47842315));
    EXPECT_DOUBLE_EQ(54.878, subtraction(0, -54.878));
    EXPECT_DOUBLE_EQ(442748.21001, subtraction(447355, 4606.78999));
}

/** 
 * @brief Test of function multiplication() with normal inputs
 * 
 * @see multiplication(double, double)
 */
TEST(multiplication, normalInputs){
    EXPECT_EQ(12, multiplication(3, 4));
    EXPECT_EQ(-1728, multiplication(-36, 48));
    EXPECT_EQ(234651280, multiplication(415312, 565));
}

/** 
 * @brief Test of function multiplication() with problematic inputs
 * 
 * @see multiplication(double, double)
 */
TEST(multiplication, problematicInputs){
    EXPECT_EQ(52, multiplication(-13, -4));
    EXPECT_EQ(multiplication(-899, 151), multiplication(151, -899));
    EXPECT_EQ(0, multiplication(0, 4458984545));
    EXPECT_EQ(0, multiplication(45154878, 0));
    EXPECT_EQ(180, multiplication(0.25, 720));
    EXPECT_DOUBLE_EQ(46212.21045256, multiplication(88.5656, 521.7851));
    EXPECT_EQ(multiplication(1000000, 1000000), 1000000000000);
}

/** 
 * @brief Test of function division() with normal inputs
 * 
 * @see division(double, double)
 */
TEST(division, normalInputs){
    EXPECT_EQ(9, division(63, 7));
    EXPECT_EQ(1165, division(1149855, 987));
    EXPECT_EQ(-47, division(-39668, 844));
    EXPECT_EQ(96, division(-11808, -123));
}

/** 
 * @brief Test of function division() with problematic inputs
 * 
 * @see division(double, double)
 */
TEST(division, problematicInputs){
    EXPECT_EQ(0, division(0, 684));
    EXPECT_EQ(0, division(0, -846));
    EXPECT_ANY_THROW(division(99771, 0));
    EXPECT_NE(division(14,7), division(7,14));
    EXPECT_DOUBLE_EQ(10626.98412698413, division(6695, 0.63));
    EXPECT_DOUBLE_EQ(3.709954307870418, division(541.568, 145.977));
}

/** 
 * @brief Test of function factorial() with normal inputs
 * 
 * @see factorial(double)
 */
TEST(factorial, normalInputs){
    EXPECT_EQ(6, factorial(3));
    EXPECT_EQ(39916800, factorial(11));
    EXPECT_EQ( 121645100408832000 ,factorial(19));
}

/** 
 * @brief Test of function factorial() with problematic inputs
 * 
 * @see factorial(double)
 */
TEST(factorial, problematicInputs){
    EXPECT_EQ(1, factorial(0));
    EXPECT_ANY_THROW(factorial(-1));
    EXPECT_ANY_THROW(factorial(-38));
    EXPECT_ANY_THROW(factorial(0.26));
}

/** 
 * @brief Test of function exponentiation() with normal inputs
 * 
 * @see exponentiation(double, double)
 */
TEST(exponentiation, normalInputs){
    EXPECT_EQ(32, exponentiation(2, 5));
    EXPECT_EQ(7529536, exponentiation(14,6));
    EXPECT_EQ(815730721, exponentiation(169, 4));
    EXPECT_NEAR(0.0180143985, exponentiation(0.8, 18), 0.000000001);
    EXPECT_EQ(-371293, exponentiation(-13, 5));
}

/** 
 * @brief Test of function exponentiation() with problematic inputs
 * 
 * @see exponentiation(double, double)
 */
TEST(exponentiation, problematicInputs){
    EXPECT_EQ(1, exponentiation(1632, 0));
    EXPECT_EQ(0, exponentiation(0, 64614));
    EXPECT_EQ(1, exponentiation(0.34, 0));
    EXPECT_EQ(282429536481, exponentiation(-81, 6));
    EXPECT_ANY_THROW(exponentiation(7845, -78));
    EXPECT_ANY_THROW(exponentiation(4656, 0.540));
}

/** 
 * @brief Test of function nthRoot() with normal inputs
 * 
 * @see nthRoot(double, double)
 */
TEST(nthRoot, normalInputs){
    EXPECT_EQ(2, nthRoot(64, 6));
    EXPECT_NEAR(5, nthRoot(125, 3), 0.000000001);
    EXPECT_NEAR(0.73680629972, nthRoot(0.4, 3), 0.000000001);
    EXPECT_NEAR(11.4476969088, nthRoot(2250654, 6), 0.000000001);
}

/** 
 * @brief Test of function nthRoot() with problematic inputs
 * 
 * @see nthRoot(double, double)
 */
TEST(nthRoot, problematicInputs){
    EXPECT_NEAR(-5, nthRoot(-125, 3), 0.000000001);
    EXPECT_EQ(0, nthRoot(0, 13));
    EXPECT_NEAR(0.79370052598, nthRoot(0.25, 6), 0.000000001);
    EXPECT_ANY_THROW(nthRoot(-35, 2));
}

/*
 Modulo should be implemented in the same way as in C++
 Visible on the example:
 -161641 / 716 = -225
 -161641 - (-225 * 716) = -161641 + 161100 =  -541
 */

/** 
 * @brief Test of function modulo() with normal inputs
 * 
 * @see modulo(double, double)
 */
TEST(modulo, normalInputs){
    EXPECT_EQ(1, modulo(5, 2));
    EXPECT_EQ(272, modulo(64114, 466)); 
    EXPECT_EQ(-541, modulo(-161641, 716));
    EXPECT_EQ(-25, modulo(-641, -154));
}

/** 
 * @brief Test of function modulo() with problematic inputs
 * 
 * @see modulo(double, double)
 */
TEST(modulo, problematicInputs){
    EXPECT_EQ(-3, modulo(-7878, 25));
    EXPECT_DOUBLE_EQ(0.25, modulo(0.25, 100));
    EXPECT_DOUBLE_EQ(0.105, modulo(0.897, 0.264));
    EXPECT_DOUBLE_EQ(0.540, modulo(0.540, 1.0));
    EXPECT_EQ(2252, modulo(791313, -8671));
}

/** 
 * Main function where all the tests are run
 * @brief The main function of mathlib-test
 * @param argc number of command-line arguments
 * @param argv array of command-line arguments
 * @return 0 if all the tests passed or non-zero if not
 */
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*** End of file mathlib-test.cpp ***/