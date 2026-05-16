#!/bin/bash

n0=("256" "128" "64" "32" "16")

for n in "${n0[@]}"; do
    
    ./uhr/uhr resultados/csv/resultados_NORMAL_HIBRIDO_BASE"$n".csv 32 512 2048 NORMAL HIBRIDO "$n"
    
done
