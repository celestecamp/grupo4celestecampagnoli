#include <stdio.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"

int calcularTamano(int conjunto[]) {    // devuelve el tamaño del arreglo
    int cant = 0;
    
    while (conjunto[cant] != -1) {
        cant++;
    }

    return cant;
}

void subconjRecursiva(int conjunto[], int tamano, int sumaObjetivo, int sumaActual, int pos, int subconjunto[], int tamSubconj, int **res, int *cantSubconjuntos) {
    if (sumaActual == sumaObjetivo) {  // caso base: llego a la suma deseada
        res[*cantSubconjuntos] = (int*) malloc((tamSubconj + 1) * sizeof(int));
        
        for (int i = 0; i < tamSubconj; i++) {  // lo guardo
            res[*cantSubconjuntos][i] = subconjunto[i];
        }

        res[*cantSubconjuntos][tamSubconj] = -1;  // final del subconjunto
        (*cantSubconjuntos)++;
        return;
    }

    if (pos >= tamano || sumaActual > sumaObjetivo) return;

    // incluir el elemento actual
    subconjunto[tamSubconj] = conjunto[pos];
    subconjRecursiva(conjunto, tamano, sumaObjetivo, sumaActual + conjunto[pos], pos + 1, subconjunto, tamSubconj + 1, res, cantSubconjuntos);

    // no incluir el elemento actual
    subconjRecursiva(conjunto, tamano, sumaObjetivo, sumaActual, pos + 1, subconjunto, tamSubconj, res, cantSubconjuntos);
}

int **subconjuntosQueSumanN(int conjunto[], int n) {   
    int **res = (int **)malloc(100 * sizeof(int *)); // reservo memoria para resultado
    
    int tamano = calcularTamano(conjunto);  // calculo el tamaño del conjunto
    int subconjunto[tamano];  
    int cantSubconjuntos = 0;

    subconjRecursiva(conjunto, tamano, n, 0, 0, subconjunto, 0, res, &cantSubconjuntos);
    res[cantSubconjuntos] = NULL;
    return res; 
}