# Analisis-de-Algoritmos-Tarea-1

# Integrantes:
* Gabriel Sebastián Castillo Castillo
* Marcos Emiliano Martínez Rojas
* Daniel Alexander Tamaro Sierra

## Estructura del Proyecto


```text
Analisis-de-Algoritmos-Tarea-1/
├── resultados/
│   ├── csv/           # Archivos csv de salida
│   └── graficas/      # Gráficas de los resultados
├── src/
│   ├── algoritmos/    # Algortimos de multiplicación de matrices
│   ├── generador/     # Código para generar las matrices de prueba
│   └── matriz/        # Clase para el manejo de matrices
└── urh/               # Utilidades sugeridas para las pruebas
```

## Instrucciones de Compilacion

Para compilar la herramienta de pruebas se debe de ejecutar el siguiente comando:

```bash
g++ -std=c++11 -O0 -o uhr/uhr uhr/uhr.cpp src/matriz/matriz.cpp
```

## Ejecución de Pruebas

Para facilitar la ejecución de los experimentos se ha creado el script `run_experiments.sh`. 

Este script ejecutará las pruebas para los algoritmos y los distintos tipos de matrices, y sus resultados se almacenarán en  `resultados/csv/`.

Para ejecutar el script se debe de ingresar el siguiente comando desde la terminal:

```bash
./run_experiments.sh
```

