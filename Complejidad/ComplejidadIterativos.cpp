#include <iostream>
#include <string>
using namespace std;

int get_gcd_euclides(int a, int b, int & cantEntradasBucle) {
    cantEntradasBucle = 0;

    // En a se almacena el minimo
    if (b > a){
        int aux = a;
        a = b;
        b = aux;
    }

    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
        cantEntradasBucle += 1;
    }
    return a;
}

int get_gcd_naive(int a, int b, int & cantEntradasBucle) {
    int gcd = 1;
    cantEntradasBucle = 0;
    int min_ = a; // La variable min_ almacena el valor minimo entre a y b para controlar la cantidad de iteraciones del for
    if (b < min_)
        min_ = b;
    for (int i = 1; i <= min_; i++) {
		  cantEntradasBucle += 1;
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int main() {
    int a = 100, cantEntradasBucle;

    // En arrB guardamos valores de b para armar las tablas de las filminas
    int arrB[] = {1,2,3,4,5,6,7,8,20,50,77,89,93};
    const int MAXB = 13;

    // its = iteraciones
    cout << "GCD(a;b) GCD_naive GCD_euclides #its_naive #its_euclides\n\n";
    for (int i = 0; i < MAXB; i++){
        int iteraciones_naive, iteraciones_euclides;
        int gcd_naive = get_gcd_naive(a, arrB[i], iteraciones_naive);
        int gcd_euclides = get_gcd_euclides(a, arrB[i], iteraciones_euclides);
        cout << "GCD(" << a << ";" << arrB[i] << ")\t" << gcd_naive << "\t" << gcd_euclides << "\t\t" << iteraciones_naive << "\t" << iteraciones_euclides << endl;
        //\t es el caracter especial usado para tabulacion
    }

    return 0;
}
/** Se puede simplificar la cantidad de lineas de codigo del minimo en la funcion de
*** GCD intuitiva reemplazando:
***    int min_ = a;
***    if (b<min_)
***      min_=b;
*** por
***     int min_ = a < b ? a : b;
*/

