/****************************************************************** 
* Project name: IVS 2 project
* Date: 25.3.2025
* Last change: 18.4.2025
* Team: audentes Fortuna iuvat 
* Author: Marek Furiš
* Brief: Header file of mathematical library functions
*****************************************************************/
/**
* @file mathlib-code.h
*
* @brief Header file of mathematical library functions
* @author Marek Furiš
*/

#pragma once

/**
 * @brief Computes the sum of two floating-point numbers.
 * 
 * This function performs basic arithmetic addition.
 * 
 * @param x The first operand.
 * @param y The second operand.
 * @return The result of x + y.
 */
double addition(double x, double y);

/**
 * @brief Computes the difference between two floating-point numbers.
 * 
 * Performs subtraction by deducting y from x.
 * 
 * @param x The minuend.
 * @param y The subtrahend.
 * @return The result of x - y.
 */
double subtraction(double x, double y);

/**
 * @brief Computes the product of two floating-point numbers.
 * 
 * Multiplies the two input values.
 * 
 * @param x The first operand.
 * @param y The second operand.
 * @return The result of x * y.
 */
double multiplication(double x, double y);

/**
 * @brief Computes the quotient of two floating-point numbers.
 * 
 * Performs division of x by y. Handles division by zero appropriately.
 * 
 * @param x The dividend.
 * @param y The divisor.
 * @return The result of x / y.
 */
double division(double x, double y);

/**
 * @brief Computes the factorial of a non-negative number.
 * 
 * Returns the product of all positive integers less than or equal to x.
 * For non-integer or negative inputs, behavior is undefined unless otherwise handled.
 * 
 * @param x The number for which the factorial is to be computed.
 * @return The factorial of x.
 */
double factorial(double x);

/**
 * @brief Raises a number to the power of another.
 * 
 * Calculates x raised to the power of n (x^n).
 * 
 * @param x The base.
 * @param n The exponent.
 * @return The result of x raised to the power of n.
 */
double exponentiation(double x, double n);

/**
 * @brief Calculates the n-th root of a number.
 * 
 * Computes the real n-th root of x. Handles even roots of negative numbers appropriately.
 * 
 * @param x The radicand.
 * @param n The degree of the root.
 * @return The n-th root of x.
 */
double nthRoot(double x, double n);

/**
 * @brief Computes the remainder of division between two floating-point numbers.
 * 
 * Performs modulo operation, returning the remainder of x divided by y.
 * 
 * @param x The dividend.
 * @param y The divisor.
 * @return The remainder of x divided by y.
 */
double modulo(double x, double y);

/**
 * @brief Returns the absolute value of a number.
 * 
 * Converts negative values to positive.
 * 
 * @param x The input number.
 * @return The absolute value of x.
 */
double absoluteValue(double x);

/*** End of file mathlib-code.h ***/