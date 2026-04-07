#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "validaciones.h"

int numero_valido(const char *str) {
    int i = 0;

    // ignorar el salto de linea si esta presente
    size_t len = strlen(str);
    if (str[len - 1] == '\n') {
        ((char *)str)[len - 1] = '\0';
    }

    if (str[0] == '\0') return 0;   //str vacio

    // si el primer caracter es un signo, permitirlo solo si luego es acompañado de algo mas que sea valido
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
        if (str[1] == '\0') return 0; // evitar que solo haya un signo
    }

    // verificar que el resto sean solo dígitos
    for (; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) return 0;
    }

    return 1;
}

int str_a_int(const char *str) {
    int resultado = 0;
    int signo = 1;
    int i = 0;

    while (str[i] == ' ') i++; // saltar espacios en blanco

    if (str[i] == '-') {  // manejar signo negativo
        signo = -1;
        i++;
    }
    else if (str[i] == '+') {
        i++;
    }

    // convertir c/digito
    while (str[i] >= '0' && str[i] <= '9') {
        resultado = resultado * 10 + (str[i] - '0');
        i++;
    }

    return signo * resultado;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

char * ingresarString(){
    char *cadena;
    int cantidadInicial = 100;
 
    cadena = (char*) malloc(cantidadInicial * sizeof(char));
 
    if (cadena == NULL) {
       printf("Error de asignacion de memoria");
    }
 
    printf("Ingrese una cadena: ");
    fgets(cadena , cantidadInicial , stdin);
 
    size_t longitud = strlen(cadena);
    if (longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
 
    return cadena;
}

bool ingresoEntero(int *n){
    char s[10];
    bool resultado = true;
    *n = 0;
    printf("Ingrese un numero o '.' para nulo: ");
    scanf("%s", s);
    if (s[0] == '.') {
        resultado = false;
    }
    else {
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i] >= '0') && (s[i] <= '9')) {
                *n = *n * 10 + (s[i] - 48);
            }
        }
    }
    return resultado;
}

// 
char *int_to_char(int num){
    int i = log10(num) + 1;
    char *s = (char *)calloc(i + 1, sizeof(char));

    for (i--; num != 0; i--) {
        s[i] = (num % 10) + '0';
        num /= 10;
    }

    return s;
}
