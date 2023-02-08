/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A4_rom_gen_chaotic_map.c
 * Description: VHDL ROM generator for chaotic map
 * Compile: gcc -o A4_rom_cm.exe A4_rom_gen_chaotic_map.c
 * Run: ./A4_rom_cm.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Global variables
int _a;                     // integer part
int _b;                     // fractional part
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

// fixed point to binary_string for 64 bits
char *to_binary(long n){
	char *binary = (char *)malloc(sizeof(char) * (64 + 1) ); // extra byte for null terminator
	int k = 0;
    unsigned long mask, i;
    mask = ( (long)1 << (64 - 1) ); 
	for (i = mask; i > 0; i >>= 1) {
		binary[k++] = (n & i) ? '1' : '0';
	}
	binary[k] = '\0';
	return binary;
}

int main(void){
    double an[12] = {-0.6, -0.1, 1.1, 0.2, -0.8, 0.6, -0.7, 0.7, 0.7, 0.3, 0.6, 0.9};
    long fixed_value = 0;
    int i = 0;
    int length = sizeof(an)/sizeof(an[0]);

    int integer, frac;
    integer = 3; frac = 64 - integer - 1; 
    initialize( integer, frac );
    printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);
    printf(" # Number of elements: %d\n", length);
    printf(" # ROM generated, see rom_cm.vhd\n");

    FILE *fpointer = fopen("rom_cm.vhd","w");	    // Open file
	fprintf(fpointer,"library ieee;\n");
	fprintf(fpointer,"use ieee.std_logic_1164.all;\n\n");
    fprintf(fpointer,"entity rom_cm is\n");
    fprintf(fpointer,"    generic(n : integer := 64);\n");
    fprintf(fpointer,"    port(\n");
    fprintf(fpointer,"        ");
    for(i = 1; i <= length; i++){
        if(i == length)
            fprintf(fpointer,"a%d",i);
        else
            fprintf(fpointer,"a%d,",i);
    }
    fprintf(fpointer," : out std_logic_vector(n-1 downto 0)\n");
    fprintf(fpointer,"    );\n");
    fprintf(fpointer,"end;\n\n");
    fprintf(fpointer,"architecture arch of rom_cm is\n");
    fprintf(fpointer,"begin\n");

    char *binary_string;
    for(i = 0; i<length; i++){
        fixed_value = setNumber(an[i]);
        binary_string = to_binary(fixed_value);
        fprintf(fpointer,"    a%d <= \"%s\"; --%5.2lf\n",i+1, binary_string, getNumber(fixed_value) );
        free(binary_string);
        binary_string = NULL;
    }

    fprintf(fpointer,"end;\n");
	fclose(fpointer); // Close file
	return 0;
}
