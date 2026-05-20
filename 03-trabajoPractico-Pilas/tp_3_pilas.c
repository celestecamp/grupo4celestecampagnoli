#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pilas/headers/pilas.h"
#include "tp_3_pilas.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// -----------------------  FUNCIONES AUXILIARES   ----------------------- 

void p_intercambiar(Pila P, Pila Paux){ // Pasamos el contenido de Paux a P, recordar que queda invertida, [A,B,C] -> [C,B,A]
    TipoElemento tipoAux;
    while (! p_es_vacia(Paux)){
        tipoAux = p_desapilar(Paux);
        p_apilar(P,tipoAux);
    }
    return;
}

int contarLongitud(Pila P, Pila Paux){ //Contamos elementos de 'P' desapilando y apilando en 'PAUX', luego llamamos a P_INTERCAMBIAR(P,Paux), QUEDAN LAS MISMAS PILAS ORIGINALES Y RETORNA LA LONGITUD
    int longitud = 0;
    TipoElemento tipoAux;
    while (! p_es_vacia(P)){
        tipoAux = p_desapilar(P);
        p_apilar(Paux,tipoAux);
        longitud++;
    }
    p_intercambiar(P,Paux);
    return longitud;
}


// -----------------------  FUNCIONES DE LOS EJERCICIOS   ----------------------- 

// EJERCICIO 2-a:

// EJERCICIO 2-b:

// EJERCICIO 2-c:

// EJERCICIO 2-d:

// EJERCICIO 2-e:

// EJERCICIO 2-f:

// EJERCICIO 3:

// EJERCICIO 4:






// EJERCICIO 4:
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){

    if (nrootrabase < 2 || nrootrabase > 16){
        char* str = malloc(20);
        sprintf(str, "%d", nrobasedecimal);
        return str;
    }

    if (nrobasedecimal == 0){
        char* str = malloc(2);
        strcpy(str, "0");
        return str;
    }

    Pila p;
    TipoElemento teAux;
    p = p_crear();
    int n = nrobasedecimal;

    while (n > 0){
        int resto = n % nrootrabase;
        teAux = te_crear(resto);
        p_apilar(p, teAux);
        n = n / nrootrabase;
    }

    char* resultado = malloc(100);
    int i = 0;
    while (!p_es_vacia(p)){
        teAux = p_desapilar(p);
        if (teAux->clave < 10){
            resultado[i] = teAux->clave + '0';
        }
        else{
            resultado[i] = (teAux->clave - 10) + 'A';
        }
        i++;
    }
    resultado[i] = '\0';
    return resultado;

}
// COMPLEJIDAD ALGORITMICA EJERCICIO 4: O(log n) siendo N el numero decimal a convertir, ya que en el peor de los casos tenemos que dividir el numero entre la base hasta llegar a 0, y eso depende del numero decimal, osea N.



// EJERCICIO 5:
// EJERCICIO 6:
// EJERCICIO 7:
// EJERCICIO 8: