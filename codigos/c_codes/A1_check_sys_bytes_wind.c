/*
 * Engineer: Ciro Fabian Bermudez Marquez
 * Date: 16/06/2022
 * Desing name: check_sys_bytes_wind.c
 * Description: Check the number of byte of each data type for windows.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Data type <float> -> 4 bytes, in other words 32 bits.
    printf("float is %lu bytes.\n",sizeof(float));
    
    // Data type <double> -> 8 bytes, in other words 64 bits.
    printf("double is %lu bytes.\n",sizeof(double));
    
    // Data type <__int128> -> 16 bytes, in other words 128 bits.
    printf("__int128 is %lu bytes.\n",sizeof(__int128));

    // Data type <long long> -> 8 bytes, in other words 64 bits.
    printf("long is %lu bytes.\n",sizeof(long long));

    // Data type <int> -> 4 bytes, in other words 32 bits.
    printf("int is %lu bytes.\n",sizeof(int));

    // Data type <short> -> 2 bytes, in other words 16 bits.
    printf("short is %lu bytes.\n",sizeof(short));
    
    // Data type <char> -> 1 bytes, in other words 8 bits.
    printf("char is %lu bytes.\n",sizeof(char));
    
    return 0;
}
// gcc -o check_wind check_sys_bytes_wind.c
// ./check_wind 