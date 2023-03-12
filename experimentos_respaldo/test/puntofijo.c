#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double c){
    double g = 9.81;
    double m = 68.1;
    double t = 10.0;
    double v = 40.0;
    double f = 0.0;

    /* f = ( (g*m)/c )*(1 - expf( -(c/m) *t ) ) - v; */
    f = exp(-c);
    /* f = exp(-c) - c; */
    return f;
}

double punto_fijo(double x0) {
    double xr = 0.0;
    int iter = 10;
    double error = 0.0;
    double x_old = 0.0;
    double tol = 1e-3;
    
    xr = x0;
    for (int i = 0; i < iter; i++) {
        x_old = xr;
        xr = func(x_old);
        if (xr != 0.0) {
            error = fabs( (xr - x_old) / (xr) ) * 100.0;
        }
        printf("i = %d\txr = %7.4lf\terror = %10.6lf\n",i,xr,error);

        if (error < tol) {
            break;
        }
    }
    return xr;
}

double secante(double x0, double x1) {
    double xr = 0.0;
    int iter = 10;
    double error = 0.0;
    double x_old = 0.0;
    double tol = 1e-3;
    
    xr = x1;
    for (int i = 0; i < iter; i++) {
        x_old = xr;
        /* xr = x_old - func(x_old); */
        xr = x1 - (func(x1)*(x0 - x1) )/( func(x0) - func(x1));
        x0 = x1;
        x1 = xr;
        printf("i = %d\txr = %7.4lf\terror = %10.6lf\n",i+1,xr,error);

        if (xr != 0.0) {
            error = fabs( (xr - x_old) / (xr) ) * 100.0;
        }

        if (error < tol) {
            break;
        }
    }
    return xr;
}

int main(void){
    double x0 = 0.0;
    double resultado = 0.0;

    /* resultado = secante(0.0, 1.0); */
    resultado = punto_fijo(0.0);

    return 0;
} 

