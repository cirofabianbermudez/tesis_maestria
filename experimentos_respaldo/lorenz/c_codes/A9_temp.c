#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE 2048

int number_of_lines(char *filename){
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int current_line = 1;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            current_line++;
        }
    }

    /* do { */
    /*     c = fgetc(file); */
    /*     if (c == '\n') current_line++; */
    /* } while (c != EOF); */

    fclose(file);

    return current_line - 1;
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
    int old_length = strlen(oldsub);

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


int experimental(char *string, char character){
    int number = -1;
    char *ptr = strchr(string, character);
    int index = ptr-string;
    if (ptr != NULL) {
        number = index;
    } 
    return number;
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
    int total_lines = number_of_lines(filename);
    int temp = 0;
    /* printf("Number of lines: %d\n", number_of_lines(filename)); */
    FILE *input_file, *output_file;
    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[MAX_LINE];
    char line_counter = 0;
    char *result = NULL;
    int bits = 0;
    int arch = 0;
    bool semicolon = true;

    /* Read line by line the input_file */
    while (true) {
        /* fgets(buffer, MAX_LINE, input_file); */
        /* line_counter++; */
        /* if (feof(input_file)) { */
        /*     break; */
        /* } */
        if (fgets(buffer, MAX_LINE, input_file) == NULL) {
            break;
        }
        line_counter++;
        if (line_counter == 20) {
            arch = extract_number(buffer,'[', ':');
            printf("    signal\n");
        }
        if (line_counter > 20 && strstr(buffer,"endmodule") == NULL) {
            if (semicolon == true && strchr(buffer, ';') != NULL) {
                result = truncate(buffer, ";");
                printf("%s", result);
                printf("\n    : signed (%d downto 0);\n", arch);
                semicolon = false;
                free(result); result = NULL;
                continue;
            }
            result = replace(buffer, "  assign ", "    ");
            result = replace(result, " = ", " <= ");
            result = replace(result, "w1 <= X;", "w1 <= resize(signed(X), w1'length);");
            if ( (bits = extract_number(buffer, ' ', ';')) != 0 ) {
                result = truncate(result, " << ");
                printf("%s(%d downto 0) & \"", result, bits);
                for (int k = 0; k < bits; k++) {
                    printf("0");
                }
                printf("\";\n");
            } else if (strstr(buffer, "Y =") != NULL) {
                result = replace(result, "    Y <= ", "");
                result = truncate(result, "[");
                printf("    M <= std_logic_vector( %s(%d downto %d) );\n",result, arch, arch-32+1);
            } else {
                printf("%s", result);
            }
            free(result); result = NULL;
        }
    }
    fclose(input_file);
    printf("line_counter: %d\n", line_counter);
    printf("%s", buffer);
    return 0;
}
