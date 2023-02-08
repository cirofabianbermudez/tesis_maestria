/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A6_chaotic_map_mod_wind.c
 * Description: Sproot chaotic map simulation using fixed point and mod 256 for windows
 * Compile: gcc -o A6_chaotic_mod_wind.exe A6_chaotic_map_mod_wind.c
 * Run: ./A6_chaotic_mod_wind.exe
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

// fixed point multiplication with truncation
long long multTrunc( long long x, long long y ){		
	__int128 r;
	__int128 a=0;
	__int128 b=0;
	a = x;
	b = y;
	r = a*b;
	r = r >> _b;
	return( r );
}

int main(void){
  	FILE *fpointer = fopen("output_chaotic_mod.txt","w");

	long long ai[12], xi, yi, xni, yni;
	unsigned short si;
	double x0,y0;
	int integer, frac;
	
	integer = 3; frac = 64 - integer - 1; 
	initialize( integer, frac );
	printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);

	x0 = 0.1; y0 = 0.2;
	printf(" # x0: %f\n # y0: %f\n", x0, y0);
	
	xi = setNumber( x0 ); yi = setNumber( y0 );
	printf(" # x0 real: %2.10f\n # y0 real: %2.10f\n",getNumber(xi), getNumber(yi) );
	printf(" # see output_chaotic_mod.txt\n");

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
	
	for(int i = 0; i<20; i++){
	    xni = ai[0] + multTrunc( multTrunc( ai[2] , xi )  + ai[1] , xi) + multTrunc(multTrunc(xi,yi), ai[3]) + 
	          multTrunc( multTrunc( ai[5] , yi )  + ai[4] , yi);
	    
	    yni = ai[6] + multTrunc( multTrunc( ai[8] , xi )  + ai[7] , xi) + multTrunc(multTrunc(xi,yi), ai[9]) + 
	          multTrunc( multTrunc( ai[11] , yi )  + ai[10] , yi);
		
		xi = xni;			 
		yi = yni;
		/* fprintf(fpointer,"%c%c",(unsigned char)xi,(unsigned char)yi); */
		fprintf(fpointer,"%2.2x %2.2x\n",(unsigned char)xi,(unsigned char)yi);
	}
	
	fclose(fpointer);
	return 0;
}
