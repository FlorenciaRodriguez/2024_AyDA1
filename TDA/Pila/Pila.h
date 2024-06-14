// Pila_H
#ifndef Pila_H
#define Pila_H

class Pila
{
public:
    Pila();
    void apilar(int element);
    void desapilar();
    int getTope() const;
    bool esVacia() const;
    int getCantidad() const;

private:
    int capacidad;
    // int *tope;
    int cantElementos;
    struct Nodo
    {
        int elemento;
        Nodo *siguiente;
    };
    Nodo *tope;
};

#include "Pila.cpp"

#endif // Pila_H
