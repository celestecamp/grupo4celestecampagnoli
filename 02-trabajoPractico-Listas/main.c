#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"



// menu
void mostrarMenu();
void ingresarOpcion(char *ingresado, int *nro_elegido);

// funciones inicializadoras
void ejercicio2(char opcion);
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();

void mostrarMenu() {
    printf("------ TP2: LISTAS ------\n\n");
    printf("Seleccione un ejercicio:\n");
    printf("2 - Valores entre listas\n");
    printf("3 - Multiplo\n");
    printf("4 - Mayor, igual o menor\n");
    printf("5 - Polinomio\n");
    printf("6 - Sublista\n");
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

    ingresarOpcion(ingresado, &nro_elegido);
    while (nro_elegido != 0) {
        switch (nro_elegido) {
            case 2:
                limpiarPantalla();
                printf("-- 2. VALORES ENTRE LISTAS --\n");
                printf("Seleccione un ejercicio:\n");
                printf("a - Ver elementos de L1 que no estan en L2\n");
                printf("b - Ver elementos de L2 que no estan en L1\n");
                printf("c - Ver elementos comunes en ambas listas\n");
                printf("d - Promedios de L1 y L2\n");
                printf("e - Valor minimo y posicion ordinal de ambas listas\n");

                char opcion;
                do {
                    printf("Ingrese una opcion (a, b, c, d o e): ");
                    scanf(" %c", &opcion);
                    opcion = tolower(opcion);
                    if (opcion < 'a' || opcion > 'e') {
                        printf("Opcion no valida. Intente nuevamente.\n");
                    }
                } while (opcion < 'a' || opcion > 'e');
                ejercicio2(opcion);
                break;
            case 3:
                limpiarPantalla();
                printf("-- 3. MULTIPLO --\n");
                ejercicio3();
                break;
            case 4:
                limpiarPantalla();
                printf("-- 4. MAYOR, IGUAL O MENOR --\n");
                ejercicio4();
                break;
            case 5:
                limpiarPantalla();
                printf("-- 5. POLINOMIO --\n");
                ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. SUBLISTA --\n");
                ejercicio6();
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


//--------------------------------------- LLAMADAS A FUNCIONES DEL TP

void ejercicio2(char opcion){
}
void ejercicio3(){
}
void ejercicio4(){
}
void ejercicio5(){
}
void ejercicio6(){
}
