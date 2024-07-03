#include <iostream>
#define INVALIDO -1

int buscarDosElementos(int arr[], int i, int j, int s)
{
    if (i == j)
    {
        if (arr[i] == s)
        {
            return i;
        }
        return INVALIDO;
    }
    else
    {
        int mid = (i + j) / 2;
        if (arr[mid] == s)
            return mid;
        else
        {
            if (arr[mid] < s)
                return buscarDosElementos(arr, mid + 1, j, s);
            else
                return buscarDosElementos(arr, i, mid + 1, s);
        }
    }
}

// Función para encontrar dos elementos en un arreglo ordenado que sumen "s"
// Devuelve true si encuentra dos elementos cuya suma sea s
// La estrategia consiste en considerar el primer elemento, restarle a s el valor
// del primer elemento y ver si en el resto del arreglo hay algun elemento cuya suma
// complemente lo que le falta al primer elelmento para llegar a s.
// Mientras no lo encuentre, sigue buscando con el resto de los elementos.
bool existenElementosSumaS(int *arr, int n, int s)
{
    bool estan = false;
    int i = 0;
    while (!estan && i < (n - 1))
    {
        int complemento = s - arr[i];
        int j = buscarDosElementos(arr, i + 1, n, complemento);
        if (j != INVALIDO)
        {
            estan = true;
            std::cout << "Elementos: arr[" << i << "] = " << arr[i] << " y arr[" << j << "] = " << arr[j] << std::endl;
        }
        i++;
    }
    return estan;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Cuando se inicializa de esta forma no es necesario eliminarlo con delete
    int n = 9;
    int s = 7; // suma deseada
    bool buscar = existenElementosSumaS(arr, n, s);
    return 0;
}
