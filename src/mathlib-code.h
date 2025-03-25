



/****************************************************************** 
* Project name: IVS 2 project
* Date: 20.3.2025
* Last change: 20.3.2024
* Team: audentes Fortuna iuvat 
* Author: Marek Furiš
* Brief: Test for test driven development of math library 
*****************************************************************
/**
* @file mathlib_code.h
*
* @brief Header file of mathematical library functions
* @author Marek Furiš
*/


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
    if (y == 0) return 1;
    return x / y;
}

double factorial(double x) {
    int y = 1;
    if (x == 0) return y;

    for (int i = x; i > 0; i--) {
        y *= x;
    }
    return y;
}

double exponentiation(double x, double y) {
    for (int i = y - 1; i > 0; i--) {
        x *= x;
    }
    return x;
}

double nthRoot(double x, double y) {
    if (y == 0) return 1;
    return x / y;
}

double modulo(double x, double y) {
    for (int i = 1; true; i++) {
        if(x - i*y < 0) return (x - (i - 1) * y);
    }
}