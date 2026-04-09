#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"


// EJERCICIO 1

void func_pasar_a_mayusculas(char cadena[]) {
    int i = 0;

    while (cadena[i] != '\0') {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - ('a' - 'A');
        }
        i++;
    }
}

bool func_uno_adicional(char * cadena) {
    int longitud = strlen(cadena);

    if (longitud <= 1) {
        return true;
    }

    if (cadena[0] != cadena[longitud - 1]) {
        return false;
    }

    cadena[longitud - 1] = '\0';
    return func_uno_adicional(cadena + 1);
}

bool func_uno_base (){
    printf("Vamos a ver si una palabra es un palidromo. Ingrese la palabra:\n");
    char cadena2[200];
    fgets(cadena2,200,stdin);

    if (cadena2[0]=='\n'){
        printf ("Error: entrada vacia!\n");
        return false;
    }
    
    int long_cadena2=strlen(cadena2)-1;
    cadena2[long_cadena2] = '\0';

    char cadena[long_cadena2+1];
    for (int i=0; i<long_cadena2;i++){
        cadena[i]=cadena2[i];
    }
    cadena[long_cadena2] = '\0';
    bool resultado=false;

    func_pasar_a_mayusculas(cadena);

    if (func_uno_adicional(cadena)==true){
        resultado=true;
    }

    return resultado;
    }

// EJERCICIO 2

int producto(int m, int n) {
    if (m == 0 || n == 0) return 0;

    else if (n < 0){
        return -producto(m, -n);
    }
    else{
    return m + producto(m, n - 1);
    }
}

// EJERCICIO 3

// EJERCICIO 4
float division(int m, int n,int d){
    int signo = 1;
    float resultado;
    if (n==0){
        printf("\n\n Error! No es posible dividir por 0.");
        return -1;
    }

    if ((m<0 && n>0) || (m>0 && n<0) ){     // SI SOLO UNO DE LOS DOS ES NEGATIVO
        signo = -1;
    }
    if (m<0) m=-m;                      // CAMBIAMOS EL SIGNO AL NEGATIVO
    if (n<0) n=-n;

    if (m>=n){
        resultado = 1+division(m-n, n, d);
    }

    else if (m==0){
        return 0;   
    }
    else{
        resultado = partedecimal(m,n,d,0);
    }

    return signo * resultado; // CAMBIO EL SIGNO SI ERA NEGATIVO EL RESULTADO
}

float partedecimal(int m, int n, int d, int nivel){
    int nuevo;
    int num_decimal=0;
    float posicion = 1;
    int resto;
    // Caso base: si no hay resto no hay más decimales, o ya se alcanzo los d decimales
    if (m == 0 || nivel == d)
        return 0;

    nuevo = m * 10;

    num_decimal = division_decimal(nuevo, n, &resto);

    for (int i=0; i<= nivel; i++){
        posicion /= 10;
    }

    if (resto==0){ 
        return num_decimal * posicion;
    }
    return (num_decimal * posicion) + partedecimal(resto,n,d, nivel+1);
}

float division_decimal(int nuevo, int n, int *resto){
    if (nuevo < n) {
        *resto = nuevo;
        return 0;
    }
    return 1 + division_decimal(nuevo - n, n, resto);
}

// EJERCICIO 5
char* separadorMiles(char* numero, int cantidadPuntos, int longitudUsada, int contador){
    if (longitudUsada==0){
        return numero;
    }

    if (contador<=3){
        numero[longitudUsada+cantidadPuntos] = numero[longitudUsada];

        if (cantidadPuntos==1){
            numero[longitudUsada] = '.';
        }

        contador++;
        longitudUsada--;
        return separadorMiles(numero, cantidadPuntos, longitudUsada, contador);
    }
    else{
        contador=1;
        numero[longitudUsada+cantidadPuntos]= '.';
        cantidadPuntos--;
        return separadorMiles(numero, cantidadPuntos, longitudUsada, contador);
    }
}



char * agregarSeparadorMiles(char numero[]){
    int largoString = strlen(numero);
    int inicio = 0;
    
    if (largoString>0 && numero[0]=='-'){
        largoString--;
        inicio++;
    }
    
    int cantidadPuntos = (largoString - 1) / 3;
    int contador = 0;

    separadorMiles(&numero[inicio], cantidadPuntos, largoString, contador);

    return numero;
}

// EJERCICIO 6
int ondaAux(char *onda, char seniales[], int i, int j) {
    if (seniales[i] == '\0') {
        onda[j] = '\0';
        return j;
    }

    if (i == 0) {
        // Primera señal
        if (seniales[i] == 'h' || seniales[i] == 'H')
            onda[j++] = '-';
        else
            onda[j++] = '_';
    } else {
        char ant = seniales[i - 1];
        char actual = seniales[i];

        int esHAnterior = (ant == 'h' || ant == 'H');
        int esHActual = (actual == 'h' || actual == 'H');

        if (esHAnterior && esHActual) {
            onda[j++] = '-';
        } else if (!esHAnterior && !esHActual) {
            onda[j++] = '_';
        } else if (!esHAnterior && esHActual) {
            onda[j++] = '|';
            onda[j++] = '-';
        } else if (esHAnterior && !esHActual) {
            onda[j++] = '|';
            onda[j++] = '_';
        }
    }

    return ondaAux(onda, seniales, i + 1, j);
}

char *ondaDigital (char seniales[]) {
    char *onda = malloc(sizeof(char) * (2 * strlen(seniales) + 1));
    ondaAux(onda, seniales, 0, 0);
    return onda;
}
// EJERCICIO 7

void func_siete_mostrar(char salida[], char salida2[], char salida_final[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (salida2[i] != '0') {
        salida_final[k] = salida2[i];
        i++;
        k++;
    }

    while (salida[j] != '!') {
        salida_final[k] = salida[j];
        j++;
        k++;
    }

    salida_final[k] = '\0';
}

void func_siete_adicional (int n, char salida[], char salida2[]){

    salida[5+(n-1)*3]='.';
    salida[5+((n-1)*3)+1]='-';
    salida[5+((n-1)*3)+2]=')';

    salida2[0+(n-1)*3]='(';
    salida2[1+(n-1)*3]='-';
    salida2[2+(n-1)*3]='.';

    if (n>1){
        func_siete_adicional (n-1, salida, salida2);
    }

    return;
}

char *func_siete_base(int n){
    char salida[200];
    char salida2[200];

    int tam_salida3 = 6 * n;
    char *salida3 = malloc(tam_salida3 * sizeof(char));

    if (salida3 == NULL) {
    return NULL;
    }

        for (int i=0; i<200; i++){
            salida[i]='!';
            salida2[i]='0';
        }
    
    
        salida[2]='.';
        salida[3]='-';
        salida[4]=')';
        salida[1]='-';
        salida[0]='(';

        if (n>1){func_siete_adicional (n-1, salida, salida2);
        }

    func_siete_mostrar(salida, salida2, salida3);
    return salida3;
}

bool func_siete_esta_bien(char entrada[], int * n){
    int longuitud=strlen(entrada)-1;
    char entrada2[longuitud];

    for (int i=0; i<longuitud;i++){
        entrada2[i]=entrada[i];
    }

    for (int i=0; i<longuitud;i++){
        if ((entrada2[i]<'0')||(entrada2[i]>'9')){
            printf ("Error: la entrada no es un numero correcto!\n");
            return false;
        }
    }

    int multiplo=1;

    for (int i=longuitud-1; i!=-1;i--){
        *n=*n+((entrada2[i]-'0')*multiplo);
        multiplo=multiplo*10;
    }
    return true;
}


// EJERCICIO 8

int calcularTamano(int conjunto[]) {    // devuelve el tamaño del arreglo
    int cant = 0;
    
    while (conjunto[cant] != -1) {
        cant++;
    }

    return cant;
}

void subconjRecursiva(int conjunto[], int tamano, int sumaObjetivo, int sumaActual, int pos, int subconjunto[], int tamSubconj, int **res, int *cantSubconjuntos) {
    if (sumaActual == sumaObjetivo) {  // caso base: llego a la suma deseada
        res[*cantSubconjuntos] = (int*) malloc((tamSubconj + 1) * sizeof(int));
        
        for (int i = 0; i < tamSubconj; i++) {  // lo guardo
            res[*cantSubconjuntos][i] = subconjunto[i];
        }

        res[*cantSubconjuntos][tamSubconj] = -1;  // final del subconjunto
        (*cantSubconjuntos)++;
        return;
    }

    if (pos >= tamano || sumaActual > sumaObjetivo) return;

    // incluir el elemento actual
    subconjunto[tamSubconj] = conjunto[pos];
    subconjRecursiva(conjunto, tamano, sumaObjetivo, sumaActual + conjunto[pos], pos + 1, subconjunto, tamSubconj + 1, res, cantSubconjuntos);

    // no incluir el elemento actual
    subconjRecursiva(conjunto, tamano, sumaObjetivo, sumaActual, pos + 1, subconjunto, tamSubconj, res, cantSubconjuntos);
}

int **subconjuntosQueSumanN(int conjunto[], int n) {   
    int **res = (int **)malloc(100 * sizeof(int *)); // reservo memoria para resultado
    
    int tamano = calcularTamano(conjunto);  // calculo el tamaño del conjunto
    int subconjunto[tamano];  
    int cantSubconjuntos = 0;

    subconjRecursiva(conjunto, tamano, n, 0, 0, subconjunto, 0, res, &cantSubconjuntos);
    res[cantSubconjuntos] = NULL;
    return res; 
}

// EJERCICIO 9

bool divisiblePor7(int n){

    if (n < 0) {
        n = -n;
    }

    if (n < 70) {
        return n % 7 == 0;
    }
    
    int ultima = n % 10;
    int resto  = n / 10;
    return divisiblePor7(resto - ultima * 2);
}

// EJERCICIO 10
