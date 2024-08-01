#include <stdio.h>
#include <math.h>

double func(double x) {
    return (double) pow(x,2)-4*x+8;
}

double antiFunc(double x) {
    return (pow(x,3)/3)-(2*pow(x,2))+8*x;
}

double integraFunc(double a, double b) {
    if (a > b) {
        return antiFunc(a) - antiFunc(b);
    }
    return antiFunc(b) - antiFunc(a);
}

int main() {
    //printf("%lf", integraFunc(1,5));

    return 0;
}
