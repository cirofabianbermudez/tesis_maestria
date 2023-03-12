#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double func(double x, double y);

int main(void){
    double y, x = 0.0;

    FILE *file = fopen("slope.txt", "w");

    if (file == NULL) {
        printf("Error while opeing file.\n");
        return 1;
    }

    double x_left, x_right, y_down, y_up = 0.0;
    x_left = 0.0;
    x_right = 10.0;
    y_down = 0.0;
    y_up = 2.0;

    double nx = 21.0;
    double hx = (x_right - x_left)/(nx - 1.0);

    double ny = 14.0;
    double hy = (y_up - y_down)/(ny - 1.0);

    double slope = 0.0;
    double angle = 0.0;
    double delta_x = 0.0;
    double delta_y = 0.0;
    double factor_x = 1.0;
    double factor_y = 0.2;  // despues agragegar formula del porciento
    double factor = 0.4;

    x = x_left;
    y = y_down;
    for (int i = 0; i < nx; i++, x+=hx) {
        y = y_down;
        for (int j = 0; j < ny; j++, y+=hy) {
            slope = func(x,y);
            /* angle = atan(slope)*(180.0/M_PI); */
            angle = atan(slope);
            delta_x = factor*factor_x*cos(angle);
            delta_y = factor*factor_y*sin(angle);


            fprintf(file,"%10.7lf\t%10.7lf\t%10.7lf\t%10.7lf\n", x, y, delta_x, delta_y);

        }
    }

    return 0;
} 

double func(double x, double y){
    double f = 0.0;
    /* f = -2.0*pow(x,3.0) + 12.0*pow(x,2.0) - 20.0*x + 8.5; */
    /* f = 4.0*exp(0.8*x) - 0.5*y; */
    f = y*(1.0 - y);
    return f;
}

