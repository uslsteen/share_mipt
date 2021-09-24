#include "test.hh"


void run_test() {

    printf("Unit tests started\n\n");

    test_wrapper test1{{1.0, 3.0, 2.0}, {-1.0, -2.0}, TWO_ROOTS};
    unit_test(&test1, "Square unit test");

    test_wrapper test2{{0.0, 5.0, -6.0}, {1.2, 0}, ONE_ROOT};
    unit_test(&test2, "Linear unit test");

    test_wrapper test3{{0, 0, 0}, {NAN, NAN}, INF_ROOTS};
    unit_test(&test3, "Inf roots unit test");

    test_wrapper test4{{0, 0, 1.0}, {NAN, NAN}, NONE};
    unit_test(&test4, "None roots unit test");

    printf("End of unit tests\n\n");
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

bool check_solution(EqSolver* solver, double x1, double x2, ROOTS_NUM type) {

    solve(solver);

    if (solver->type != type)
        return false;

    if (solver->type == TWO_ROOTS || solver->type == NONE || solver->type == INF_ROOTS)
        return root_check(x1, solver->roots[0]) & root_check(x2, solver->roots[1]);

    else if (solver->type == ONE_ROOT)
        return root_check(x1, solver->roots[0]);
}

void unit_test(test_wrapper* test ,const char* info) {

    assert(test);

    EqSolver solver{};
    solver.coeffs = test->coeffs;
    double x1 = test->roots[0], x2 = test->roots[1];
    ROOTS_NUM type = test->type;

    if (check_solution(&solver, x1, x2, type))
        printf("%s passed\n", info);
    else
        printf("%s failed\n", info);
}