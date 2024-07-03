#ifndef Pila_H
#define Pila_H
template <typename T>
class Pila
{
public:
    Pila();
    virtual ~Pila();
    void apilar(const T &element);
    void desapilar();
    T getTope() const;
    bool esVacia() const;
    int getCantidad() const;
    Pila &operator=(const Pila &otro);

private:
    void vaciar();
    int capacidad;
    int cantElementos;
    struct Nodo
    {
        T elemento;
        Nodo *siguiente;
    };
    Nodo *tope;
};

#endif // Pila_H
