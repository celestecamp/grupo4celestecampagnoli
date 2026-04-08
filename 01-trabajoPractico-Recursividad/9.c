#include <stdio.h>
#include "tp_1_recursividad.h"
#include <stdbool.h>

bool divisiblePor7(int n){

    if (n < 0) {
        n = -n;
    }

    if (n < 70) {
        return n % 7 == 0;
    }
    
    int ultima = n % 10;
    int resto  = n / 10;
    return divisiblePor7(resto - ultima * 2);
}