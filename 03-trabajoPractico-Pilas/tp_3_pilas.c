#include "../libs/tipoElemento/headers/tipo_elemento.h"
#include "../libs/pilas/headers/pilas.h"
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_3_pilas.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// -----------------------  FUNCIONES AUXILIARES   ----------------------- 
Pila llenarpilas(Pila p,int cantidad){
    while (cantidad <= 0 || cantidad > TAMANIO_MAXIMO){
        printf("Error. Ingrese una cantidad entre 1 y %d: ", TAMANIO_MAXIMO);
        cantidad = leer_entero();
    }
    printf("Ingrese los elementos de la pila:\n");
    for (int i = 0; i < cantidad; i++){
        printf("\nIngrese un numero entero: ");
        int num = leer_entero();
        TipoElemento teAux = te_crear(num);
        p_apilar(p,teAux);
    }
    return p;
}
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
Pila  p_ej5_invertir(Pila p){
    Pila Pinvertida = p_crear();
    Pila Paux = p_crear();
    TipoElemento teAux; 
    while (!p_es_vacia(p)){
        teAux = p_desapilar(p);
        p_apilar(Pinvertida,teAux);
        p_apilar(Paux,teAux);
    }
    p_intercambiar(p,Paux);
    return Pinvertida;
}

// EJERCICIO 6:
Pila p_ej6_eliminarclave(Pila p, int clave){
    if (p_es_vacia(p)){return p;}
    bool encontrado = false;
    Pila Paux = p_crear();
    Pila nuevapila = p_crear();

    TipoElemento teAux;

    while(!p_es_vacia(p)){
        teAux = p_desapilar(p);
        p_apilar(Paux,teAux);
    }

    while (!p_es_vacia(Paux)){
        teAux = p_desapilar(Paux);
        if (teAux->clave != clave){
            p_apilar(p,teAux);
            p_apilar(nuevapila,teAux);
        }
        else{
            p_apilar(p,teAux);
            encontrado = true;
        }
    }
    if (encontrado){
        return nuevapila;
    }
    else{
        return p;
    }
}

Pila p_ej6_eliminarclave_recprincipal(Pila p, int clave)
{
    if (p_es_vacia(p)) {return p;}
    TipoElemento teAux;
    Pila nuevapila = p_crear();
    Pila Paux = p_crear();
    bool encontrado = false;

    while (!p_es_vacia(p)){
        teAux = p_desapilar(p);
        p_apilar(Paux,teAux);
    }
    p_ej6_eliminarclave_recaux(p, nuevapila, Paux, clave, &encontrado);

    if (encontrado){
        return nuevapila;
    }
    else{
        return p;
    }
    
}


void p_ej6_eliminarclave_recaux(Pila p, Pila nuevapila,Pila Paux, int clave, bool* encontrado)
{
    
    if (p_es_vacia(Paux)) {return;}
    else{
        TipoElemento teAux = p_desapilar(Paux);
        if (teAux->clave != clave){
            p_apilar(p,teAux);
            p_apilar(nuevapila,teAux);
        }
        else{
            p_apilar(p,teAux);
            *encontrado = true;
        }
        p_ej6_eliminarclave_recaux(p, nuevapila, Paux, clave, encontrado);
    }

}

// EJERCICIO 7:
// EJERCICIO 8: