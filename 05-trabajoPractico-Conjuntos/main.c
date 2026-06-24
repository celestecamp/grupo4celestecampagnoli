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
            printf("El valor debe ser un ENTERO VALIDO.\n");
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


void ejercicio7(){
    
    printf("\n\n");
    pausar();
}


void ejercicio8(){
    
    printf("\n\n");
    pausar();
}