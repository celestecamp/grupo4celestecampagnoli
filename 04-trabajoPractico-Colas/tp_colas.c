#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_colas.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// -----------------------  FUNCIONES DE LOS EJERCICIOS   ----------------------- 

// EJERCICIO 2-a:
bool c_ej2_existeclave(Cola c, int clave){ 

}

// EJERCICIO 2-b:
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){

}

// EJERCICIO 2-c:
Cola c_ej2_sacarelemento(Cola c, int clave){ 

}

// EJERCICIO 2-d:
int c_ej2_contarelementos(Cola c) {

}

// EJERCICIO 2-e:
Cola c_ej2_copiar(Cola c){

}

// EJERCICIO 2-f:
Cola c_ej2_invertir(Cola c){ 

}

// EJERCICIO 3:
bool c_ej3_iguales(Cola c1, Cola c2){

}

// EJERCICIO 4:
Cola  c_ej4_colanorepetidos(Cola c){

}

// EJERCICIO 5:
Cola c_ej5_divisortotal(Cola c){

}

// EJERCICIO 6:
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    Lista l_res = l_crear();

    if (p_es_vacia(p) || c_es_vacia(c)) return l_res;

    TipoElemento actual_pila, actual_cola;
    TipoElemento comun;
    Pila paux = p_crear();
    Cola caux = c_crear();

    bool encontrado;
    int longitudP = 0;

    // invierto la pila original a paux
    while (!p_es_vacia(p)) {
        actual_pila = p_desapilar(p);
        p_apilar(paux, actual_pila);
        longitudP++;
    }
    
    int posP = longitudP;

    while (!p_es_vacia(paux)) {
        actual_pila = p_desapilar(paux);

        if (l_buscar(l_res, actual_pila->clave)) {
            posP++;
            continue;
        }

        encontrado = false;
        
        int posC = 1;
        while (!c_es_vacia(c)) {
            actual_cola = c_desencolar(c);

            if (!encontrado && actual_cola->clave == actual_pila->clave) {
                char* str_pos = malloc(10 * sizeof(char));
                sprintf(str_pos, "%d:%d", posP, posC);

                comun = te_crear_con_valor(actual_cola->clave, str_pos);
                l_agregar(l_res, comun);

                encontrado = true;
            }

            c_encolar(caux, actual_cola);
            posC++;
        }

        
        while (!c_es_vacia(caux)) {
            actual_cola = c_desencolar(caux);
            c_encolar(c, actual_cola);
        }
        
        posP--;
        p_apilar(p, actual_pila); 
    }

    return l_res;
}

// EJERCICIO 7:
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){

}