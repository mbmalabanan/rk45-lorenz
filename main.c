#include "rk45.h"

int main(int argc, char** argv) {
    int num_equations = 3;

    double sigma = 10;
    double beta = 8.0/3;
    double rho = 28;

    runge(num_equations, sigma, beta, rho);

    return 0;
}

