#!/bin/bash

algoritmos=("STRASSEN" "CLASICO")
tipo_matrices=("NORMAL" "DISPERSA" "DECIMAL" "TRIANGULAR_SUP" "DIAGONAL")

for algoritmo in "${algoritmos[@]}"; do
    for tipo_matriz in "${tipo_matrices[@]}"; do
        ./uhr/uhr resultados/csv/resultados_"$tipo_matriz"_"$algoritmo".csv 32 512 2048 "$tipo_matriz" "$algoritmo"
    done
done
