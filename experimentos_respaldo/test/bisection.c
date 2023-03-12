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
    f = pow(c,10.0) -1;
    return f;
}

double biseccion(double xl, double xu){
    int iter = 100;
    double test = 0.0;
    double xr = 0.0;
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    double fl = func(xl);
    double fu = func(xu);
    double fr = 0.0;

    /* Check if input is correct */
    if (fl*fu > 0) {
        printf("Error\n");
        return 1;
    }

    /* Algorithm */
    for (int i = 0; i < iter; i++) {
        xr_old = xr;
        xr = (xl + xu)/2.0;
        fr = func(xr);

        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        test = fl*fr;
        /* test = func(xl)*func(xr); */
        printf("i = %d\txl = %7.4lf\txu = %7.4lf\txr = %7.4lf\ttest = %7.4lf\terror = %10.6lf\n",i+1,xl,xu,xr,test,error);
        if (test < 0) {
            xu = xr;
        } else if (test > 0) {
            xl = xr;
            fl = fr;
        } else {
            error = 0.0;
        }

        if (error < tol) {
            break;
        }

    }
    return xr;
}



double false_position(double xl, double xu){
    int iter = 100;
    double test = 0.0;
    double xr = 0.0;
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    double fl = func(xl);
    double fu = func(xu);
    double fr = 0.0;

    int il = 0;
    int iu = 0;

    /* Check if input is correct */
    if (fl*fu > 0) {
        printf("Error\n");
        return 1;
    }

    /* Algorithm */
    for (int i = 0; i < iter; i++) {
        xr_old = xr;
        xr = xu - ( fu *(xl - xu) ) /( fl - fu);
        fr = func(xr);

        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        test = fl*fr;
        /* test = func(xl)*func(xr); */
        printf("i = %d\txl = %7.4lf\txu = %7.4lf\txr = %7.4lf\ttest = %7.4lf\terror = %10.6lf\n",i+1,xl,xu,xr,test,error);
        if (test < 0) {
            xu = xr;
            fu = func(xu);
            il++; iu = 0; 
            if (il >= 2) {
                fl /= 2.0;
            }
        } else if (test > 0) {
            xl = xr;
            fl = func(xl);
            il = 0; iu++; 
            if (iu >= 2) {
                fu /= 2.0;
            }
        } else {
            error = 0.0;
        }

        if (error < tol) {
            break;
        }

    }
    return xr;
}

int main(void){
    double c = 0.0;
    double result = 0.0;

    double center = 14.0;
    /* double left = center*(1.1); */
    /* double right = center*(0.9); */

    /* double left = 12.0; */
    /* double right = 16.0; */

    double left = 0.0;
    double right = 1.3;

    result = false_position(left, right);

    return 0;
} 
