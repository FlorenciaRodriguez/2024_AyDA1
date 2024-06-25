#ifndef POLIGONO_H
#define POLIGONO_H
#include "Punto.h"
class Poligono {
private:
    int N;
    Punto* vertices;
    int cantidad;
    double crossProduct(const Punto& A, const Punto& B, const Punto& C) const;
    bool esConvexo() const;
    bool sentidoAntihorario() const;
public:

    Poligono(int n);
    void agregarPunto(const Punto & p);

    double costoTriangulacion() const;
    int getTotalVertices() const;
};
#endif // POLIGONO_H
