#include <iostream>
#define MINIMO -999

int sumaMedia(int *arr, int ini, int mid, int fin)
{
    int sum = 0;
    int sumIzq = MINIMO;
    for (int i = mid; i >= ini; i--)
    {
        sum += arr[i];
        if (sum > sumIzq)
            sumIzq = sum;
    }

    sum = 0;
    int sumDer = MINIMO;
    for (int i = mid + 1; i <= fin; i++)
    {
        sum += arr[i];
        if (sum > sumDer)
            sumDer = sum;
    }

    return sumIzq + sumDer;
}

int subsecuenciaSumaMaxima(int *arr, int ini, int fin)
{
    if (ini == fin)
        return arr[ini];

    int mid = ini + (fin - ini) / 2;

    int izqSum = subsecuenciaSumaMaxima(arr, ini, mid);
    int derSum = subsecuenciaSumaMaxima(arr, mid + 1, fin);
    int mediaSum = sumaMedia(arr, ini, mid, fin);

    return std::max(izqSum, std::max(derSum, mediaSum));
}
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    int max_sum = subsecuenciaSumaMaxima(arr, 0, n - 1);

    // La subsecuencia de mayor suma es [4, -1, 2, 1] con una suma de 6.
    std::cout << "La suma de la subsecuencia de mayor suma es: " << max_sum << std::endl;

    return 0;
}
