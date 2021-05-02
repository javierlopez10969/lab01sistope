# Laboratorio número 1 

Laboratorio 1 de sistope hecho por Javier López y Felipe Sepulveda.

## Comandos para ejecutar
Para ejecutar estos scripts, abra una terminal y ejecute el siguiente comando para compilar:

### `make`

Entradas que recibe este laboratorio:
### • -I filename : especifica el nombre de la imagen de entrada
### • -Z filename : especifica el nombre de la imagen resultante del zoom-in
### • -S filaname : especifica el nombre de la imagen resultante del suavizado (a la resultante del zoom-in)
### • -M numero : especifica el número de filas de la imagen
### • -N numero : especifica el número de columnas de la imagen
### • -r factor : factor de replicación para Zoom-in
### • -b: bandera que indica si se entregan resultados por consola. En caso de que se ingrese este flag deberá

Para ejecutar el código sin mostrar nada por pantalla su bandera debe estar en 0, por default es cero, asi que si no ingresa nada quedará en 0.


### `./lab1 -I cameraman_256x256.raw -Z salida_i_zoom.raw -S imagen_i_suavizado.raw -M 256 -N 256 -r 2`

Para mostrar las entradas por pantalla ejecute :  

### `./lab1 -I cameraman_256x256.raw -Z salida_i_zoom.raw -S imagen_i_suavizado.raw -M 256 -N 256 -r 2 -b 1`

Si no entrega alguna de las entradas el programa no correrá. Tampoco correrá en caso de tener una cantidad distinta entre filas y columnas.
