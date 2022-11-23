/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: rom_generator.c
 * Description: VHDL ROM generator for message in RS232 protocol
 * Compile: gcc -o rom.exe A0_rom_generator.c
 * Run: ./rom.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void){
    char message[] = "Hello world ";
    int i = 0;
    int counter = 0;
    int length = strlen(message);
    float check = length;
    FILE *fpointer = fopen("rom.vhd","w");	    // Open file
	
	fprintf(fpointer,"-- string length = %d\n",length);
	fprintf(fpointer,"-- load %d, x\"%x\" in the counter\n",length,length);
    while(check > 1){
        check = check/2.0;
        counter++;
    }
    printf("number of bits = %d\n",counter);
	printf("load %d, x\"%x\" in the counter\n",length,length);

	fprintf(fpointer,"-- number of bits = %d\n",counter);
	fprintf(fpointer,"library ieee;\n");
	fprintf(fpointer,"use ieee.std_logic_1164.all;\n\n");
    fprintf(fpointer,"entity rom is\n");
    fprintf(fpointer,"    generic(n : integer := 8);\n");
    fprintf(fpointer,"    port(\n");
    fprintf(fpointer,"        ADDRESS : in  std_logic_vector(%d downto 0);\n",counter-1);
    fprintf(fpointer,"        VAL     : out std_logic_vector(n-1 downto 0)\n");
    fprintf(fpointer,"    );\n");
    fprintf(fpointer,"end;\n\n");

    fprintf(fpointer,"architecture arch of rom is\n");
    fprintf(fpointer,"begin\n");
    fprintf(fpointer,"    with ADDRESS select\n");
    fprintf(fpointer,"        VAL <=\n");

    for(i = 0; i<length; i++){
        fprintf(fpointer,"        x\"%2.2x\" when x\"%2.2x\", -- %c %d\n",message[i],i,message[i],message[i]);
    }

    fprintf(fpointer,"        (others => '0')  when others;\n");
    fprintf(fpointer,"end;\n");
	fclose(fpointer); // Close file
	return 0;
}