#include "Punto.h"
#include "Poligono.h"
int main()
{
    Punto* v0 = new Punto(0,10);
    Punto* v1 = new Punto(0,20);
    Punto* v2 = new Punto(8,26);
    Punto* v3 = new Punto(15,26);
    Punto* v4 = new Punto(27,21);
    Punto* v5 = new Punto(22,12);
    Punto* v6 = new Punto(10,0);
    Poligono* p = new Poligono (7);
    p->agregarPunto(*v0);
    p->agregarPunto(*v1);
    p->agregarPunto(*v2);
    p->agregarPunto(*v3);
    p->agregarPunto(*v4);
    p->agregarPunto(*v5);
    p->agregarPunto(*v6);
    p->costoTriangulacion();

    return 0;
}