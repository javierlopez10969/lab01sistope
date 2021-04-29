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

$ ./lab1 -I imagen1.raw -Z imagen1Z.raw -S imagen1S.raw -M 512 -N 512 -r 2
./lab -I onion_135x198.raw -Z salidaZoom -S salidaSuave -M 10 -N 10 -r 10
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "funciones.h"

int main (int argc, char **argv) {
    char * nombreImagen = NULL;
    char * imagenZoom = NULL;
    char * imagenSuavizado = NULL;
    char c;
    int filas,columnas,bandera,factor,opterr;
    filas =0 ;
    columnas = 0;
    bandera = 0;
    factor= 0 ;
    opterr= 0;
    opterr+=1;    
    printf("Samuel\n");
    //el siguiente ciclo se utiliza para recibir los parametros de entrada usando getopt
    while ((c = getopt (argc, argv, "I:Z:S:M:N:r:b:")) != -1)
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

                if (optopt == 'c'){
                fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
                }
                
                else if (isprint (optopt))
                fprintf (stderr, "Opcion desconocida `-%c'.\n", optopt);
                else
                fprintf (stderr,
                        "Opcion con caracter desconocido `\\x%x'.\n",
                        optopt);
                return 1;

            default:
                abort ();
            }
    printf ("Nombre imagen de entrada : %s \n Imagen zoom : %s \n Imagen Suavizado: %s \n filas : %d \n columnas : %d \n factor : %d \n bandera : %d\n",
           nombreImagen, imagenZoom, imagenSuavizado, filas, columnas, factor, bandera);

    //cantidad de bytes
    int N = (filas * columnas)*4;
    float *buffer=(float*)malloc(sizeof(float)*N);

    int f1;
    if ((f1 = open(nombreImagen,O_RDONLY)) == -1) {
        printf("Error al abrir archivo\n");
        exit(-1);
    }

    int nbytes;
    if ((nbytes = read(f1, buffer, N)) != N) {
        printf("Tamaño incorrercto de filas y columnas\n");
        exit(-1);
    }
    close(f1);

    for(int x = 0 ; x < columnas * filas; x++){
      printf("%f ",buffer[x]);
    }
    
}