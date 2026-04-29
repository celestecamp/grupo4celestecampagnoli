#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include "tp_2_listas.h"
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

void mostrarMenu() {
    printf("------ TP2: LISTAS ------\n\n");
    printf("Seleccione un ejercicio:\n");
    printf("2 - Valores entre listas\n");
    printf("3 - Multiplo\n");
    printf("4 - Mayor, igual o menor\n");
    printf("5 - Polinomio\n");
    printf("6 - Sublista\n");
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
                printf("-- 3. MULTIPLO --\n");
                ejercicio3();
                break;
            case 4:
                limpiarPantalla();
                printf("-- 4. MAYOR, IGUAL O MENOR --\n");
                ejercicio4();
                break;
            case 5:
                limpiarPantalla();
                printf("-- 5. POLINOMIO --\n");
                ejercicio5();
                break;
            case 6:
                limpiarPantalla();
                printf("-- 6. SUBLISTA --\n");
                ejercicio6();
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


//--------------------------------------- LLAMADAS A FUNCIONES DEL TP

void ejercicio2(){
    Lista lista1, lista2;
    Lista nueva_lista = l_crear();
    char opcion = ' ';

    //-----------------------------Llenar las listas una sola vez al entrar -----------------------------
    printf("\n\n-- 2. VALORES ENTRE LISTAS --\n");
    printf("Si desea llenar las listas manualmente presione '1', de lo contrario presione '0': ");
    int valor = leerEnteroEnRango(0, 1);
    

    if (valor == 1) { // Llenar las listas manualmente
        printf("\n\nPor favor ingrese la cantidad de elementos de la lista:\n");
        int n_elementos = leerEnteroEnRango(0, TAMANIO_MAXIMO);
        lista1 = rellenarLista_manual(n_elementos);
        printf("\n");
        l_mostrar(lista1);
        printf("\nLista 1 llena! Ahora ingrese la cantidad de elementos de la lista 2:\n");
        n_elementos = leerEnteroEnRango(0, TAMANIO_MAXIMO);
        lista2 = rellenarLista_manual(n_elementos);
        printf("\n");
        l_mostrar(lista2);
        printf("\nLista 2 llena!\n");
        printf("\n Presione ENTER para continuar\n");
        getchar();
    }
    else { // Llenar las listas automaticamente
        printf("\n\nPor favor ingrese la cantidad de elementos de la lista:\n");
        int n_elementos = leerEnteroEnRango(0, TAMANIO_MAXIMO);
        lista1 = rellenarLista_auto(n_elementos);
        printf("\n");
        l_mostrar(lista1);
        printf("\nLista 1 llena! Ahora ingrese la cantidad de elementos de la lista 2:\n");
        n_elementos = leerEnteroEnRango(0, TAMANIO_MAXIMO);
        lista2 = rellenarLista_auto(n_elementos);
        printf("\n");
        l_mostrar(lista2);
        printf("\nLista 2 llena!\n");
        printf("\n Presione ENTER para continuar\n");
        getchar();
    }

    while (opcion != 'f') {
        printf("\n\nSeleccione un ejercicio:\n");
        printf("a - Ver elementos de L1 que no estan en L2\n");
        printf("b - Ver elementos de L2 que no estan en L1\n");
        printf("c - Ver elementos comunes en ambas listas\n");
        printf("d - Promedios de L1 y L2\n");
        printf("e - Valor minimo y posicion ordinal de ambas listas\n");
        printf("f - Volver al menu principal\n");

        do {
            printf("\nIngrese una opcion (a, b, c, d o e) o f para salir: ");
            scanf(" %c", &opcion);
            opcion = tolower(opcion);
            limpiarbuffer();
            if (opcion < 'a' || opcion > 'f') {
                printf("\nOpcion no valida. Intente nuevamente.\n");
            }
        } while (opcion < 'a' || opcion > 'f');

        float promedio1, promedio2;
        switch (opcion) {
        case 'a':
                vaciarLista(nueva_lista);
                nueva_lista = verElementosQueNoSeRepiten(lista1, lista2);
                if (nueva_lista!= NULL){
                    printf("\nElementos de L1 que no estan en L2:\n");
                    l_mostrar(nueva_lista);
                        printf("\n Presione ENTER para continuar\n");
                        getchar();
                }
                else {
                    printf("No hay elementos de L1 que no esten en L2.\n");
                }
                break;
        case 'b':                            
                vaciarLista(nueva_lista);
                nueva_lista = verElementosQueNoSeRepiten(lista2, lista1);
                if (nueva_lista!= NULL){
                    printf("\nElementos de L2 que no estan en L1:\n");
                    l_mostrar(nueva_lista);
                        printf("\n Presione ENTER para continuar\n");
                        getchar();
                }
                else {
                    printf("No hay elementos de L2 que no esten en L1.\n");
                }
                break;
        case 'c':
                vaciarLista(nueva_lista);
                nueva_lista = verElementosRepetidos(lista1, lista2);
                if (nueva_lista!= NULL){
                    printf("\nElementos comunes en ambas listas:\n");
                    l_mostrar(nueva_lista);
                        printf("\n Presione ENTER para continuar\n");
                        getchar();
                }
                else {
                    printf("No hay elementos comunes en ambas listas.\n");
                }
                break;
        case 'd':
                promedio1 = promedio(lista1);
                promedio2 = promedio(lista2);
                printf("\nPromedio de L1: %.3f\n", promedio1);
                printf("Promedio de L2: %.3f\n", promedio2);
                printf("\n Presione ENTER para continuar\n");
                getchar();
                break;
        case 'e':
                if (l_es_vacia(lista1) || l_es_vacia(lista2)){
                    printf("\nNo se puede calcular el valor minimo de una lista vacia.\n");
                    printf("\n Presione ENTER para continuar\n");
                    getchar();
                    break;
                }
                ResultadoValorMinimo resultado = valorMinimo(lista1, lista2);
                printf("\nValor minimo de L1: %d en la posicion %d\n", resultado.valor, resultado.pos);
                printf("Valor minimo de L2: %d en la posicion %d\n", resultado.valor_2, resultado.pos_2);

                
                printf("\n Presione ENTER para continuar\n");
                getchar();
                break;
        default:
            printf("Volviendo al menu principal.\n");
            break;
        }
    }

    vaciarLista(lista1);
    vaciarLista(lista2);
    vaciarLista(nueva_lista);

}

void ejercicio3(){
    Lista lista1, lista2;
    int valor;

    printf("\n-- 3. DETERMINAR SI L2 ES MULTIPLO DE L1 --\n");
    printf("Si desea llenar las listas manualmente presione '1', de lo contrario presione '0' (azar): ");
    
    valor = leerEnteroEnRango(0, 1); 

    printf("\nIngrese la cantidad de elementos para las listas (deben ser iguales): ");
    int n_elementos = leerEnteroEnRango(1, TAMANIO_MAXIMO);

    if (valor == 1) { 
        printf("\n--- Cargando Lista 1 (Divisores) ---\n");
        lista1 = rellenarLista_manual(n_elementos);
        printf("\n--- Cargando Lista 2 (Dividendos) ---\n");
        lista2 = rellenarLista_manual(n_elementos);
    } 
    else { 
        lista1 = rellenarLista_auto(n_elementos);
        lista2 = rellenarLista_auto(n_elementos);
        printf("\nListas generadas automaticamente:");
        printf("\nL1: "); l_mostrar(lista1);
        printf("L2: "); l_mostrar(lista2);
    }

    ResultadosMul resultado = multiplo(lista1, lista2);

    printf("\n--- RESULTADOS ---\n");
    if (resultado.esMultiplo) {
        printf("RESULTADO: L2 es multiplo de L1 posicion por posicion.\n");
        if (resultado.escalar) {
            printf("DETALLE: Existe un escalar constante. El escalar es: %d\n", resultado.numEscalar);
        } else {
            printf("DETALLE: Son multiplos pero NO tienen un escalar constante.\n");
        }
    } else {
        printf("RESULTADO: L2 NO es multiplo de L1 (o hubo division por cero).\n");
    }

    printf("\nPresione ENTER para continuar\n");
    getchar(); 
    getchar();
}

void ejercicio4(){
}

void ejercicio5(){
    Lista l = l_crear();
    hacerPolinomio(l);

    fflush(stdin);
    limpiarPantalla();

    if (l_es_vacia(l)) printf("LISTA VACIA\n");
    else {
        float min, max, dif;
        printf("RANGO A EVALUAR\n");
        printf("Minimo: "); scanf("%f", &min);
        printf("Maximo: "); scanf("%f", &max);
        printf("Incrementando de a: "); scanf("%f", &dif);
    
        printf("\n");
        Lista resultado = calcularRango(l, min, max, dif);
    }

    printf("\nPresione ENTER para volver al menu\n");
    getchar();
}

void ejercicio6(){
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    bool seguirAgregando = true;
    int index = 1;
    int inputNumber;
    char inputChar;

    while(seguirAgregando){
        printf("Ingrese el #%i elemento de la primer lista o 'n' para terminar: ", index);

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L1, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("Terminando ingreso de la primer lista.\n");
            }else{
                printf("Debe ingresar un valor valido.\n");
            }

            fflush(stdin);
        }
        index++;
    }

    seguirAgregando = true;
    index = 1;

    while(seguirAgregando){
        printf("Ingrese el #%i elemento de la segunda lista o 'n' para terminar: ", index);

        if(scanf("%d", &inputNumber) > 0){
            l_agregar(L2, te_crear(inputNumber));
        }else{
            if(scanf("%c", &inputChar) > 0 && inputChar == 'n'){
                seguirAgregando = false;
                printf("Terminando ingreso de la segunda lista.\n");
            }else{
                printf("Debe ingresar un valor valido.\n");
            }
            
            fflush(stdin);
        }
        index++;
    }

    if(esSublista(L1, L2)){
        printf("L2 es sublista de L1.\n");
    }else{
        printf("L2 no es sublista de L1.\n");
    }

    system("pause");
}
