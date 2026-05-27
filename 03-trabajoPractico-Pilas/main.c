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

void ejercicio2();
void ejercicio2_a(Pila p);
void ejercicio2_b(Pila p);
void ejercicio2_c(Pila p);
void ejercicio2_d(Pila p);
void ejercicio2_e(Pila p);
void ejercicio2_f(Pila p);
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();

void mostrarMenu() {
    printf("\n\n\n------ TP3: PILAS ------\n\n");
    printf("Seleccione un ejercicio:\n");
    printf("2 - Valores cargados al azar (a-f)\n");
    printf("3 - Contenidos iguales\n");
    printf("4 - Convertir un numero \n");
    printf("5 - Invertir el contenido\n");
    printf("6 - Eliminar todas las ocurrencias de un elemento\n");
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
                ejercicio2();
                break;
            case 3:
                limpiarPantalla();
                printf("-- 3. CONTENIDOS IGUALES --\n");
                ejercicio3();
                break;
            case 4:
                limpiarPantalla();
                printf("-- 4. CONVERTIR UN NUMERO --\n");
                ejercicio4();
                break;
            case 5:
                limpiarPantalla();
                printf("-- 5. INVERTIR EL CONTENIDO --\n");
                ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. ELIMINAR TODAS LAS OCURRENCIAS DE UN ELEMENTO --\n\n");
                ejercicio6();
                break;
            case 7:
                limpiarPantalla();
                printf("-- 7. ELEMENTOS EN COMUN --\n\n");
                ejercicio7();
                break;
            case 8:
                limpiarPantalla();
                printf("-- 8. ELEMENTOS SIN REPETICION --\n\n");
                ejercicio8();
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

void ejercicio2_a(Pila p){
    printf("\nPILA ORIGINAL:\n\t");
    p_mostrar(p);
    if (p_es_vacia(p)){
        printf("\nLa pila esta vacia, no se puede buscar ningun elemento.\n");
        printf("\n\n");
        pausar();
        return;
    }
    printf("Ingrese la clave a buscar: ");
    int clave = leer_entero();
    bool existe = p_ej2_existeclave(p, clave);
    printf("La clave %d %s en la pila.\n", clave, existe ? "EXISTE" : "NO existe");
    printf("\n\n");
    pausar();
}

void ejercicio2_b(Pila p){
    printf("\nPILA ORIGINAL:\n\t");
    p_mostrar(p);
    printf("Ingrese la posicion donde insertar (1 = fondo): ");
    int pos = leer_entero();
    printf("Ingrese la clave del nuevo elemento: ");
    int clave = leer_entero();
    p = p_ej2_colocarelemento(p, pos, te_crear(clave));
    printf("\nPila resultado:\n");
    p_mostrar(p);
    printf("\n\n");
    pausar();
}

void ejercicio2_c(Pila p){
    printf("\nPILA ORIGINAL:\n\t");
    p_mostrar(p);
    if (p_es_vacia(p)){
        printf("\nLa pila esta vacia, no se puede eliminar ningun elemento.\n");
        printf("\n\n");
        pausar();
        return;
    }
    printf("Ingrese la clave a eliminar: ");
    int clave = leer_entero();
    p = p_ej2_eliminarclave(p, clave);
    printf("\nPila resultado:\n");
    p_mostrar(p);
    printf("\n\n");
    pausar();
}

void ejercicio2_d(Pila p){
    printf("\nPILA ORIGINAL:\n\t");
    p_mostrar(p);
    if (p_es_vacia(p)){
        printf("\nLa pila esta vacia, no se puede intercambiar ningun elemento.\n");
        printf("\n\n");
        pausar();
        return;
    }
    printf("Ingrese la primera posicion (1 = fondo): ");
    int pos1 = leer_entero();
    printf("Ingrese la segunda posicion: ");
    int pos2 = leer_entero();
    p = p_ej2_intercambiarposiciones(p, pos1, pos2);
    printf("\nPila resultado:\n");
    p_mostrar(p);
    printf("\n\n");
    pausar();
}

void ejercicio2_e(Pila p){
    printf("\nPILA ORIGINAL:\n\t");
    p_mostrar(p);
    if (p_es_vacia(p)){
        printf("\nLa pila esta vacia, no se puede duplicar.\n");
        printf("\n\n");
        pausar();
        return;
    }
    p = p_ej2_duplicar(p);
    printf("Pila duplicada:\n");
    p_mostrar(p);
    printf("\n\n");
    pausar();
}

void ejercicio2_f(Pila p){
    printf("\nPILA ORIGINAL:\n\t");
    p_mostrar(p);
    int cantidad = p_ej2_cantidadelementos(p);
    printf("La pila tiene %d elementos.\n", cantidad);
    printf("\n\n");
    pausar();
}

void ejercicio2(){
    printf("-- 2. VALORES CARGADOS AL AZAR --\n\n");
    Pila p = p_crear();
    printf("\n\tSI DESEA CARGAR LA PILA AL AZAR, INGRESE 1, SI DESEA CARGARLA MANUALMENTE, INGRESE 2: ");
    int opcion = leer_entero();
    while (opcion != 1 && opcion != 2){
        printf("\nOpcion no valida. Ingrese 1 para cargar al azar, o 2 para cargar manualmente: ");
        opcion = leer_entero();
    }
    if (opcion == 1){
        p = llenarpilasauto(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }
    else{
        p = llenarpilas(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }
    printf("\n\n");
    pausar();
    bool volver = false;
    while (!volver){
        printf("\n\nSELECCIONE EL EJERCICIO A REALIZAR:\n");
        printf("\t1) Buscar un elemento.\n");
        printf("\t2) Colocar un elemento en una posicion ordinal dada.\n");
        printf("\t3) Eliminar un elemento dado por su clave.\n");
        printf("\t4) Intercambiar los valores de dos posiciones ordinales.\n");
        printf("\t5) Duplicar el contenido de una pila.\n");
        printf("\t6) Contar los elementos de la pila.\n");  
        printf("\n\t0) Volver al menu principal.\n");
        printf("\nIngrese el numero del ejercicio a ejecutar (0-6): ");

        int ejercicio = leer_entero();
        while (ejercicio < 0 || ejercicio > 6){
            printf("Error. Ingrese un numero entre 0 y 6: ");
            ejercicio = leer_entero();
        } 
        switch (ejercicio){
            case 1:
                limpiarPantalla();
                printf("-- 2.a) BUSCAR UN ELEMENTO --\n\n");
                ejercicio2_a(p);
                break;
            case 2:
                limpiarPantalla();
                printf("-- 2.b) COLOCAR UN ELEMENTO EN UNA POSICION ORDINARIA DADA --\n\n");
                ejercicio2_b(p);
                break;
            case 3:
                limpiarPantalla();
                printf("-- 2.c) ELIMINAR UN ELEMENTO DADO POR SU CLAVE --\n\n");
                ejercicio2_c(p);
                break;
            case 4:
                limpiarPantalla();
                printf("-- 2.d) INTERCAMBIAR LOS VALORES DE DOS POSICIONES ORDINARIAS --\n\n");
                ejercicio2_d(p);
                break;
            case 5:
                limpiarPantalla();
                printf("-- 2.e) DUPLICAR EL CONTENIDO DE UNA PILA --\n\n");
                ejercicio2_e(p);
                break;
            case 6:
                limpiarPantalla();
                printf("-- 2.f) CONTAR LOS ELEMENTOS DE LA PILA --\n\n");
                ejercicio2_f(p);
                break;
            case 0:
                volver = true;
                break;
            default:
                limpiarPantalla();
                printf("No existe esa opcion!\n");
        }
    }
}


void ejercicio3(){
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    int opcion = elegirllenar();
    if (opcion == 1){
        p1 = llenarpilasauto(p1);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p1);
    }
    else{
        p1 = llenarpilas(p1);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p1);
    }
    printf("\n\n PROCEDAMOS A CARGAR LA SEGUNDA PILA:\n\n");
    opcion = elegirllenar();
    if (opcion == 1){
        p2 = llenarpilasauto(p2);
        printf("\nPILA CARGADA !!!\n\t ");
    }
    else{
        p2 = llenarpilas(p2);
        printf("\nPILA CARGADA !!!\n\t ");
    }
    pausar();    
    printf("------------------------------------------------------");
    printf("\n\n PILA 1 ORIGINAL:\n\t ");
    p_mostrar(p1);
    printf("\n\n PILA 2 ORIGINAL:\n\t ");
    p_mostrar(p2);
    if (p_ej3_iguales(p1, p2)) {
        printf("\n[RESULTADO] -> Las pilas son EXACTAMENTE IGUALES.\n");
    } else {
        printf("\n[RESULTADO] -> Las pilas son DIFERENTES.\n");
    }
    printf("\n\n");
    pausar();
}

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
        printf("\n\n");
        pausar();
        return;
    }
    printf("\nEl numero %d en base %d es: %s\n", nrobasedecimal, nrootrabase, resultado);
    free(resultado);
    printf("\n\n");
    pausar();

}

void ejercicio5(){
    Pila p = p_crear();
    int opcion = elegirllenar();
    if (opcion == 1){
        p = llenarpilasauto(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }
    else{
        p = llenarpilas(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }
    Pila Pinvertida = p_ej5_invertir(p);
    printf("\nPila invertida:\n");
    p_mostrar(Pinvertida);
    printf("\n\n");
    pausar();
}


void ejercicio6(){
    Pila p = p_crear();
    Pila nuevaPila = p_crear();
    int opcion = elegirllenar();
    if (opcion == 1){
        p = llenarpilasauto(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }
    else{
        p = llenarpilas(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }

    if (!p_es_vacia(p)){
        printf("\nINGRESE EL NUMERO (clave) A ELIMINAR DE LA PILA: ");
        int clave = leer_entero();
        printf("\n Si desea realizar el ejercicio ITERATIVAMENTE, ingrese 1, si desea realizarlo RECURSIVAMENTE, ingrese 2: ");
        int opcion = leer_entero();
        while (opcion != 1 && opcion != 2){
            printf("\nOpcion no valida. Ingrese 1 para ITERATIVO, o 2 para RECURSIVO: ");
            opcion = leer_entero();
        }
        if (opcion == 1){
            nuevaPila = p_ej6_eliminarclave(p, clave);
            printf("\nPILA ACTUALIZADA :\n\t",clave);
            p_mostrar(nuevaPila);
            printf("\n\n");
            pausar();
        }
        else{
            nuevaPila = p_ej6_eliminarclave_recprincipal(p, clave);
            printf("\nPILA ACTUALIZADA :\n\t",clave);
            p_mostrar(nuevaPila);
            printf("\n\n");
            pausar();
        }
    }
    else{
        printf("\nLa pila esta vacia, no se puede eliminar ningun elemento.\n");
        printf("\n\n");
        pausar();
        return;
    }
    
}


void ejercicio7(){
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    Pila nueva = p_crear();
    printf("\n LLENANDO LA PILA 1:\n");
    int opcion = elegirllenar();
    if (opcion == 1){
        p1 = llenarpilasauto(p1);
        printf("\nPILA CARGADA !!!\n\t ");
    }
    else{
        p1 = llenarpilas(p1);
        printf("\nPILA CARGADA !!!\n\t ");
    }
    printf("\n LLENANDO LA PILA 2:\n");
    opcion = elegirllenar();
    if (opcion == 1){
        p2 = llenarpilasauto(p2);
        printf("\nPILA CARGADA !!!\n\t ");
    }
    else{
        p2 = llenarpilas(p2);
        printf("\nPILA CARGADA !!!\n\t ");
    }
    printf("------------------------------------------------------");
    printf("\n\n PILA 1 ORIGINAL:\n\t ");
    p_mostrar(p1);
    printf("\n\n PILA 2 ORIGINAL:\n\t ");
    p_mostrar(p2);

    nueva = p_ej7_elementoscomunes(p1,p2);
    printf("\n\n PILA CON LOS ELEMENTOS COMUNES ENTRE P1 Y P2 :\n\t");
    p_mostrar(nueva);
    printf("\n\n");
    pausar();
}


void ejercicio8(){
    Pila p = p_crear();
    Pila nueva_pila = p_crear();
    int opcion = elegirllenar();
    if (opcion == 1){
        p = llenarpilasauto(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }
    else{
        p = llenarpilas(p);
        printf("\nPILA CARGADA !!!\n\t ");
        p_mostrar(p);
    }

    nueva_pila = p_ej8_sacarrepetidos(p);
    printf("\n\n PILA SIN REPETIDOS: \n\t");
    p_mostrar_con_valor(nueva_pila);
    printf("\n\n");
    pausar();
}

