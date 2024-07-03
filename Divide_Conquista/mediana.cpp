#include <iostream>
template <typename T>
T findMedianUtil(T arr1[], T arr2[], int left1, int right1, int left2, int right2)
{
    if (right1 - left1 == 1 && right2 - left2 == 1)
    {
        return std::min(arr1[right1], arr2[right2]);
    }

    int mid1 = left1 + (right1 - left1) / 2;
    int mid2 = left2 + (right2 - left2) / 2;

    int median1 = arr1[mid1];
    int median2 = arr2[mid2];

    if (median1 == median2)
    {
        return median1;
    }

    if (median1 < median2)
    {
        return findMedianUtil(arr1, arr2, mid1, right1, left2, mid2);
    }
    else
    {
        return findMedianUtil(arr1, arr2, left1, mid1, mid2, right2);
    }
}

template <typename T>
T findMedian(T arr1[], T arr2[], int n)
{
    return findMedianUtil(arr1, arr2, 0, n - 1, 0, n - 1);
}

int main()
{
    int arr1[] = {1, 12, 15, 26};
    int arr2[] = {2, 13, 17, 30};
    int n = 4;

    int median = findMedian(arr1, arr2, n);

    std::cout << "La mediana de los dos arreglos es: " << median << std::endl;

    char arr3[] = {'a', 'c', 'e', 'g', 'i', 'j', 'k', 'l'};
    char arr4[] = {'b', 'h', 'o', 'p', 'q', 'r', 's', 't'};
    int n2 = 8;

    char median1 = findMedian(arr3, arr4, n2);

    std::cout << "La mediana de los dos arreglos es: " << median1 << std::endl;
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}
