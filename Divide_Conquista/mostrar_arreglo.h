#ifndef MOSTRAR_ARR_H
#define MOSTRAR_ARR_H
#include <iostream>
using namespace std;
template <typename T>
void mostrarArreglo(T *arr, int n)
{

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
#endif // MOSTRAR_ARR_H
