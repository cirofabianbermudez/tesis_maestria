/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A7_chaotic_map_mod_bin.c
 * Description: Sproot chaotic map simulation using fixed point and mod 256 output in binary
 * Compile: gcc -o A7_chaotic_mod_bin.exe A7_chaotic_map_mod_bin.c
 * Run: ./A7_chaotic_mod_bin.exe
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

// fixed point multiplication with truncation
long multTrunc( long x, long y ){		
	__int128 r;
	__int128 a=0;
	__int128 b=0;
	a = x;
	b = y;
	r = a*b;
	r = r >> _b;
	return( r );
}

// fixed point to binary_string for 64 bits
char *to_binary(unsigned char n){
	char *binary = (char *)malloc(sizeof(char) * (8 + 1) ); // extra byte for null terminator
	int k = 0;
    unsigned char mask, i;
    mask = ( (char)1 << (8 - 1) ); 
	for (i = mask; i > 0; i >>= 1) {
		binary[k++] = (n & i) ? '1' : '0';
	}
	binary[k] = '\0';
	return binary;
}

int main(void){
  	FILE *fpointer = fopen("output_chaotic_mod_binary.txt","w");

	long ai[12], xi, yi, xni, yni;
	unsigned char x,y;
	double x0,y0;
	int integer, frac;
	
	integer = 3; frac = 64 - integer - 1; 
	initialize( integer, frac );
	printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);

	x0 = 0.1; y0 = 0.2;
	printf(" # x0: %f\n # y0: %f\n", x0, y0);
	
	xi = setNumber( x0 );
	yi = setNumber( y0 );
	printf(" # x0 real: %2.10f\n # y0 real: %2.10f\n",getNumber(xi), getNumber(yi) );
	printf(" # see output_chaotic_mod_binary.txt\n");

	ai[0]  = setNumber( -0.6 );
	ai[1]  = setNumber( -0.1 );
	ai[2]  = setNumber(  1.1 );
	ai[3]  = setNumber(  0.2 );
	ai[4]  = setNumber( -0.8 );
	ai[5]  = setNumber(  0.6 );
	ai[6]  = setNumber( -0.7 );
	ai[7]  = setNumber(  0.7 );
	ai[8]  = setNumber(  0.7 );
	ai[9]  = setNumber(  0.3 );
	ai[10] = setNumber(  0.6 );
	ai[11] = setNumber(  0.9 );
	
    char *xp, *yp;
	for(int i = 0; i<20; i++){
	    xni = ai[0] + multTrunc( multTrunc( ai[2] , xi )  + ai[1] , xi) + multTrunc(multTrunc(xi,yi), ai[3]) + 
	          multTrunc( multTrunc( ai[5] , yi )  + ai[4] , yi);
	    
	    yni = ai[6] + multTrunc( multTrunc( ai[8] , xi )  + ai[7] , xi) + multTrunc(multTrunc(xi,yi), ai[9]) + 
	          multTrunc( multTrunc( ai[11] , yi )  + ai[10] , yi);
		
		xi = xni;  yi = yni;
		x = (unsigned char)xi;  y = (unsigned char)yi;
        xp = to_binary(x);  yp = to_binary(y);
        fprintf(fpointer,"%s %s\n",xp, yp);
        free(xp); xp = NULL;
        free(yp); yp = NULL;
	}
	
	fclose(fpointer);
	return 0;
}
