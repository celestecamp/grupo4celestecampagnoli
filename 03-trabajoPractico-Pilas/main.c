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
void ejercicio2_a();
void ejercicio2_b();
void ejercicio2_c();
void ejercicio2_d();
void ejercicio2_e();
void ejercicio2_f();
//void ejercicio3();
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
    printf("6 - Eliminar un elemento\n");
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
                ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. OCURRENCIAS DE UN ELEMENTO --\n\n");
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

void ejercicio2_a(){
    Pila p = p_crear();
    for (int i = 0; i < 6; i++)
        p_apilar(p, te_crear(rand() % 99 + 1));
    p_mostrar(p);
    printf("Ingrese la clave a buscar: ");
    int clave = leer_entero();
    bool existe = p_ej2_existeclave(p, clave);
    printf("La clave %d %s en la pila.\n", clave, existe ? "EXISTE" : "NO existe");
}

void ejercicio2_b(){
    Pila p = p_crear();
    for (int i = 0; i < 5; i++)
        p_apilar(p, te_crear(rand() % 99 + 1));
    p_mostrar(p);
    printf("Ingrese la posicion donde insertar (1 = fondo): ");
    int pos = leer_entero();
    printf("Ingrese la clave del nuevo elemento: ");
    int clave = leer_entero();
    p = p_ej2_colocarelemento(p, pos, te_crear(clave));
    printf("\nPila resultado:\n");
    p_mostrar(p);
}

void ejercicio2_c(){
    Pila p = p_crear();
    for (int i = 0; i < 6; i++)
        p_apilar(p, te_crear(rand() % 99 + 1));
    p_mostrar(p);
    printf("Ingrese la clave a eliminar: ");
    int clave = leer_entero();
    p = p_ej2_eliminarclave(p, clave);
    printf("\nPila resultado:\n");
    p_mostrar(p);
}

void ejercicio2_d(){
    Pila p = p_crear();
    for (int i = 0; i < 6; i++)
        p_apilar(p, te_crear(rand() % 99 + 1));
    p_mostrar(p);
    printf("Ingrese la primera posicion (1 = fondo): ");
    int pos1 = leer_entero();
    printf("Ingrese la segunda posicion: ");
    int pos2 = leer_entero();
    p = p_ej2_intercambiarposiciones(p, pos1, pos2);
    printf("\nPila resultado:\n");
    p_mostrar(p);
}

void ejercicio2_e(){
    Pila p = p_crear();
    for (int i = 0; i < 4; i++)
        p_apilar(p, te_crear(rand() % 99 + 1));
    printf("Pila original:\n");
    p_mostrar(p);
    p = p_ej2_duplicar(p);
    printf("Pila duplicada:\n");
    p_mostrar(p);
}

void ejercicio2_f(){
    Pila p = p_crear();
    for (int i = 0; i < 7; i++)
        p_apilar(p, te_crear(rand() % 99 + 1));
    p_mostrar(p);
    int cantidad = p_ej2_cantidadelementos(p);
    printf("La pila tiene %d elementos.\n", cantidad);
}

void ejercicio2(){
    ejercicio2_a();
    pausar();
    ejercicio2_b();
    pausar();
    ejercicio2_c();
    pausar();
    ejercicio2_d();
    pausar();
    ejercicio2_e();
    pausar();
    ejercicio2_f();
}

void ejercicio3(){
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    printf("\nVamos a comprobar si dos pilas son exactamente iguales\n");
    printf("\nIngrese la cantidad de elementos a cargar en la Pila 1 (1-10): ");
    int cant1 = leer_entero();
    p1 = llenarpilas(p1, cant1);
    printf("\nIngrese la cantidad de elementos a cargar en la Pila 2 (1-10): ");
    int cant2 = leer_entero();
    p2 = llenarpilas(p2, cant2);
    printf("\nPila 1 original:\n");
    p_mostrar(p1);
    printf("\nPila 2 original:\n");
    p_mostrar(p2);
    if (p_ej3_iguales(p1, p2)) {
        printf("\n[RESULTADO] -> Las pilas son EXACTAMENTE IGUALES.\n");
    } else {
        printf("\n[RESULTADO] -> Las pilas son DIFERENTES.\n");
    }
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
        pausar();
        return;
    }
    printf("\nEl numero %d en base %d es: %s\n", nrobasedecimal, nrootrabase, resultado);
    free(resultado);

    pausar();

}

void ejercicio5(){
    Pila p = p_crear();
    printf("Ingrese la cantidad de elementos a cargar en la pila: (1-10)");
    int cantidad = leer_entero();
    p = llenarpilas(p,cantidad);
    printf("\nPila original:\n");
    p_mostrar(p);
    Pila Pinvertida = p_ej5_invertir(p);
    printf("\nPila invertida:\n");
    p_mostrar(Pinvertida);
}


void ejercicio6(){
Pila p = p_crear();
    printf("Ingrese la cantidad de elementos a cargar en la pila: (1-10)");
    int cantidad = leer_entero();
    p = llenarpilas(p,cantidad);
    printf("\nPila original:\n");
    p_mostrar(p);
    printf("\nIngrese el numero a eliminar de la pila: ");
    int clave = leer_entero();

    printf("\n Si desea realizar el ejercicio iterativamente, ingrese 1, si desea realizarlo recursivamente, ingrese 2: ");
    int opcion = leer_entero();
    while (opcion != 1 && opcion != 2){
        printf("\nOpcion no valida. Ingrese 1 para iterativo, o 2 para recursivo: ");
        opcion = leer_entero();
    }
    if (opcion == 1){
        Pila nuevaPila = p_ej6_eliminarclave(p, clave);
        printf("\nPila actualizada:\n");
        p_mostrar(nuevaPila);
    }
    else{
        Pila nuevaPila = p_ej6_eliminarclave_recprincipal(p, clave);
        printf("\nPila actualizada:\n");
        p_mostrar(nuevaPila);
    }
}


void ejercicio7(){
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    Pila res;
    int cant1, cant2;
    int i, num;

    printf("\nVamos a hacer ej. 7!\n");

    printf("Cuantos elementos vas a tener en pila 1?\n");
    cant1 = leerEnteroEnRango(0, 10);

    printf("Bueno, cuantos elementos vas a tener en pila 2?\n");
    cant2 = leerEnteroEnRango(0, 10);

    printf("Ingresa los elementos para pila 1 (solo enteros positivos):\n");
    for (i = 0; i < cant1; i++) {
        printf("Elemento %d: ", i + 1);
        num = leer_entero_positivo();
        p_apilar(p1, te_crear(num));
    }

    printf("Pila 1 cargada!\n");

    printf("Ahora ingresa los elementos para pila 2 (solo enteros positivos):\n");
    for (i = 0; i < cant2; i++) {
        printf("Elemento %d: ", i + 1);
        num = leer_entero_positivo();
        p_apilar(p2, te_crear(num));
    }

    printf("Pila 2 cargada!\n");
    printf("Vamos a ver los elementos comunes:\n");

    res = p_ej7_elementoscomunes(p1, p2);
    p_mostrar(res);

    printf("\nPresione ENTER para volver al menu principal\n");
    getchar();
}


void ejercicio8(){
    Pila p = p_crear();
    Pila res;
    int cant, i, num;

    printf("\nVamos a hacer ej. 8!\n");

    printf("Cuantos elementos vas a tener en la pila?\n");
    cant = leerEnteroEnRango(0, 10);

    printf("Ingresa los elementos de la pila:\n");
    for (i = 0; i < cant; i++) {
        printf("Elemento %d: ", i + 1);
        num = leer_entero_positivo();
        p_apilar(p, te_crear(num));
    }

    printf("Pila cargada!\n");
    printf("Vamos a sacar los repetidos:\n");

    res = p_ej8_sacarrepetidos(p);
    p_mostrar_clave_valor(res);

    printf("\nPresione ENTER para volver al menu principal\n");
    getchar();
}

