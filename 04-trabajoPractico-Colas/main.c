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
    printf("\nCOLA ORIGINAL:\n\t");
    c_mostrar(c);
    if (c_es_vacia(c)){
        printf("\nLa cola esta vacia, no se puede buscar ningun elemento.\n");
        printf("\n\n");
        pausar();
        return;
    }
    printf("Ingrese la clave a buscar: ");
    int clave = leer_entero();
    bool existe = c_ej2_existeclave(c, clave);
    printf("La clave %d %s en la cola.\n", clave, existe ? "EXISTE" : "NO existe");
    printf("\n\n");
    pausar();
}

void ejercicio2_b(Cola c){
    printf("\nCOLA ORIGINAL:\n\t");
    c_mostrar(c);
    printf("Ingrese la posicion donde insertar (1 = FRENTE): ");
    int pos = leer_entero();
    printf("Ingrese la clave del nuevo elemento: ");
    int clave = leer_entero();
    c = c_ej2_colarelemento(c, pos, te_crear(clave));
    printf("\nCola resultado:\n");
    c_mostrar(c);
    printf("\n\n");
    pausar();
}

void ejercicio2_c(Cola c){
    printf("\nCOLA ORIGINAL:\n\t");
    c_mostrar(c);
    if (c_es_vacia(c)){
        printf("\nLa cola esta vacia, no se puede eliminar ningun elemento.\n");
        printf("\n\n");
        pausar();
        return;
    }
    printf("Ingrese la clave a eliminar: ");
    int clave = leer_entero();
    c = c_ej2_sacarelemento(c, clave);
    printf("\nCola resultado:\n");
    c_mostrar(c);
    printf("\n\n");
    pausar();
}

void ejercicio2_d(Cola c){
    printf("\nCOLA ORIGINAL:\n\t");
    c_mostrar(c);
    int cantidad = c_ej2_contarelementos(c);
    printf("La cola tiene %d elementos.\n", cantidad);
    printf("\n\n");
    pausar();
}

void ejercicio2_e(Cola c){
    printf("\nCOLA ORIGINAL:\n\t");
    c_mostrar(c);
    if (c_es_vacia(c)){
        printf("\nLa cola esta vacia, no se puede copiar.\n");
        printf("\n\n");
        pausar();
        return;
    }
    Cola copia = c_ej2_copiar(c);
    printf("Cola copia:\n");
    c_mostrar(copia);
    printf("\n\n");
    pausar();
}

void ejercicio2_f(Cola c){
    printf("\nCOLA ORIGINAL:\n\t");
    c_mostrar(c);
    if (c_es_vacia(c)){
        printf("\nLa cola esta vacia, no se puede invertir.\n");
        printf("\n\n");
        pausar();
        return;
    }
    Cola invertida = c_ej2_invertir(c);
    printf("Cola invertida:\n");
    c_mostrar(invertida);
    printf("\n\n");
    pausar();
}

void ejercicio2(){
    printf("-- 2. VALORES CARGADOS AL AZAR --\n\n");
    Cola c = c_crear();
    printf("\n\tSI DESEA CARGAR LA COLA AL AZAR, INGRESE 1, SI DESEA CARGARLA MANUALMENTE, INGRESE 2: ");
    int opcion = leer_entero();
    while (opcion != 1 && opcion != 2){
        printf("\nOpcion no valida. Ingrese 1 para cargar al azar, o 2 para cargar manualmente: ");
        opcion = leer_entero();
    }
    if (opcion == 1){
        c = llenarcolasauto(c);
        printf("\nCOLA CARGADA !!!\n\t ");
        c_mostrar(c);
    }
    else{
        c = llenarcolasmanual(c);
        printf("\nCOLA CARGADA !!!\n\t ");
        c_mostrar(c);
    }
    printf("\n\n");
    pausar();
    bool volver = false;
    while (!volver){
        printf("\n\n-------------------- MENU DEL PUNTO 2 ----------------------------------");
        printf("\n\nSELECCIONE EL EJERCICIO A REALIZAR:\n");
        printf("\t1) Buscar un elemento.\n");
        printf("\t2) Colar un elemento en una posicion ordinal dada.\n");
        printf("\t3) Sacar un elemento dado por su clave.\n");
        printf("\t4) Contar los elementos de la cola.\n");
        printf("\t5) Copiar la cola.\n");
        printf("\t6) Invertir la cola.\n");
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
                ejercicio2_a(c);
                break;
            case 2:
                limpiarPantalla();
                printf("-- 2.b) COLAR UN ELEMENTO EN UNA POSICION ORDINAL DADA --\n\n");
                ejercicio2_b(c);
                break;
            case 3:
                limpiarPantalla();
                printf("-- 2.c) SACAR UN ELEMENTO DADO POR SU CLAVE --\n\n");
                ejercicio2_c(c);
                break;
            case 4:
                limpiarPantalla();
                printf("-- 2.d) CONTAR LOS ELEMENTOS DE LA COLA --\n\n");
                ejercicio2_d(c);
                break;
            case 5:
                limpiarPantalla();
                printf("-- 2.e) COPIAR LA COLA --\n\n");
                ejercicio2_e(c);
                break;
            case 6:
                limpiarPantalla();
                printf("-- 2.f) INVERTIR LA COLA --\n\n");
                ejercicio2_f(c);
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
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    printf("\nLLENANDO LA COLA 1:\n");
    int opcion = elegirllenar_colas();
    if (opcion == 1){
        c1 = llenarcolasauto(c1);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    else{
        c1 = llenarcolasmanual(c1);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    printf("\nLLENANDO LA COLA 2:\n");
    opcion = elegirllenar_colas();
    if (opcion == 1){
        c2 = llenarcolasauto(c2);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    else{
        c2 = llenarcolasmanual(c2);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    printf("\n\n COLA 1 ORIGINAL:\n ");
    c_mostrar(c1);
    printf("\n\n COLA 2 ORIGINAL:\n ");
    c_mostrar(c2);
    bool iguales = c_ej3_iguales(c1, c2);
    printf("\nLas colas %s iguales.\n", iguales ? "SON" : "NO SON");
    printf("\n\n");
    pausar();
}

void ejercicio4(){
    Cola c = c_crear();
    printf("\nLLENANDO LA COLA:\n");
    int opcion = elegirllenar_colas();
    if (opcion == 1){
        c = llenarcolasauto(c);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    else{
        c = llenarcolasmanual(c);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    printf("\n\n COLA ORIGINAL:\n ");
    c_mostrar(c);
    Cola resultado = c_ej4_colanorepetidos(c);
    printf("\n\n COLA CON LOS ELEMENTOS NO REPETIDOS:\n ");
    c_mostrar(resultado);
    printf("\n\n");
    pausar();

}

void ejercicio5(){
    Cola c = c_crear();
    Cola nueva = c_crear();
    int opcion = elegirllenar_colas();
    if (opcion == 1){
        c = llenarcolasauto(c);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    else{
        c = llenarcolasmanual(c);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    printf("\n\n COLA ORIGINAL:\n ");
    c_mostrar(c);
    nueva = c_ej5_divisortotal(c);
    printf("\n\n COLA CON LOS DIVISORES TOTALES Y PARCIALES DE LOS ELEMENTOS DE LA COLA ORIGINAL:\n ");
    c_mostrar(nueva);
    printf("\n\n");
    while(!c_es_vacia(nueva)){
        TipoElemento teAux = c_desencolar(nueva);
        bool* valorBool = (bool*) teAux->valor;
        if(*valorBool == true){
            printf("El numero %d es un divisor total.\n", teAux->clave);
        }
        else{
            printf("El numero %d es un divisor parcial.\n", teAux->clave);
        }
    }
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
    Cola nueva = c_crear();
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    Cola c3 = c_crear();
    printf("\n LLENANDO LA COLA 1:\n");
    int opcion = elegirllenar_colas();
    if (opcion == 1){
        c1 = llenarcolasauto(c1);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    else{
        c1 = llenarcolasmanual(c1);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    printf("\n LLENANDO LA COLA 2:\n");
    opcion = elegirllenar_colas();
    if (opcion == 1){
        c2 = llenarcolasauto(c2);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    else{
        c2 = llenarcolasmanual(c2);
        printf("\nCOLA CARGADA !!!\n\t ");
    }
    printf("\n LLENANDO LA COLA 3:\n");
    opcion = elegirllenar_colas();
    if (opcion == 1){
        c3 = llenarcolasauto(c3);
        printf("\nCOLA CARGADA !!!\n ");
    }
    else{
        c3 = llenarcolasmanual(c3);
        printf("\nCOLA CARGADA !!!\n ");
    }
    printf("------------------------------------------------------");
    printf("\n\n COLA 1 ORIGINAL:\n ");
    c_mostrar(c1);
    printf("\n\n COLA 2 ORIGINAL:\n ");
    c_mostrar(c2);
    printf("\n\n COLA 3 ORIGINAL:\n ");
    c_mostrar(c3);
    if((c_longitud(c1) + c_longitud(c2) + c_longitud(c3)) >99){
        printf("La cantidad total de clientes supera el limite de 99, no se pueden atender mas clientes\n");
        printf("\n\n");
        pausar();
        return;
    }
    nueva = c_ej7_atenderclientes(c1,c2,c3,10);
    printf("\n\n ORDEN DE ATENCION DE LOS CLIENTES:\n");
    c_mostrar_con_valorstring(nueva);
    printf("\n\n");
    pausar();
}