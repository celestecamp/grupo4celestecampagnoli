#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <stdbool.h>

char * ingresarString();    // pide un string
bool ingresoEntero(int *n); // pide un entero, o un "." como representación de nulo. devuelve V en el primer caso y F en el segundo.

int numero_valido(const char *str); // comprueba si un string es un num valido (retorna 1 si lo es)
int str_a_int(const char *str); // transforma strings a enteros, solo si son numeros

void limpiarPantalla();  // limpia consola segun el sist. operativo

#endif