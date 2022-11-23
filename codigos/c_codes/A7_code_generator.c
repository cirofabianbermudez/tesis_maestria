/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: code_generator.c
 * Description: Simple code generator for 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printf_bin(char n){
    unsigned char mask = 1;
    for(int i = 4-1; i >= 0; i--){
        mask = (char)1 << i;
        (n & mask) ? printf("1") : printf("0");
    }
}

int main(void){
    //FILE *fpointer = fopen("code_generator.vhd","w");	    // Open file
	int i = 0;
    for(i = 0; i<8; i++){
        printf("Xn(%d downto %d) when \"",8*(8-i)-1,8*(8-i)-8);    
        printf_bin(i);
        printf("\",\n");    
    }

    for(i = 8; i<16; i++){
        printf("Yn(%d downto %d) when \"",8*(8-i+8)-1,8*(8-i+8)-8);    
        printf_bin(i);
        printf("\",\n");    
    }

	//fclose(fpointer); // Close file
	return 0;
}
// gcc -o generator code_generator.c
// ./generator