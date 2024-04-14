#include <iostream>
using namespace std;
int main() 
{
    int numero = 0;
    int suma = 0;
    cout << "Ingrese numeros (ingrese 0 para terminar):\n";
    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
        if (numero != 0) {
            suma += numero;
        }
    } while (numero != 0);
    cout << "La suma de los numeros ingresados es: " << suma << endl;
    return 0;
}
