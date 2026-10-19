/*
 * Programa: Inventario de productos de una tienda
 * Materia: ISWZ1102 - Programacion I
 * Autor: Mateo Acero - NRC 2337
 */
#include <stdio.h>
#include <string.h>
#include "inventario.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];   // nombres de los productos
    float precios[MAX_PRODUCTOS];             // precios de los productos
    char buscado[MAX_NOMBRE];
    int n, opcion, pos;

    printf("=== INVENTARIO DE LA TIENDA ===\n");
    n = leerCantidad();
    ingresarProductos(nombres, precios, n);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Ver inventario\n");
        printf("2. Precio total\n");
        printf("3. Producto mas caro y mas barato\n");
        printf("4. Precio promedio\n");
        printf("5. Buscar producto\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) opcion = 0;   // si escriben letras
        while (getchar() != '\n');                    // limpia la entrada

        switch (opcion) {
            case 1:
                mostrarProductos(nombres, precios, n);
                break;
            case 2:
                printf("Precio total: $%.2f\n", calcularTotal(precios, n));
                break;
            case 3:
                pos = buscarMasCaro(precios, n);
                printf("Mas caro: %s ($%.2f)\n", nombres[pos], precios[pos]);
                pos = buscarMasBarato(precios, n);
                printf("Mas barato: %s ($%.2f)\n", nombres[pos], precios[pos]);
                break;
            case 4:
                printf("Precio promedio: $%.2f\n", calcularPromedio(precios, n));
                break;
            case 5:
                printf("Nombre a buscar: ");
                scanf(" %29[^\n]", buscado);
                pos = buscarProducto(nombres, n, buscado);
                if (pos != -1)
                    printf("%s cuesta $%.2f\n", nombres[pos], precios[pos]);
                else
                    printf("El producto no existe.\n");
                break;
            case 6:
                printf("Fin del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 6);

    return 0;
}

// Pide cuantos productos se van a ingresar (de 1 a 10)
int leerCantidad() {
    int n;
    do {
        printf("Cuantos productos desea ingresar (1 a 10): ");
        if (scanf("%d", &n) != 1) n = 0;   // si escriben letras
        while (getchar() != '\n');
        if (n < 1 || n > MAX_PRODUCTOS) printf("Cantidad invalida.\n");
    } while (n < 1 || n > MAX_PRODUCTOS);
    return n;
}

// Pide el nombre y el precio de cada producto.
// El producto i tiene su nombre en nombres[i] y su precio en precios[i]
void ingresarProductos(char nombres[][MAX_NOMBRE], float precios[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: ");
        scanf(" %29[^\n]", nombres[i]);    // permite nombres con espacios
        do {
            printf("Precio: ");
            if (scanf("%f", &precios[i]) != 1) precios[i] = 0;   // si escriben letras
            while (getchar() != '\n');
            if (precios[i] <= 0) printf("Precio invalido, debe ser mayor a 0.\n");
        } while (precios[i] <= 0);
    }
}

// Muestra todos los productos
void mostrarProductos(char nombres[][MAX_NOMBRE], float precios[], int n) {
    int i;
    printf("\n--- INVENTARIO ---\n");
    for (i = 0; i < n; i++) {
        printf("%d. %-20s $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}

// Suma todos los precios
float calcularTotal(float precios[], int n) {
    int i;
    float total = 0;
    for (i = 0; i < n; i++) {
        total = total + precios[i];
    }
    return total;
}

// Promedio = total / numero de productos
float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

// Devuelve la posicion del producto mas caro
int buscarMasCaro(float precios[], int n) {
    int i, pos = 0;
    for (i = 1; i < n; i++) {
        if (precios[i] > precios[pos]) pos = i;
    }
    return pos;
}

// Devuelve la posicion del producto mas barato
int buscarMasBarato(float precios[], int n) {
    int i, pos = 0;
    for (i = 1; i < n; i++) {
        if (precios[i] < precios[pos]) pos = i;
    }
    return pos;
}

// Busca un producto por nombre. Devuelve su posicion, o -1 si no existe
int buscarProducto(char nombres[][MAX_NOMBRE], int n, char buscado[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(nombres[i], buscado) == 0) return i;
    }
    return -1;
}
