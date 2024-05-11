#include <iostream>
#include <cstdlib>

using namespace std;
struct Nodo
{
    int elemento;
    Nodo * siguiente;
};

Nodo * crear_nodo(int elemento, Nodo * sigte)
{
    Nodo * nuevo = new Nodo();
    nuevo->elemento = elemento;
    nuevo->siguiente = sigte;
    return nuevo;
}

void agregar_final(int nuevo_elemento, Nodo * & primero)
{
    Nodo * nuevo = crear_nodo(nuevo_elemento, NULL);

    // Si la lista esta vacía, el nuevo nodo se convierte en el primero
    if (primero == NULL)
    {
        primero = nuevo;
    }
    else
    {
        Nodo * actual = primero;
        // Recorrer la lista hasta llegar al ultimo nodo
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        // Agregar el nuevo nodo al final de la lista
        actual->siguiente = nuevo;
    }
}

void agregar_principio (int nuevo_elemento, Nodo * & primero)
{
    // Si la lista esta vacia, el nuevo nodo se convierte en el primero
    if (primero == NULL)
    {
        primero = crear_nodo(nuevo_elemento, NULL);
    }
    else
    {
        primero = crear_nodo(nuevo_elemento, primero);
    }
}

void mostrar_elementos(const Nodo * primero)
{
    while (primero!=NULL)
    {
        cout<<primero->elemento<<" -> ";
        primero = primero->siguiente;
    }
    cout<<"NULL"<<endl;
}

bool eliminar_elemento(Nodo * & primero, int elemento_borrar)
{
    Nodo * actual = primero;
    Nodo * anterior = NULL;

    // Buscar el nodo que contiene el elemento a borrar
    while (actual != NULL && actual->elemento != elemento_borrar)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si el elemento no esta presente en la lista, retornar falso
    if (actual == NULL)
        return false;

    // Si el nodo a borrar es el primero de la lista
    if (actual == primero)
    {
        primero = actual->siguiente;
    }
    else
    {
        // Si el nodo a borrar no es el primero de la lista
        anterior->siguiente = actual->siguiente;
    }

    // Liberar la memoria del nodo a borrar
    delete actual;
    actual = NULL;

    return true;
}

void liberar_memoria(Nodo * & primero)
{
    Nodo * actual = primero;
    while (actual != NULL)
    {
        Nodo * siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    primero = NULL;
}

int main()
{

    Nodo * primero = NULL;

    cout<<"\nSecuencia con un solo valor: "<<endl;
    agregar_principio(4, primero);
    mostrar_elementos(primero);


    cout<<"\nSecuencia con dos valores: "<<endl;
    agregar_final(11, primero);
    mostrar_elementos(primero);


    cout<<"\nSecuencia con tres valores: "<<endl;
    agregar_principio(1991,primero);
    mostrar_elementos(primero);

    bool elimino = eliminar_elemento(primero, 11);
    if (elimino)
    {
        cout<<"\nSecuencia luego de eliminar el 11: "<<endl;
        mostrar_elementos(primero);
    }
    liberar_memoria(primero);
    return 0;

}
