#include <iostream>
#include "mostrara_rreglo.h"

template <typename T>
int indiceParticion(T arr[], int ini, int fin)
{
    int pivote = arr[fin];
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++)
    {
        if (arr[j] < pivote)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[fin]);
    return (i + 1);
}
template <typename T>
void quickSort(T arr[], int ini, int fin)
{
    if (ini < fin)
    {
        int pi = indiceParticion(arr, ini, fin);

        quickSort(arr, ini, pi - 1);
        quickSort(arr, pi + 1, fin);
    }
}
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;
    std::cout << "Arreglo original para QuickSort: ";
    mostrarArreglo(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Arreglo ordenado por QuickSort: ";
    mostrarArreglo(arr, n);

    delete[] arr;

    return 0;
}
