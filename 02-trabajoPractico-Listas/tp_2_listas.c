#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul resultado;
    resultado.esMultiplo = true;
    resultado.escalar = true;
    resultado.numEscalar = 0;

    //vacio
    if (l_longitud(l1) != l_longitud(l2) || l_es_vacia(l1)) {
        resultado.esMultiplo = false;
        resultado.escalar = false;
        return resultado;
    }

    Iterador it1 = iterador(l1);
    Iterador it2 = iterador(l2);
    bool primer_elemento = true;
    
    while (hay_siguiente(it1) && hay_siguiente(it2) && resultado.esMultiplo) {
        TipoElemento e1 = siguiente(it1);
        TipoElemento e2 = siguiente(it2);
        
        if (e1->clave == 0 || e2->clave % e1->clave != 0) {
            resultado.esMultiplo = false;
            resultado.escalar = false;
        } else {

            int cociente = e2->clave / e1->clave;
            
            if (primer_elemento) {
                resultado.numEscalar = cociente;
                primer_elemento = false;
            } else if (cociente != resultado.numEscalar) {
                resultado.escalar = false;
            }
        }
    }

    if (!resultado.escalar) {
        resultado.numEscalar = 0;
    }
    
    return resultado;
}

// P4
int CompararListas(Lista l1, Lista l2){     // COMPLEJIDAD: O(n)
    int contadorL1 = 0;
    int contadorL2 = 0;
    
    int len1 = l_longitud(l1);
    int len2 = l_longitud(l2);
    int minLen = (len1 < len2) ? len1 : len2;

    for (int i = 1; i <= minLen; i++) {
        TipoElemento e1 = l_recuperar(l1, i);
        TipoElemento e2 = l_recuperar(l2, i);

        if (e1->clave > e2->clave) {
            contadorL1++;
        } else if (e2->clave > e1->clave) {
            contadorL2++;
        }
    }

    if (contadorL1 > contadorL2) {
        return 1; // L1 > L2
    } else if (contadorL2 > contadorL1) {
        return 2; // L2 > L1
    } else {
        return 0; // L1 = L2
    }
}

// P5
void hacerPolinomio(Lista list) {
    if (l_es_llena(list)) {
        printf("Lista llena!\n");
        return;
    }
    
    int i = 0, exp;
    float* coef = malloc(sizeof(float));
    int valido;

    printf("[Ingreso del polinomio a evaluar]\n");
    while (!l_es_llena(list)) {
        printf("\n- Termino #%i:", i+1);
        do {
            printf("\nExponente (>= 0) [-1 para FINALIZAR]: ");
            valido = scanf("%i", &exp);

            if (!valido) {
                printf("INVALIDO! Debes ingresar un NUMERO ENTERO.\n");
                while (getchar() != '\n');
            }

            else if (exp < -1) {
                printf("Invalido, vuelva a intentar. Debe ser un numero mayor o igual a cero!\n");
            }
            
            else if (exp == -1) break;
            
            else {
                printf("Coeficiente: ");
                valido = scanf("%f", coef);
                
                if (valido) {
                    l_agregar(list, te_crear_con_valor(exp, coef));
                    break;
                }
                else {
                    printf("El coeficiente debe ser un NUMERO REAL.\n");
                    while (getchar() != '\n');
                }
            }
        } while (1);
        
        if (exp == -1) break;

        coef = malloc(sizeof(float));
        i++;
    }

    printf("POLINOMIO GUARDADO.\n");
}

float evaluarPoliomio(Lista list, float x) {
    if (l_es_vacia(list)) {
        printf("Polinomio invalido.\n");
        return false;
    }

    float resultado = 0, exp; float coef; TipoElemento elem;
    Iterador ite = iterador(list);
    while (hay_siguiente(ite)) {
        elem = siguiente(ite);
        exp = elem->clave;
        coef = *(float*)elem->valor;

        resultado += (coef * pow(x, exp));
    }

    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando) { 
    Lista l = l_crear();

    if (l_es_vacia(list)) return l;

    TipoElemento elem;
    
    float i = x;
    while (i <= y) {
        float* res = malloc(sizeof(float));
        *res =  evaluarPoliomio(list, i);
        printf("F(%.2lf) = %.2lf\n", i, *res); // muestro el resultado en pantalla

        elem = te_crear_con_valor(0, res);
        l_agregar(l, elem);

        i += sumando;
    }

    return l;
}

// P6


//LA COMPLEJIDAD ALGORITMICA SE ENCUENTRA EN EL README.md DE ESTE DIRECTORIO
bool esSublista(Lista l1, Lista l2){
    Iterador iterL2 = iterador(l2);

    if(l_longitud(l2) > l_longitud(l1)) return false;
    
    while(hay_siguiente(iterL2)){
        bool contiene = false;
    
        TipoElemento elementoActualL2 = siguiente(iterL2);
        Iterador iterL1 = iterador(l1);
    
        while(hay_siguiente(iterL1) && !contiene){
            TipoElemento elementoActualL1 = siguiente(iterL1);
    
            if(elementoActualL1->clave == elementoActualL2->clave){
                contiene = true;
            }
        }
        if(!contiene) return false;
    }
    return true;
}
