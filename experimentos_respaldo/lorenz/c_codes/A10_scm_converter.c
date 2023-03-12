#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE 2048

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
            if (strstr(&before[i], oldsub) == &before[i]) {
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
    while (i < before_length) {
        if (strstr(&before[i], oldsub) == &before[i]) {
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

char *truncate(char *before, char *oldsub){
    int before_length = strlen(before);
    char *after = malloc( (before_length + 1) * sizeof(char) );
    int i = 0;
    while (i < before_length) {
        if (strstr(&before[i], oldsub) == &before[i]) {
            break;
        } else {
            i++;
        }
    }
    strcpy(after, before);
    after[i] = '\0';
    return after;
}

int extract_number(char *string, char left_chr, char right_chr){
    char *ptr = strchr(string, right_chr);
    char chr = 0;
    int number = 0;
    int index = 0;
    int dec_place = 1;

    if (ptr != NULL) {
        index = ptr-string-1;
        while (true) {
            chr = string[index];
            if (isdigit(chr)) {
                number += (chr - '0')*dec_place;
                dec_place *= 10;
                index--;
            } else if(chr == left_chr) {
                break;
            } else {
                number = 0;
                break;
            }
        }
    } 
    return number;
}

int main(void) {
    char filename[] = "scm.v";
    FILE *input_file, *output_file;
    input_file = fopen(filename, "r");
    output_file = fopen("scm_custom.vhd", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s).\n");
        return 1;
    }

    printf(" # SCM generated, see scm_custom.vhd\n");

    char buffer[MAX_LINE];
    char line_counter = 0;
    char *result = NULL;
    int bits = 0;
    int arch = 0;
    bool semicolon = true;

    fprintf(output_file,"library ieee;\n");
	fprintf(output_file,"use ieee.std_logic_1164.all;\n");
	fprintf(output_file,"use ieee.numeric_std.all;\n\n");
    fprintf(output_file,"entity scm_custom is\n");
    fprintf(output_file,"    generic(n : integer := 32);\n");
    fprintf(output_file,"    port(\n");
    fprintf(output_file,"        X  :  in  std_logic_vector(n-1 downto 0);\n");
    fprintf(output_file,"        M  :  out std_logic_vector(n-1 downto 0)\n");
    fprintf(output_file,"    );\n");
    fprintf(output_file,"end;\n\n");
    fprintf(output_file,"architecture arch of scm_custom is\n");

    /* Read line by line the input_file */
    while (true) {
        if (fgets(buffer, MAX_LINE, input_file) == NULL) {
            break;
        }
        line_counter++;
        if (line_counter == 20) {
            arch = extract_number(buffer,'[', ':');
            fprintf(output_file,"    signal\n");
        }
        if (line_counter > 20 && strstr(buffer,"endmodule") == NULL) {
            if (semicolon == true && strchr(buffer, ';') != NULL) {
                result = truncate(buffer, ";");
                fprintf(output_file,"%s", result);
                fprintf(output_file,"\n    : signed (%d downto 0);\n", arch);
                fprintf(output_file,"begin\n");
                semicolon = false;
                free(result); result = NULL;
                continue;
            }
            result = replace(buffer, "  assign ", "    ");
            result = replace(result, " = ", " <= ");
            result = replace(result, "w1 <= X;", "w1 <= resize(signed(X), w1'length);");
            if ( (bits = extract_number(buffer, ' ', ';')) != 0 ) {
                result = truncate(result, " << ");
                fprintf(output_file,"%s(%d downto 0) & \"", result, arch-bits);
                for (int k = 0; k < bits; k++) {
                    fprintf(output_file,"0");
                }
                fprintf(output_file,"\";\n");
            } else if (strstr(buffer, "Y =") != NULL) {
                result = replace(result, "    Y <= ", "");
                result = truncate(result, "[");
                fprintf(output_file,"    M <= std_logic_vector( %s(%d downto %d) );\n",result, arch, arch-32+1);
            } else {
                fprintf(output_file,"%s", result);
            }
            free(result); result = NULL;
        }
    }
    fprintf(output_file,"end arch;\n");
    fclose(input_file);
    fclose(output_file);
    printf(" # Processed Line: %d\n", line_counter);
    return 0;
}

