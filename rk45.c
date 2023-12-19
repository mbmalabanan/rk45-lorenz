#include "rk45.h"

double* calculate_k(double t, double h, const double* input, const size_t n, 
                    double sigma, double beta, double rho) {
    double f[n];
    double x = input[0], y = input[1], z = input[2];

    // functions here
    f[0] = sigma*(y - x);
    f[1] = x*(rho - z) - y;
    f[2] = x*y - beta*z;

    return num_times_array(h, f, n); 
}

double* rk_step(double t, double h, double* y, const size_t n,
             double sigma, double beta, double rho){
    double *dy;
    double *k1, *k2, *k3, *k4;

    dy = malloc(sizeof(double) * n);

    // ugly array operations
    k1 = calculate_k(t, h, y, n, sigma, beta, rho);
    k2 = calculate_k(t+h/2, h, add_arrays(y, num_times_array(0.5, k1, n), n), n, sigma, beta, rho);
    k3 = calculate_k(t+h/2, h, add_arrays(y, num_times_array(0.5, k2, n), n), n, sigma, beta, rho);
    k4 = calculate_k(t+h, h, add_arrays(y, k3, n), n, sigma, beta, rho);

    // Copy k1 to dy
    for (int i = 0; i < n; i++) dy[i] = k1[i];

    add_array_to_array(dy, num_times_array(2, k2, n), n);
    add_array_to_array(dy, num_times_array(2, k3, n), n);
    add_array_to_array(dy, k4, n);

    mult_num_array(1.0/6.0, dy, n);

    return dy; 
}

void runge(int num_equations, double sigma, double beta,
             double rho){
    FILE *fptr;

    double t, dt, t_max;
    double y[num_equations];

    y[0] = 1.0;   // x, y, z
    y[1] = 1.0;
    y[2] = 1.0;

    t = 0;
    dt = 0.05;
    t_max = 75;

    fptr = fopen("lorentz.txt", "w");

    while (t < t_max) {
        double *dy;

        fprintf(fptr, "%.16f\t%.16f\t%.16f\n", y[0], y[1], y[2]);
        dy = rk_step(t, dt, y, num_equations, sigma, beta, rho);
        add_array_to_array(y, dy, num_equations);
        t += dt;
    }

    fclose(fptr);
}
