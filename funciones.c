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
    int i = 1;
    int k = 0;
    for(int j = 0 ; j < columnas *filas; j++){
      printf("%f, ",buffer[j]);
      k++;
      if(k == columnas){
          printf("\n\n fila %d \n\n", i);
          k = 0;
          i++;
      }
    }
}
int escribirImagen(char * salidaName , int filas, int columnas,float * buffer,int N){

    int f2;
    if ((f2 = open(salidaName, O_WRONLY | O_CREAT , 0644)) == -1) {
        printf("Error al abrir archivo\n");
        exit(-1);
    }
    
    else if (f2  == 1) {
        printf("Se abrio correctamente\n");
        exit(-1);
    }

    if(write(f2, buffer, N) != -1){
        printf("Se ha escrito corectamente el archivo : %s\n" , salidaName);
    } 
    close(f2);
    
    return 1;

}
//Entradas: cantidad de filas, 
//cantidad de columnas, 
//buffer con los datos de la imagen,
//factor en el que se debehacer el zoom, N (cantidad de bytes)= Filas x Columnas x 4
//Funcionamiento: Realiza el proceso de zoomo in a la imagen de entrada
//Salidas: Nuevo buffer donde su contenido corresponde a la imagen posterior al proceso de zoom in.
void zoomIN(int filas, int columnas,float * buffer , float ** zoom,int factor, int N){
    //(filas * factor) * (columnas * factor) * 4 = (N) * factor * factor
    float * newBuffer = (float*)malloc(sizeof(float)*N*factor);
    float elemento  = buffer[0];
    //Iterador que recorre el nuevo buffer
    int k = 0;
    int i = 0 ;
    int j = 0;
    int l = 0;
    //Hacer las primeras N*factor columnas   * M filas
    while (i < filas*columnas){ 
        elemento  = buffer[i];
        //printf("buffer[%d] : %f \n",i ,elemento);
        //printf("k:%d, ",k);
        j = 0;
        while (j < factor){
            //aumentar por los lados y por abajo
            //Aumentamos por los lados
            newBuffer [k] = elemento;
            //printf("[%d] : ", k);
            //printf("%f ,",  newBuffer[k]);
            k++; 
            j++;         
        }
        if(i!=0){
            if(k%(columnas*factor) ==0){
                //printf("\n\n fila %d \n\n", l);
                l++;
            }
        }
        i++; 
    }
    i = 0;
    j = 0;
    k = 0;
    l=0;
    int z  = 0;
    float * bufferFinal = (float*)malloc(sizeof(float)*N*factor*factor);
    while (i < columnas*filas*factor*factor){
        j=0;
        while (j < factor){
            l = 0;
            k = z;
            while(l < columnas*factor){
                bufferFinal[i] = newBuffer[k]; 
                //printf("i : %d,",i);
                //printf("k : %d, \n",k);
                l++;
                i++;
                k++;
            }
            j++;
        }
        z = k;

    }
    


    //printBuffer(filas*factor,columnas*factor,newBuffer);
    *zoom = bufferFinal; 
}

