/*
 * Author: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: A9_scm_converter_wind.c
 * Description: Single Constant Multiplier converter Verilog to VHDL windows
 * Compile: gcc -o A9_scm_converter_wind.exe A9_scm_converter_wind.c
 * Run: ./A9_scm_converter_wind.exe
 * Notes: The file should be downloaded directly from Spiral not copy paste
 *        the program needs that the file have 2 new lines at the end.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE 2048

void delete(char string[], char substri[]);
char *replace(char *before, char *oldsub, char *newsub);
int right_detector(char string[], char character);
int left_detector(char string[], char character);
int detector(char string[], char character);
void truncate(char string[], char character);
int file_lines(FILE *input_file);

int main(void){
    char buffer[MAX_LINE];
    FILE *out_file, *input_file;
    printf(" # SCM generated, see scm_custom.vhd\n");

    out_file = fopen("scm_custom.vhd", "w");        // open file
    input_file = fopen("scm.v", "r");               // open file
                                                    //

    if ( out_file == NULL || input_file == NULL) {
        printf("Error opening out_file\n");
        return 1;
    }

    fprintf(out_file,"library ieee;\n");
	fprintf(out_file,"use ieee.std_logic_1164.all;\n");
	fprintf(out_file,"use ieee.numeric_std.all;\n\n");
    fprintf(out_file,"entity scm_custom is\n");
    fprintf(out_file,"    generic(n : integer := 32);\n");
    fprintf(out_file,"    port(\n");
    fprintf(out_file,"        X  :  in  std_logic_vector(n-1 downto 0);\n");
    fprintf(out_file,"        M  :  out std_logic_vector(n-1 downto 0)\n");
    fprintf(out_file,"    );\n");
    fprintf(out_file,"end;\n\n");
    fprintf(out_file,"architecture arch of scm_custom is\n");

    bool keep_reading = true;
    int current_line = 1;
    char *result = NULL;
    int counter_dots = 0;
    int number = 0;
    int bits = 0;
    int limit = file_lines(input_file);
    /* printf("%d\n", limit); */

    while ( keep_reading ) {
        fgets(buffer, MAX_LINE, input_file);
        if ( feof(input_file) ) {
            keep_reading = false;
        } else if ( current_line == 20 ) {
            bits = left_detector(buffer, '[');
            fprintf(out_file,"    signal\n");
        } else if ( current_line > (limit-6) ){
            keep_reading = false;
        } else if ( current_line > 20 ) {
            if ( detector(buffer, ';') ) {
                if ( counter_dots == 0 ) {
                    result = replace(buffer, ";", " ");
                    fprintf(out_file,"%s", result);
                    fprintf(out_file,"    : signed (%d downto 0);\n", bits);
                    fprintf(out_file,"begin\n");
                } else {
                    number = right_detector(buffer, ';');
                    result = replace(buffer, "assign ", "");
                    if (number) {
                        truncate(result, '<');
                        result = replace(result, "=", "<=");
                        fprintf(out_file,"%s(%d downto 0) & \"", result, bits-number);
                        for (int k = 0; k < number; k++) {
                            fprintf(out_file,"0");
                        }
                        fprintf(out_file,"\";\n");
                    } else {
                        result = replace(result, "=", "<=");
                        result = replace(result, "w1 <= X;", "w1 <= resize( signed(X), w1'length);");
                        fprintf(out_file,"%s", result);
                    }
                }
                counter_dots++;
            } else {
                fprintf(out_file,"%s", buffer);
            }
        }         free(result); 
        result = NULL;
        current_line++;
    }
    
    fgets(buffer, MAX_LINE, input_file);
    result = replace(buffer, "  assign Y = ", "");
    truncate(result, '[');
    fprintf(out_file,"  M <= std_logic_vector( %s(%d downto %d) );\n",result, bits, bits-32+1);

    fprintf(out_file,"end arch;\n");
	fclose(input_file); // Close file
	fclose(out_file); // Close file
	return 0;
}

int file_lines(FILE *input_file){
    bool keep_reading = true;
    char buffer[MAX_LINE];
    int lines = 1;
    while ( keep_reading ) {
        fgets(buffer, MAX_LINE, input_file);
        if ( feof(input_file) ) {
            keep_reading = false;
        } 
        lines++;
    }
    rewind(input_file);
    return lines-1;
}

void delete(char string[], char substr[]){
    int i = 0;
    int string_length = strlen(string);
    int substr_length = strlen(string);

    while (i < string_length) {
        if ( strstr(&string[i], substr) == &string[i] ) {
            string_length -= substr_length;
            for (int j = i; j < string_length; j++) {
                string[j] = string[j + substr_length];
            }
        } else {
            i++;
        }
    }
    string[i] = '\0';
}

char *replace(char *before, char *oldsub, char *newsub){
    int before_length = strlen(before);
    int old_length = strlen(oldsub);
    int new_length = strlen(newsub);

    char *after;

    if (old_length == new_length) {
        after  = malloc( (before_length + 1) * sizeof(char) );
    } else {
        int occurrences = 0;
        int i = 0;
        while (i < before_length) {
            if ( strstr(&before[i], oldsub) == &before[i] ) {
                occurrences++;
                i += old_length;
            } else {
                i++;
            }
            
        }
        int sub_diff = new_length - old_length;
        int after_length = before_length;
        after_length += occurrences * sub_diff;
        after = malloc( (after_length + 1) * sizeof(char));
    }
        int i = 0;
        int j = 0;
        while ( i < before_length ) {
            if ( strstr(&before[i], oldsub) == &before[i] ) {
                strcpy(&after[j], newsub);
                i += old_length;
                j += new_length;
            } else {
                after[j] = before[i];
                i++;
                j++;
            }
        }
        after[j] = '\0';
        return after;
}

int right_detector(char string[], char character){
    char *ptr = strchr(string, character);
    int index = 0;
    char str_numb[3] = {' '};
    int number = 0;

    str_numb[2] = '\0';
    
    if (ptr == NULL) {
        number = 0;
    } else {
        index = ptr-string;
        if (isdigit(string[index-1]) && string[index-2] == ' ') {
            str_numb[1] = string[index-1];
        } else if (isdigit(string[index-1]) && isdigit(string[index-2]) && string[index-3] == ' ') {
            str_numb[1] = string[index-1];
            str_numb[0] = string[index-2];
        }
        number = atoi( str_numb  );
    }
    return number;
}

int left_detector(char string[], char character){
    char *ptr = strchr(string, character);
    int index = 0;
    char str_numb[3] = {' '};
    int number = 0;

    str_numb[2] = '\0';
    
    if (ptr == NULL) {
        number = 0;
    } else {
        index = ptr-string;
        if (isdigit(string[index+1]) && string[index+1] == ':') {
            str_numb[0] = string[index+1];
        } else if (isdigit(string[index+1]) && isdigit(string[index+2]) && string[index+3] == ':') {
            str_numb[0] = string[index+1];
            str_numb[1] = string[index+2];
        }
        number = atoi( str_numb  );
    }
    return number;
}

int detector(char string[], char character){
    char *ptr = strchr(string, character);
    return (ptr == NULL) ? 0 : 1 ;
}

void truncate(char string[], char character){
    char *ptr = strchr(string, character);
    int index  = ptr-string;
    string[index] = '\0';
}

