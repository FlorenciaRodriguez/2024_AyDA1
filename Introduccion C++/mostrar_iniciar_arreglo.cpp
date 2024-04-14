#include <iostream>

using namespace std;

const int TAMANO = 5;
void inicializarArreglo(char arreglo[]) {
    cout << "Ingrese " << TAMANO << " chars para llenar el arreglo:" << std::endl;

    for (int i = 0; i < TAMANO; ++i) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

void mostrarArreglo (const char arreglo[]) {
    cout << "El arreglo ingresado es: ";
    for (int i = 0; i < TAMANO; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
int main() {
    char arreglo[TAMANO];
    inicializarArreglo(arreglo);
    mostrarArreglo(arreglo);
    return 0;
}
