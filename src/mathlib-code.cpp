/****************************************************************** 
* Project name: IVS 2 project
* Date: 25.3.2025
* Last change: 25.3.2025
* Team: audentes Fortuna iuvat 
* Author: Marek Furiš
* Brief: Test for test driven development of math library 
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


double addition(double x, double y) {
    return x + y;
}

double subtraction(double x, double y) {
    return x - y;
}

double multiplication(double x, double y) {
    return x * y;
}

double division(double x, double y) {
    if (y == 0) throw std::runtime_error("An error occurred");
    return x / y;
}

double factorial(double x) {
    double y = 1;
    if (x < 0) throw std::runtime_error("An error occurred");
    if (x == 0) return y;
    if (modulo(x, 1.0) != 0) throw std::runtime_error("An error occurred");

    for (double i = x; i > 0; i--) {
        y *= i;
    }
    return y;
}

double exponentiation(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) throw std::runtime_error("An error occurred");
    if (modulo(x, 1.0) != 0) throw std::runtime_error("An error occurred");
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

double nthRoot(double x, double n) {
    if (x < 0 && modulo(n, 2) != 1) throw std::runtime_error("An error occurred");
    
    double precision = 0.0000001;
    double lowerBound = 0;
    double higherBound = x;
    double mid;
    
    if (x < 1) higherBound = 1;  // If x is between 0 and 1, set upper bound to 1

    while (higherBound - lowerBound > precision) {
        mid = (lowerBound + higherBound) / 2;
        double midPower = exponentiation(mid, n);

        if (midPower > x)
            higherBound = mid;
        else
            lowerBound = mid;
    }

    if (x < 0 && modulo(n, 2) != 0)
        return -lowerBound;
    else
        return lowerBound;
}

double modulo(double x, double y) {
    if (y == 0) throw std::runtime_error("An error occurred");
    return x - y * static_cast<int>(x / y);
}