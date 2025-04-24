/****************************************************************** 
* Project name: IVS 2 project
* Date: 22.4.2025
* Last change: 22.4.2025
* Team: audentes Fortuna iuvat 
* Author: Tobias Leščenko, Marek Furiš
* Brief: Tests for math formula parsing 
*****************************************************************
/**
* @file parser-test.cpp
*
* @brief Tests for math formula parsing
* @author Tobias Leščenko
* @author Marek Furiš
*/

#include <gtest/gtest.h>
#include "parser.h"

using namespace testing;

TEST(ParserTests, SimpleExpressions) {
    EXPECT_EQ(parse("2+2"), "4");
    EXPECT_EQ(parse("10-3"), "7");
    EXPECT_EQ(parse("5*6"), "30");
    EXPECT_EQ(parse("8/2"), "4");
}

TEST(ParserTests, ComplexExpressions) {
    EXPECT_EQ(parse("2+3*4"), "14"); // Test operator precedence
    EXPECT_EQ(parse("(2+3)*4"), "20"); // Test parentheses
    EXPECT_EQ(parse("10/(5-3)"), "5"); // Test division with parentheses
    EXPECT_EQ(parse("3^3"), "27"); // Test exponentiation
    EXPECT_EQ(parse("√16"), "4"); // Test square root
}

TEST(ParserTests, EdgeCases) {
    EXPECT_EQ(parse("0+0"), "0"); // Test zero addition
    EXPECT_EQ(parse("0*1000"), "0"); // Test multiplication by zero
    EXPECT_EQ(parse("1/1"), "1"); // Test division by one
    EXPECT_EQ(parse("1^0"), "1"); // Test exponentiation with zero
    EXPECT_EQ(parse("0!"), "1"); // Test factorial of zero
}

TEST(ParserTests, FaultyInputs) {
    EXPECT_EQ(parse("2++2"), "Error: Invalid input"); // Test invalid operator usage
    EXPECT_EQ(parse("10/0"), "Error: Division by zero"); // Test division by zero
    EXPECT_EQ(parse("√-1"), "Error: Not a real number"); // Test invalid square root
    EXPECT_EQ(parse("5**2"), "Error: Invalid input"); // Test invalid operator usage
    EXPECT_EQ(parse(")2+2("), "Error: Invalid input"); // Test misplaced parentheses
}

TEST(ParserTests, NestedExpressions) {
    EXPECT_EQ(parse("((2+3)*4)/2"), "10"); // Test nested parentheses
    EXPECT_EQ(parse("√((3^2)+(4^2))"), "5"); // Test Pythagorean theorem
    EXPECT_EQ(parse("((2+3)*(5-2))^2"), "225"); // Test nested operations with exponentiation
}

TEST(ParserTests, UnaryOperations) {
    EXPECT_EQ(parse("-5+10"), "5"); // Test unary minus
    EXPECT_EQ(parse("|-5|"), "5"); // Test absolute value
    EXPECT_EQ(parse("-(3+2)"), "-5"); // Test unary minus with parentheses
    EXPECT_EQ(parse("5!"), "120"); // Test factorial
}

TEST(ParserTests, ModuloOperation) {
    EXPECT_EQ(parse("10%3"), "1"); // Test simple modulo
    EXPECT_EQ(parse("-10%3"), "-1"); // Test negative modulo
    EXPECT_EQ(parse("10%-3"), "1"); // Test modulo with negative divisor
    EXPECT_EQ(parse("-10%-3"), "-1"); // Test negative modulo with negative divisor
}

TEST(ParserTests, FloatingPointOperations) {
    EXPECT_EQ(parse("0.1+0.2"), "0.3"); // Test floating-point addition
    EXPECT_EQ(parse("1.5*2"), "3"); // Test floating-point multiplication
    EXPECT_EQ(parse("5/2"), "2.5"); // Test floating-point division
    EXPECT_EQ(parse("2.5^2"), "6.25"); // Test floating-point exponentiation
    EXPECT_EQ(parse("√2"), "1.41421"); // Test square root of a non-perfect square
}

TEST(ParserTests, LargeNumbers) {
    EXPECT_EQ(parse("1000000*1000000"), "1e+12"); // Test large multiplication
    EXPECT_EQ(parse("1000000/0.000001"), "1e+12"); // Test large division
    EXPECT_EQ(parse("20!"), "2.4329e+18"); // Test large factorial
    EXPECT_EQ(parse("2^100"), "1.26765e+30"); // Test large exponentiation
}

TEST(ParserTests, NthRoot) {
    EXPECT_EQ(parse("2√16"), "4"); // Square root with explicit n
    EXPECT_EQ(parse("3√27"), "3"); // Cube root
    EXPECT_EQ(parse("4√81"), "3"); // Fourth root
    EXPECT_EQ(parse("√16"), "4");  // Default square root
    EXPECT_EQ(parse("-2√16"), "0.25"); // Negative base with even root
    EXPECT_EQ(parse("3√-27"), "-3"); // Valid cube root of negative number
}

TEST(ParserTests, CombinedMultiplicationAndDivision) {
    EXPECT_EQ(parse("6*3/2"), "9"); // Test multiplication followed by division
    EXPECT_EQ(parse("12/4*3"), "9"); // Test division followed by multiplication
    EXPECT_EQ(parse("(6*3)/2"), "9"); // Test multiplication and division with parentheses
    EXPECT_EQ(parse("6*(3/2)"), "9"); // Test division inside parentheses followed by multiplication
    EXPECT_EQ(parse("12/(4*3)"), "1"); // Test multiplication inside parentheses followed by division
    EXPECT_EQ(parse("(12/4)*3"), "9"); // Test division inside parentheses followed by multiplication
    EXPECT_EQ(parse("6*3/2/3"), "3"); // Test multiple divisions after multiplication
    EXPECT_EQ(parse("6/(3*2)"), "1"); // Test division with multiplication in the denominator
}

/*** End of file parser-test.cpp ***/