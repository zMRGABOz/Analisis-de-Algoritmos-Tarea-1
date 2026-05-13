// Para compilar: g++ -o test_matriz test_matriz.cpp  ../matriz/matriz.cpp -O2
// ./test_matriz

#include <iostream>
#include <iomanip>
#include "../matriz/matriz.h"
#include "fabricar_matriz.cpp"

// Función auxiliar para imprimir matrices en consola
void imprimir_matriz(const Matriz& m, std::string nombre) {
    std::cout << "--- Matriz " << nombre << " (" << m.get_filas() << "x" << m.get_columnas() << ") ---" << std::endl;
    for (int i = 0; i < m.get_filas(); ++i) {
        std::cout << "[ ";
        for (int j = 0; j < m.get_columnas(); ++j) {
            // Usamos setw(6) para que los números no se amontonen
            std::cout << std::fixed << std::setprecision(1) << std::setw(6) << m(i, j) << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n = 5; // Tamaño matriz

    // 1. Probar Identidad
    Matriz id = fabricar_matriz(IDENTIDAD, n);
    imprimir_matriz(id, "IDENTIDAD");

    // 2. Probar Escalar
    Matriz esc = fabricar_matriz(ESCALAR, n);
    imprimir_matriz(esc, "ESCALAR");

    // 3. Probar Triangular Superior
    Matriz sup = fabricar_matriz(TRIANGULAR_SUP, n);
    imprimir_matriz(sup, "TRIANGULAR SUPERIOR");

    // 4. Probar Simétrica
    Matriz sim = fabricar_matriz(SIMETRICA, n);
    imprimir_matriz(sim, "SIMETRICA");

    // 5. Probar Dispersa
    Matriz dis = fabricar_matriz(DISPERSA, 6); // Un poco más grande para ver los huecos
    imprimir_matriz(dis, "DISPERSA (30%)");

    return 0;
}
