#include <iostream>
#include "mostrararreglo.h"
template<typename T>
void bubbleSortRecursivo(T arr[], int n) {
    // Caso base: Si el tamaño del arreglo es 1, ya está ordenado
    if (n <= 1) {
        return;
    }

    // Realizar una pasada del algoritmo de Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }

    // Llamada recursiva para ordenar el resto del arreglo
    bubbleSortRecursivo(arr, n - 1);
}
template<typename T>
void bubbleSort(T arr[], int n) {
    bubbleSortRecursivo(arr, n);
}


int main() {
    char arr[] = {'6', '3', '2', 'a', '5', '1', '9'};
    int n = 7;

    std::cout << "Arreglo original: ";
    mostrarArreglo(arr, n);

    bubbleSort(arr, n);

    std::cout << "Arreglo ordenado por Bubble Sort: ";
    mostrarArreglo(arr, n);

    return 0;
}
