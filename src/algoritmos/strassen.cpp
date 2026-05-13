#include "../matriz/matriz.h"
#include "clasico.cpp"

Matriz strassen(const Matriz& A, const Matriz& B, int n0=1) {
    int n = A.get_filas();
    // CASO BASE: Si el tamaño es menor o igual a n0, usar multiplicación estándar
    // en caso de n0 = 1, se usa la versión clásica
    if (n <= n0) {
        return clasico(A, B);
    }

    // DIVIDIR: Calcular el tamaño de las submatrices
    int k = n / 2;

    // Crear submatrices (cuadrantes)
    Matriz A11(k, k), A12(k, k), A21(k, k), A22(k, k);
    Matriz B11(k, k), B12(k, k), B21(k, k), B22(k, k);

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A11(i, j) = A(i, j);
            A12(i, j) = A(i, j + k);
            A21(i, j) = A(i + k, j);
            A22(i, j) = A(i + k, j + k);

            B11(i, j) = B(i, j);
            B12(i, j) = B(i, j + k);
            B21(i, j) = B(i + k, j);
            B22(i, j) = B(i + k, j + k);
        }
    }

    // CONQUISTAR: Las 7 llamadas recursivas de Strassen
    Matriz M1 = strassen(A11 + A22, B11 + B22, n0);
    Matriz M2 = strassen(A21 + A22, B11, n0);
    Matriz M3 = strassen(A11, B12 - B22, n0);
    Matriz M4 = strassen(A22, B21 - B11, n0);
    Matriz M5 = strassen(A11 + A12, B22, n0);
    Matriz M6 = strassen(A21 - A11, B11 + B12, n0);
    Matriz M7 = strassen(A12 - A22, B21 + B22, n0);

    // COMBINAR: Construir la matriz resultado C
    Matriz C(n, n);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C(i, j) = M1(i, j) + M7(i, j) + M4(i, j) - M5(i, j);
            C(i, j + k) = M3(i, j) + M5(i, j);
            C(i + k, j) = M2(i, j) + M4(i, j);
            C(i + k, j + k) = M6(i, j) + M1(i, j) - M2(i, j) + M3(i, j);
        }
    }

    return C;
}
