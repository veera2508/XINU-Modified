#include <stdio.h>
double powcustom(double x, int exponent);
double logcustom(double x);
double expdev(double lambda);

double powcustom(double x, int exponent) {
    double i;
    double result = 1;
    for (i = 0; i < exponent; i++) result *= x;
    return result;
}

double logcustom(double x) {
    if (x > 1) return 0;
    double n = 20, i;
    double result = 0;
    for (i = 1; i < n; i++)
        result += powcustom(-1, i+1) * powcustom(x-1, i) / i;
    return result;
}

double expdev(double lambda) {
    double dummy;
    do {
        dummy = (double) rand() / RAND_MAX;
    }while (dummy == 0.0);
    return -logcustom(dummy)/lambda;
}
