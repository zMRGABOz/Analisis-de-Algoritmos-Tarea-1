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

    friend Matriz operator+(const Matriz& A, const Matriz& B);
    friend Matriz operator-(const Matriz& A, const Matriz& B);

    inline double& operator()(int fila, int columna){
        return coeficientes[fila * columnas + columna];
    }

    inline const double& operator()(int fila, int columna) const{
        return coeficientes[fila * columnas + columna];
    }

    // Versión para modificar
    std::vector<double>& get_data_vector();

    // Versión para solo lectura
    const std::vector<double>& get_data_vector() const;

    int get_filas() const;

    int get_columnas() const;
};

#endif
