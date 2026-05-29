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
int elegirllenar(){ // FUNCION PARA LLENAR PILAS, DEVUELVE 1 PARA LLENAR AL AZAR, O 2 PARA LLENAR MANUALMENTE
    printf("\n\tSI DESEA CARGAR LA PILA AL AZAR, INGRESE 1, SI DESEA CARGARLA MANUALMENTE, INGRESE 2: ");
    int opcion = leer_entero();
    while (opcion != 1 && opcion != 2){
        printf("\nOpcion no valida. Ingrese 1 para cargar al azar, o 2 para cargar manualmente: ");
        opcion = leer_entero();
    }
    return opcion;
}

Pila llenarpilasauto(Pila p){ // FUNCION PARA LLENAR PILAS AUTOMATICAMENTE, DEVUELVE LA PILA LLENA
    printf("Ingrese la cantidad de elementos a cargar en la pila (0-%d): ",TAMANIO_MAXIMO);
    int cantidad = leer_entero();
    while (cantidad < 0 || cantidad > TAMANIO_MAXIMO){
        printf("Error. Ingrese una cantidad entre 0 y %d: ", TAMANIO_MAXIMO);
        cantidad = leer_entero();
    }
    if (cantidad == 0){
        return p;
    }
    printf("\nINGRESANDO LOS %d ELEMENTOS DE LA PILA:",cantidad);
    for (int i = 0; i < cantidad; i++){
        int num = rand() % 100; // Genera un número aleatorio entre 0 y 99
        TipoElemento teAux = te_crear(num);
        p_apilar(p,teAux);
    }
    return p;
}

Pila llenarpilas(Pila p){ // FUNCION PARA LLENAR PILAS MANUALMENTE, DEVUELVE LA PILA LLENA
    printf("Ingrese la cantidad de elementos a cargar en la pila (0-%d): ",TAMANIO_MAXIMO);
    int cantidad = leer_entero();
    while (cantidad < 0 || cantidad > TAMANIO_MAXIMO){
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

void p_mostrar_con_valor(Pila pila) {
    if (p_es_vacia(pila)) {
        printf("PILA VACIA !!!\n");
        return;
    }

    Pila Paux = p_crear();
    TipoElemento X;

    printf("Contenido de la pila: ");

    while (!p_es_vacia(pila)) {

        X = p_desapilar(pila);

        // convertir void* a int*
        int valor = *((int*) X->valor);

        printf("%d:%d ", X->clave, valor);

        p_apilar(Paux, X);
    }
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

    if (i < posicionordinal){
        printf("\nLa posicion ordinal %d es mayor a la cantidad de elementos disponibles a insertar, se agregara al final.\n", posicionordinal);
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
bool p_ej3_iguales(Pila p1, Pila p2) {
    bool son_iguales = true;
    Pila p_aux = p_crear();
    TipoElemento e1, e2;


    while (!p_es_vacia(p1) && !p_es_vacia(p2) && son_iguales) {
        e1 = p_desapilar(p1);
        e2 = p_desapilar(p2);
        if (e1->clave != e2->clave) {
            son_iguales = false;
        }
        p_apilar(p_aux, e1);
        p_apilar(p_aux, e2);
    }
    if (son_iguales && (!p_es_vacia(p1) || !p_es_vacia(p2))) {
        son_iguales = false;
    }
    while (!p_es_vacia(p_aux)) {
        e2 = p_desapilar(p_aux); 
        e1 = p_desapilar(p_aux); 
        p_apilar(p2, e2);
        p_apilar(p1, e1);
    }
    return son_iguales;
}


// EJERCICIO 4:
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){

    if (nrootrabase < 2 || nrootrabase > 16){
        char* str = malloc(12);
        sprintf(str, "%d", nrobasedecimal);
        return str;
    }

    if (nrobasedecimal == 0){
        char* str = malloc(2);
        strcpy(str, "0");
        return str;
    }
    bool negativo = false;
    if (nrobasedecimal < 0){
        negativo = true;
        nrobasedecimal = -nrobasedecimal;
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
    if (negativo){
        resultado[i] = '-';
        i++;
    }

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

Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    Pila Paux1 = p_crear();
    Pila Paux2 = p_crear();
    Pila comun = p_crear();
    Pila comunAux = p_crear();
    TipoElemento teAux1;
    TipoElemento teAux2;
    bool encontrado;
    while(!p_es_vacia(p1)){
        encontrado = false;
        teAux1 = p_desapilar(p1);
        p_apilar(Paux1,teAux1);
        while(!p_es_vacia(p2) && !encontrado){
            teAux2 = p_desapilar(p2);
            p_apilar(Paux2,teAux2);
            if (teAux1->clave == teAux2->clave){
                encontrado = true;
            }
        }
        p_intercambiar(p2,Paux2);
        bool existe = false;
        if (encontrado){
            while(!p_es_vacia(comun) && !existe){
                teAux2 = p_desapilar(comun);
                p_apilar(comunAux,teAux2);
                if(teAux1->clave == teAux2->clave){
                    existe = true;
                }
            }
            p_intercambiar(comun,comunAux);
            if (!existe){
                TipoElemento nuevo = te_crear(teAux1->clave);
                p_apilar(comun,nuevo);
            }
        }
    }
    p_intercambiar(p1,Paux1);

    return comun;
}
// EJERCICIO 8:

Pila p_ej8_sacarrepetidos(Pila p){
    if (p_es_vacia(p)){
        Pila nueva = p_crear();
        return nueva;
    }
    
    Pila Paux = p_crear();
    Pila OriginalInvertida = p_crear();
    Pila P_unicos = p_crear();
    Pila unicos_aux = p_crear(); 
    TipoElemento teAux;
    TipoElemento teAux2;
    
    while (!p_es_vacia(p)){ 
        teAux = p_desapilar(p);
        p_apilar(OriginalInvertida,teAux);
        p_apilar(Paux,teAux);
    }
    p_intercambiar(p,OriginalInvertida);
    // LLENAR UNA PILA CON ELEMENTOS UNICOS
    while(!p_es_vacia(Paux)){
        teAux = p_desapilar(Paux);
        bool encontrado = false;
        while(!p_es_vacia(P_unicos) && !encontrado){
            teAux2 = p_desapilar(P_unicos);
            p_apilar(unicos_aux,teAux2);
            if(teAux->clave == teAux2->clave){
                encontrado = true;
            }
        }
        p_intercambiar(P_unicos,unicos_aux);
        if (!encontrado){
            p_apilar(P_unicos,teAux);
        }
    }
    
    while(!p_es_vacia(P_unicos)){
        int contador = 0;
        teAux = p_desapilar(P_unicos);
        while(!p_es_vacia(p)){
            teAux2 = p_desapilar(p);
            p_apilar(OriginalInvertida,teAux2);
            if(teAux->clave == teAux2->clave){
                contador++;
            }
        }
        int* valor = malloc(sizeof(int));
        *valor = contador;
        p_intercambiar(p,OriginalInvertida);
        teAux->valor = valor;
        p_apilar(unicos_aux,teAux);
    }
    return unicos_aux;
}