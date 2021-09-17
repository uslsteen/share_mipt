#include "eq_solver.hpp"

void init(EqSolver* solver) {

    assert(solver);

    allocate(solver);
    input(solver);
}

void allocate(EqSolver* solver) {

    assert(solver);

    solver->coeffs = (double*)calloc(COEFFS_NUM, sizeof(double));
    assert(solver->coeffs);

    for (uint32_t i = 0; i < COEFFS_NUM; ++i)
        solver->coeffs[i] = NAN;
}

void destruct(EqSolver* solver) {
    free(solver->coeffs);
}

void input(EqSolver* solver) {

    assert(solver->coeffs);

    for (uint32_t i = 0; i < COEFFS_NUM; ++i) {

        printf("Input coeff '%c' of equation:\n", coeffs_name[i]);
        uint8_t res = scanf("%lf", &solver->coeffs[i]);

        if (res != 1) {
            printf("Invalid input\nInput integer or floating point number\n");
            --i;    
            while (getchar() != '\n');
        }

        assert(isfinite(coeffs_name[i]));
        printf("Succesful input\n");
    }

    dump(solver);
}

void solve(EqSolver* solver) {

    assert(solver->coeffs);
    
    double a = solver->coeffs[0], b = solver->coeffs[1], c = solver->coeffs[2];
    double *x1 = &solver->roots[0], *x2 = &solver->roots[1]; 

    if (is_equal(a))
        solver->type = solve_linear(b, c, x1);

    else if (is_equal(c))
    {
        if (is_equal(b))
            solver->type = TWO_ROOTS;
        else {
            solve_linear(a, b, x2);
            solver->type = TWO_ROOTS;
        }
    }
    else
    {
        double discr = b * b - 4 * a * c;

        if (is_equal(discr)) {
            *x1 = -b / (2*a);
            *x2 = *x1;
        }
        else if (discr < 0)
            solver->type = NONE;
        
        else if (discr > 0) {
            double sqrt_d = sqrt(discr);

            *x1 = (-b + sqrt_d) / (2 * a);
            *x2 = (-b - sqrt_d) / (2 * a);

            solver->type = TWO_ROOTS;
        }
    }
}

ROOTS_NUM solve_linear(double b, double c, double* root) {

    assert(root);
    
    if (is_equal(b))
        return is_equal(c) ? INF_ROOTS : NONE;

    else {
        if (is_equal(c))
            return ONE_ROOT;
        else {
            *root = - c / b;
            return ONE_ROOT;
        }
    }
}

void analyze(EqSolver* solver) {

    assert(solver);
    
    double x1 = solver->roots[0], x2 = solver->roots[1];

    switch (solver->type)
    {
    case NONE: printf("The equation has no roots\n");
		break; 
    case ONE_ROOT: printf("The equation has one root: x = %.4lf\n", x1);
		break;
    case TWO_ROOTS: printf("The equation has two roots: x1 = %.4lf, x2 = %.4lf\n", x1, x2);
		break;
    case INF_ROOTS: printf("The equation has infinity number of roots\n");
		break;
    default: printf("Error occured in\n  void analyze(EqSolver* solver)\nInvalid value of EQ_TYPE\n");
        break;
    }
}

void dump(EqSolver* solver) {
    
    double* tmp = solver->coeffs;
    printf("equation: %lf * x^2 + %lf * x + %lf\n", tmp[0], tmp[1], tmp[2]);
}
