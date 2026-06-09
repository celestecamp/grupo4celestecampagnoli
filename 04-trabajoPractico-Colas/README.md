## EJERCICIO 3:
Complejidad algorítmica: Siendo N = cantidad de elementos de las colas (ambas deben tener la misma longitud para el peor caso). Primero aparecen cuatro ciclos while: dos para contar y restaurar c1 y dos para contar y restaurar c2. Cada uno depende de N, por lo que suman O(n) + O(n) + O(n) + O(n). Luego aparece un for que recorre ambas colas simultáneamente comparando sus elementos, también dependiendo de N.
Complejidad total: O(n) + O(n) + O(n) + O(n) + O(n) = O(n), COMPLEJIDAD ORDEN LINEAL, considerando comportamiento asintótico.

## EJERCICIO 4:

Complejidad algorítmica: Siendo N = cantidad de elementos de la cola. Primero aparecen dos ciclos while: uno para contar los elementos y copiar la cola auxiliar, y otro para restaurar la cola original. Ambos dependen de N, sumando O(n) + O(n).

Luego aparece un for externo que recorre la cola completa (N iteraciones). Dentro de él existe otro for que vuelve a recorrer prácticamente toda la cola (N−1 iteraciones).

Complejidad total: O(n) + O(n) + O(n) × O(n) = O(n²) = O(n²), COMPLEJIDAD ORDEN CUADRÁTICO.

## EJERCICIO 5:

Complejidad algorítmica: Siendo N = cantidad de elementos de la cola. Primero aparece un while que recorre toda la cola para calcular la longitud y generar las copias auxiliares, por lo que tiene costo O(n).

Luego aparece un segundo while que se ejecuta N veces. Dentro del mismo:

Existe un while que recorre completamente la cola copia → O(n).
Se ejecuta c_intercambiar(copia, copiaAux), cuya complejidad depende de la implementación, pero normalmente es lineal → O(n).
Se calcula c_longitud(nueva), que dependiendo de la implementación puede ser O(1) o O(n).
Luego aparece un for que recorre la cola nueva. En el peor caso nueva puede contener hasta N elementos → O(n).

Por lo tanto, cada iteración del while externo tiene costo lineal.

Complejidad total: O(n) + O(n) × [O(n) + O(n) + O(n)]

= O(n) + O(n) × O(n)

= O(n²), COMPLEJIDAD ORDEN CUADRÁTICO.

## EJERCICIO 6:

Complejidad algorítmica: Siendo P = cantidad de elementos de la pila y C = cantidad de elementos de la cola.

Primero aparece un while que transfiere todos los elementos de la pila a paux, dependiendo de P → O(P).

Luego aparece un segundo while que recorre nuevamente la pila auxiliar (P iteraciones).

Dentro de cada iteración:

Existe un while que recorre toda la cola (C iteraciones).
Luego otro while que restaura la cola desde caux, también de tamaño C.

Por lo tanto, cada iteración del ciclo exterior cuesta O(C) + O(C) = O(C).

Complejidad total:

O(P) + O(P) × [O(C) + O(C)]

= O(P) + O(P × C)

= O(P × C), COMPLEJIDAD ORDEN CUADRÁTICO GENERALIZADO.

Si se considera que la pila y la cola tienen aproximadamente la misma cantidad de elementos (P = C = N), entonces:

O(N × N) = O(N²)

→ O(n²), COMPLEJIDAD ORDEN CUADRÁTICO.