#include "matriz.h"

Matriz::Matriz(int filas, int columnas): filas(filas), columnas(columnas), coeficientes(filas * columnas, 0.0){}

Matriz operator+(const Matriz& A, const Matriz& B) {
    // Creamos la matriz de resultado del mismo tamaño
    Matriz res(A.filas, A.columnas);

    // Sumamos directamente los vectores de coeficientes
    for (std::size_t i = 0; i < A.coeficientes.size(); ++i) {
        res.coeficientes[i] = A.coeficientes[i] + B.coeficientes[i];
    }

    return res;
}

Matriz operator-(const Matriz& A, const Matriz& B) {
    // Creamos la matriz de resultado del mismo tamaño
    Matriz res(A.filas, A.columnas);

    // Restamos directamente los vectores de coeficientes
    for (std::size_t i = 0; i < A.coeficientes.size(); ++i) {
        res.coeficientes[i] = A.coeficientes[i] - B.coeficientes[i];
    }

    return res;
}

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
