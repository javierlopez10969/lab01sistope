//En  este archivo van las cabeceras de las funciones.
#ifndef funciones_h_
#define funciones_h_

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

//Entradas: explicar qué se recibe
//Funcionamiento: explicar qué hace
//Salidas: explicar qué se retorna
int leerArchivo(char * pathname , int filas, int columnas,float * buffer,int N);
float *  zoomIN(int filas, int columnas,float * buffer ,int factor, int N);
void printBuffer(int filas, int columnas, float * buffer);
int escribirImagen(char * salidaName , int filas, int columnas,float * buffer,int N);
//fin de directivas
#endif // funciones_h_