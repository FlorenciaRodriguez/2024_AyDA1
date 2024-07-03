#include <iostream>
/** encontrar el valor más pequeño en un arreglo que disminuye hasta cierto valor y luego aumenta*/

int encontrarInflexion(int arr[], int ini, int fin)
{

    // Caso base: Si el arreglo tiene un solo elemento
    if (ini == fin)
    {
        return arr[ini];
    }

    // Caso base: Si el arreglo tiene dos elementos
    if (fin == ini + 1)
    {
        return std::min(arr[ini], arr[fin]);
    }

    int medio = ini + (fin - ini) / 2;

    // Verifica si el elemento del medio es el punto de inflexión
    if (arr[medio] < arr[medio - 1] && arr[medio] < arr[medio + 1])
    {
        return arr[medio];
    }

    // Si el medio es parte de la secuencia decreciente, busca en la mitad derecha
    if (arr[medio] > arr[medio + 1])
    {
        return encontrarInflexion(arr, medio + 1, fin);
    }
    else
    {
        // Si el medio es parte de la secuencia creciente, busca en la mitad izquierda
        return encontrarInflexion(arr, ini, medio - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int minimo = encontrarInflexion(arr, 0, n);
    delete[] arr;
    std::cout << "El valor mínimo en el arreglo es: " << minimo << std::endl;

    int arr1[] = {10, 7, 2, 1, -2, 8, 9, 23, 35, 58};
    int n1 = 10;
    int minimo1 = encontrarInflexion(arr1, 0, n1);
    delete[] arr1;
    std::cout << "El valor mínimo en el arreglo es: " << minimo1 << std::endl;

    return 0;
}
