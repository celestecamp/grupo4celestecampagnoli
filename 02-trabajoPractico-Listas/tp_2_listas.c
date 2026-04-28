#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "tp_2_listas.h"

typedef struct Promedios {
    float promedio_l1;
    float promedio_l2;
} Promedios;

typedef struct Min_val {
    int clave;
    int pos;
} Min_val;

Lista ejercicio2_a(Lista l1, Lista l2);
Lista ejercicio2_b(Lista l1, Lista l2);
Lista ejercicio2_c(Lista l1, Lista l2);
Promedios ejercicio2_d(Lista l1, Lista l2);
Min_val ejercicio2_e(Lista l1, Lista l2);
void esperar_enter();

void esperar_enter() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Presione ENTER para continuar...' x");
#endif
}

int leer_entero_positivo() {
    printf("Ingresa un numero positivo:\n");
    int n;
    int leidos;
    while (1) {
        leidos = scanf("%d", &n);
        if (leidos == 1 && n > 0) {
            return n;
        }
        printf("Hay que ingresar un numero mas de 0!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
}

void elegir_en_ej2(Lista l1, Lista l2){
    printf("Que parte de ejercicio 2 vamos a ver? Ingresa un numero de 1 a 5,\ndonde 1 es a, 2 es b, etc.\n");
    printf("Si queres salir, ingresa cualqiera otro valor\n");
    int seleccion;
    scanf("%d",&seleccion);
    switch (seleccion)
    {
    case 1:{
        Lista respuesta1=l_crear();
        respuesta1=ejercicio2_a(l1, l2);
        printf("Vamos a ver los valores de L1 que no estan en L2:\n");
        Iterador it1 = iterador(respuesta1);
        while (hay_siguiente(it1)) {
            TipoElemento e = siguiente(it1);
            printf("%d\n", e->clave);
        }
        esperar_enter();
        elegir_en_ej2(l1, l2);
        break;}
    case 2: {
        Lista respuesta2=l_crear();
        respuesta2=ejercicio2_b(l1, l2);
        printf("Vamos a ver los valores de L2 que no estan en L1:\n");
        Iterador it2 = iterador(respuesta2);
        while (hay_siguiente(it2)) {
            TipoElemento e2 = siguiente(it2);
            printf("%d\n", e2->clave);
        }
        esperar_enter();
        elegir_en_ej2(l1, l2);
        break;}
    case 3:{
        Lista respuesta3=l_crear();
        respuesta3=ejercicio2_c(l1, l2);
        printf("Vamos a ver los valores comunes para ambas listas:\n");
        Iterador it3 = iterador(respuesta3);
        while (hay_siguiente(it3)) {
            TipoElemento e3 = siguiente(it3);
            printf("%d\n", e3->clave);
        }
        esperar_enter();
        elegir_en_ej2(l1, l2);
        break;}
    case 4:{
        Promedios respuesta4=ejercicio2_d(l1, l2);
        printf("Vamos a ver los promedios de ambas listas:\n");
        printf("El promedio de L1 es %f\n",respuesta4.promedio_l1);
        esperar_enter();
        printf("El promedio de L2 es %f\n",respuesta4.promedio_l2);
        esperar_enter();
        elegir_en_ej2(l1, l2);
        break;}
    case 5:{
        Min_val respuesta5=ejercicio2_e(l1, l2);
        printf("Vamos a ver el valor minimo de ambas listas y su posicion:\n");
        printf("El valor minimo es %d\n",respuesta5.clave);
        esperar_enter();
        printf("Su posicion es %d\n",respuesta5.pos);
        esperar_enter();
        elegir_en_ej2(l1, l2);
        break;}
    default:{
        printf("No elegiste ningun valor correcto. Chau!\n");
        break;}
    }   
}

void ej2_cargar_mis_valores(){
    printf("Vamos a cargar listas con tus valores\n");
    int tamanio1 = leer_entero_positivo();
    printf("Tamanio para L1 cargado\n");
    esperar_enter();
    printf("Ahora ingresa tamanio para L2\n");
    int tamanio2 = leer_entero_positivo();
    printf("Tamanio para L2 cargado\n");
    Lista l1=l_crear();
    Lista l2=l_crear();
    esperar_enter();
    printf("Vamos a cargar valores para L1\n");
    int valor_agregado;
    for (int i=0; i<tamanio1; i++){
        valor_agregado = leer_entero_positivo();
        l_agregar(l1, te_crear(valor_agregado));
    }
    printf("Valores para L1 fueron cargados\n");
    esperar_enter();
    printf("Ahora vamos a cargar valores para L2\n");
    for (int i=0; i<tamanio2; i++){
        valor_agregado = leer_entero_positivo();
        l_agregar(l2, te_crear(valor_agregado));
    }
    printf("Todos los valores fueron cargados\n");
    esperar_enter();
    elegir_en_ej2(l1, l2);
}

void ej2_cargar_al_azar(){
    srand(time(NULL)); 
    int tamanio1 = 1 + rand() % (10 - 1 + 1);
    int tamanio2 = 1 + rand() % (10 - 1 + 1);
    Lista l1=l_crear();
    Lista l2=l_crear();
    int valor_para_agregar;
    for (int i=0; i<tamanio1; i++){
        valor_para_agregar=1 + rand() % (99 - 1 + 1);
        l_agregar(l1, te_crear(valor_para_agregar));
    }
    for (int i=0; i<tamanio2; i++){
        valor_para_agregar=1 + rand() % (99 - 1 + 1);
        l_agregar(l2, te_crear(valor_para_agregar));
    }
    printf("Tengo valores cargados\n");
    esperar_enter();
    printf("Vamos a ver los valores en L1:\n");
    Iterador it1 = iterador(l1);
        while (hay_siguiente(it1)) {
            TipoElemento e = siguiente(it1);
            printf("%d\n", e->clave);
        }
    esperar_enter();
    printf("\nAhora vamos a ver los valores en L2:\n");
    Iterador it2 = iterador(l2);
        while (hay_siguiente(it2)) {
            TipoElemento e2 = siguiente(it2);
            printf("%d\n", e2->clave);
        }
    esperar_enter();
    elegir_en_ej2(l1, l2);
}

void ejercicio2(){
    printf("\nVamos a iniciar el ejercicio 2\n");
    printf("Queres cargar valores al azar?\nIngresa 1 para SI, el resto para NO\n");
    int al_azar;
    scanf("%d", &al_azar);
    if (al_azar==1){
        printf("Entonces, vamos a cargar los valores al azar\n");
        esperar_enter();
        ej2_cargar_al_azar();
    } else {
        printf("Entonces, vas a cargas tus valores\n");
        esperar_enter();
        ej2_cargar_mis_valores();
    }
}

Min_val ejercicio2_e (Lista l1, Lista l2){
    Min_val respuesta;
    int candidato_l1;
    int valor_comprobado;
    int pos1=1;
    Iterador it = iterador(l1);
    TipoElemento e = siguiente(it);
    candidato_l1=e->clave;
    valor_comprobado=e->clave;
    int pos_actual=1;
        while (hay_siguiente(it)) {
            pos_actual++;
            TipoElemento e = siguiente(it);
            valor_comprobado=e->clave;
            if (valor_comprobado<candidato_l1){
                candidato_l1=valor_comprobado;
                pos1=pos_actual;
            }
        }
    int candidato_l2;
    int valor_comprobado2;
    int pos2=1;
    Iterador it2 = iterador(l2);
    TipoElemento e2 = siguiente(it2);
    candidato_l2=e2->clave;
    valor_comprobado2=e2->clave;
    pos_actual=1;
        while (hay_siguiente(it2)) {
            pos_actual++;
            TipoElemento e2 = siguiente(it2);
            valor_comprobado2=e2->clave;
            if (valor_comprobado2<candidato_l2){
                candidato_l2=valor_comprobado2;
                pos2=pos_actual;
            }
        }
    int respuesta_final;
    int pos_final;
    if (candidato_l1<candidato_l2){
        respuesta_final=candidato_l1;
        pos_final=pos1;
    } else {
        respuesta_final=candidato_l2;
        pos_final=pos2;
    }
    respuesta.clave=respuesta_final;
    respuesta.pos=pos_final;
    return respuesta;
}

Promedios ejercicio2_d (Lista l1, Lista l2){
    float p1=0;
    float p2=0;
    Promedios promedios_respuesta;
    Iterador it = iterador(l1);
        while (hay_siguiente(it)) {
            TipoElemento e = siguiente(it);
            p1=p1+e->clave;
        }
    p1=p1/(l_longitud(l1));
    Iterador it2 = iterador(l2);
        while (hay_siguiente(it2)) {
            TipoElemento e2 = siguiente(it2);
            p2=p2+e2->clave;
        }
    p2=p2/(l_longitud(l2));
    promedios_respuesta.promedio_l1=p1;
    promedios_respuesta.promedio_l2=p2;
    return promedios_respuesta;
} 

Lista ejercicio2_c(Lista l1, Lista l2){
    Lista lista_respuesta = l_crear();
    if (l_longitud(l1)<=l_longitud(l2)){

        Iterador it = iterador(l1);
        while (hay_siguiente(it)) {
            TipoElemento e = siguiente(it);
            if ((l_buscar(l2, e->clave)!=NULL)&&(l_buscar(lista_respuesta, e->clave)==NULL)){
                l_agregar(lista_respuesta, te_crear(e->clave));
        }
    }
    } else {

        Iterador it = iterador(l2);
        while (hay_siguiente(it)) {
            TipoElemento e = siguiente(it);
            if ((l_buscar(l1, e->clave)!=NULL)&&(l_buscar(lista_respuesta, e->clave) ==NULL)){
                l_agregar(lista_respuesta, te_crear(e->clave));
        }
    }
    }
    return lista_respuesta;
}

Lista ejercicio2_b(Lista l1, Lista l2){
    Lista lista_respuesta = l_crear();
    Iterador it = iterador(l2);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);
        if (l_buscar(l1, e->clave)==NULL){
            l_agregar(lista_respuesta, te_crear(e->clave));
        }
    }
    return lista_respuesta;
}

Lista ejercicio2_a(Lista l1, Lista l2){
    Lista lista_respuesta = l_crear();
    Iterador it = iterador(l1);
    while (hay_siguiente(it)) {
        TipoElemento e = siguiente(it);
        if (l_buscar(l2, e->clave)==NULL){
            l_agregar(lista_respuesta, te_crear(e->clave));
        }
    }
    return lista_respuesta;
}
