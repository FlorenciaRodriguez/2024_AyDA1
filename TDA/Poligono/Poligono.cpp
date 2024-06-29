#include "Poligono.h"
#include<iostream>
#include <cassert>
#define MAX 9999

Poligono::Poligono(int n)
{
    this->vertices = new Punto[n];
    this->cantidad=0;
    this->N=n;
}
Poligono::~Poligono()
{
    delete this->vertices;
    this->cantidad=0;
    this->N=0;
}
/**
void Poligono::triangular(int i, int j, int ** p) const
{
    if (0<=i && 0<=j && i<this->cantidad-2 && j<this->cantidad){
    int k = p[i][j];
    //if (k!=1)
        std::cout<<"v"<<j<<"; v"<<j+k<<std::endl;
    //if (k!=j-2)
        std::cout<<"v"<<j+k<<"; v"<<i-k+3<<std::endl;
    triangular(j,k+1,p);
    triangular(k+j,i-k,p);
    }
}**/
double Poligono::costoTriangulacion() const
{
    assert(this->cantidad > 3 && this->esConvexo() && this->sentidoAntihorario());

    double ** c = new double*[this->cantidad-3];
    //int ** p = new int*[this->cantidad-3];

    for (int s = 4; s <= this->cantidad; s++)
    {
        c[s-4] = new double[this->cantidad];
        //p[s-4] = new int[this->cantidad];

        for (int i=0; i< this->cantidad; i++)
        {
            int ultimo = (s+i-1)%this->cantidad;

            const Punto & pi = this->vertices[i];
            const Punto & ps = this->vertices[ultimo];
            c[s-4][i] = MAX;

            for (int k=1; k<= s-2; k++)
            {
                int x = (i+k)%this->cantidad;
                const Punto & pk = this->vertices[x];

                double c1 = (k+1>=4) ? c[k-3][i] : 0;
                double c2 = (s-k>=4) ? c[s-k-4][x] : 0;
                double d1 = (k!=1) ? pi.getDistancia(pk) : 0;
                double d2 = (x != (ultimo-1) ) ? pk.getDistancia(ps) : 0;
                double costo_k = c1 + c2 + d1 + d2;

                if (costo_k < c[s-4][i])
                {
                    c[s-4][i] = costo_k;
                    //p[s-4][i] = k;

                }

            }

        }

    }
    /**
    for (int i=0; i<this->cantidad-3; i++)
    {
        std::cout<<"\nSubproblemas tamanio "<<i+4<<std::endl;
        for (int j=0; j< this->cantidad; j++)
            std::cout<<c[i][j] << " ";
    }**/
    double costo = c[this->cantidad-4][0];
    //triangular(3,0,p);
    for (int i=0;i<this->cantidad-3;i++){
        delete c[i];
    }
    delete c;

    return costo;
}



int Poligono::getTotalVertices() const
{
    return this->cantidad;
}
void Poligono::agregarPunto(const Punto & p)
{
    assert(this->cantidad<=this->N);
    this->vertices[this->cantidad]=p;
    this->cantidad++;
}

double Poligono::crossProduct(const Punto& A, const Punto& B, const Punto& C) const {
    double ABx = B.getX() - A.getX();
    double ABy = B.getY() - A.getY();
    double BCx = C.getX() - B.getX();
    double BCy = C.getY() - B.getY();
    return ABx * BCy - ABy * BCx;
}
bool Poligono::esConvexo() const {
    if (this->cantidad < 4) {
        return true;
    }

    int i = 0;
    bool gotNegative = false;

    while (!gotNegative && i < this->cantidad) {
        double cross = crossProduct(this->vertices[i], this->vertices[(i + 1) % this->cantidad], this->vertices[(i + 2) % this->cantidad]);
        if (cross > 0) {
            gotNegative = true;
        }
        i++;
    }

    return !gotNegative;
}

bool Poligono::sentidoAntihorario() const {

    double sum = 0.0;

    for (int i = 0; i < this->cantidad; ++i) {
        const Punto& current = this->vertices[i];
        const Punto& next = this->vertices[(i + 1) % this->cantidad];
        sum += (next.getX() - current.getX()) * (next.getY() + current.getY());
    }

    return sum > 0;
}
