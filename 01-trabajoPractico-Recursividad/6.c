#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"

int ondaAux(char *onda, char seniales[], int i, int j) {
    if (seniales[i] == '\0') {
        onda[j] = '\0';
        return j;
    }

    if (i == 0) {
        // Primera señal
        if (seniales[i] == 'h' || seniales[i] == 'H')
            onda[j++] = '-';
        else
            onda[j++] = '_';
    } else {
        char ant = seniales[i - 1];
        char actual = seniales[i];

        int esHAnterior = (ant == 'h' || ant == 'H');
        int esHActual = (actual == 'h' || actual == 'H');

        if (esHAnterior && esHActual) {
            onda[j++] = '-';
        } else if (!esHAnterior && !esHActual) {
            onda[j++] = '_';
        } else if (!esHAnterior && esHActual) {
            onda[j++] = '|';
            onda[j++] = '-';
        } else if (esHAnterior && !esHActual) {
            onda[j++] = '|';
            onda[j++] = '_';
        }
    }

    return ondaAux(onda, seniales, i + 1, j);
}

char *ondaDigital (char seniales[]) {
    char *onda = malloc(sizeof(char) * (2 * strlen(seniales) + 1));
    ondaAux(onda, seniales, 0, 0);
    return onda;
}