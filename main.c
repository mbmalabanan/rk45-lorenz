#include "rk45.h"

int main(int argc, char** argv) {
    int num_equations = 3;

    double a = 1.0;
    double b = 1.0;
    double c = 1.0;

    double emf = 10;
    double capacity = 1;
    double resistance = 2;

    runge(num_equations, a, b, c);

    return 0;
}

