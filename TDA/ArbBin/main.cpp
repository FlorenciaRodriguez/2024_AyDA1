#include <iostream>
#include "Arbin.h"
using namespace std;

std::ostream & operator << (std::ostream & salida, Arbin<int> & arbol)
{
    	arbol.preOrden(salida); // Usamos arbol. porque arbol no es puntero. Si lo fuera, usamos arbol->
    	return salida;
}

int main()
{
    	Arbin<int>* a1= new Arbin<int>;
	Arbin<int>* a2= new Arbin<int>;
	Arbin<int>* a3= new Arbin<int>;
	Arbin<int>* a11= new Arbin<int>;
	Arbin<int>* a12= new Arbin<int>;
	Arbin<int>* a4= new Arbin<int>;
	Arbin<int>* a5= new Arbin<int>;
	Arbin<int>* a6= new Arbin<int>;

	a3->construir(a1,a2,5);
	a4->construir(a11,a12,10);
	a5->construir(a3,a4,90);
	a6->construir(a5,a5,100);

	Arbin<int>* a7 (a6);

	cout << "Raiz de a3 (5): " << a3->raiz() <<endl;
	cout << "Altura de a1 (0): " << a1->altura() <<endl;
	cout << "Altura de a6 (3): " << a6->altura() <<endl;
	cout << "Altura de a3 (1): " << a3->altura() <<endl;
	cout << "# nodos de a6 (7): " << a6->cantidadNodos() <<endl;
	cout << "# nodos de a5 (6): " << a5->cantidadNodos() <<endl;
	cout << "True: " << a6->existeElemento(90) <<endl;
	cout << "False: " << a6->existeElemento(190) <<endl;
	cout << "True: " << a6->existeElemento(10) <<endl;
	cout << "True: " << a6->existeElemento(100) <<endl;
	cout << "True: " << a6->existeElemento(5) <<endl;
	if (a6 == a7)
        	cout << "Comparacion por ==: a6 y a7 son iguales" <<endl;
	if (a6 != a7)
        	cout << "Comparacion por !=: a6 y a7 son distintos" <<endl;
	if (!a5->esVacio())
        	cout << "a5 no es vacio" << endl;
    	if (a1->esVacio())
        	cout << "a1 es vacio" << endl;
    	if (a3->esHoja())
        	cout << "a3 es hoja" << endl;
    	if (!a6->esHoja())
        	cout << "a6 no es hoja" << endl;
    	if (a5 == a7)
        	cout << "a5 y a7 no son iguales" <<endl;

    	cout << "Recorrido pre orden del arbol a7: "<<endl;
    	cout << *a7;
	
    	return 0;
}
