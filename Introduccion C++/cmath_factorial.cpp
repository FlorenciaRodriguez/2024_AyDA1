#include <iostream>
#include <cmath> // La biblioteca cmath proporciona diversas funciones matematicas, como pow, sqrt, abs, entre otras
using namespace std;

int main() {
    int nro;
    cout << "Ingrese un numero para calcular su factorial: ";
    cin >> nro;
    nro = abs(nro);

    unsigned long resultado = 1;
    for (unsigned int i = 2; i <= nro; i++) {
        resultado *= i;
    }
    cout << "El factorial de " << nro << " es: " << resultado << endl;

    return 0;
}
