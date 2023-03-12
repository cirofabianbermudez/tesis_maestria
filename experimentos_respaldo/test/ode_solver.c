#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double func(double x, double y);
double forward_euler(double x, double t, double h);
double heun(double x, double y, double h);
double euler_middle(double x, double y, double h);
double runge_kutta_4th(double x, double y, double h);

int main(void){
    /* Condiciones iniciales */
    double y, x = 0.0;
    double x0 = 0.0;
    double y0 = 0.5;

    /* Parametros para vector de tiempo */
    double a = 0.0;
    double b = 10.0;
    double h = 0.001;
    int    n = (b-a)/h + 1;

    FILE *file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    x = x0;
    y = y0;
    for (int i = 0; i < n; i++, x += h) {
        /* printf("x = %lf\ty = %9.6lf\n",x,y); */
        fprintf(file,"%lf\t%9.6lf\n",x,y);

        /* y = forward_euler(x,y,h); */
        /* y = heun(x,y,h); */
        /* y = euler_middle(x,y,h); */
        y = runge_kutta_4th(x,y,h);
        /* y = forward_euler(x,y,h); */
    }

    return 0;
} 

/*                 t         y */
double func(double x, double y){
    double f = 0.0;
    /* f = -2.0*pow(x,3.0) + 12.0*pow(x,2.0) - 20.0*x + 8.5; */
    /* f = 4.0*exp(0.8*x) - 0.5*y; */
    f = y*(1.0 - y);
    return f;
}

double forward_euler(double x, double y, double h){
    double yn = 0.0;
    yn = y + func(x,y)*h;
    return yn;
}

double heun(double x, double y, double h){
    double pred = 0.0;
    double eval = 0.0;
    double yn = 0.0;

    eval = func(x,y);
    pred = y + eval*h;
    yn = y + ( eval + func( x+h, pred) )*(h/2.0);
    return yn;
}

double euler_middle(double x, double y, double h){
    double pred = 0.0;
    double eval = 0.0;
    double yn = 0.0;

    pred = y + func(x,y)*(h/2.0);
    yn = y + func(x + h/2.0, pred)*h;
    return yn;
}

double runge_kutta_4th(double x, double y, double h){
    double k1 = func(x,y);
    double k2 = func(x + h/2.0, y + k1*h/2.0);
    double k3 = func(x + h/2.0, y + k2*h/2.0);
    double k4 = func(x + h, y + k3*h);
    double yn = y + (k1 + 2.0*k2 + 2.0*k3 + k4)*h/6.0;
    return yn;
}
