#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_conjunto.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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