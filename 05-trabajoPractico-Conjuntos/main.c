#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "tp_conjunto.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/validaciones/headers/validaciones.h"

// menu
void mostrarMenu();
void ingresarOpcion(char *ingresado, int *nro_elegido);

// funciones inicializadoras
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();

// ------------------ AUXILIARES ------------------
void cargarConjunto(Conjunto conjunto) { 
    char input_buffer[100];
    int numero_deseado;
    int cont_elem_cargados = 0;
    printf("(Ingrese '.' para salir)\n");

    do {
        printf("Valor a cargar en el conjunto: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        if (numero_valido(input_buffer) == 1) {
            numero_deseado = str_a_int(input_buffer);
            cto_agregar(conjunto, te_crear(numero_deseado));
            cont_elem_cargados++;
        }
        else {
            if (input_buffer[0] != '.') {
                printf("El valor debe ser un ENTERO VALIDO.\n");
            }
        }
    } while (input_buffer[0] != '.' && !cto_es_lleno(conjunto));
}

void cargarConjuntoNaturales(Conjunto conjunto){ 
    char numero_natural[100];
    int numero_deseado;
    int cont_elem_cargados = 0;
    printf("(Ingrese '.' para salir)\n");

    do {
        printf("Valor a cargar en el conjunto: ");
        fgets(numero_natural, sizeof(numero_natural), stdin);

        if (numero_valido(numero_natural) == 1) {
            numero_deseado = str_a_int(numero_natural);

            if (numero_deseado >= 0) {
                cto_agregar(conjunto, te_crear(numero_deseado));
                cont_elem_cargados++;
            }
            else {
                printf("Debe ser un numero natural (mayor o igual a 0)!\n");
                continue;
            }
        }
        else {
            if (numero_natural[0] != '.') {
                printf("El valor debe ser un ENTERO NATURAL VALIDO.\n");
            }
        }
    } while (numero_natural[0] != '.' && !cto_es_lleno(conjunto));
}

void cargarListaConjuntos(Lista listaConjuntos){
    char entero[20];
    int numero_deseado;
    Conjunto conjunto;
    int cantConjuntos = 0;

    do {
        printf("\nIngrese la cantidad de conjuntos que desea cargar en la lista (minimo 1): ");
        fgets(entero, sizeof(entero), stdin);
        cantConjuntos = str_a_int(entero);
        
        if (cantConjuntos < 1) {
            printf("Debe ingresar al menos 1 conjunto.\n");
        }
    } while (cantConjuntos < 1);

    for (int i = 0; i < cantConjuntos; i++) {
        printf("\nCONJUNTO:%d\n", i + 1);
        conjunto = cto_crear();
        cargarConjunto(conjunto);
        l_agregar(listaConjuntos, te_crear_con_valor(0, conjunto));
    }

    printf("Se cargaron %d conjuntos en la lista.\n" , cantConjuntos);
}

void mostrarMenu() {
    printf("\n\n\n------ TP5: CONJUNTOS ------\n\n");
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

void ejercicio2() {
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    char inputClave[20]; int clave;
    
    printf("\n[Carga del conjunto A]\n");
    cargarConjunto(A);
    printf("\n[Carga del conjunto B]\n");
    cargarConjunto(B);

    do {
        printf("\nClave a buscar: ");
        fgets(inputClave, sizeof(inputClave), stdin);

        if (!numero_valido(inputClave)) {
            printf("El valor debe ser un numero valido.\n");
        }
    } while (!numero_valido(inputClave));

    clave = str_a_int(inputClave);

    if (!clavePertenece(A, B, clave)) {
        printf("\nLa clave no pertenece a ningun conjunto!\n");
    }
    
    // union
    printf("\n----------------------------\n");
    printf("\n- UNION -\n");
    printf("\n[Conjunto A] "); cto_mostrar(A);
    printf("[Conjunto B] "); cto_mostrar(B);
    
    Conjunto unionConjuntos = c_ej2_union(A, B);
    printf("\nUnion de A y B: ");
    cto_mostrar(unionConjuntos);
    printf("\n----------------------------\n");
    
    // interseccion
    printf("\n- INTERSECCION -\n");
    printf("\n[Conjunto A] "); cto_mostrar(A);
    printf("[Conjunto B] "); cto_mostrar(B);

    Conjunto interseccionConjuntos = c_ej2_interseccion(A, B);
    printf("\nInterseccion de A y B: ");
    cto_mostrar(interseccionConjuntos);
    printf("\n----------------------------\n");

    // diferencia
    printf("\n- DIFERENCIA -\n");
    printf("\n[Conjunto A] "); cto_mostrar(A);
    printf("[Conjunto B] "); cto_mostrar(B);

    printf("\nDiferencia de A y B: \n");
    Conjunto diferenciaConjuntos = c_ej2_diferencia(A, B);
    cto_mostrar(diferenciaConjuntos);

    printf("\nDiferencia B y A:\n");
    Conjunto diferenciaBa = c_ej2_diferencia(B, A);
    cto_mostrar(diferenciaBa);

    printf("\n\n");
    pausar();
}


void ejercicio3() {
    Lista listaConjuntos = l_crear();
    cargarListaConjuntos(listaConjuntos);

    printf("\nUniones de los conjuntos de la coleccion:\n");
    Conjunto conjuntoUniones = c_ej3_uniones(listaConjuntos);
    cto_mostrar(conjuntoUniones);

    printf("\n----------------------------\n");

    Conjunto conjuntoIntersecciones = c_ej3_intersecciones(listaConjuntos);
    if (cto_es_vacio(conjuntoIntersecciones)) {
        printf("\nNo hay intersecciones!\n");
    }
    else {
        printf("\nIntersecciones de los conjuntos de la lista:\n");
        cto_mostrar(conjuntoIntersecciones); // 
    }  

    printf("\n\n");
    pausar();
}

void ejercicio4(){
    Conjunto A = cto_crear();
	Conjunto B = cto_crear();
	Conjunto C = cto_crear();

    printf("\n[Carga del conjunto A]\n");
    cargarConjuntoNaturales(A);
    printf("\n[Carga del conjunto B]\n");
	cargarConjuntoNaturales(B);
	printf("\n[Carga del conjunto C]\n");
	cargarConjuntoNaturales(C);

    if (c_ej4_transitividad(A, B, C)) printf("\nA es subconjunto de C -> se cumple la transitividad\n");
    else printf("\nNO se cumple la transitividad.\n");

    printf("\n\n");
    pausar();

}

void ejercicio5(){
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
 
    printf("\n[Carga del conjunto A]\n");
    cargarConjunto(A);
    printf("\n[Carga del conjunto B]\n");
    cargarConjunto(B);

    printf("\n[Conjunto A] "); cto_mostrar(A);
    printf("\n[Conjunto B] "); cto_mostrar(B);
 
    Conjunto resultado = c_ej5_dif_simetrica(A, B);
 
    if (cto_es_vacio(resultado)) printf("\nLos conjuntos son simetricos. La diferencia simetrica es un conjunto vacio.\n");

    else {
        printf("\nLa diferencia simetrica contiene los elementos: \n");
        cto_mostrar(resultado);       
    }

    printf("\n\n");
    pausar();
}

void ejercicio6(){
    Conjunto A = cto_crear();
	Conjunto B = cto_crear();

    printf("\n[Carga del conjunto A]\n");
    cargarConjuntoNaturales(A);
    printf("\n[Carga del conjunto B]\n");
	cargarConjuntoNaturales(B);

	printf("\n[Conjunto A] "); cto_mostrar(A);
	printf("\n[Conjunto B] "); cto_mostrar(B);
	printf("\n");

	if (cto_es_vacio(A) && cto_es_vacio(B))  printf("\nAmbos conjuntos estan vacios, por lo que ninguno es subconjunto propio del otro.\n");
		
	else if (!c_ej6_subconjuntopropio(A,B)) printf("\nNinguno de los conjuntos es un subconjunto propio del otro.\n");

    printf("\nComplejidad: Sin TAD: O(1) --> Constante (sin tener en cuenta cto_interseccion); sino O(n^2) --> Cuadratica.\nCon TAD Conj. Listas: O(n^2) --> Cuadratica\n");

    printf("\n\n");
    pausar();
}


void ejercicio7() {
    Conjunto A = cto_crear();
	Conjunto B = cto_crear();
	Conjunto C = cto_crear();

    printf("\n[Carga del conjunto A]\n");
    cargarConjuntoNaturales(A);
    printf("\n[Carga del conjunto B]\n");
	cargarConjuntoNaturales(B);
	printf("\n[Carga del conjunto C]\n");
	cargarConjuntoNaturales(C);

	printf("\n[Conjunto A] "); cto_mostrar(A);
	printf("\n[Conjunto B] "); cto_mostrar(B);
	printf("\n[Conjunto C] "); cto_mostrar(C);
	printf("\n");

    c_ej7_subconjtotalparcial(A, B, C);

    printf("\nComplejidad: sin TAD): O(1) --> constante (sin tener en cuenta cto_diferencia); sino O(n^2) --> cuadratica\nCon TAD Conj. Listas: O(n^2).\n");

    printf("\n\n");
    pausar();
}


void ejercicio8(){
    
    printf("\n\n");
    pausar();
}