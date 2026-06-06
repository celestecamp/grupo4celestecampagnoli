#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "tp_colas.h"
#include "../03-trabajoPractico-Pilas/tp_3_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/colas/headers/colas.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"

// menu
void mostrarMenu();
void ingresarOpcion(char *ingresado, int *nro_elegido);

// funciones inicializadoras

void ejercicio2();
void ejercicio2_a(Cola c);
void ejercicio2_b(Cola c);
void ejercicio2_c(Cola c);
void ejercicio2_d(Cola c);
void ejercicio2_e(Cola c);
void ejercicio2_f(Cola c);
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();

void mostrarMenu() {
    printf("\n\n\n------ TP4: COLAS ------\n\n");
    printf("Seleccione un ejercicio:\n");
    printf("2 - Punto 2 (a-f)\n");
    printf("3 - Contenidos iguales\n");
    printf("4 - Elementos no repetidos \n");
    printf("5 - Divisores totales y parciales\n");
    printf("6 - Valores comunes\n");
    printf("7 - Atender clientes\n");
    printf("0 - Salir\n");
    printf("Ingrese una opcion: ");
}

void ingresarOpcion(char *ingresado, int *nro_elegido) {
    while (1) {
    mostrarMenu();

    fgets(ingresado, sizeof(ingresado), stdin);
    
    // si todo fue bien se asigna ingresado a nro_elegido convertido a entero
    if (numero_valido(ingresado)) {
        *nro_elegido = str_a_int(ingresado);
        break;
    }

    printf("\nError: dato incorrecto\n");
    printf("Presione ENTER para volver al menu\n");
    getchar();

    fflush(stdin);
    limpiarPantalla();
    }
}

int main(){
    char ingresado[10];
    int nro_elegido;
    srand(time(NULL));

    ingresarOpcion(ingresado, &nro_elegido);

    while (nro_elegido != 0) {
        switch (nro_elegido) {
            case 2:
                limpiarPantalla();
                ejercicio2();
                break;
            case 3:
                limpiarPantalla();
                printf("-- 3. CONTENIDOS IGUALES --\n");
                ejercicio3();
                break;
            case 4:
                limpiarPantalla();
                printf("-- 4. NO REPETIDOS --\n");
                ejercicio4();
                break;
            case 5:
                limpiarPantalla();
                printf("-- 5. DIVISORES --\n");
                ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. VALORES COMUNES --\n\n");
                ejercicio6();
                break;
            case 7:
                limpiarPantalla();
                printf("-- 7. ATENDER CLIENTES --\n\n");
                ejercicio7();
                break;
            default:
                limpiarPantalla();
                printf("No existe esa opcion!\n");
                break;
        }

        ingresado[0] = '\0';
        ingresarOpcion(ingresado, &nro_elegido);
    }
        return 0;
}

void ejercicio2_a(Cola c){

    printf("\n\n");
    pausar();
}

void ejercicio2_b(Cola c){
    
    printf("\n\n");
    pausar();
}

void ejercicio2_c(Cola c){
    
    printf("\n\n");
    pausar();
}

void ejercicio2_d(Cola c){
    
    printf("\n\n");
    pausar();
}

void ejercicio2_e(Cola c){

    printf("\n\n");
    pausar();
}

void ejercicio2_f(Cola c){

    printf("\n\n");
    pausar();
}

void ejercicio2(){
    printf("\n\n");
    pausar();
}


void ejercicio3(){

    printf("\n\n");
    pausar();
}

void ejercicio4(){

    printf("\n\n");
    pausar();

}

void ejercicio5(){
    printf("\n\n");
    pausar();
}


void ejercicio6(){
    Pila p = p_crear();
    Cola c = c_crear();

    TipoElemento elem;

    char n[10];
    int valor;

    printf("[PILA]\n");
    llenarpilas(p);

    if (p_es_llena(p)){
        printf("\nLa pila esta llena, no se puede apilar mas elementos\n");
    }

    printf("\n[COLA]\n");
    printf("Ingrese '.' para salir.\n");
    do {
        printf("Valor en cola:");
        fgets(n, sizeof(n), stdin);

        if (numero_valido(n) == 1){ 
            valor = str_a_int(n);
            c_encolar(c, te_crear(valor));
        }
        else {
            if (n[0] != '.') printf("- Debe ser numerico! Vuelva a intentar -\n");
        }
    } while (!c_es_llena(c) && (n[0] != '.'));

    if (c_es_llena(c)){
        printf("\nLa cola esta llena, no se pueden encolar mas elementos\n");
    }
    
    printf("\n[PILA] \n"); p_mostrar(p);
    printf("\n[COLA] \n"); c_mostrar(c);

    printf("----------------------------------------\n[COMUNES] ");
    Lista l_res = c_ej6_comunesapilaycola(p, c);
    Iterador iter = iterador(l_res);
    TipoElemento actual;

    if (l_es_vacia(l_res)) l_mostrar(l_res);
    else {
        while (hay_siguiente(iter)) {
            actual = siguiente(iter);
            printf("%i:%s ", actual->clave, actual->valor);
        }
    }

    printf("\n\n");
    pausar();
}


void ejercicio7(){
    
    printf("\n\n");
    pausar();
}