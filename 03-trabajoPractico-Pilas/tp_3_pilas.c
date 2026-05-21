#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pilas/headers/pilas.h"
#include "tp_3_pilas.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// -----------------------  FUNCIONES AUXILIARES   ----------------------- 

void p_intercambiar(Pila P, Pila Paux){ // Pasamos el contenido de Paux a P, recordar que queda invertida, [A,B,C] -> [C,B,A]
    TipoElemento tipoAux;
    while (! p_es_vacia(Paux)){
        tipoAux = p_desapilar(Paux);
        p_apilar(P,tipoAux);
    }
    return;
}

int contarLongitud(Pila P, Pila Paux){ //Contamos elementos de 'P' desapilando y apilando en 'PAUX', luego llamamos a P_INTERCAMBIAR(P,Paux), QUEDAN LAS MISMAS PILAS ORIGINALES Y RETORNA LA LONGITUD
    int longitud = 0;
    TipoElemento tipoAux;
    while (! p_es_vacia(P)){
        tipoAux = p_desapilar(P);
        p_apilar(Paux,tipoAux);
        longitud++;
    }
    p_intercambiar(P,Paux);
    return longitud;
}


// -----------------------  FUNCIONES DE LOS EJERCICIOS   ----------------------- 

// EJERCICIO 2-a:
bool p_ej2_existeclave(Pila p, int clave){
    Pila aux= p_crear();
    bool encontrado= false;

    while (!p_es_vacia(p)){
        TipoElemento elemento= p_desapilar(p);
        if(elemento->clave == clave){
            encontrado= true;
        }

        p_apilar(aux, elemento);
    }

    while (!p_es_vacia(aux)){
        p_apilar(p, p_desapilar(aux));
    }

    return encontrado;
}

// EJERCICIO 2-b:

Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    
    Pila aux= p_crear();

    int i= 1;

    while(!p_es_vacia(p) && i<posicionordinal){
        p_apilar(aux, p_desapilar(p));
        i++;
    }

    p_apilar(p, x);

    while(!p_es_vacia(aux)){
        p_apilar(p, p_desapilar(aux));
    }

    return p;
}

// EJERCICIO 2-c:
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila aux= p_crear();

    bool encontrado= false;

    while (!p_es_vacia(p)){
        TipoElemento elemento= p_desapilar(p);
        if( elemento->clave== clave && !encontrado){
            encontrado= true;
        }
        else{
            p_apilar(aux, elemento);
        }
    }

    while(!p_es_vacia(aux)){
        p_apilar(p,p_desapilar(aux));
    }

    return p;
}

// EJERCICIO 2-d:
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    Pila aux= p_crear();

    TipoElemento elemento;
    TipoElemento valor1;
    TipoElemento valor2;

    int i=1;
    int total= 0;

    while(!p_es_vacia(p)){

        elemento= p_desapilar(p);
        
        if(i==pos1){
            valor1= elemento;
        }

        if(i==pos2){
            valor2= elemento;
        }

        p_apilar(aux, elemento);

        i++;
        total++;
    }

    i=1;

    while(!p_es_vacia(aux)){

        elemento= p_desapilar(aux);
        int posoriginal= total - i + 1;

        if(posoriginal==pos1){
            p_apilar(p, valor2);
        }

        else if(posoriginal==pos2){
            p_apilar(p, valor1);
        }

        else{
            p_apilar(p, elemento);
        }

        i++;
    }

    return p;
}

// EJERCICIO 2-e:
Pila p_ej2_duplicar(Pila p){
    Pila copia= p_crear();
    Pila aux= p_crear();
    
    TipoElemento elemento;

    while(!p_es_vacia(p)){
        elemento= p_desapilar(p);

        p_apilar(copia,elemento);
        p_apilar(aux, elemento);
    }

    while (!p_es_vacia(copia)){
        elemento= p_desapilar(copia);

        p_apilar(p,elemento);
    }

    while(!p_es_vacia(aux)){
        elemento= p_desapilar(aux);

        p_apilar(p, elemento);
    }

    return p;
}

// EJERCICIO 2-f:
int p_ej2_cantidadelementos(Pila p){
    
    int contador= 0;
    Pila aux= p_crear();
    TipoElemento elemento;
    while(!p_es_vacia(p)){
        elemento= p_desapilar(p);

        contador++;

        p_apilar(aux,elemento);
    }

    while(!p_es_vacia(aux)){
        p_apilar(p, p_desapilar(aux));
    }

    return contador;
}

// EJERCICIO 3:

// EJERCICIO 4:






// EJERCICIO 4:
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){

    if (nrootrabase < 2 || nrootrabase > 16){
        char* str = malloc(20);
        sprintf(str, "%d", nrobasedecimal);
        return str;
    }

    if (nrobasedecimal == 0){
        char* str = malloc(2);
        strcpy(str, "0");
        return str;
    }

    Pila p;
    TipoElemento teAux;
    p = p_crear();
    int n = nrobasedecimal;

    while (n > 0){
        int resto = n % nrootrabase;
        teAux = te_crear(resto);
        p_apilar(p, teAux);
        n = n / nrootrabase;
    }

    char* resultado = malloc(100);
    int i = 0;
    while (!p_es_vacia(p)){
        teAux = p_desapilar(p);
        if (teAux->clave < 10){
            resultado[i] = teAux->clave + '0';
        }
        else{
            resultado[i] = (teAux->clave - 10) + 'A';
        }
        i++;
    }
    resultado[i] = '\0';
    return resultado;

}
// COMPLEJIDAD ALGORITMICA EJERCICIO 4: O(log n) siendo N el numero decimal a convertir, ya que en el peor de los casos tenemos que dividir el numero entre la base hasta llegar a 0, y eso depende del numero decimal, osea N.



// EJERCICIO 5:
// EJERCICIO 6:
// EJERCICIO 7:

bool func_buscar(TipoElemento comparado, Pila p){
    if (p_es_vacia(p)==true){
        return false;
    }
    
    Pila pila_aux;
    pila_aux=p_crear();
    Pila copia;
    copia=p_crear();

    TipoElemento e1;
    while (p_es_vacia(p)!=true){
        e1=p_desapilar(p);
        p_apilar(pila_aux, e1);
    }

    while (p_es_vacia(pila_aux)!=true){
        e1=p_desapilar(pila_aux);
        p_apilar(p, e1);
        p_apilar(copia, e1);
    }

    while (p_es_vacia(copia)!=true){
    e1=p_desapilar(copia);
    if (comparado->clave==e1->clave){
        return true;
    }
    }

    return false;
}

Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    Pila pila_res;
    pila_res=p_crear();

    if (p_es_vacia(p1)||(p_es_vacia(p2))){
        return pila_res;
    }

    Pila pila_copia1;
    pila_copia1=p_crear();
    Pila pila_copia2;
    pila_copia2=p_crear();


    Pila pila_aux1;
    pila_aux1=p_crear();
    TipoElemento e1;
    while (p_es_vacia(p1)!=true){
        e1=p_desapilar(p1);
        p_apilar(pila_aux1, e1);
    }

    Pila pila_aux2;
    pila_aux2=p_crear();
    TipoElemento e2;
    while (p_es_vacia(p2)!=true){
        e2=p_desapilar(p2);
        p_apilar(pila_aux2, e2);
    }

    while (p_es_vacia(pila_aux1)!=true){
        e1=p_desapilar(pila_aux1);
        p_apilar(p1, e1);
        p_apilar(pila_copia1, e1);
    }

    while (p_es_vacia(pila_aux2)!=true){
        e1=p_desapilar(pila_aux2);
        p_apilar(p2, e1);
        p_apilar(pila_copia2, e1);
    }

    TipoElemento e3;
    while (p_es_vacia(pila_copia1)!=true){
        e3=p_desapilar(pila_copia1);
        if (func_buscar(e3, pila_copia2)==true){
            if (func_buscar(e3, pila_res)==false){
                p_apilar(pila_res, e3);
            }
        }
    }
    printf ("\nLa comlpejidad de la solucion del EJ7 es cuadratica, porque tenemos un ciclo anidado.\n");
   return pila_res;
}

// EJERCICIO 8:

void func_8_aumentar(TipoElemento comparado, Pila p);
void func_procesar_8(Pila pila_res, TipoElemento e);
void p_mostrar_clave_valor(Pila p);

void p_mostrar_clave_valor(Pila p) {
    if (p_es_vacia(p)) {
        printf("PILA VACIA !!!\n");
        return;
    }

    Pila aux = p_crear();
    TipoElemento e;
    int primero = 1;

    while (!p_es_vacia(p)) {
        e = p_desapilar(p);
        p_apilar(aux, e);
    }

    while (!p_es_vacia(aux)) {
        e = p_desapilar(aux);
        p_apilar(p, e);

        if (!primero) {
            printf(" ");
        }

        printf("%d:%d", e->clave, *(int*)e->valor);
        primero = 0;
    }

    printf("\n");
}

void func_8_aumentar(TipoElemento comparado, Pila p){
    Pila pila_aux;
    pila_aux=p_crear();
    Pila copia;
    copia=p_crear();

    TipoElemento e1;
    while (p_es_vacia(p)!=true){
        e1=p_desapilar(p);
        p_apilar(pila_aux, e1);
    }

    while (p_es_vacia(pila_aux)!=true){
        e1=p_desapilar(pila_aux);
        p_apilar(p, e1);
        p_apilar(copia, e1);
    }

    while (p_es_vacia(copia)!=true){
    e1=p_desapilar(copia);
    if (comparado->clave==e1->clave){
        (*(int*)e1->valor)++;
    }
    }
}

void func_procesar_8(Pila pila_res, TipoElemento e){
    if (func_buscar(e, pila_res)==false){
        int *x = malloc(sizeof(int));
        *x = 1;
        TipoElemento e2 = te_crear_con_valor(e->clave, x);
        p_apilar(pila_res, e2);
    } else {
        func_8_aumentar(e, pila_res);
    }
}

Pila p_ej8_sacarrepetidos(Pila p){
    Pila pila_res;
    pila_res=p_crear();

    if (p_es_vacia(p)==true){
        return pila_res;
    }

    Pila pila_copia1;
    pila_copia1=p_crear();

    Pila pila_aux1;
    pila_aux1=p_crear();
    TipoElemento e1;
    while (p_es_vacia(p)!=true){
        e1=p_desapilar(p);
        p_apilar(pila_aux1, e1);
    }

    while (p_es_vacia(pila_aux1)!=true){
        e1=p_desapilar(pila_aux1);
        p_apilar(p, e1);
        p_apilar(pila_copia1, e1);
    }

    TipoElemento e3;
    while (!p_es_vacia(pila_copia1)){
        e3 = p_desapilar(pila_copia1);
        func_procesar_8(pila_res, e3);
    }
    printf ("\nLa comlpejidad de la solucion del EJ8 es cuadratica, porque tenemos un ciclo anidado.\n");
   return pila_res;
}