#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"
#include "../libs/validaciones/headers/validaciones.h"

// menu
void mostrarMenu();
void ingresarOpcion(char *ingresado, int *nro_elegido);

// funciones inicializadoras
void ejercicio1();
void ejercicio2();
//void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
//void ejercicio10();

bool func_uno_base(void);
bool func_siete_esta_bien(char entrada[], int *n);
char *func_siete_base(int n);

void mostrarMenu() {
  printf("------ TP1: RECURSIVIDAD ------\n\n");
  printf("Seleccione un ejercicio:\n");
  printf("1 - Palindromo\n");
  printf("2 - Producto\n");
  printf("3 - Serie Fibonacci\n");
  printf("4 - Division\n");
  printf("5 - Agregar separador de miles\n");
  printf("6 - Onda digital\n");
  printf("7 - Mafia china\n");
  printf("8 - Subconjuntos\n");
  printf("9 - Divisible por 7\n");
  printf("10 - Explosion\n");
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

int main() {
  char ingresado[10];
  int nro_elegido;

  ingresarOpcion(ingresado, &nro_elegido);

  while (nro_elegido != 0) {
    switch (nro_elegido) {
      case 1:
        limpiarPantalla();
        printf("-- 1. PALINDROMO --\n");
        ejercicio1();
        break;
      case 2:
        limpiarPantalla();
        printf("-- 2. PRODUCTO --\n");
        ejercicio2();
        break;
      case 3:
        limpiarPantalla();
        printf("-- 3. FIBONACCI --\n");
        //ejercicio3();
        break;
      case 4:
        limpiarPantalla();
        printf("-- 4. DIVISION --\n");
        ejercicio4();
        break;
      case 5:
        limpiarPantalla();
        printf("-- 5. AGREGAR SEPARADOR DE MILES --\n");
        ejercicio5();
        break;
      case 6:
        limpiarPantalla();
        printf("-- 6. ONDA DIGITAL --\n");
        ejercicio6();
        break;
      case 7:
        limpiarPantalla();
        printf("-- 7. MAFIA CHINA --\n");
        ejercicio7();
        break;
      case 8:
        limpiarPantalla();
        printf("-- 8. SUBCONJUNTOS --\n");
        ejercicio8();
        break;
      case 9:
        limpiarPantalla();
        printf("-- 9. DIVISIBLE POR 7 --\n");
        ejercicio9();
        break;
      case 10:
        limpiarPantalla();
        printf("-- 10. EXPLOSION --\n");
        //ejercicio10();
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

void ejercicio1(){
    if (func_uno_base()==true){
        printf("True. La palabra ingresada fue un palindromo.\n");
    } else {
        printf("False. La palabra ingresada no fue un palindromo.\n");
    }
  printf("\n Presione ENTER para volver al menu\n");
  getchar();
}

void ejercicio2() {
  int multiplicando;
  int multiplicador;
  printf("\n\t INGRESE EL VALOR DEL MULTIPLICANDO : ");
  while (scanf("%d",&multiplicando) != 1){
    printf("\n\t VALOR DEL MULTIPLICANDO INVALIDO, INTENTE NUEVAMENTE...");
    printf("\n\t INGRESE EL VALOR DEL MULTIPLICANDO : ");
    while(getchar()!= '\n'){}     // LIMPIO EL BUFFER PARA CUANDO SE INGRESA MAL, LO VUELVA A INGRESAR.
  }
  while(getchar()!= '\n'){}   // LIMPIO EL BUFFER SI INGRESO BIEN, PARA AHORRARME ERORRES EN POSIBLES FGETS O INPUTS

  printf("\n\t INGRESE EL VALOR DEL MULTIPLICADOR : ");
  while (scanf("%d",&multiplicador) != 1){
    printf("\n\t VALOR DEL MULTIPLICADOR INVALIDO, INTENTE NUEVAMENTE...");
    printf("\n\t INGRESE EL VALOR DEL MULTIPLICADOR : ");
    while(getchar()!= '\n'){}   
  }
  while(getchar()!= '\n'){} 

// TERMINO LOS INGRESOS DE VALORES

  int resultado = producto(multiplicador,multiplicando);
  printf("\n\n EL PRODUCTO DE %d POR %d ES : %d",multiplicando,multiplicador,resultado);

  printf("\n Presione ENTER para volver al menu\n");
  getchar();
};

/**/
void ejercicio3() {
  int k;
  while(getchar()!= '\n'){} 

  int resultado = terminoSeridFibonacci(k);

  printf("\n\n EL TERMINO %d DE FIBONACCI ES : %d", k, resultado);

  printf("\n Presione ENTER para volver al menu\n");
  getchar();

};

void ejercicio4() {
  int dividendo;
  int divisor;
  int decimales;
  printf("\n\t INGRESE EL VALOR DEL DIVIDENDO : ");
  while (scanf("%d",&dividendo) != 1){
    printf("\n\t VALOR DEL DIVIDENDO INVALIDO, INTENTE NUEVAMENTE...");
    printf("\n\t INGRESE EL VALOR DEL DIVIDENDO : ");
    while(getchar()!= '\n'){}     // LIMPIO EL BUFFER PARA CUANDO SE INGRESA MAL, LO VUELVA A INGRESAR.
  }
  while(getchar()!= '\n'){}   // LIMPIO EL BUFFER SI INGRESO BIEN, PARA AHORRARME ERORRES EN POSIBLES FGETS O INPUTS

  printf("\n\t INGRESE EL VALOR DEL DIVISOR : ");
  while (scanf("%d",&divisor) != 1 || divisor==0){
    printf("\n\t VALOR DEL DIVISOR INVALIDO, INTENTE NUEVAMENTE...");
    printf("\n\t INGRESE EL VALOR DEL DIVISOR : ");
    while(getchar()!= '\n'){}   
  }
  while(getchar()!= '\n'){}

  printf("\n\t INGRESE EL VALOR DE LA MAXIMA CANTIDAD DE DECIMALES SI SE REQUIERE : ");
  while (scanf("%d",&decimales) != 1 || (decimales<1 || decimales>10)){
    printf("\n\t VALOR DE DECIMALES INVALIDO, INTENTE NUEVAMENTE...");
    printf("\n\t INGRESE EL VALOR DE LA MAXIMA CANTIDAD DE DECIMALES SI SE REQUIERE : ");
    while(getchar()!= '\n'){}   
  }
  while(getchar()!= '\n'){}

// TERMINO LOS INGRESOS DE VALORES.

  float resultado = division(dividendo,divisor,decimales);
  printf("\n\t EL RESULTADO DE LA DIVISION %d / %d = %.*f",dividendo,divisor,decimales,resultado);
  
  printf("\n Presione ENTER para volver al menu\n");
  getchar();
};

void ejercicio5() {
    char numero[100];
    bool valido = false;
    
    while (!valido){
        printf("[INPUT] Ingrese el numero al que desea agregar los puntos de miles: ");
        fgets(numero, sizeof(numero), stdin);
        numero[strcspn(numero, "\n")] = '\0';

        valido = numero_valido(numero);

        if (!valido){
            printf("[ERROR] No se ingresaron numeros validos.\n");
        }
    }

    agregarSeparadorMiles(numero);
    printf("[OUTPUT] Su numero con los puntos de los miles es %s\n", numero);

    printf("\n Presione ENTER para volver al menu\n");
    getchar();
};

void ejercicio6() {
  char cadena[50] = "";
  char ingresado[10];
  int longitud = 0;

  while (1) {
    printf("Ingrese H o L para formar una onda ('.' para salir): ");
    fgets(ingresado, sizeof(ingresado), stdin);

    ingresado[strcspn(ingresado, "\n")] = '\0'; // elimina salto de linea

    if (strlen(ingresado) == 1) {
      char c = ingresado[0];

      if (c == '.') break;
      else if (c == 'H' || c == 'L' || c == 'h' || c == 'l') {
      if (longitud < sizeof(cadena) - 1) {
        cadena[longitud++] = c;
          cadena[longitud] = '\0';
        }
        else printf("Cadena llena: limite de caracteres alcanzado.\n");
      }
      else printf("Entrada invalida.\n");
    }
    else printf("Entrada invalida. Ingrese solo un caracter a la vez (H, L, h, l o .).\n");
    }

    printf("Onda generada: %s\n", ondaDigital(cadena));

    printf("\n Presione ENTER para volver al menu\n");
    getchar();
};

void ejercicio7(){
    int n=0;
    printf("Vamos a ver la apariencia del grupo de chinos que asisten a una reunión de nivel “n”.\nIngrese el numero N:\n");
    char entrada[200];
    fgets(entrada,200,stdin);

    if (entrada[0]=='-'){
        printf("Error: numero negativo!\n");
        return;
    }

    if (func_siete_esta_bien(entrada, &n)==true){
        if (n==0){
            printf("Error: N no puede ser 0!\n");
            return;
        } else {
        
            char *resultado = func_siete_base(n);

             if (resultado == NULL) {
            printf("Error: no se pudo reservar la memoria!\n");
            return;
            }

            printf("%s\n", resultado);
            free(resultado);
        } 
    }
      printf("\n Presione ENTER para volver al menu\n");
      getchar();
}

void ejercicio8() {
  char num_ingresado[50];
  int conjunto[100];
  int contador = 0;

  // Primera parte: formar el subconjunto
  printf("Ingrese numeros al conjunto (o '.' para salir).\n");
  while (1) {
    printf("Ingresar numero: ");
    fgets(num_ingresado, sizeof(num_ingresado), stdin);

    if (num_ingresado[0] == '.') break;

    // sino validar que el numero ingresado sea entero
    else if (numero_valido(num_ingresado) == 1) {
      conjunto[contador] = str_a_int(num_ingresado);
      contador += 1;
    }
    else {
      printf("Error, vuelva a intentar.\n");
    }
  }

  // Segunda parte: suma a la que se debe llegar
  int num_a_sumar;
  char ingresado[10];
  while (1) {
    printf("Numero a sumar en el subconjunto: ");
    fgets(ingresado, sizeof(ingresado), stdin); // primero lo guardo en otra variable para validarlo

    if (numero_valido(ingresado) == 1) { // si es valido, se convierte a entero y se guarda en num_a_sumar
      num_a_sumar = str_a_int(ingresado);
      break;
    }
    else {
      printf("Numero no valido! Vuelva a intentar.\n");
    }
  }

  conjunto[contador + 1] = -1;

  // Tercera parte: ejecutar y mostrar el resultado de la funcion
  int **subconjuntos = subconjuntosQueSumanN(conjunto, num_a_sumar);

  printf("\nSubconjuntos que suman %d:\n", num_a_sumar);
  for (int i = 0; subconjuntos[i] != NULL; i++) {
    printf("{");
    for (int j = 0; subconjuntos[i][j] != -1; j++) {
      printf("%d", subconjuntos[i][j]);

      if (subconjuntos[i][j+1] != -1) printf(", ");
    }
    printf("}\n");
    
    free(subconjuntos[i]);
  }

  free(subconjuntos);

  printf("\n Presione ENTER para volver al menu\n");
  getchar();
};

void ejercicio9() {
  char ingresado[50];
  int numero;

  while (1) {
    printf("Ingrese un numero entero para verificar: ");
    fgets(ingresado, sizeof(ingresado), stdin);

    if (numero_valido(ingresado) == 1) {
      numero = str_a_int(ingresado);
      break;
    } else {
      printf("Numero invalido. intentar nuevamente.\n");
    }
  }

  printf("\nResultado:\n");

  if (divisiblePor7(numero)) {
    printf("El numero %d es divisible por 7\n", numero);
  } else {
    printf("El numero %d no es divisible por 7\n", numero);
  }

  printf("\nPresione ENTER para volver al menu...");
  getchar();
};

/*void ejercicio10() {
  //
};*/
