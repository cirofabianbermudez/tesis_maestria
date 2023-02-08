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
#include <string.h>

// Global variables
int _a;						// integer part
int _b;						// fractional part
long long _power;

// A(a,b) fixed point representation
void initialize( int a, int b ){		
	_a = a;								
	_b = b;
	_power = (long long)1 << _b;
}

// double to fixed point convertion with truncation
long long setNumber( double v ){				 
	return ( (long long)(v*_power) );
}

// fixed point to double convertion
double getNumber( long long r ){				
	return ( (double)r/_power);
}

// fixed point to binary_string for 64 bits
char *to_binary(long long n){
	char *binary = (char *)malloc(sizeof(char) * (64 + 1) ); // extra byte for null terminator
	int k = 0;
    unsigned long long mask, i;
    mask = ( (long long)1 << (64 - 1) ); 
	for (i = mask; i > 0; i >>= 1) {
		binary[k++] = (n & i) ? '1' : '0';
	}
	binary[k] = '\0';
	return binary;
}

int main(void){
  	FILE *fpointer = fopen("convertion.txt","w");

  	double values[] = {0.1, 0.2};
    long long fixed_value = 0;
	int length = sizeof(values)/sizeof(values[0]);
	int integer, frac;
	
	integer = 3; frac = 64 - integer - 1; 
	initialize( integer, frac );
	printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);
	printf(" # Number of elements: %d\n", length);
	printf(" # See convertion.txt\n\n");

    char *binary_string;
    for (int i = 0; i < length; i++){
        fixed_value = setNumber(values[i]);
        binary_string = to_binary(fixed_value);
        printf(" v%d <= \"%s\"; -- %5.2lf\n",i+1, binary_string, getNumber(fixed_value) );
        fprintf(fpointer," v%d <= \"%s\"; -- %5.2lf\n",i+1, binary_string, getNumber(fixed_value) );
        free(binary_string);
        binary_string = NULL;
    }

	fclose(fpointer);
	return 0;
}
