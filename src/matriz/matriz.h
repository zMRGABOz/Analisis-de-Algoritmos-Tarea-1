#ifndef MATRIZ_H
#define MATRIZ_H
#include <vector>

class Matriz{
private:
    std::vector<double> coeficientes;
    int filas;
    int columnas;

public:
    Matriz(int filas, int columnas);

    inline double& operator()(int fila, int columna){
        return coeficientes[fila * columnas + columna];
    }

    inline const double& operator()(int fila, int columna) const{
        return coeficientes[fila * columnas + columna];
    }
};

#endif