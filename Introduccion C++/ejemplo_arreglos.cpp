#include <iostream>
using namespace std;

int main() {
    const int TAMANO = 5;
    char arreglo[TAMANO];
    cout << "Ingrese " << TAMANO << " char para llenar el arreglo:\n";
    
    // Alternativa: pedir el tamaño del arreglo por consola y declarar el arreglo.
    // int tamanio;
    // cout<< "Ingrese el tamaño del arreglo:\n";
    // cin >> tamanio;
    // char arreglo[tamanio];
    
    for (int i = 0; i < TAMANO; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    cout << "El arreglo ingresado es: ";
    for (int i = 0; i < TAMANO; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}
