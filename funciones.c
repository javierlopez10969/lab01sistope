#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <pthread.h>
#include "estructuras.h"
#include "funciones.h"

int leerArchivo(char * pathname){
    int f1;
    if (( f1 = open(pathname, O_RDONLY)) == -1) {
        printf("Error al abrir archivo\n");
        return -1;
    }
    return 0;
}