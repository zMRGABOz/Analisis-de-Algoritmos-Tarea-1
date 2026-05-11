#include <iostream>
#include "matriz.h"

Matriz::Matriz(int filas, int columnas): filas(filas), columnas(columnas), coeficientes(filas * columnas, 0.0){}