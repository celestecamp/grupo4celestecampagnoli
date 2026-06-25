#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_conjunto.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Conjunto c_ej2_union(Conjunto A, Conjunto B) {
    Conjunto conjuntoUnion = cto_crear();
    conjuntoUnion = cto_union(A , B);
    return conjuntoUnion;
}

Conjunto c_ej2_diferencia(Conjunto A , Conjunto B){
    Conjunto conjuntoDiferencia = cto_crear();
    conjuntoDiferencia = cto_diferencia(A , B);
    return conjuntoDiferencia;
}

Conjunto c_ej2_interseccion(Conjunto A , Conjunto B){
    Conjunto conjuntoInterseccion = cto_crear();
    conjuntoInterseccion = cto_interseccion(A , B);

    return conjuntoInterseccion;
}

bool clavePertenece(Conjunto A, Conjunto B, int clave){
    bool resultado = false;

    if (cto_pertenece(A, clave)) {
        printf("\nLa clave pertenece al conjunto A.");
        resultado = true;
    }
         
    if (cto_pertenece(B, clave)) {
        printf("\nLa clave pertenece al conjunto B.");
        resultado = true;
    }

    return resultado;
}

Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Conjunto conjunto;
    Iterador ite = iterador(l_de_conjuntos);
    Conjunto conjResultante = cto_crear();
    TipoElemento elem;

    while (hay_siguiente(ite)) {
        elem = siguiente(ite);
        conjunto = (Conjunto)elem->valor;
        conjResultante = cto_union(conjResultante, conjunto);
    }

    return conjResultante;   
}

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    Conjunto conjunto;
    Iterador ite = iterador(l_de_conjuntos);
    Conjunto conjResultante = cto_crear();
    TipoElemento elem;

    bool esPrimerConjunto = true;

    while (hay_siguiente(ite)) {
        elem = siguiente(ite);
        conjunto = (Conjunto) elem->valor;

        if (esPrimerConjunto) {
            //copiar todo el primer cto para no tener interseccion vacia
            conjResultante = cto_union(conjResultante, conjunto);
            esPrimerConjunto = false;
        }

        conjResultante = cto_interseccion(conjResultante, conjunto);        
    }
        
    return conjResultante;
}

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){
    if (cto_es_vacio(A) && cto_es_vacio(B) && cto_es_vacio(C)) {
        printf("\nTodos los conjuntos son vacios.");
        return true;
    }
        
    bool aEsSubconjuntoDeB = false;
    Conjunto ABsubconjunto = cto_interseccion(A, B);
    if ((cto_cantidad_elementos(A)) == (cto_cantidad_elementos(ABsubconjunto))) {
        aEsSubconjuntoDeB = true;
        printf("\nA es subconjunto de B\n");
         
        bool bEsSubconjuntoDeC = false;
        Conjunto BCsubconjunto = cto_interseccion(B, C);
        if ((cto_cantidad_elementos(B)) == (cto_cantidad_elementos(BCsubconjunto))) {
            bEsSubconjuntoDeC = true;
            printf("\nB es subconjunto de C\n");

            bool aEsSubconjuntoDeC = false;
            Conjunto ACsubconjunto = cto_interseccion(A, C);
            if ((cto_cantidad_elementos(A)) == (cto_cantidad_elementos(ACsubconjunto))) {
                aEsSubconjuntoDeC = true;
                printf("\nA es subconjunto de C\n");
                return true;
            }
            else {
                printf("\nNo se cumple la transitividad\n");
                return false; 
            }
        }
        else {
            printf("\nB NO es subconjunto de C\n");
            return false;     
        }
    }
    else {
        printf("\nA NO es subconjunto de B\n");
        return false; 
    }
}

Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    if (cto_es_vacio(A) && cto_es_vacio(B)) {
        Conjunto conjuntoVacio = cto_crear();
        return conjuntoVacio;
    }

    if (cto_es_vacio(A)) return cto_union(B ,A);

    if (cto_es_vacio(B)) return cto_union(A ,B);
    
    Conjunto diferenciaAB = cto_crear();
    Conjunto diferenciaBA = cto_crear();
         
    diferenciaAB = cto_diferencia(A, B);
    diferenciaBA = cto_diferencia(B, A);

    Conjunto resultado = cto_crear();

    resultado = cto_union(diferenciaAB, diferenciaBA);
         
    return resultado;
}

bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B) {
    Conjunto interseccionAB = cto_interseccion(A , B);	

	if (cto_cantidad_elementos(A) < cto_cantidad_elementos(B)) {
		if (cto_cantidad_elementos(interseccionAB) == cto_cantidad_elementos(A)) {
			printf("\nEl conjunto A es un subconjunto propio del conjunto B\n");
			return true;
		}
        return false;
	}

    else if (cto_cantidad_elementos(B) < cto_cantidad_elementos(A)) {
		if (cto_cantidad_elementos(interseccionAB) == cto_cantidad_elementos(B)) {
		    printf("\nEl conjunto B es un subconjunto propio del conjunto A\n");
			return true;
		}
		return false;
	}
    
    else return false;
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C) {
	int cantA = cto_cantidad_elementos(A);
	int cantB = cto_cantidad_elementos(B);
	int cantC = cto_cantidad_elementos(C);

	if (cantA == cantB && cantB == cantC &&
    cto_cantidad_elementos(cto_diferencia(A, B)) == 0 &&
    cto_cantidad_elementos(cto_diferencia(B, A)) == 0 &&
    cto_cantidad_elementos(cto_diferencia(A, C)) == 0 &&
    cto_cantidad_elementos(cto_diferencia(C, A)) == 0) {
    	printf("Los subconjuntos son IGUALES. Todos son subconjuntos totales entre si.\n");
		return;
	}

	Conjunto dif_AB = cto_diferencia(A, B);
	Conjunto dif_BA = cto_diferencia(B, A);
	Conjunto dif_AC = cto_diferencia(A, C);
	Conjunto dif_CA = cto_diferencia(C, A);
	Conjunto dif_BC = cto_diferencia(B, C);
	Conjunto dif_CB = cto_diferencia(C, B);

	int al_menos_uno = 0;
	
	if (cto_es_vacio(A)) {
		printf("A es subconjunto total de todos por ser vacio.\n");
		al_menos_uno++;
	}
	else {
		// A y B
		int cant_AB = cto_cantidad_elementos(dif_AB);
		if (cant_AB == 0) {
			printf("A es subconjunto TOTAL de B.\n");
			al_menos_uno++;
		}
		else if (2 * (cantA - cant_AB) >= cantA) {
			printf("A es subconjunto PARCIAL de B.\n");
			al_menos_uno++;
		}
	
		// A y C
		int cant_AC = cto_cantidad_elementos(dif_AC);
		if (cant_AC == 0) {
			printf("A es subconjunto TOTAL de C.\n");
			al_menos_uno++;
		}
		else if (2 * (cantA - cant_AC) >= cantA) {
			printf("A es subconjunto PARCIAL de C.\n");
			al_menos_uno++;
		}
	}

	if (cto_es_vacio(B)) {
		printf("B es subconjunto total de todos por ser vacio.\n");
		al_menos_uno++;
	}
	else {
		// B y A
		int cant_BA = cto_cantidad_elementos(dif_BA);
		if (cant_BA == 0) {
			printf("B es subconjunto TOTAL de A.\n");
			al_menos_uno++;
		}
		else if (2 * (cantB - cant_BA) >= cantB) {
			printf("B es subconjunto PARCIAL de A.\n");
			al_menos_uno++;
		}
		
		// B y C
		int cant_BC = cto_cantidad_elementos(dif_BC);
		if (cant_BC == 0) {
			printf("B es subconjunto TOTAL de C.\n");
			al_menos_uno++;
		}
		else if (2 * (cantB - cant_BC) >= cantB) {
			printf("B es subconjunto PARCIAL de C.\n");
			al_menos_uno++;
		}
	}	
	
	if (cto_es_vacio(C)) {
		printf("C es subconjunto total de todos por ser vacio.\n");
		al_menos_uno++;
	}
	else {
		// C y A
		int cant_CA = cto_cantidad_elementos(dif_CA);
		if (cant_CA == 0){
			printf("C es subconjunto TOTAL de A.\n");
			al_menos_uno++;
		}
		else if (2 * (cantC - cant_CA) >= cantC) {
			printf("C es subconjunto PARCIAL de A.\n");
			al_menos_uno++;
		}
		
		// C y B
		int cant_CB = cto_cantidad_elementos(dif_CB);
		if (cant_CB == 0){
			printf("C es subconjunto TOTAL de B.\n");
			al_menos_uno++;
		}
		else if (2 * (cantC - cant_CB) >= cantC) {
			printf("C es subconjunto PARCIAL de B.\n");
			al_menos_uno++;
		}
	}

	if (al_menos_uno == 0) printf("Ningun conjunto es subconjunto de otro.\n");
}