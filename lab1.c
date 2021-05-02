//Autores: Javier López - Felipe Sepulveda
/*
• -I filename : especifica el nombre de la imagen de entrada
• -Z filename : especifica el nombre de la imagen resultante del zoom-in
• -S filaname : especifica el nombre de la imagen resultante del suavizado (a la resultante del zoom-in)
• -M numero : especifica el número de filas de la imagen
• -N numero : especifica el número de columnas de la imagen
• -r factor : factor de replicación para Zoom-in
• -b: bandera que indica si se entregan resultados por consola. En caso de que se ingrese este flag deberá
mostrar: dimensiones de la imagen antes y después de aplicar zoom-in
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "funciones.h"

int main(int argc, char **argv)
{
    char *nombreImagen = NULL;
    char *imagenZoom = NULL;
    char *imagenSuavizado = NULL;
    char c;
    int filas, columnas, bandera, factor, opterr;
    filas = 0;
    columnas = 0;
    bandera = 0;
    factor = 0;
    opterr = 0;
    opterr += 1;
    //el siguiente ciclo se utiliza para recibir los parametros de entrada usando getopt
    while ((c = getopt(argc, argv, "I:Z:S:M:N:r:b:")) != -1)
        switch (c)
        {
        case 'I':
            nombreImagen = optarg;
            break;
        case 'Z':
            imagenZoom = optarg;
            break;
        case 'S':
            imagenSuavizado = optarg;
            break;
        case 'M':
            sscanf(optarg, "%d", &filas);
            break;
        case 'N':
            sscanf(optarg, "%d", &columnas);
            break;
        case 'r':
            sscanf(optarg, "%d", &factor);
            break;
        case 'b':
            sscanf(optarg, "%d", &bandera);
            break;
        case '?':

            if (optopt == 'c')
            {
                fprintf(stderr, "Opcion -%c requiere un argumento.\n", optopt);
            }

            else if (isprint(optopt))
                fprintf(stderr, "Opcion desconocida `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Opcion con caracter desconocido `\\x%x'.\n",
                        optopt);
            return 1;

        default:
            abort();
    }

    if (nombreImagen == NULL || imagenSuavizado == NULL || imagenSuavizado == NULL || 
    filas == 0 || columnas == 0 ||factor == 0){
        printf("Faltan entradas para poder ejecutar el programa \n");
    }
    else if(columnas!= filas){
        printf("Cantidad de filas y columnas es distinto \n");
    }
    else{
        if (bandera != 0){
        printf("Nombre imagen de entrada : %s \n Imagen zoom : %s \n Imagen Suavizado: %s \n filas : %d \n columnas : %d \n factor : %d \n bandera : %d\n",
        nombreImagen, imagenZoom, imagenSuavizado, filas, columnas, factor, bandera);
        }


        //Tamaño de bytes (N)
        int N = (filas * columnas * 4);
        float *buffer = (float *)malloc(sizeof(float) * N);
        leerArchivo(nombreImagen, filas, columnas, buffer, N);

        //Procesar el zoom in
        float *zoom = NULL;
        zoomIN(filas, columnas, buffer, &zoom, factor, N);
        //printBuffer(filas*factor, columnas*factor, zoom);
        escribirImagen(imagenZoom, filas * factor, columnas * factor, zoom, N * factor * factor);

        //Procesar el suavizado
        float *suavizados = NULL;
        suavizado(filas, columnas, buffer, &suavizados, N);
        //printBuffer(filas,columnas,suavizados);
        escribirImagen(imagenSuavizado, filas, columnas, suavizados, N);

        //./lab1 -I cameraman_256x256.raw -Z salida_i_zoom.raw -S imagen_i_suavizado.raw -M 256 -N 256 -r 2 -b 1
        //liberar memoria dinamica
        free(buffer);
        free(zoom);
        free(suavizados);
    }
}