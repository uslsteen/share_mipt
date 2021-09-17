#include "test.hpp"

int main(int argc, char** argv) {

    printf("Equation solver program\n");
    printf("VERSION 1.0\n");
    printf("All rigths is resever\n\n");

    EqSolver solver{};

    run_test();

    init(&solver);
    solve(&solver);
    analyze(&solver);
    destruct(&solver);

    return 0;
}

