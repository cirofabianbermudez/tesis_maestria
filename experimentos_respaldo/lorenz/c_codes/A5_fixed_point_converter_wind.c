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
int _power;

// A(a,b) fixed point representation
void initialize( int a, int b ){		
	_a = a;								
	_b = b;
	_power = (int)1 << _b;
}

// double to fixed point convertion with truncation
int setNumber( double v ){				 
	return ( (int)(v*_power) );
}

// fixed point to double convertion
double getNumber( int r ){				
	return ( (double)r/_power);
}

// fixed point to binary_string for 64 bits
char *to_binary(int n){
    int arch = 32;
	char *binary = (char *)malloc(sizeof(char) * (arch + 1) ); // extra byte for null terminator
	int k = 0;
    unsigned int mask, i;
    mask = ( (int)1 << (arch - 1) ); 
	for (i = mask; i > 0; i >>= 1) {
		binary[k++] = (n & i) ? '1' : '0';
	}
	binary[k] = '\0';
	return binary;
}

int main(void){
  	FILE *fpointer = fopen("convertion.txt","w");

  	double values[] = {10.0, 8.0/3.0, 28.0, 0.005, 1.0, 0.0, 1.0};
    int fixed_value = 0;
	int length = sizeof(values)/sizeof(values[0]);
	int integer, frac;
	
	integer = 10; frac = 32 - integer - 1; 
	initialize( integer, frac );
	printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);
	printf(" # Number of elements: %d\n", length);
	printf(" # See convertion.txt\n\n");

    char *binary_string;
    for (int i = 0; i < length; i++){
        fixed_value = setNumber(values[i]);
        binary_string = to_binary(fixed_value);
        printf(" v%d <= \"%s\"; -- %64.60lf\n",i+1, binary_string, getNumber(fixed_value) );
        fprintf(fpointer," v%d <= \"%s\"; -- %64.60lf\n",i+1, binary_string, getNumber(fixed_value) );
        free(binary_string);
        binary_string = NULL;
    }

	fclose(fpointer);
	return 0;
}
