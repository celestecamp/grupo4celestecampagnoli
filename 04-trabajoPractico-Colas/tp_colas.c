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

// --------- FUNCIONES AUXILIARES ---------
int elegirllenar_colas(){
    printf("\n\tSI DESEA CARGAR LA COLA AL AZAR, INGRESE 1, SI DESEA CARGARLA MANUALMENTE, INGRESE 2: ");
    int opcion = leer_entero();
    while (opcion != 1 && opcion != 2){
        printf("\nOpcion no valida. Ingrese 1 para cargar al azar, o 2 para cargar manualmente: ");
        opcion = leer_entero();
    }
    return opcion;
}

void c_intercambiar(Cola c, Cola caux){  // ENCOLA TODOS LOS ELEMENTOS DE CAUX, EN C
    TipoElemento teAux;
    while(!c_es_vacia(caux)){
        teAux = c_desencolar(caux);
        c_encolar(c,teAux);
    }
    return;
}

int c_longitud(Cola c){
    Cola caux = c_crear();
    TipoElemento teAux;
    int contador = 0;
    while (!c_es_vacia(c)){
        contador++;
        teAux = c_desencolar(c);
        c_encolar(caux,teAux);
    }
    c_intercambiar(c,caux);
    return contador;
}

void c_mostrar_con_valorstring(Cola cola) {
    if (c_es_vacia(cola)) {
        printf("COLA VACIA !!!\n");
        return;
    }

    Cola Caux = c_crear();
    TipoElemento X = te_crear(0);

    printf("-------------------------------------\n");
    printf("Imprimiendo los elementos de la Cola\n");
    printf("-------------------------------------\n");

    // Desencolar e imprimir
    while (!c_es_vacia(cola)) {
        X = c_desencolar(cola);
        if (X->valor != NULL) {
            printf("%s", (char *) X->valor);
        }
        printf("\n");
        c_encolar(Caux, X);
    }

    // Restaurar la cola original
    while (!c_es_vacia(Caux)) {
        X = c_desencolar(Caux);
        c_encolar(cola, X);
    }

    printf("\n");
}

Cola llenarcolasmanual(Cola c){
    printf("Ingrese la cantidad de elementos a cargar en la cola (0-%d): ",TAMANIO_MAXIMO-1);
    int cantidad = leer_entero();
    while (cantidad < 0 || cantidad > TAMANIO_MAXIMO-1){
        printf("Error. Ingrese una cantidad entre 0 y %d: ", TAMANIO_MAXIMO-1);
        cantidad = leer_entero();
    }
    if (cantidad == 0){
        return c;
    }
    printf("\nINGRESANDO LOS %d ELEMENTOS DE LA COLA:",cantidad);
    for (int i = 0; i < cantidad; i++){
        printf("\n\tIngrese un numero entero: ");
        int num = leer_entero();
        TipoElemento teAux = te_crear(num);
        c_encolar(c,teAux);
    }
    return c;
}

Cola llenarcolasauto(Cola c){
    printf("Ingrese la cantidad de elementos a cargar en la cola (0-%d): ",TAMANIO_MAXIMO-1);
    int cantidad = leer_entero();
    while (cantidad < 0 || cantidad > TAMANIO_MAXIMO-1){
        printf("Error. Ingrese una cantidad entre 0 y %d: ", TAMANIO_MAXIMO-1);
        cantidad = leer_entero();
    }
    if (cantidad == 0){
        return c;
    }
    printf("\nINGRESANDO LOS %d ELEMENTOS DE LA COLA:",cantidad);
    for (int i = 0; i < cantidad; i++){
        int num = rand() % 100; // Genera un número aleatorio entre 0 y 99
        TipoElemento teAux = te_crear(num);
        c_encolar(c,teAux);
    }
    return c;
}
// -----------------------  FUNCIONES DE LOS EJERCICIOS   ----------------------- 

// EJERCICIO 2-a:
bool c_ej2_existeclave(Cola c, int clave){ 
    Cola nueva= c_crear();

    bool encontrado= false;

    TipoElemento elemento;

    while (!c_es_vacia(c)){
        elemento= c_desencolar(c);
        if(elemento ->clave == clave){
            encontrado= true;
        }

        c_encolar(nueva, elemento);
    }

    while(!c_es_vacia(nueva)){
        c_encolar(c, c_desencolar(nueva));
    }

    return encontrado;
}

// EJERCICIO 2-b:
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    Cola nueva= c_crear();

    int i= 1;
    TipoElemento elemento;
    while(!c_es_vacia(c) && i<posicionordinal){
        elemento= c_desencolar(c);
        c_encolar(nueva, elemento);
        i++;
    }

    c_encolar(nueva, X);

    while(!c_es_vacia(c)){
        c_encolar(nueva, c_desencolar(c));
    }

    while(!c_es_vacia(nueva)){
        c_encolar(c, c_desencolar(nueva));
    }

    return c;
}

// EJERCICIO 2-c:
Cola c_ej2_sacarelemento(Cola c, int clave){ 
    Cola nueva= c_crear();
    Cola aux= c_crear();

    TipoElemento elemento;

    while(!c_es_vacia(c)){
        elemento= c_desencolar(c);
        if(elemento->clave==clave){
            c_encolar(aux, elemento);
        }
        else{
            c_encolar(nueva, elemento);
        }
    }

    while(!c_es_vacia(nueva)){
        c_encolar(c, c_desencolar(nueva));
    }

    return c;
}

// EJERCICIO 2-d:
int c_ej2_contarelementos(Cola c) {
    Cola nueva= c_crear();

    int contador= 0;
    TipoElemento elemento;

    while(!c_es_vacia(c)){
        elemento= c_desencolar(c);
        contador+= 1;
        
        c_encolar(nueva, elemento);
    }

    while(!c_es_vacia(nueva)){
    c_encolar(c, c_desencolar(nueva));
}

    return contador;
}

// EJERCICIO 2-e:
Cola c_ej2_copiar(Cola c){
    Cola aux= c_crear();
    Cola c2= c_crear();

    while(!c_es_vacia(c)){
        TipoElemento elemento= c_desencolar(c);

        c_encolar(aux, elemento);
        c_encolar(c2, elemento);
    }

    while(!c_es_vacia(aux)){
        c_encolar(c, c_desencolar(aux));
    }

    return c2;
}

// EJERCICIO 2-f:
Cola c_ej2_invertir(Cola c){ 
    Pila nueva= p_crear();
    Cola aux= c_crear();
    Cola resultado= c_crear();

    TipoElemento elemento;

    while(!c_es_vacia(c)){
        elemento= c_desencolar(c);

        c_encolar(aux, elemento);
        p_apilar(nueva, elemento);
    }

    while(!p_es_vacia(nueva)){
        c_encolar(resultado, p_desapilar(nueva));
    }

    while(!c_es_vacia(aux)){
        c_encolar(c, c_desencolar(aux));
    }

    return resultado;
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
    Cola caux = c_crear();
    Cola copia = c_crear();
    Cola copiaAux = c_crear();
    Cola nueva = c_crear();
    TipoElemento teAux;
    TipoElemento teAux2;
    int longitud = 0;
    int contador;

    while(!c_es_vacia(c)){
        longitud ++;
        teAux = c_desencolar(c);
        c_encolar(caux,teAux);
        c_encolar(copia,teAux);
    }

    while(!c_es_vacia(caux)){
        teAux = c_desencolar(caux);
        c_encolar(c,teAux);
        contador = 0;
        while(!c_es_vacia(copia)){
            teAux2 = c_desencolar(copia);
            c_encolar(copiaAux,teAux2);
            if(teAux2->clave % teAux->clave == 0){
                contador++;
            }
        }
        c_intercambiar(copia,copiaAux);

        if(contador == longitud){
            bool* total = malloc(sizeof(bool));
            *total = true;
            TipoElemento te_nuevo = te_crear_con_valor(teAux->clave,total);
            c_encolar(nueva,te_nuevo);
        }
        else if(contador > longitud/2){
            bool* parcial = malloc(sizeof(bool));
            *parcial = false;
            TipoElemento te_nuevo = te_crear_con_valor(teAux->clave,parcial);
            c_encolar(nueva,te_nuevo);
        }
    }
    return nueva;
}

// EJERCICIO 6:
Lista c_ej6_comunesapilaycola(Pila p, Cola c) {

    Lista l_res = l_crear();

    if (p_es_vacia(p) || c_es_vacia(c)) return l_res;

    TipoElemento actual_pila, actual_cola, comun;

    Pila paux = p_crear();
    Cola caux = c_crear();

    while (!p_es_vacia(p)) {
        actual_pila = p_desapilar(p);
        p_apilar(paux, actual_pila);
    }

    int posP = 1;

    while (!p_es_vacia(paux)) {
        actual_pila = p_desapilar(paux);

        int posC = 1;

        while (!c_es_vacia(c)) {
            actual_cola = c_desencolar(c);

            if (actual_pila->clave == actual_cola->clave) {
                char *str_pos = malloc(20);
                sprintf(str_pos, "%d:%d", posP, posC);

                comun = te_crear_con_valor(
                    actual_pila->clave,
                    str_pos
                );

                l_agregar(l_res, comun);
            }

            c_encolar(caux, actual_cola);
            posC++;
        }

        while (!c_es_vacia(caux)) {
            actual_cola = c_desencolar(caux);
            c_encolar(c, actual_cola);
        }

        p_apilar(p, actual_pila);

        posP++;
    }

    return l_res;
}

// EJERCICIO 7:
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    Cola nueva = c_crear();
    TipoElemento teAux;
    int tiempo_actual;
    int clientecola1 = 0;
    int clientecola2 = 0;
    int clientecola3 = 0;

    while (!c_es_vacia(c1) || !c_es_vacia(c2) || !c_es_vacia(c3)){
        tiempo_actual = tiempoatencion;
        while(!c_es_vacia(c1) && tiempo_actual>0){
                teAux = c_recuperar(c1);
                teAux->clave = teAux->clave - tiempo_actual;
                if(teAux->clave < 0){
                    tiempo_actual = -1*(teAux->clave);
                    c_desencolar(c1);
                    clientecola1++;
                    char* mensaje = malloc(20);
                    sprintf(mensaje,"Cliente %d Cola 1,\n",clientecola1);
                    TipoElemento te_nuevo = te_crear_con_valor(1,mensaje);
                    c_encolar(nueva,te_nuevo);
                }
                else if(teAux->clave == 0){
                    tiempo_actual = 0;
                    c_desencolar(c1);
                    clientecola1++;
                    char* mensaje = malloc(20);
                    sprintf(mensaje,"Cliente %d Cola 1,\n",clientecola1);
                    TipoElemento te_nuevo = te_crear_con_valor(1,mensaje);       
                    c_encolar(nueva,te_nuevo);
                }
                else {
                    tiempo_actual = 0;
                }
        }

        tiempo_actual = tiempoatencion;
        while(!c_es_vacia(c2) && tiempo_actual>0){
                teAux = c_recuperar(c2);
                teAux->clave = teAux->clave - tiempo_actual;
                if(teAux->clave < 0){
                    tiempo_actual = -1*(teAux->clave);
                    c_desencolar(c2);
                    clientecola2++;
                    char* mensaje = malloc(20);
                    sprintf(mensaje,"Cliente %d Cola 2,\n",clientecola2);
                    TipoElemento te_nuevo = te_crear_con_valor(2,mensaje);   
                    c_encolar(nueva,te_nuevo);

                }
                else if(teAux->clave == 0){
                    tiempo_actual = 0;
                    c_desencolar(c2);
                    clientecola2++;
                    char* mensaje = malloc(20);
                    sprintf(mensaje,"Cliente %d Cola 2,\n",clientecola2);
                    TipoElemento te_nuevo = te_crear_con_valor(2,mensaje);
                    c_encolar(nueva,te_nuevo);

                }
                else {
                    tiempo_actual = 0;
                }
        }

        tiempo_actual = tiempoatencion;
        while(!c_es_vacia(c3) && tiempo_actual>0){
                teAux = c_recuperar(c3);
                teAux->clave = teAux->clave - tiempo_actual;
                if(teAux->clave < 0){
                    tiempo_actual = -1*(teAux->clave);
                    c_desencolar(c3);
                    clientecola3++;
                    char* mensaje = malloc(20);
                    sprintf(mensaje,"Cliente %d Cola 3,\n",clientecola3);
                    TipoElemento te_nuevo = te_crear_con_valor(3,mensaje);
                    c_encolar(nueva,te_nuevo);

                }
                else if(teAux->clave == 0){
                    tiempo_actual = 0;
                    c_desencolar(c3);
                    clientecola3++;
                    char* mensaje = malloc(20);
                    sprintf(mensaje,"Cliente %d Cola 3,\n",clientecola3);
                    TipoElemento te_nuevo = te_crear_con_valor(3,mensaje); 
                    c_encolar(nueva,te_nuevo);

                }
                else {
                    tiempo_actual = 0;
                }
        }
        
    }
    return nueva;
}
