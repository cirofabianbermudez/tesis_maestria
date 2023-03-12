#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double t){
    double g = 9.81;
    double c = 12.5;
    double m = 68.1;
    double r = 0.0;
    r = ( (g*m)/c )*(1 - expf( -(c/m) *t ));
    return r;
}


int main(void){
    FILE *file;
    file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("See output.txt\n");
    /* Valores iniciales */
    double t = 0.0;
    double y = 0.0;

    /* Parametros para vector de tiempo */
    double a = 0.0;
    double b = 10.0;
    double n = 1000.0;
    double h = (b-a)/(n-1);

    printf("%20s\t%20s\n","t","y");
    for (int i = 0; i < (int)n; i++) {
        y = func(t);
        /* printf("%20.15lf\t%20.15lf\n",t,y); */
        fprintf(file,"%20.15lf\t%20.15lf\n",t,y);
        t += h;
    }
    
    return 0;
}
