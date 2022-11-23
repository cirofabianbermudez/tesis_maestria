/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: fixed_point_converter.c
 * Description: Fixed point converter
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Global variables
int _a;						// integer part
int _b;						// fractional part
long _power;

// A(a,b) fixed point representation
void initialize( int a, int b ){		
	_a = a;								
	_b = b;
	_power = (long)1 << _b;
}

// double to fixed point convertion with truncation
long setNumber( double v ){				 
	return ( (long)(v*_power) );
}

// fixed point to double convertion
double getNumber( long r ){				
	return ( (double)r/_power);
}

void fprintf_bin(FILE *fpointer,long n){
    unsigned long mask = 1;
    for(int i = sizeof(n)*8-1; i >= 0; i--){
        mask = (long)1 << i;
        (n & mask) ? fprintf(fpointer,"1") : fprintf(fpointer,"0");
    }
}

void printf_bin(long n){
    unsigned long mask = 1;
    for(int i = sizeof(n)*8-1; i >= 0; i--){
        mask = (long)1 << i;
        (n & mask) ? printf("1") : printf("0");
    }
}

int main(void){
  	FILE *fpointer = fopen("convertion.txt","w");

  	double values[2] = {0.1, 0.2};
	long values_fp[2] = {0};
	int length = sizeof(values)/sizeof(values[0]);
	int integer, frac;
	int i = 0;
	
	integer = 3; frac = 64 - integer - 1; 
	initialize( integer, frac );
	printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);
	printf(" Number of elements: %d\n", length);

    for(i = 0; i<length; i++){
        values_fp[i] = setNumber(values[i]);
        fprintf(fpointer,"v%d <= \"",i+1);
        fprintf_bin(fpointer,values_fp[i]);    
        fprintf(fpointer,"\"; -- %5.2lf\n",getNumber(values_fp[i]) );
        printf(" v%d <= \"",i+1);
        printf_bin(values_fp[i]);    
        printf("\"; -- %5.2lf\n",getNumber(values_fp[i]) );
    }
	
	fclose(fpointer);
	return 0;
}
// gcc -o convertion fixed_point_converter.c
// ./convertion