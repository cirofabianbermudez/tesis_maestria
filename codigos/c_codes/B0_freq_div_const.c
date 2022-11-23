/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: freq_div_const.c
 * Description: Compute constant for frequency divider
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printf_bin(int n){
    unsigned int mask = 1;
    double check = n;
    int j = 0;
    while(check > 1){
    	check = check / 2;
    	j++;
    	//printf("%f, %d\n",check, j); 
    }
    for(int i = j-1; i >= 0; i--){
        mask = (int)1 << i;
        (n & mask) ? printf("1") : printf("0");
    }
    printf(", bits: %d\n", j);
}


int main(void){
	double f = 115200;
	double t = 1.0/f;
	double f_fpga = 100e6;
	double k = t*f_fpga - 1;
	printf(" Load: %d, ",(int)round(k) ); // 10 bits
	printf_bin(k);
	return 0;
}
// gcc -o const freq_div_const.c
// ./const