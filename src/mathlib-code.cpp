/******************************************************************
 * Project name: IVS 2 project
 * Date: 25.3.2025
 * Last change: 18.4.2025
 * Team: audentes Fortuna iuvat
 * Author: Marek Furiš
 * Brief: Implementantion of functions from mathlib-code.h
 *****************************************************************/
/**
 * @file mathlib_code.cpp
 *
 * @brief Implementantion of functions from mathlib-code.h
 * @author Marek Furiš
 */

#include "mathlib-code.h"
#include <stdexcept>
#include <iostream>


/**
 * @brief Adds two numbers together
 *
 * @param x The first number to be added to the second
 * @param y The second number to be added to the first
 *
 * @return Sum of the two given numbers
 */
double addition(double x, double y) {
    return x + y;
}


/**
 * @brief Subtracts second number from the first
 *
 * @param x Number which is being subtracted from
 * @param y Number which is being subtracted
 *
 * @return Difference of the two given numbers
 */
double subtraction(double x, double y) {
    return x - y;
}


/**
 * @brief Multiplies two numbers
 *
 * @param x First number to be multiplied by the second
 * @param y Second number to be multiplied by the first
 *
 * @return Multiplication of the two given numbers
 */
double multiplication(double x, double y) {
    return x * y;
}


/**
 * @brief Divides first number by the second
 *
 * @param x Dividend, the number being divided
 * @param y Divisor, the number that is being divided by
 *   
 * @note Division by zero is being handled by throwing an exception.
 *
 * @return Quotient of the division
 */
double division(double x, double y) {
    if (y == 0) {
        throw std::runtime_error("An error occurred");
    }
    return x / y;
}


/**
 * @brief Calculates factorial of non-negative integer number
 *
 * @param x Number of which's factorial is being calculated
 *   
 * @note If the number given is not an integer or non-negative, an exception is thrown.
 *
 * @return Factorial of the number given
 */
double factorial(double x) {
    double y = 1;
    if (x < 0) {
        throw std::runtime_error("An error occurred");
    }
    if (x == 0) {
        return y;
    }
    if (modulo(x, 1.0) != 0.0) {
        throw std::runtime_error("An error occurred");
    }

    for (double i = x; i > 0; i--) {
        y *= i;
    }
    return y;
}


/**
 * @brief Calculates natural exponentiation
 *
 * @param x Base, the number that is being multiplied by itself
 * @param n Exponent, the number that tells how many times the base is multiplied by itself
 *   
 * @note Non-natural exponents are being handled by throwing an exception
 *
 * @return The power of @p x raised to @p n
 */
double exponentiation(double x, double n) {
    if (modulo(n, 1.0) != 0.0) {
        throw std::runtime_error("An error occurred");
    }
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        throw std::runtime_error("An error occurred");
    }
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}


/**
 * @brief Calculates nthRoot of a number
 *
 * @param x Radicand, the number beneath the root
 * @param n Index, the number on the top left of the root
 *   
 * @note odd roots of negative numbers are being handled by throwing an exception
 *
 * @return Returns nthRoot of @p x 
 */
double nthRoot(double x, double n) {
    bool reset = false;
    if (x < 0 && modulo(n, 2) != 1) {
        throw std::runtime_error("An error occurred");
    }

    if (x < 0) {
        x = -x;
        reset = true;
    }
    double precision = 0.000000001;
    double lowerBound = 0;
    double higherBound = x;
    double mid;
    
    if (x < 1) {
        higherBound = 1;  // If x is between 0 and 1, set upper bound to 1
    }

    while (higherBound - lowerBound > precision) {
        mid = (lowerBound + higherBound) / 2;
        double midPower = exponentiation(mid, n);

        if (midPower > x) {
            higherBound = mid;
        }
        else {
            lowerBound = mid;
        }
    }

    if (reset) {
        return -lowerBound;
    }
    else {
        return lowerBound;
    }
}


/**
 * @brief Calculates modulo of two numbers
 *
 * @param x Dividend, the number that is being divided
 * @param y Divisor, the number that is being divided by
 *   
 * @note if the divisor is 0, an exception is thrown
 *
 * @return The remainder of @p x divided by @p y
 */
double modulo(double x, double y) {
    if (y == 0) {
        throw std::runtime_error("An error occurred");
    }
    return x - y * static_cast<int>(x / y);
}


/**
 * @brief Calculates absolute value of a number
 *
 * @param x Number of which absolute value is being calculated
 *
 * @return The absolute value of @p x
 */
double absoluteValue(double x) {
    if (x < 0) {
        x *= -1;
    }
    return x;
}