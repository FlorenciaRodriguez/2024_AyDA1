#include "Arbin.h"
#include <cassert>

template<typename T>
Arbin<T>::Arbin()
{
    //std::cout<< "Constructor vacio"<<std::endl;
    inicio = NULL;
}

template<typename T>
Arbin<T>::Arbin(const Arbin<T> & otro)
{
   if (otro.inicio == NULL)
        inicio = NULL;
    else
        inicio = copiar(otro);
}

template<typename T>
Arbin<T>::~Arbin()
{
    vaciar(this);
}

template<typename T>
void Arbin<T>:: vaciar(Arbin<T> * a)
{
    if (a->inicio != NULL)
    {
        vaciar(a->arbolIzquierdo());
        vaciar(a->arbolDerecho());
        delete a->inicio;
        a->inicio = NULL;
        delete a;
    }
}

template<typename T>
void Arbin<T>::construir( Arbin<T>* izq, Arbin<T>* der, const T & dato)
{
    Arbin<T> * i = new Arbin<T>(*izq);
    Arbin<T> * d = new Arbin<T>(*der);
    this->inicio = new NodoArbin(dato,i,d);

}

template <typename T>
const T & Arbin<T>::raiz() const {
    assert (inicio);
    return inicio->getDato();
}

template <typename T>
Arbin<T>* Arbin<T>::arbolIzquierdo() const {
    assert (inicio);
    return inicio->obtenerIzquierda();
}

template <typename T>
Arbin<T>* Arbin<T>::arbolDerecho() const {
    assert (inicio);
    return inicio->obtenerDerecha();
}

template <typename T>
bool Arbin<T>::esVacio()const {
	return(inicio==NULL);
}
template <typename T>
bool Arbin<T>::esHoja()const {
    assert (inicio);
    return ((inicio->obtenerIzquierda()->inicio == NULL) &&
            (inicio->obtenerDerecha()->inicio == NULL));
}

template <typename T>
int Arbin<T>::altura() const
{
    if (this->esVacio())
        return 0;
    if (this->esHoja())
        return 1;
    int alturaDer = inicio->obtenerDerecha()->altura();
    int alturaIzq = inicio->obtenerIzquierda()->altura();
    if (alturaDer > alturaIzq)
        return 1+ alturaDer;
    else
        return 1 + alturaIzq;
}

template <typename T>
bool Arbin<T>::existeElemento(const T& elem) const
{
   if (this->esVacio())
	   return false;
   if (this->inicio->getDato()== elem)
	   return true;

   return inicio->obtenerDerecha()->existeElemento(elem)||
            inicio->obtenerIzquierda()->existeElemento(elem);
}


template <typename T>
int Arbin<T>::cantidadNodos() const
{   if (this->esVacio())
        return 0;
    return 1 +
        this->inicio->obtenerIzquierda()->cantidadNodos() +
        this->inicio->obtenerDerecha()->cantidadNodos();
}


template <typename T>
bool Arbin<T>::operator== (const Arbin<T>& otroArbol)const
{
    if (this->esVacio() && otroArbol.esVacio())
        return true;
    if (!this->esVacio() &&  !otroArbol.esVacio() )
        return  (this->inicio->getDato() == otroArbol.inicio->getDato() ) &&
           this->inicio->obtenerIzquierda()->operator== ( *otroArbol.inicio->obtenerIzquierda() ) &&
           this->inicio->obtenerDerecha()->operator== ( *otroArbol.inicio->obtenerDerecha() );
   else
        return false;
}

template<typename T>
Arbin<T> & Arbin<T>::operator= (const Arbin<T> & otro)
{
    if (otro.inicio == NULL)
        inicio = NULL;
    else
        inicio = copiar(otro);//new NodoArbin(otro.inicio->getDato(),otro.inicio->obtenerIzquierda(),otro.inicio->obtenerDerecha());
}

template <typename T>
void Arbin<T>::preOrden(std::ostream & salida) const {
    if (!this->esVacio()) {
         salida << inicio->getDato()<<std::endl ;
         inicio->obtenerIzquierda()->preOrden(salida);
         inicio->obtenerDerecha()->preOrden(salida);
    }
}


template class Arbin<int>;
template class Arbin<char>;
template class Arbin<float>;
