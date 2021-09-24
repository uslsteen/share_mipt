#ifndef TEST_HPP
#define TEST_HPP

#include "eq_solver.hh"

#include <stdbool.h>
#include <stdint.h>

struct test_wrapper {
    double coeffs[COEFFS_NUM];
    double roots[MAX_ROOTS_NUM];

    ROOTS_NUM type;
};

/**
 * @brief function to run unit test
 * 
 */
void run_test();

/**
 * @brief function to build usfull stff for unit test
 * 
 * @param coeffs pnter to array of coeffs
 * @param x1 first root of equation 
 * @param x2 second root of equation
 * @param info description of the test
 */
void unit_test(test_wrapper* test ,const char* info);

/**
 * @brief function to check result of solver
 * 
 * @param solver wrapper of equation solver
 * @param coeffs_arr pnter to coeffs array
 */
void check_solution(EqSolver* solver, double* coeffs_arr);

/**
 * @brief function to check roots
 * 
 * @param expct_root expected root of equation
 * @param cur_root   recieved root of equation
 * @return true if roots are right
 * @return otherwise false 
 */
bool root_check(double expct_root, double cur_root);

#endif /* TEST_HPP */