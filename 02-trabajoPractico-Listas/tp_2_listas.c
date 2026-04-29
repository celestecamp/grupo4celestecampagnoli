#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/listas/headers/listas.h"
#include "tp_2_listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"  

// FUNCION PARA LLENAR Y BORRAR LISTAS 

Lista rellenarLista_manual(int elementos){
    if (elementos == 0){
        return l_crear();
    }
    printf("Ingrese las claves que desea para sus TipoElementos: \n");
    Lista l = l_crear();
    TipoElemento elemento;
    int i = 0;
    while(i<elementos && !l_es_llena(l)){
        int clave = 0;
        int valido = 0;
        while(valido != 1){
            printf("Clave del elemento %d: ", i+1);
            valido = scanf("%d", &clave);
            if (valido != 1) {
                printf("Clave ingresada incorrecta. Solo numeros enteros. Ingrese nuevamente la clave ");
                limpiarbuffer();
                printf("\n");
            }
        }
        elemento = te_crear(clave);
        i++;
        l_agregar(l,elemento);
    }
    return l; 
}

Lista rellenarLista_auto(int elementos){
    if (elementos == 0){
        return l_crear();
    }
    Lista l = l_crear();
    TipoElemento elemento;
    int i = 0;
    while(i<elementos && !l_es_llena(l)){

        int clave = rand() % 100; // Genera un número aleatorio entre 0 y 99
        elemento = te_crear(clave);
        i++;
        l_agregar(l,elemento);
    }
    return l; 
}

void vaciarLista(Lista lista) {
    while (!l_es_vacia(lista)) {
        TipoElemento te = l_recuperar(lista, 1);
        if (te != NULL) {
            free(te);               // libera el TipoElemento creado con te_crear
        }
        l_eliminar(lista, 1);       // SACA el primer elemento de la lista
    }
}

// ---------------------------------------------------------------- FUNCIONES DEL TP ----------------------------------------------------------------

// P2 a y b
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Lista nuevaLista = l_crear();
    TipoElemento Te_nuevo;
    Iterador ite = iterador(l1);

    while(hay_siguiente(ite)){
        Te_nuevo = siguiente(ite);
        if(l_buscar(l2, Te_nuevo->clave) == NULL){
            l_agregar(nuevaLista, Te_nuevo);
        }
    }
    return nuevaLista;
}

// Punto 2 C
Lista verElementosRepetidos(Lista l1, Lista l2){
    Lista nuevaLista = l_crear();
    TipoElemento Te_nuevo;
    Iterador ite = iterador(l1);

    while(hay_siguiente(ite)){
        Te_nuevo = siguiente(ite);
        if(l_buscar(l2, Te_nuevo->clave) != NULL){
            l_agregar(nuevaLista, Te_nuevo);
        }
    }
    return nuevaLista;
}

// Punto 2 D
float promedio(Lista l1){
    if (l_es_vacia(l1)){
        return 0;
    }
    int suma = 0;
    int cantidad = l_longitud(l1);
    TipoElemento Te_nuevo;
    Iterador ite = iterador(l1);

    while(hay_siguiente(ite)){
        Te_nuevo = siguiente(ite);
        suma += Te_nuevo->clave;
    }
    return (float)suma/cantidad;

}

// Punto 2 E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    ResultadoValorMinimo resultado;

    TipoElemento Te_nuevo = l_recuperar(l1, 1);
    int clave_minima = Te_nuevo->clave;
    int posicion_minima = 1;
    int pos_actual=0;
    Iterador ite = iterador(l1);
    while(hay_siguiente(ite)){
        pos_actual++;
        Te_nuevo = siguiente(ite);
        if (Te_nuevo->clave < clave_minima){
            clave_minima = Te_nuevo->clave;
            posicion_minima = pos_actual;
        }
    }
    resultado.pos = posicion_minima;
    resultado.valor = clave_minima;

    TipoElemento Te_nuevo_2 = l_recuperar(l2, 1);
    int clave_minima_2 = Te_nuevo_2->clave;
    posicion_minima = 1;
    pos_actual=0;
    Iterador ite_2 = iterador(l2);
    while(hay_siguiente(ite_2)){
        pos_actual++;
        Te_nuevo_2 = siguiente(ite_2);
        if (Te_nuevo_2->clave < clave_minima_2){
            clave_minima_2 = Te_nuevo_2->clave;
            posicion_minima = pos_actual;
        }
    }
    resultado.pos_2 = posicion_minima;
    resultado.valor_2 = clave_minima_2;
    return resultado;
}

// P3
ResultadosMul multiplo(Lista l1, Lista l2){

}

// P4
int CompararListas(Lista l1, Lista L2){

}

// P5
void hacerPolinomio(Lista list){

}

float evaluarPoliomio(Lista list, float x){

}

Lista calcularRango(Lista list, double x, double y, double sumando){

}

// P6
bool esSublista(Lista l1, Lista l2){
    
}