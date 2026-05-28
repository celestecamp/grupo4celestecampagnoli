# COMPLEJIDAD ALGORITMICA TP°3 PILAS GRUPO4CELESTECAMPAGNOLI

## TODOS LOS EJERCICIOS SERAN SIN TENER EN CUENTA EL MAIN, SOLO SE DETERMINARA LA COMPLEJIDAD RESPECTO DE LAS FUNCIONES DEL tp_3_pilas.c
## EN CASO DE DEPENDER DE LA IMPLEMENTACION SE VA A ACLARAR

*EJERCICIO 3:*

-Complejidad algortimica : En primer caso tenemos un while que itera hasta pila vacia, lo que depende de N siendo N = cantidad de elementos de la pila, por lo que este while
sumaria O(n). Luego encontramos otro while que itera hasta vaciar la pila auxiliar lo que tambien depende de N sumando otro O(n). 
-Complejidad total : O(n) + O(n) = *O(n), COMPLEJIDAD LINEAL*, siempre pensando en el comportamiento asintotico (n tiende a infinito)

*EJERCICIO 4:*

-Complejidad algortimica : En primer caso tenemos un while(N>0) siendo N nuestro numero en base decimal, ciclo el cual lo divide sucesivamente por la nueva base(B).
La cantidad de iteraciones depende de la cantidad de dígitos del número en la nueva base(2-16). La cantidad de veces que se puede dividir N por B antes de que se llegue a la 
condicion n>0 es por log b (N) *logaritmo en base 'b' de N*. Luego tenemos un while que itera hasta que se vacia la pila que llenamos con log b (N) elementos.
-Complejidad total : O(log b (N)) +  O(log b (N)) = *O(log b (N)) COMPLEJIDAD LOGARITMICA*

*EJERCICIO 5:*

-Complejidad algortimica : Siendo N = cantidad de elementos de la pila. Tiene complejidad lineal, ya que siempre voy a tener que recorrer la pila en su totalidad, este proceso
lo voy a tener que hacer 2 veces, 1 en el while y otro en p_intercambiar (ambos dependen de N). 
-Complejidad total : O(n) + O(n)  que en comportamiento asintotico es igual a *O(n), COMPLEJIDAD LINEAL*

*EJERCICIO 6:*

# EN ESTE EJERCICIO SE PUEDE RESOLVER DE MANERA 'ITERATIVA' COMO 'RECURSIVA'
# SE INDICARA LA COMPLEJIDAD EN CADA CASO

## ITERATIVO
-Complejidad algortimica 'ITERATIVA': Siendo N = cantidad de elementos de la pila -> Primero tenemos un while que recorre 'p' dependiendo de N , luego otro while que recorre
'Paux' O(n).

-Complejidad total 'ITERATIVA': O(n)+O(n)= *O(n), COMPLEJIDAD LINEAL* 

## RECURSIVO

-Complejidad algortimica 'RECURSIVA': Siendo N = cantidad de elementos de la pila -> se utiliza una recursion Directa con Parámetros Acumuladores. En la funcion PRINCIPAL aparece un while que depende de N, y la llamada a la funcion AUXILIAR, donde se llama recursivamente hasta vaciar 'Paux', proceso el cual tambien depende de N

-Complejidad total 'RECURSIVA' : O(n) + O(n) = *O(n), COMPLEJIDAD LINEAL*

*EJERCICIO 7:*

-Complejidad algortimica : 
-Complejidad total :

*EJERCICIO 8:*

-Complejidad algortimica : 
-Complejidad total :