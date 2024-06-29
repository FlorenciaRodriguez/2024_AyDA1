#ifndef AVL_H
#define AVL_H
#include <iostream>
class AVL {
private:

    // Chequear los const y esas cosas
    // Hacer la parametrizacion
    // los destructores

    class NodoAVL {
    private:
        int elemento;
        NodoAVL* izquierdo;
        NodoAVL* derecho;
        int altura;
    public:
        NodoAVL(int v){
            this->elemento = v;
            this->izquierdo = NULL;
            this->derecho = NULL;
            this->altura = 1;
        }
        int getElemento(){
            return this->elemento;
        }
         void setElemento(int v){
            this->elemento=v;
        }
        NodoAVL* getIzquierdo()
        {
            return this->izquierdo;
        }
        NodoAVL* getDerecho()
        {
            return this->derecho;
        }
        NodoAVL* setIzquierdo(NodoAVL* i)
        {
            this->izquierdo=i;
        }
        NodoAVL* setDerecho(NodoAVL* d)
        {
            this->derecho=d;
        }
        int getAltura () const{
            return this->altura;
        }
        void setAltura (int nueva) {
            this->altura = nueva;
        }

    };

    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
    NodoAVL* agregarNuevo(NodoAVL* nodo, int value);
    void inOrdenRecursivo( NodoAVL* nodo) const;
    int getAltura(NodoAVL* nodo) const;
    int getBalance(NodoAVL* nodo) const;

    NodoAVL* root;
public:
    AVL();

    void agregarNuevo(int value);
    void inOrder() const;
};

#endif

