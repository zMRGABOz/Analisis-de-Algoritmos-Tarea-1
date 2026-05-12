#include <iostream>
#include <stdexcept>
#include "../matriz/matriz.h"

Matriz clasico(const Matriz& A, const Matriz& B){
    int n1 = A.get_filas();
    int n2 = A.get_columnas();
    int n3 = B.get_columnas();
    if( A.get_columnas() != B.get_filas()){
        throw std::invalid_argument("No es posible la multiplicación de matrices.");
    }

    Matriz C = Matriz(n1, n3);

    for(int i = 0; i < n1; i++ ){
        for(int j = 0; j < n3; j++){
            for(int k = 0; k < n2; k++ ){
                C(i,j) = C(i,j) + A(i,k)*B(k,j);
            }
        }
    }
    return C;
}