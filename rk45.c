#include "rk45.h"

double* calculate_k(double x, double h, const double* y_input, const size_t n, 
                    double emf, double capacity, double resistance) {
    double f[n];

    // functions here
    f[0] = (emf - y_input[0]/capacity) / resistance;
    f[1] = -y_input[1] / (capacity * resistance);

    return num_times_array(h, f, n); 
}

double* rk_step(double t, double h, double* y, const size_t n,
             double emf, double capacity, double resistance){
    double *dy;
    double *k1, *k2, *k3, *k4;

    dy = malloc(sizeof(double) * n);

    // ugly array operations
    k1 = calculate_k(t, h, y, n, emf, capacity, resistance);
    k2 = calculate_k(t+h/2, h, add_arrays(y, num_times_array(0.5, k1, n), n), n, emf, capacity, resistance);
    k3 = calculate_k(t+h/2, h, add_arrays(y, num_times_array(0.5, k2, n), n), n, emf, capacity, resistance);
    k4 = calculate_k(t+h, h, add_arrays(y, k3, n), n, emf, capacity, resistance);

    // Copy k1 to dy
    for (int i = 0; i < n; i++) dy[i] = k1[i];

    add_array_to_array(dy, num_times_array(2, k2, n), n);
    add_array_to_array(dy, num_times_array(2, k3, n), n);
    add_array_to_array(dy, k4, n);

    mult_num_array(1.0/6.0, dy, n);

    return dy; 
}

void runge(int num_equations, double a, double b,
             double c){
    double t, dt, t_max;
    double y[num_equations];

    y[0] = 0;
    y[1] = emf / resistance;

    t = 0;
    dt = 0.1;
    t_max = 10;

    while (t < t_max) {
        double *dy;

        printf("%.16f\t%.16f\t%.16f\n", t, y[0], y[1]);
        dy = rk_step(t, dt, y, num_equations, emf, capacity, resistance);
        add_array_to_array(y, dy, num_equations);
        t += dt;
    }
}
