#ifndef EQ_SOLVER_HPP
#define EQ_SOLVER_HPP

#include <iostream>

#include <assert.h>
#include <stdint.h>
#include <math.h>

enum EQ_PARAMS { MAX_ROOTS_NUM = 2, COEFFS_NUM = 3 };
enum ROOTS_NUM { INF_ROOTS = -1, NONE = 0, ONE_ROOT = 1, TWO_ROOTS = 2 };

const char coeffs_name[COEFFS_NUM] = {'a', 'b', 'c'};

const double EPS = 10e-6;

/**
 * @brief wrapper of equation solver
 * 
 */
struct EqSolver {

    double* coeffs = nullptr;
    double roots[MAX_ROOTS_NUM] = {NAN, NAN};

    ROOTS_NUM type = NONE;
};

/**
 * @brief constructor for eq solver
 * 
 * @param solver eq solver object
 */
void init(EqSolver* solver);

/**
 * @brief function to allocate memory
 * 
 * @param solver eq solver object
 */
void allocate(EqSolver* solver);

/**
 * @brief function to destruct memory
 * 
 * @param solver eq solver object
 */
void destruct(EqSolver* solver);

/**
 * @brief function to input coeffs of equation
 * 
 * @param solver eq solver object
 */
void input(EqSolver* solver);

/**
 * @brief function to solve current equation
 * 
 * @param solver eq solver object
 */
void solve(EqSolver* solver);

/**
 * @brief function to solve linear eqation
 * 
 * @param b - coeff of equation
 * @param c  - coeff of equation
 * @param root - root of equation
 * @return ROOTS_NUM - number of roots
 */
ROOTS_NUM solve_linear(double b, double c, double* root);

/**
 * @brief function to analyze roots of equation
 * 
 * @param solver eq solver object
 */
void analyze(EqSolver* solver);

/**
 * @brief function to dump equation
 * 
 * @param solver - eq solver object
 */
void dump(EqSolver* solver);

/**
 * @brief function to compare two double numbers
 * 
 * @param fst lhs value
 * @param snd rhs value
 * @return bool if equal otherwise false 
 */
inline bool is_equal(double fst, double snd = 0) {

    if (isnan(fst) && isnan(snd))
        return 1;
    else return (fabs(fst - snd) < EPS);
}


#endif /* EQ_SOLVER_HPP */