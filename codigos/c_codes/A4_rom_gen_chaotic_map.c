/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: rom_gen_chaotic_map.c
 * Description: VHDL ROM generator for chaotic map
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

void fprintf_bin(FILE *fpointer,long n){
    unsigned long mask = 1;
    for(int i = sizeof(n)*8-1; i >= 0; i--){
        mask = (long)1 << i;
        (n & mask) ? fprintf(fpointer,"1") : fprintf(fpointer,"0");
    }
}

int main(void){
    double an[12] = {-0.6, -0.1, 1.1, 0.2, -0.8, 0.6, -0.7, 0.7, 0.7, 0.3, 0.6, 0.9};
    long an_fp[12] = {0};
    int i = 0;
    int length = sizeof(an)/sizeof(an[0]);

    int integer, frac;
    integer = 3; frac = 64 - integer - 1; 
    initialize( integer, frac );
    printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);
    printf(" Number of elements: %d\n", length);

    for(i = 0; i<length; i++){
        an_fp[i] = setNumber(an[i]);
    }

    FILE *fpointer = fopen("rom_cm.vhd","w");       // Open file
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
    for(i = 0; i<length; i++){
        fprintf(fpointer,"    a%d <= \"",i+1);
        fprintf_bin(fpointer,an_fp[i]);    
        fprintf(fpointer,"\"; -- %5.2lf\n",getNumber(an_fp[i]) );
    }
    fprintf(fpointer,"end;\n");
    fclose(fpointer); // Close file
    return 0;
}
// gcc -o rom_cm rom_gen_chaotic_map.c
// ./rom_cm