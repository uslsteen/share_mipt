#ifndef COMMON_HPP
#define COMMON_HPP

#include <stdio.h>
#include <math.h>

const double EPS = 10e-6;

enum { COEFFS_NUM = 3 };
enum EQ_TYPE { INF_ROOTS = -1, NONE = 0, LINEAR = 1, SQUARE = 2 };

const char coeffs_name[COEFFS_NUM] = {'a', 'b', 'c'};

void print_greeting();
void unit_test();

inline int is_zero(double num) {
    return (fabs(num - 0) < EPS);
}

#endif /* COMMON_HPP */