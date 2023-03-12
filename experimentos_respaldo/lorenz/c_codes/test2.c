#include <stdio.h>
#include <string.h>

int main()
{
    char str[100] = "Hello, World!";
    char ch = 'W';
    char *ptr;

    ptr = strchr(str, ch);
    if (ptr) {
        printf("El carácter '%c' se encuentra en la posición %ld de la cadena '%s'\n", ch, ptr - str + 1, str);
    } else {
        printf("El carácter '%c' no se encuentra en la cadena '%s'\n", ch, str);
    }

    return 0;
}
