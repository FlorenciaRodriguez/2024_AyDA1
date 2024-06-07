#include <iostream>
#define INVALIDO -1
// Función para encontrar dos elementos en un arreglo ordenado que sumen "s"
int findTwoElements(int arr[], int i, int j,int s) {
    if (i == j){
        if (arr[i]==s){
            return i;}
        return INVALIDO;}
    else{
        int mid = (i+j)/2;
        if (arr[mid] == s)
            return mid;
        else{
            if (arr[mid] < s)
                return findTwoElements(arr,mid+1,j,s);
            else
                return findTwoElements(arr,i,mid+1,s);}

    }
   
}
bool encontrar(int * arr,int n,int s){
    bool estan = false;
    int i = 0;
    while(!estan && i<(n-1)){
        int complemento = s-arr[i];
        int j = findTwoElements(arr,i+1,n,complemento);
        if (j!=INVALIDO)
        {
           estan = true;
           std::cout<<"Elementos: arr["<<i<<"] = "<<arr[i]<<" y arr["<<j<<"] = "<<arr[j]<<std::endl;
        }
        i++;
        
    }
    return encontrar;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 20; // suma deseada
    bool buscaque=encontrar(arr,n,s);

    return 0;
}