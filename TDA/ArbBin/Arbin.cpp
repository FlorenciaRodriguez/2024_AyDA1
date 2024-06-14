#include "Arbin.h"
#include <cassert>
#include <iostream>

template <typename T>
Arbin<T>::Arbin() {
	inicio = NULL;
}

template <typename T>
Arbin<T>::~Arbin () {
	vaciar (this);
}

template <typename T>
void Arbin<T>::vaciar(Arbin<T>* a) {
    if (a->inicio != NULL) {
        vaciar(a->arbol_izquierdo());
        vaciar(a->arbol_derecho());

        delete a->inicio;
        a->inicio = NULL;
        delete a;
    }
}

template <typename T>
Arbin<T>::Arbin(const Arbin<T>& otroArbol) {
    inicio = NULL;
    this->operator=(otroArbol);
   }

template <typename T>
void Arbin<T>::construir(Arbin<T>* izq, Arbin<T>* der, const T & dato) {
	Arbin* i = new Arbin(*izq);
	Arbin* d = new Arbin(*der);
	inicio =  new NodoArbol(dato,i,d);
}

template <typename T>
const T & Arbin<T>::raiz() const {
    assert (inicio);
    return inicio->obtener_dato();
}

template <typename T>
Arbin<T>* Arbin<T>::arbol_izquierdo() const {
    assert (inicio);
    return inicio->obtener_izquierda();
}

template <typename T>
Arbin<T>* Arbin<T>::arbol_derecho() const {
    assert (inicio);
    return inicio->obtener_derecha();
}

template <typename T>
bool Arbin<T>::es_vacio()const {
	return(inicio==NULL);
}

template <typename T>
bool Arbin<T>::es_hoja()const {
    assert (inicio);
    return ((inicio->obtener_izquierda()->inicio == NULL) &&
            (inicio->obtener_derecha()->inicio == NULL));
}

template <typename T>
Arbin<T> & Arbin<T>::operator= (const Arbin<T> & a) {
    vaciar(this);

    if (a.inicio == NULL )
        inicio = NULL;
    else
        inicio =  new NodoArbol (a.inicio->obtener_dato(),
                                (a.inicio->obtener_izquierda()),
                                (a.inicio->obtener_derecha()));

    return *this;
}


template <typename T>
int Arbin<T>::altura() const
{
   if (this->es_vacio()) return 0;
   if (this->es_hoja()) return 1;
   int alturaDer = inicio->obtener_derecha()->altura();
   int alturaIzq = inicio->obtener_izquierda()->altura();
   return (alturaDer > alturaIzq)? 1+ alturaDer : 1 + alturaIzq;
}


template <typename T>
bool Arbin<T>::existe_elemento(T& elem) const
{
   if (this->es_vacio()) return false;
   if (this->inicio->obtener_dato()== elem) return true;

   return inicio->obtener_derecha()-> existe_elemento(elem)||
                   inicio->obtener_izquierda()->existe_elemento(elem);
}


template <typename T>
int Arbin<T>::cantidadNodos() const
{   if (this->es_vacio()) return 0;
    return 1 +
        this->inicio->obtener_izquierda()->cantidadNodos() +
        this->inicio->obtener_derecha()->cantidadNodos();
}

template <typename T>
int Arbin<T>::operator== (const Arbin<T>& otroArbol)const
{ if (this->es_vacio() && otroArbol.es_vacio()) return true;
  if (!this->es_vacio() &&  !otroArbol.es_vacio() )
        return  (this->inicio->obtener_dato() == otroArbol.inicio->obtener_dato() ) &&
           this->inicio->obtener_izquierda()-> operator== ( *otroArbol.inicio->obtener_izquierda() ) &&
           this->inicio->obtener_derecha()-> operator== ( *otroArbol.inicio->obtener_derecha() );

   else
        return false;
}

template class Arbin<int>;
template class Arbin<char>;
