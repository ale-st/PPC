#include <stdio.h>
#include <math.h>

// função q representa f(x)= x^2 - 4x + 8
double func(double x) {
    return (double) pow(x,2)-4*x+8;
}

//função que calcula area aproximada de um retângulo, no intervalo [a,b] de func
double integra(double a, double b) {
    double altura, largura;
    if (a > b) {
        return integra(b,a);
    }
    if (func(a) < func(b)) {
        altura = func(b);
    }
    else {
        altura = func(a);
    }
    largura = b - a;
    return altura*largura;
}

int main() {
    printf("%lf", integra(1,0.004f));

    return 0;
}
