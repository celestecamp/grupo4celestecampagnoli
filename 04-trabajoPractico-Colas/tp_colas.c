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
    Cola c_aux = c_crear();
    int len1 = 0;
    int len2 = 0;
    bool iguales = true;
	
    while (!c_es_vacia(c1)) {
        c_encolar(c_aux, c_desencolar(c1));
        len1++;
    }
    
    while (!c_es_vacia(c_aux)) {
        c_encolar(c1, c_desencolar(c_aux));
    }

    
    while (!c_es_vacia(c2)) {
        c_encolar(c_aux, c_desencolar(c2));
        len2++;
    }
    
    while (!c_es_vacia(c_aux)) {
        c_encolar(c2, c_desencolar(c_aux));
    }
 
    if (len1 != len2) {
        return false; 
    }

    
    for (int i = 0; i < len1; i++) {
        TipoElemento e1 = c_desencolar(c1);
        TipoElemento e2 = c_desencolar(c2);

        if (e1->clave != e2->clave) {
            iguales = false;
        }
        c_encolar(c1, e1);
        c_encolar(c2, e2);
    }

    return iguales;
}

// EJERCICIO 4:
Cola  c_ej4_colanorepetidos(Cola c){
    Cola resultado = c_crear();
    if (c_es_vacia(c)) {
        return resultado;
    }
    int n = 0;
    Cola c_aux = c_crear();
    while (!c_es_vacia(c)) {
        c_encolar(c_aux, c_desencolar(c));
        n++;
    }
    while (!c_es_vacia(c_aux)) {
        c_encolar(c, c_desencolar(c_aux));
    }
    for (int i = 0; i < n; i++) {

        TipoElemento actual = c_desencolar(c);
        int repeticiones = 1; 
        for (int j = 0; j < n - 1; j++) {
            TipoElemento temp = c_desencolar(c);
            if (temp->clave == actual->clave) {
                repeticiones++;
            }
            c_encolar(c, temp); 
        }
        if (repeticiones == 1) {
            TipoElemento nuevo = te_crear_con_valor(actual->clave, actual->valor);
            c_encolar(resultado, nuevo);
        }
        c_encolar(c, actual);
    }
    return resultado;
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