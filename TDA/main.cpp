// main.cpp
#include "Pila.h"
#include <iostream>

int main() {
    Pila pila(5); 

    pila.apilar(1);
    pila.apilar(2);
    pila.apilar(3);
    pila.apilar(4);
    pila.apilar(5);

    std::cout << "Cantidad de elementos: " << pila.getCantidad() << std::endl;

    std::cout << "Top element: " << pila.getTope() << std::endl;

    pila.desapilar();
    pila.desapilar();

    std::cout << "Cantidad de elementos después de desapilar: " << pila.getCantidad() << std::endl;

    if (pila.esVacia()) {
        std::cout << "Pila vacia" << std::endl;
    } else {
        std::cout << "Pila no vacia" << std::endl;
    }

    return 0;
}