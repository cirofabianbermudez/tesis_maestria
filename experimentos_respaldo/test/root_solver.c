#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


double func(double x);
double bisection(double xl, double xu, int imax);
double bisection_simple(double xl, double xu, int imax);
double false_position_simple(double xl, double xu, int imax);
double false_position(double xl, double xu, int imax);
double fixed_point(double x0, int imax);
double secant_simple(double x0, double x1, int imax);
double secant(double x0, double delta, int imax);
double newton_rapshon(double x0, int imax);

int main(void){
    double x0 = 0.0;
    double result = 0.0;

    /* result = false_position_simple(12.0, 16.0, 100); */
    /* result = false_position(0.0, 1.3, 100); */
    /* result = false_position_simple(0.0, 1.3, 100); */
    /* result = fixed_point(0.0, 100); */
    /* result = newton_rapshon(0.5, 100); */
    /* result = secant_simple(0.0, 1.0, 100); */

    result = secant(0.1, 0.01, 100);

    

    return 0;
} 


double func(double x){
    /* double g = 9.81; */
    /* double m = 68.1; */
    /* double t = 10.0; */
    /* double v = 40.0; */
    double f = 0.0;

    /* f = ( (g*m)/c )*(1 - expf( -(c/m) *t ) ) - v; */
    /* f = pow(c,10.0) - 1; */
    /* f = exp(-c); */
    /* f = exp(-c) - c; */
    /* f = pow(c, 10.0) - 1; */
    /* f = log(c); */
    f = 0.5 + x + log(1.0 + x);
    return f;
}

double func_d(double x){
    double f = 0.0;
    /* f = -exp(-x) - 1.0; */
    f = 10.0 * pow(x, 9.0);
    return f;
}


/* Secant modified, similar to bisection but is consider an open method*/
double secant(double x0, double delta, int imax){
    double xr = 0.0;               // x2
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    xr = x0;
    int i = 0;

    printf("i = %d\txr = %7.4lf\terror = \n",i,xr);
    while (true) {
        xr_old = xr;
        xr = xr - ( func(xr) * (delta) )/( func(xr+delta) - func(xr) );
        i++;
        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        printf("i = %d\txr = %7.4lf\terror = %10.6lf\n",i,xr,error);

        if (error < tol || i >= imax) {
            break;
        }
    }
    return xr;
}

/* Secant method, similar to bisection but is consider an open method*/
double secant_simple(double x0, double x1, int imax){
    double xr = 0.0;               // x2
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    xr = x1;
    int i = 0;

    printf("i = %d\txr = %7.4lf\terror = \n",i,xr);
    while (true) {
        xr_old = xr;
        xr = x1 - (func(x1)*(x0-x1))/( func(x0) - func(x1) );
        x0 = x1;
        x1 = xr;
        i++;
        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        printf("i = %d\txr = %7.4lf\terror = %10.6lf\n",i,xr,error);

        if (error < tol || i >= imax) {
            break;
        }
    }
    return xr;
}

/* Newthon-Rapshon method, it is required to know the derivative open method*/
double newton_rapshon(double x0, int imax){
    double xr = 0.0;               // x2
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    xr = x0;
    int i = 0;

    printf("i = %d\txr = %7.4lf\terror = \n",i,xr);
    while (true) {
        xr_old = xr;
        xr = xr - func(xr)/func_d(xr);
        i++;
        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        printf("i = %d\txr = %7.4lf\terror = %10.6lf\n",i,xr,error);

        if (error < tol || i >= imax) {
            break;
        }
    }
    return xr;
}

/* Fixed point method, this methods needs to change-simplify the func, open method */
double fixed_point(double x0, int imax){
    double xr = 0.0;               // x2
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    xr = x0;
    int i = 0;

    printf("i = %d\txr = %7.4lf\terror = \n",i,xr);
    while (true) {
        xr_old = xr;
        xr = func(xr);
        i++;
        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        printf("i = %d\txr = %7.4lf\terror = %10.6lf\n",i,xr,error);

        if (error < tol || i >= imax) {
            break;
        }
    }
    return xr;
}

/* Modified false position method with optimizations, open method*/
double false_position(double xl, double xu, int imax){
    double test = 0.0;
    double xr = 0.0;
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;
    
    double fl, fu, fr = 0.0;
    int il, iu = 0;

    /* Check if input is correct */
    fl = func(xl);
    fu = func(xu);
    if (fl*fu > 0) {
        printf("Error in selected limits.\n");
        return 1;
    }

    /* Algorithm */
    int i = 0;
    while (true) {
        xr_old = xr;
        xr = xu - ( fu *(xl - xu) ) /( fl - fu);
        fr = func(xr);
        i++;

        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        test = fl*fr;
        printf("i = %d\txl = %7.4lf\txu = %7.4lf\txr = %7.4lf\ttest = %7.4lf\terror = %10.6lf\n",i,xl,xu,xr,test,error);

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

        if (error < tol || i >= imax) {
            break;
        }

    }
    return xr;
}

/* Simple false position method no optimizations, closed method*/
double false_position_simple(double xl, double xu, int imax){
    double test = 0.0;
    double xr = 0.0;
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;
    
    double fl, fu = 0;

    /* Check if input is correct */
    if (func(xl)*func(xu) > 0) {
        printf("Error in selected limits.\n");
        return 1;
    }

    /* Algorithm */
    int i = 0;
    while (true) {
        xr_old = xr;
        fu = func(xu);
        fl = func(xl);
        xr = xu - ( fu *(xl - xu) ) /( fl - fu);
        i++;

        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        test = func(xl)*func(xr);
        printf("i = %d\txl = %7.4lf\txu = %7.4lf\txr = %7.4lf\ttest = %7.4lf\terror = %10.6lf\n",i,xl,xu,xr,test,error);

        if (test < 0) {
            xu = xr;
        } else if (test > 0) {
            xl = xr;
        } else {
            error = 0.0;
        }

        if (error < tol || i >= imax) {
            break;
        }

    }
    return xr;
}

/* Modified bisection method that saves time doing less evaluations, closed method */
double bisection(double xl, double xu, int imax){
    double test = 0.0;
    double xr = 0.0;
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    double fl, fu, fr = 0.0;

    /* Check if input is correct */
    fl = func(xl);
    fu = func(xu);
    if (fl*fu > 0) {
        printf("Error in selected limits.\n");
        return 1;
    }

    /* Algorithm */
    int i = 0;
    while (true) {
        xr_old = xr;
        xr = (xl + xu)/2.0;
        fr = func(xr);
        i++;

        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        test = fl*fr;
        printf("i = %d\txl = %7.4lf\txu = %7.4lf\txr = %7.4lf\ttest = %7.4lf\terror = %10.6lf\n",i,xl,xu,xr,test,error);

        if (test < 0) {
            xu = xr;
        } else if (test > 0) {
            xl = xr;
            fl = fr;
        } else {
            error = 0.0;
        }

        if (error < tol || i >= imax) {
            break;
        }

    }
    return xr;
}

/* Simple bisection method no optimization, closed method */
double bisection_simple(double xl, double xu, int imax){
    double test = 0.0;
    double xr = 0.0;
    double xr_old = 0.0;
    double error = 0.0;
    double tol = 1e-3;

    /* Check if input is correct */
    if (func(xl)*func(xu) > 0) {
        printf("Error in selected limits.\n");
        return 1;
    }

    /* Algorithm */
    int i = 0;
    while (true) {
        xr_old = xr;
        xr = (xl + xu)/2.0;
        i++;

        if (xr != 0.0) {
            error = fabs( (xr - xr_old) / (xr) ) * 100.0;
        }

        test = func(xl)*func(xr);
        printf("i = %d\txl = %7.4lf\txu = %7.4lf\txr = %7.4lf\ttest = %7.4lf\terror = %10.6lf\n",i,xl,xu,xr,test,error);

        if (test < 0) {
            xu = xr;
        } else if (test > 0) {
            xl = xr;
        } else {
            error = 0.0;
        }

        if (error < tol || i >= imax) {
            break;
        }

    }
    return xr;
}
