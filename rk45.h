#include "arrays.h"
#include <stdio.h>

double* calculate_k(double x, double h, const double* y_input, const size_t n, 
                    double emf, double capacity, double resistance);

double* rk_step(double t, double h, double* y, const size_t n,
             double emf, double capacity, double resistance);

void runge(int num_equations, double emf, double capacity,
             double resistance);

