/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: serial_read_wind.c
 * Description: Read from serial file and convert to double for windows
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Global variables
int _a;                     // integer part
int _b;                     // fractional part
long long _power;

// A(a,b) fixed point representation
void initialize( int a, int b ){        
    _a = a;                             
    _b = b;
    _power = (long long)1 << _b;
}

// fixed point to double convertion
double getNumber( long long r ){             
    return ( (double)r/_power);
}


int main(void){

    FILE *fptr  = fopen("serial.txt","rb");
    FILE *fptr2 = fopen("check_serial.txt","w");
    
    if(fptr == NULL){
        printf("Error while opening the file.\n");
        exit(1);
    }

    int integer, frac;
    integer = 3; frac = 64 - integer - 1; 
    initialize( integer, frac );
    printf(" Representation A(a,b) = A(%d,%d)\n a: integer\tb: fractional \n",integer,frac);

    unsigned char ch;
    int i = 0;
    int counter = 0;
    int idx = 1;
    long long  temp = 0;
    for(i = 0; i<(8*2)*100000; i++){
        ch = fgetc(fptr);
        temp |= (unsigned long long)ch << 8*(8-idx);
        //printf("%2.2hhx", ch);
        //printf(" %16.16llx\n",temp);
        counter++;
        idx++;

        if(counter == 8){
            fprintf(fptr2,"%32.29lf \t", getNumber( temp ) );
            //printf("%32.29lf\t", getNumber( temp ) );
            temp = 0;
            idx = 1;
        }

        if(counter == 16){
            fprintf(fptr2,"%32.29lf\n", getNumber( temp ) );
            //printf("%32.29lf\n", getNumber( temp ) );
            counter = 0;
            temp = 0;
            idx = 1;
        }
    }

    fclose(fptr);
    fclose(fptr2);
    return 0;
}
// gcc -o serial_read_wind serial_read_wind.c
// ./serial_read_wind