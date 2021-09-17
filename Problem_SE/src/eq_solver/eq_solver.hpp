#ifndef EQ_SOLVER_HPP
#define EQ_SOLVER_HPP

#include <iostream>

#include <assert.h>
#include <stdint.h>
#include <math.h>

enum { MAX_ROOTS_NUM = 2, COEFFS_NUM = 3 };
enum ROOTS_NUM { INF_ROOTS = -1, NONE = 0, ONE_ROOT = 1, TWO_ROOTS = 2 };

const char coeffs_name[COEFFS_NUM] = {'a', 'b', 'c'};

const double EPS = 10e-6;

/**
 * @brief 
 * 
 */
struct EqSolver {

    double* coeffs = nullptr;
    double roots[2] = {NAN, NAN};

    ROOTS_NUM type = NONE;
};

/**
 * @brief 
 * 
 * @param solver 
 */
void init(EqSolver* solver);

/**
 * @brief 
 * 
 * @param solver 
 */
void allocate(EqSolver* solver);

/**
 * @brief 
 * 
 * @param solver 
 */
void destruct(EqSolver* solver);

/**
 * @brief 
 * 
 * @param solver 
 */
void input(EqSolver* solver);

/**
 * @brief 
 * 
 * @param solver 
 */
void solve(EqSolver* solver);

/**
 * @brief 
 * 
 * @param b 
 * @param c 
 * @param root 
 * @return ROOTS_NUM 
 */
ROOTS_NUM solve_linear(double b, double c, double* root);

/**
 * @brief 
 * 
 * @param solver 
 */
void analyze(EqSolver* solver);

/**
 * @brief 
 * 
 * @param solver 
 */
void dump(EqSolver* solver);

/**
 * @brief 
 * 
 * @param fst 
 * @param snd 
 * @return int 
 */
inline int is_equal(double fst, double snd = 0) {

    if (isnan(fst) && isnan(snd))
        return 1;
    else return (fabs(fst - snd) < EPS);
}


#endif /* EQ_SOLVER_HPP */