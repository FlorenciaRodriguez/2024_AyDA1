#include "Pila.h"
#include <cassert>

Pila::Pila(){ 
    //tope = new int[n];
    tope = nullptr;
    cantElementos=0;
    //capacidad=0;
    assert(cantElementos==0);
}

void Pila::apilar(int element) {
    //assert(cantElementos >= capacidad); 
    //tope[cantElementos] = element;
    Nodo* nuevoNodo;
    nuevoNodo->elemento=element;
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
    cantElementos++;
    assert(cantElementos != 0);
}

void Pila::desapilar() {
    assert(!esVacia());
    cantElementos--;
    Nodo* temp = tope;
    tope = temp->siguiente;
}

int Pila::getTope() const {
    assert(!esVacia()); 
    //return tope[cantElementos - 1];
    return tope->elemento;
}

bool Pila::esVacia() const {
    return cantElementos == 0;
}

int Pila::getCantidad() const {
    return cantElementos;
}
/** 
Pila::~Pila() {

    while (tope!= nullptr) {
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
    cantElementos=0;
    //capacidad=0;
    assert(cantElementos==0);
}
*/