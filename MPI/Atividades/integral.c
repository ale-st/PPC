#include <stdio.h>
#include <math.h>

double func(double x) {
    return (double) pow(x,2)-4*x+8;
}

double integra(double a, double b) {
    double altura, largura;
    if (a > b) {
        return integra(b,a);
    }
    if (func(a) < func(b)) {
        
    }
    altura = func(b) - func(a);
    largura = b - a;
    return altura*largura;
}

int main() {
    printf("%lf", integra(1,5));

    return 0;
}
