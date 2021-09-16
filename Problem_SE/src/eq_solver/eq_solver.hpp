#ifndef EQ_SOLVER_HPP
#define EQ_SOLVER_HPP

#include <iostream>

#include <assert.h>
#include <stdint.h>

#include "common.hpp"

struct EqSolver {

    double* coeffs = nullptr;
    double* roots = nullptr;

    EQ_TYPE type = NONE;
};

void init(EqSolver* solver);
void allocate(EqSolver* solver);
void input(EqSolver* solver);

void solve(EqSolver* solver);
EQ_TYPE solve_linear(double b, double c, double* root);

void analyze(EqSolver* solver);

void dump(EqSolver* solver);

#endif /* EQ_SOLVER_HPP */