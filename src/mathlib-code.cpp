/******************************************************************
 * Project name: IVS 2 project
 * Date: 25.3.2025
 * Last change: 18.4.2025
 * Team: audentes Fortuna iuvat
 * Author: Marek Furiš
 * Brief: Implementantion of functions from mathlib-code.h
 *****************************************************************/
/**
 * @file mathlib-code.cpp
 *
 * @todo Rewrite errors so they actually tells the user what went wrong.
 * @brief Implementantion of functions from mathlib-code.h
 * @author Marek Furiš
 */

#include "mathlib-code.h"
#include <stdexcept>
#include <iostream>
#include <cmath>

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
    if (y == 0) {
        throw std::runtime_error("An error occurred");
    }
    return x / y;
}

double factorial(double x) {
    if (x < 0) {
        throw std::runtime_error("An error occurred");
    }
    if (x == 0) {
        return 1;
    }
    if (modulo(x, 1.0) != 0.0) {
        throw std::runtime_error("An error occurred");
    }

    return x * factorial(x - 1);
}

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
    return pow(x, n);
}

double nthRoot(double x, double n) {
    bool reset = false;
    if (x < 0 && modulo(n, 2) != 1) {
        throw std::runtime_error("An error occurred");
    }
    if (n == 0) {
        throw std::runtime_error("An error occurred");
    }
    return std::pow(x, 1.0 / n);
}

double modulo(double x, double y) {
    if (y == 0) {
        throw std::runtime_error("An error occurred");
    }
    return fmod(x, y);
}

double absoluteValue(double x) {
    if (x < 0) {
        x *= -1;
    }
    return x;
}

/*** End of file mathlib-code.cpp ***/