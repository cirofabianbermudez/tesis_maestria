/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 08/12/2022
 * Desing name: rgb_latex_converter.c
 * Description: Convert normal RGB [0-255] to [0-1] 
 * Compile: gcc -o convert.exe rgb_latex_converter.c
 * Text file (color.txt): 20 30 40
 * Run: Get-Content color.txt | ./convert.exe
 *      ./convert.exe < color.txt
 *      ./convert.exe
*/
#include <stdio.h>

void read_data(int rgb[3]){
    printf("Write the three RGB numbers separated by spaces\n");
    printf("Example: 100 200 300\n");
    printf("Input: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", rgb + i);
    }
}

void rgb_latex_convertion(int rgb[3], double rgb_latex[3]){
    for (int i = 0; i < 3; i++) {
        rgb_latex[i] = rgb[i]/255.0;
    }
}

void print_array(int rgb[3], double rgb_latex[3]){
    char letter[3] = {'r','g','b'};
    printf("\nThe convertion is:\n");
    for (int i = 0; i < 3; i++) {
        printf("%c: %3d: %lf\n",letter[i], rgb[i], rgb_latex[i]);
    }

    printf("\nCopy to LaTeX:\n");
    printf("\\definecolor{custom_color}{rgb}{");
    for (int i = 0; i < 3; i++) {
        printf("%lf",rgb_latex[i]);
        (i<2) ? printf(" ,") : printf("}\n");
    }
}
int main(void){
    int rgb[3] = {0};
    double rgb_latex[3] = {0.0};
    read_data(rgb);
    rgb_latex_convertion(rgb, rgb_latex);
    print_array(rgb, rgb_latex);

    return 0;
}
