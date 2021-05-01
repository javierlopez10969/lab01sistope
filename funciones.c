#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <pthread.h>
#include "estructuras.h"
#include "funciones.h"

//Entradas: explicar qué se recibe
//Funcionamiento: explicar qué hace
//Salidas: explicar qué se retorna
int leerArchivo(char * pathname , int filas, int columnas,float * buffer,int N){
    int f1;
    if ((f1 = open(pathname,O_RDONLY)) == -1) {
        printf("Error al abrir archivo\n");
        exit(-1);
    }

    int nbytes;
    if ((nbytes = read(f1, buffer, N)) != N) {
        printf("Tamaño incorrercto de filas y columnas\n");
        exit(-1);
    }
    close(f1);
    return 1;
}
void printBuffer(int filas, int columnas, float * buffer){
    int k = 0;
    for(int j = 0 ; j < columnas *filas; j++){
      printf("%f, ",buffer[j]);
      k++;
      if(k == columnas){
          printf("\n\n");
          k = 0;
      }
    }
}
int escribirImagen(char * salidaName , int filas, int columnas,float * buffer,int N){

    int f2;
    if ((f2 = open(salidaName, O_WRONLY | O_CREAT )) == -1) {
        printf("Error al abrir archivo\n");
        exit(-1);
    }

    elif (f2  == 1) {
        printf("Se abrio correctamente\n");
        exit(-1);
    }

    if(write(f2, buffer, N) != -1){

    } 

    return 1;

}
 
float * zoomIN(int filas, int columnas,float * buffer ,int factor, int N){
    float * newBuffer = (float*)malloc(sizeof(float)*N*factor);
    return newBuffer;
}