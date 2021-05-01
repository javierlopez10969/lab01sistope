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
    int i = 0;
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
    if ((f2 = open(salidaName, O_WRONLY | O_APPEND | O_CREAT, 0644)) == -1) {
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
    float * newBuffer = (float*)malloc(sizeof(float)*N*factor*factor);
    float elemento  = buffer[0];
    //Iterador que recorre el nuevo buffer
    int k = 0;
    int i = 0 ;
    int j = 0;
    int l = 0;
    while (i < filas*columnas){ 
        elemento  = buffer[i];
        //printf("buffer[%d] : %f \n",i ,elemento);
        //printf("k:%d, ",k);
        j = k
         while (j < factor){
            //aumentar por los lados y por abajo
            //Aumentamos por los lados
            newBuffer [j] = elemento;
            printf("ZOOM[%d] : %f \n",j,newBuffer[i]);
            //Aumentar hacia abajo
            l = j + (columnas*factor) + 1;
            while (l < factor-1){
                printf("ZOOM[%d] : %f \n",l,newBuffer[i]);
                newBuffer[l] =  elemento;
                l += columnas*factor;
            }       
            j++;     
        }
        //Divison exacta entre el iterador del nuevo buffer entre las cantidad de columnas o filas
        if(i != 0){
            if ( i % columnas == 0){
                //printf("\n AMIGA de 256 \n");
                k = k + columnas*factor +1;
            }else{
                //Pasar a la siguiente columna aumentada
                k = k + factor;
            }
        }
        else{
            //Pasar a la siguiente columna aumentada
            k = k + factor;
        }
        i++;
 
    }
    //printBuffer(columnas,filas,);
    *zoom = newBuffer;
}