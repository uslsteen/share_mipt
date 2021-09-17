#ifndef TEST_HPP
#define TEST_HPP

#include "eq_solver.hpp"

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief 
 * 
 */
void run_test();

/**
 * @brief 
 * 
 * @param coeffs 
 * @param x1 
 * @param x2 
 * @param info 
 */
void unit_test(double* coeffs, double x1, double x2, const char* info);

/**
 * @brief 
 * 
 * @param solver 
 * @param coeffs_arr 
 */
void check_solution(EqSolver* solver, double* coeffs_arr);

/**
 * @brief 
 * 
 * @param expct_root 
 * @param cur_root 
 * @return true 
 * @return false 
 */
bool root_check(double expct_root, double cur_root);

#endif /* TEST_HPP */