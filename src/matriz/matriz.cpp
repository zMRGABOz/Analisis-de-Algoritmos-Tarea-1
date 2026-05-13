#include "matriz.h"

Matriz::Matriz(int filas, int columnas): filas(filas), columnas(columnas), coeficientes(filas * columnas, 0.0){}

std::vector<double>& Matriz::get_data_vector(){
    return coeficientes;
}

const std::vector<double>& Matriz::get_data_vector() const{
    return coeficientes;
}

int Matriz::get_filas() const{
    return filas;
}

int Matriz::get_columnas() const{
    return columnas;
}
