#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "tp_3_pilas.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"



// menu
void mostrarMenu();
void ingresarOpcion(char *ingresado, int *nro_elegido);

// funciones inicializadoras
//void ejercicio2_a();
//void ejercicio2_b();
//void ejercicio2_c();
//void ejercicio2_d();
//void ejercicio2_e();
//void ejercicio2_f();
//void ejercicio3();
void ejercicio4();
//void ejercicio5();
//void ejercicio6();
//void ejercicio7();
//void ejercicio8();

void mostrarMenu() {
    printf("\n\n\n------ TP3: PILAS ------\n\n");
    printf("Seleccione un ejercicio:\n");
    printf("2 - Valores cargados al azar (a-f)\n");
    printf("3 - Contenidos iguales\n");
    printf("4 - Convertir un numero \n");
    printf("5 - Invertir el contenido\n");
    printf("6 - Ocurrencias de un elemento\n");
    printf("7 - Elementos en Comun\n");
    printf("8 - Elementos sin repeticion\n");
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
                //ejercicio2();
                break;
            case 3:
                limpiarPantalla();
                printf("-- 3. CONTENIDOS IGUALES --\n");
                //ejercicio3();
                break;
            case 4:
                limpiarPantalla();
                printf("-- 4. CONVERTIR UN NUMERO --\n");
                ejercicio4();
                break;
            case 5:
                limpiarPantalla();
                printf("-- 5. INVERTIR EL CONTENIDO --\n");
                //ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. OCURRENCIAS DE UN ELEMENTO --\n\n");
                //ejercicio6();
                break;
            case 7:
                limpiarPantalla();
                printf("-- 7. ELEMENTOS EN COMUN --\n\n");
                //ejercicio7();
                break;
            case 8:
                limpiarPantalla();
                printf("-- 8. ELEMENTOS SIN REPETICION --\n\n");
                //ejercicio8();
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



/*void ejercicio2(){
    ejercicio2_a();
    ejercicio2_b();
    ejercicio2_c();
    ejercicio2_d();
    ejercicio2_e();
    ejercicio2_f();
}
*/
/*
void ejercicio3(){
}
*/
void ejercicio4(){
    int nrobasedecimal, nrootrabase;
    printf("\nIngrese un numero decimal: ");
    nrobasedecimal = leer_entero();
    printf("Ingrese la base a la que desea convertir: ");
    nrootrabase = leer_entero();
    char* resultado = p_ej4_cambiarbase(nrobasedecimal, nrootrabase);
    if (nrootrabase < 2 || nrootrabase > 16){
        printf("\nLa base debe estar entre 2 y 16. El numero ingresado se muestra sin cambios: %s\n", resultado);
        free(resultado);
        pausar();
        return;
    }
    printf("\nEl numero %d en base %d es: %s\n", nrobasedecimal, nrootrabase, resultado);
    free(resultado);
}
/*
void ejercicio5(){
}
*/
/*
void ejercicio6(){

}
*/
/*
void ejercicio7(){
}
*/
/*
void ejercicio8(){
}
*/
