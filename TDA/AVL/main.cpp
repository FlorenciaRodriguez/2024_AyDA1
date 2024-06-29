#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{

    AVL a;

    a.agregarNuevo(10);
    a.agregarNuevo(100);
    a.agregarNuevo(150);
    a.agregarNuevo(240);
    a.agregarNuevo(100);
    a.agregarNuevo(100);
    a.agregarNuevo(100);
    a.agregarNuevo(30);
   a.agregarNuevo(-1);

    std::cout << "tendria que listar en orden o lloro: ";
    a.inOrder();
    // contratos,destructor, parametros, acomodar las funciones, chequear con las chicas

    return 0;

}
