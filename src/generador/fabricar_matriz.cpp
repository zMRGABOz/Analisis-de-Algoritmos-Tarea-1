#include "../matriz/matriz.h"
#include <random>

enum Tipo {
    NORMAL,
    IDENTIDAD,
    TRIANGULAR_SUP,
    TRIANGULAR_INF,
    SIMETRICA,
    DIAGONAL,
    DISPERSA,
    ESCALAR,
    DECIMAL
};

Matriz fabricar_matriz(Tipo tipo, int n) {
    Matriz matriz(n, n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 20.0);
    std::uniform_real_distribution<> dis_decimal(0.0, 1.0);

    switch(tipo) {
        case NORMAL:{
            auto& datos = matriz.get_data_vector();
            for(double& celda : datos){
                celda = dis(gen);
            }
            break;
        }

        case IDENTIDAD:
            for(int i = 0; i < n; ++i) matriz(i, i) = 1.0;
            break;

        case ESCALAR: {
            double valor_fijo = dis(gen);
            for(int i = 0; i < n; ++i) matriz(i, i) = valor_fijo;
            break;
        }

        case SIMETRICA:
            for(int i = 0; i < n; ++i) {
                for(int j = i; j < n; ++j) { // Empezamos j = i
                    double v = dis(gen);
                    matriz(i, j) = v;
                    matriz(j, i) = v; // Espejo inmediato
                }
            }
            break;

        case TRIANGULAR_SUP:
            for(int i = 0; i < n; ++i)
                for(int j = i; j < n; ++j) matriz(i, j) = dis(gen);
            break;

        case TRIANGULAR_INF:
            for(int i = 0; i < n; ++i)
                for(int j = 0; j <= i; ++j) matriz(i, j) = dis(gen);
            break;

        case DISPERSA: {
            std::uniform_int_distribution<> prob(0, 99); // Para el porcentaje
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(prob(gen) < 30) matriz(i, j) = dis(gen); // 30% de probabilidad de ser no cero
            break;
        }

        case DIAGONAL:
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    matriz(i, j) = (i == j) ? dis(gen) : 0.0;
            break;

        case DECIMAL:
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    matriz(i, j) = dis_decimal(gen);
            break;
    }

    return matriz;
}
