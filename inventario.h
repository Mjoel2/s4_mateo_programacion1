/*
 * inventario.h
 * Header con las constantes y los prototipos de las funciones.
 * Autor: Mateo Acero - NRC 2337
 */
#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 30

int leerCantidad();
void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int n);
void mostrarProductos(char nombres[][MAX_NOMBRE], float precios[], int n);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
int buscarMasCaro(float precios[], int n);
int buscarMasBarato(float precios[], int n);
int buscarProducto(char nombres[][MAX_NOMBRE], int n, char buscado[]);
