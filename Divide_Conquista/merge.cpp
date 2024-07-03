#include "mostrar_arreglo.h"
template <typename T>
void merge(T arr[], int ini, int mid, int fin)
{
    int n1 = mid - ini + 1;
    int n2 = fin - mid;

    T *izquierdo = new T[n1];
    T *derecho = new T[n2];

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        izquierdo[i] = arr[ini + i];
    for (int j = 0; j < n2; j++)
        derecho[j] = arr[mid + 1 + j];

    // Mezclar los arreglos temporales
    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2)
    {
        if (izquierdo[i] <= derecho[j])
        {
            arr[k] = izquierdo[i];
            i++;
        }
        else
        {
            arr[k] = derecho[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = izquierdo[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = derecho[j];
        j++;
        k++;
    }

    delete[] izquierdo;
    delete[] derecho;
}
template <typename T>
void mergeSort(T arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mezclar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

int main()
{
    // int arr[] = {12, 11, 13, 5, 6, 7};
    char arr[] = {'i', 'd', 'e', 'z', '6', 'a'};
    int arr_size = 6;

    std::cout << "Arreglo original: ";
    mostrarArreglo(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Arreglo ordenado: ";
    mostrarArreglo(arr, arr_size);

    delete [] arr;

    return 0;
}
