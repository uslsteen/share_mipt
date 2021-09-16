#include "eq_solver.hpp"

int main(int argc, char** argv) {

    print_greeting();
    EqSolver solver{};

    init(&solver);
    solve(&solver);

    return 0;
}

