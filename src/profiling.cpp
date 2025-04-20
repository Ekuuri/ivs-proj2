/******************************************************************
 * Project name: IVS 2 project
 * Date: 1.4.2025
 * Last change: 18.4.2025
 * Team: audentes Fortuna iuvat
 * Author: Marek Furiš
 * Brief: Profiling implementation
 *****************************************************************/
/**
 * @file profiling.cpp
 *
 * @brief Profiling implementation
 * @author Marek Furiš
 */

#include <iostream>
#include "mathlib-code.h"

int main() {
	float count = 0.0;
	float number;
	float sum = 0.0;
	float sumSquared = 0.0;
    while (std::cin >> number) {
        sum += number;
		//sum = addition(sum, number);
		sumSquared += exponentiation(number, 2);
		//sumSquared = addition(sumSquared, exponentiation(number, 2));
		count++;
    }

	float x_ = multiplication(division(1, count), sum);
	float s = nthRoot(multiplication(division(1, subtraction(count, 1)), subtraction(sumSquared, multiplication(count, exponentiation(x_, 2)))), 2);

	std::cout << s << std::endl;

    return 0;
}