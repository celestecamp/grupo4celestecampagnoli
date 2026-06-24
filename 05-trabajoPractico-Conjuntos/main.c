#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "tp_colas.h"
#include "../03-trabajoPractico-Pilas/tp_3_pilas.h"
#include "../libs/pilas/headers/pilas.h"
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
    printf("2 - Union, interseccion, diferencia y pertenencia entre 2 conjuntos\n");
    printf("3 - Union e interseccion en una coleccion\n");
    printf("4 - Transitividad \n");
    printf("5 - Diferencia simetrica\n");
    printf("6 - Subconjunto (2 conjuntos)\n");
    printf("7 - Subconjunto parcial o total (3 conjuntos)\n");
    printf("8 - Conjuntos iguales\n");
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
                printf("-- 2. UNION, INTERSECCION, DIFERENCIA, PERTENENCIA --\n");
                ejercicio2();
                break;
            case 3:
                limpiarPantalla();
                printf("-- 3. COLECCION - UNION E INTERSECCION --\n");
                ejercicio3();
                break;
            case 4:
                limpiarPantalla();
                printf("-- 4. TRANSITIVIDAD --\n");
                ejercicio4();
                break;
            case 5:
                limpiarPantalla();
                printf("-- 5. DIFERENCIA SIMETRICA --\n");
                ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. SUBCONJUNTO --\n\n");
                ejercicio6();
                break;
            case 7:
                limpiarPantalla();
                printf("-- 7. SUBCONJUNTO PARCIAL/TOTAL --\n\n");
                ejercicio7();
                break;
            case 8:
                limpiarPantalla();
                printf("-- 8. CONJUNTOS IGUALES --\n\n");
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

    printf("\n\n");
    pausar();
}


void ejercicio7(){
    
    printf("\n\n");
    pausar();
}


void ejercicio8(){
    
    printf("\n\n");
    pausar();
}