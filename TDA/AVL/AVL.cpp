#include "AVL.h"
#include <iostream>

AVL::AVL()
{
    this->root =NULL;
}



int AVL::getAltura(NodoAVL* nodo ) const{
    if (nodo == NULL)
        return 0;
    return nodo->getAltura();
}

int AVL::getBalance(NodoAVL* nodo) const {
    if (nodo == NULL)
        return 0;
    return getAltura(nodo->getIzquierdo()) - getAltura(nodo->getDerecho());
}

AVL::NodoAVL* AVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->getIzquierdo();
    NodoAVL* T2 = x->getDerecho();

    x->setDerecho(y);
    y->setIzquierdo(T2);

    int izquierdo_altura = getAltura(y->getIzquierdo());
    int derecho_altura = getAltura(y->getDerecho());

    if (izquierdo_altura > derecho_altura)
        y->setAltura(izquierdo_altura + 1);
    else
        y->setAltura(derecho_altura + 1);

    izquierdo_altura = getAltura(x->getIzquierdo());
    derecho_altura = getAltura(x->getDerecho());

    if (izquierdo_altura > derecho_altura)
        x->setAltura(izquierdo_altura + 1);
    else
        x->setAltura(derecho_altura + 1);

    return x;
}

AVL::NodoAVL* AVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->getDerecho();
    NodoAVL* T2 = y->getIzquierdo();

    y->setIzquierdo(x);
    x->setDerecho(T2);

    int izquierdo_altura = getAltura(x->getIzquierdo());
    int derecho_altura = getAltura(x->getDerecho());

    if (izquierdo_altura > derecho_altura)
        x->setAltura(izquierdo_altura + 1);
    else
        x->setAltura(derecho_altura + 1);

    izquierdo_altura = getAltura(y->getIzquierdo());
    derecho_altura = getAltura(y->getDerecho());

    if (izquierdo_altura > derecho_altura)
        y->setAltura(izquierdo_altura + 1);
    else
        y->setAltura(derecho_altura + 1);

    return y;
}

AVL::NodoAVL* AVL::agregarNuevo(NodoAVL* nodo, int value) {
    if (nodo == NULL)
        return new NodoAVL(value);

    if (value < nodo->getElemento())
        nodo->setIzquierdo(agregarNuevo(nodo->getIzquierdo(), value));
    else if (value > nodo->getElemento())
        nodo->setDerecho(agregarNuevo(nodo->getDerecho(), value));
    else
        return nodo;

    nodo->setAltura(1 + std::max(getAltura(nodo->getIzquierdo()), getAltura(nodo->getDerecho())));

    int balance = getBalance(nodo);

    if (balance > 1) {
        if (value < nodo->getIzquierdo()->getElemento()) {
            return rotacionDerecha(nodo);
        } else {
            nodo->setIzquierdo(rotacionIzquierda(nodo->getIzquierdo()));
            return rotacionDerecha(nodo);
        }
    }

    if (balance < -1) {
        if (value > nodo->getDerecho()->getElemento()) {
            return rotacionIzquierda(nodo);
        } else {
            nodo->setDerecho(rotacionDerecha(nodo->getDerecho()));
            return rotacionIzquierda(nodo);
        }
    }

    return nodo;
}

void AVL::agregarNuevo(int value) {
    root = agregarNuevo(root, value);
}

void AVL::inOrdenRecursivo( NodoAVL* nodo)const {
    if (nodo != NULL) {
        inOrdenRecursivo(nodo->getIzquierdo());
        std::cout << nodo->getElemento() << " ";
        inOrdenRecursivo(nodo->getDerecho());
    }
}

void AVL::inOrder() const{
    inOrdenRecursivo(root);
    std::cout << std::endl;
}
