#include "arrays.h"

void mult_num_array(double scal, double* a, const size_t length) {
    for (int i = 0; i < length; i++) a[i] *= scal; 
}

double* num_times_array(double scal, double* a, const size_t length) {
    double* prod;
    prod = malloc(sizeof(double) * length);
    for (int i = 0; i < length; i++) prod[i] = scal * a[i];
    return prod;
}

void mult_arrays(double* a, double* b, const size_t length) {
    for (int i = 0; i < length; i++) a[i] *= b[i];
}

void add_num_array(double num, double* a, int length) {
    for (int i = 0; i < length; i++) a[i] += num;
}

double* add_num_to_array(double scal, double* a, const int length) {
    double* sum;
    sum = malloc(sizeof(double) * length);
    for (int i = 0; i < length; i++) sum[i] = scal + a[i];
    return sum;
}

double* add_arrays(double* a, double* b, const size_t length) {
    double* array_sum;
    array_sum = malloc(sizeof(double) * length);
    for (int i = 0; i < length; i++) array_sum[i] = a[i] + b[i];
    return array_sum;
}

void add_array_to_array(double* a, double* b, const size_t length) {
    for (int i = 0; i < length; i++) a[i] += b[i];
}
