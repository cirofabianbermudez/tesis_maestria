/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A7_chaotic_map_mod_bin_wind.c
 * Description: Sproot chaotic map simulation using fixed point and mod 256
 *              output in binary for windows
 * Compile: gcc -o chaotic_mod_bin_wind.exe A7_chaotic_map_mod_bin_wind.c
 * Run: ./chaotic_mod_bin_wind.exe
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

void fprintf_bin(FILE *fpointer, unsigned char n){
    unsigned char mask = 1;
    for(int i = sizeof(n)*8-1; i >= 0; i--){
        mask = (long long)1 << i;
        (n & mask) ? fprintf(fpointer,"1") : fprintf(fpointer,"0");
    }
}

int main(void){
  	FILE *fpointer = fopen("output_chaotic_mod_binary.txt","w");

	long long ai[12], xi, yi, xni, yni;
	unsigned short si;
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
	
	//si = (unsigned char)xi << 8  | (unsigned char)yi;
	//fprintf(fpointer,"%32.29lf\t%32.29lf\t\t%16.16llx\t\t%16.16llx\t%4.4x\n",getNumber( xi ), getNumber( yi ),xi,yi,si);
	//fprintf(fpointer,"%4.4x\n",si);
	//fprintf(fpointer,"%c%c",(unsigned char)xi,(unsigned char)yi);
	//for(int i = 0; i<62600000; i++){
	for(int i = 0; i<1; i++){
	    xni = ai[0] + multTrunc( multTrunc( ai[2] , xi )  + ai[1] , xi) + multTrunc(multTrunc(xi,yi), ai[3]) + 
	          multTrunc( multTrunc( ai[5] , yi )  + ai[4] , yi);
	    
	    yni = ai[6] + multTrunc( multTrunc( ai[8] , xi )  + ai[7] , xi) + multTrunc(multTrunc(xi,yi), ai[9]) + 
	          multTrunc( multTrunc( ai[11] , yi )  + ai[10] , yi);
		
		xi = xni;			 
		yi = yni;
		//si = (unsigned char)xi << 8  | (unsigned char)yi;
		//fprintf(fpointer,"%32.29lf\t%32.29lf\t\t%16.16llx\t\t%16.16llx\t%4.4x\n",getNumber( xi ), getNumber( yi ),xi,yi,si);
		//fprintf(fpointer,"%4.4x\n",si);
		x = (unsigned char)xi;
		y = (unsigned char)yi;
		fprintf_bin(fpointer,x);
		fprintf_bin(fpointer,y);
	}
	
	fclose(fpointer);
	return 0;
}

