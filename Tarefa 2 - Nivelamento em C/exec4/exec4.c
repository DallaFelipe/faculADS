#include <stdio.h>

int main() {
    char   varChar;
    int    varInt;
    float  varFloat;
    double varDouble;

    printf("Tamanho dos tipos basicos :\n");
    printf("-----------------------------\n");

    printf("char:   %zu byte(s)\n",  sizeof(varChar));
    printf("int:    %zu byte(s)\n",  sizeof(varInt));
    printf("float:  %zu byte(s)\n",  sizeof(varFloat));
    printf("double: %zu byte(s)\n",  sizeof(varDouble));

    return 0;
}