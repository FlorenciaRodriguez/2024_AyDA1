#ifndef ARBIN_H
#define ARBIN_H

template <typename T>
class Arbin {
private:

    class NodoArbol {
        public:
            NodoArbol(const T & elem, Arbin* l, Arbin* r): dato(elem), pizq(l), pder(r) {};
            const T & obtener_dato() const {return dato;}
            Arbin * obtener_izquierda() const {return pizq;}
            Arbin * obtener_derecha() const {return pder;}
        private:
            T dato;
            Arbin* pizq;
            Arbin* pder;
    };

    void vaciar (Arbin* raiz);

public:
    Arbin();
    virtual ~Arbin();

    Arbin(const Arbin& otroArbol);
    void construir(Arbin* izq, Arbin* der, const T & dato);

    const T & raiz() const ;
    Arbin* arbol_izquierdo() const;
    Arbin* arbol_derecho() const;

    bool es_vacio() const;
    bool es_hoja() const;

    Arbin & operator= (const Arbin & otroArbol);
    int altura() const;
    bool existe_elemento( T& elem) const;
    int cantidadNodos () const;
    int operator== (const Arbin<T>& otroArbol) const;
private:
    NodoArbol* inicio;
};

#endif // ARBIN_H
