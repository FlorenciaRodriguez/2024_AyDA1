#ifndef ARBIN_H
#define ARBIN_H
#include <iostream>

template <typename T>
class Arbin{
private:

    class NodoArbin {
    private:
        T dato;
        Arbin<T> * pizq;
        Arbin<T> * pder;
    public:
        NodoArbin (const T& elem, Arbin<T>* izq , Arbin<T>* der)
        {
            dato = elem;
            pizq = new Arbin<T>(*izq);
            pder = new Arbin<T>(*der);
        }

        const T & getDato() const
        {
            return dato;
        }
        Arbin <T> * obtenerIzquierda () const
        {
            return pizq;
        }
        Arbin <T> * obtenerDerecha () const
        {
            return pder;
        }

    };
    NodoArbin * inicio;
    void vaciar(Arbin<T> * arbol);

    NodoArbin * copiar(const Arbin<T> & otro)
    {
        if (otro.esVacio())
            return NULL;
        else
        {
            if (otro.esHoja())
            {
                return new NodoArbin(otro.raiz(),otro.arbolIzquierdo(),otro.arbolDerecho());
            }
            else
            {
                Arbin<T> *izq = new Arbin<T>;
                izq->inicio = copiar(*otro.arbolIzquierdo());
                Arbin<T> *der = new Arbin<T>;
                der->inicio = copiar(*otro.arbolDerecho());
                return new NodoArbin(otro.raiz(),izq,der);
            }
        }
}

public:
    Arbin();
    Arbin(const Arbin<T> & otro);
    ~Arbin();

    void construir (Arbin<T>* izq,Arbin<T>* der, const T & dato);

    const T & raiz () const;
    Arbin<T>*  arbolIzquierdo() const;
    Arbin<T>*  arbolDerecho() const;

    bool esVacio() const;
    bool esHoja() const;

    int altura() const;
    bool existeElemento(const T& elem) const;
    int cantidadNodos () const;

    bool operator== (const Arbin <T>& otro) const;
    Arbin<T> &operator= (const Arbin <T>& otro);

    void preOrden(std::ostream & salida) const;

};
#endif // ARBIN_H
