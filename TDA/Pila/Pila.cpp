#include <iostream>
#include <cassert>
#include "Pila.h"
template <typename T>
Pila<T>::Pila()
{
    tope = NULL;
    cantElementos = 0;
    assert(cantElementos == 0);
}
template <typename T>
void Pila<T>::vaciar()
{
    while (tope!= NULL && !esVacia())
        desapilar();
}
template <typename T>
Pila<T>::~Pila()
{
    vaciar();
    assert(cantElementos == 0);
}
template <typename T>
void Pila<T>::apilar(const T &element)
{

    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->elemento = element;
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
    cantElementos++;
    assert(cantElementos != 0);
}

template <typename T>
void Pila<T>::desapilar()
{
    assert(!esVacia());
    cantElementos--;
    Nodo *temp = tope;
    tope = temp->siguiente;
    temp->siguiente = NULL;
    delete temp;
}
template <typename T>
const T& Pila<T>::getTope() const
{
    assert(!esVacia());
    return tope->elemento;
}
template <typename T>
bool Pila<T>::esVacia() const
{
    return cantElementos == 0;
}
template <typename T>
int Pila<T>::getCantidad() const
{
    return cantElementos;
}
template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T> &otro)
{
    Nodo *aux = otro.tope;
    Nodo *ultimo = NULL;
    Nodo *topeNuevo = NULL;

    while (aux != NULL)
    {
        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->elemento = aux->elemento;
        nuevoNodo->siguiente = NULL;

        if (topeNuevo == NULL)
        {
            topeNuevo = nuevoNodo;
        }
        else
        {
            ultimo->siguiente = nuevoNodo;
        }

        ultimo = nuevoNodo;
        aux = aux->siguiente;
    }

    tope = topeNuevo;
    cantElementos = otro.cantElementos;
    return *this;
}

template class Pila<int>;
template class Pila<char>;
