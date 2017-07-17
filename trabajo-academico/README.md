# Trabajo académico

Se compila usando gcc. Se da la opción de usar CMake.

Para Linux:

`gcc mainlinux.c graph.c graphalgorithms.c priority_queue.c queue.c -o cgmetrics`

Para Windows:

`gcc main.c graph.c graphalgorithms.c priority_queue.c queue.c -o cgmetrics`

Para ver ayuda, se puede escribir `./cgmetrics --help`. Se muestran todas las opciones posibles.

------------------------------
Uso:
 
`./cgmetrics.exe nthreads type nerdos proption nrep < autoria.txt > graphoutput.txt`

* **nthreads**: Cantidad de threads en paralelo a ejecutar (default = 1).

* **type**: 1: Calcula la métrica de cercanía usual. 2: La harmónica. 0: No calcula closeness (default = 1).

* **nerdos**: Cantidad de autores con mayor métrica a hallar en cada caso (default = 10).

* **nrep**: Cantidad de repeticiones de cada algoritmo, con fines de usar un tiempo promedio (default = 1).

* **proption**: Opción de inicialización de vértices en PageRank.
0: Inversa de |V|, 1: Degree, 2: Closeness (default = 0).

* **exp**: Exponente de epsilon = 10^-exp, usado para PageRank (default = 10).

* **alpha**: Factor amortiguador para PageRank, en formato dd -> 0.dd (default = 85).
