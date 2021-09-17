#include "test.hpp"


void run_test() {

    printf("Unit test started\n");

    double fst_coeffs[COEFFS_NUM] =  {1.0, 3.0, 2.0};
    double x1 = -1.0, x2 = -2.0;
    unit_test(&fst_coeffs[0], x1, x2, "Square unit test");

    double snd_coeefs[COEFFS_NUM] = {0.0, 5.0, -6.0};
    x1 = 1.2, x2 = 0;
    unit_test(&snd_coeefs[0], x1, x2, "Linear unit test");

    double trd_coeffs[COEFFS_NUM] = {0, 0, 0};
    x1 = NAN, x2 = NAN;
    unit_test(&trd_coeffs[0], x1, x2, "Inf roots unit test");

    double fth_coeffs[COEFFS_NUM] = {0, 0, 1.0};
    x1 = NAN, x2 = NAN;
    unit_test(&fth_coeffs[0], x1, x2, "None roots unit test");
}

bool root_check(double expct_root, double cur_root) {

    if (isnan(expct_root) && !isnan(cur_root)) {
        printf("Wrong solution\nExpected x1=nan, but got x1=%lf\n", cur_root);
        return false;
    }
    else if (!is_equal(expct_root, cur_root)) {
        printf("Wrong solution\nExpected x1=%lf, but got x1=%lf\n", expct_root, cur_root);
        return false;
    }
    
    return true;
}

bool check_solution(EqSolver* solver, double x1, double x2) {

    solve(solver);

    if (solver->type == TWO_ROOTS || solver->type == INF_ROOTS || solver->type == INF_ROOTS)
        return root_check(x1, solver->roots[0]) & root_check(x2, solver->roots[1]);

    else if (solver->type == ONE_ROOT)
        return root_check(x1, solver->roots[0]);
}

void unit_test(double* coeffs, double x1, double x2, const char* info) {

    assert(coeffs);

    EqSolver solver{};
    solver.coeffs = coeffs;

    if (check_solution(&solver, x1, x2))
        printf("%s passed\n\n", info);
    else
        printf("%s failed\n\n", info);
}