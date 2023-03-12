/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A5_fixed_point_converter_wind.c
 * Description: Fixed point converter for windows
 * Compile: gcc -o A5_converter_wind.exe A5_fixed_point_converter_wind.c
 * Run: ./A5_converter_wind.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int x[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
    double result = 0;
    double value = 0;
    for (int i = 1; i <= 21; i++) {
        value = pow(2, -i);
        result += value*(double)x[i-1];
        printf("i = %2d, value = %32.30lf, Result is %32.30lf, bit = %d\n", i , value, result, x[i-1] );
    }
	return 0;
}

