#include <iostream>
#include "Arbin.h"


using namespace std;

// void pre_orden( Arbin<int>* arbol){
//     if (!arbol->es_vacio()) {
//          cout << arbol->raiz()<< endl ;
//          pre_orden(arbol->arbol_izquierdo());
//          pre_orden(arbol->arbol_derecho());
//     }
// }

// std::ostream & operator << (std::ostream & salida, Arbin<int> & arbol)
// {
//   pre_orden (&arbol);
//   return salida;
// }

int main()
{
    Arbin<int>* a1= new Arbin<int>();   /// vacios
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

    Arbin<int>* a7 (a6); /// a7 se construye por copia

                                                /// arbol =              17
	Arbin<int>* arbol= new Arbin<int>;
	Arbin<int>* a10= new Arbin<int>;             ///          100                 vacío
	arbol->construir(a7, a10,17);               ///      90         90

    // cout << "cantidad de nodos:"  ;         ///       5     10    5     10
    // cout << arbol->cantidadNodos();
    // cout <<  endl <<"elementos del arbol listados en preorden: " << endl ;
    // cout << *arbol;

    return 0;
}