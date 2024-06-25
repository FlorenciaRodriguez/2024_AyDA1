#include "Poligono.h"
#include <iostream>
#include <cassert>
#define MAX 9999

Poligono::Poligono(int n)
{
    this->vertices = new Punto[n];
    this->cantidad=0;
    this->N=n;
}

double Poligono::costoTriangulacion() const {
    assert(this->cantidad > 3 && !this->esConvexo() && !this->sentidoAntihorario());

    double **m = new double*[this->N-2];
    //int **t = new int*[this->N-2];
    for (int j=4;j<=this->N;j++)
    {
        //std::cout<<"Subproblemas de tamaño "<<j<<std::endl;
        m[j-4] = new double[this->N];
        //t[j-4] = new int[this->N];
        for (int i=0;i<N;i++)
        {
            const Punto& pi = vertices[i];
            const Punto& pj = vertices[(i+j-1)%this->N];
            m[j-4][i] = MAX;
            //std::cout<<"Vertice v"<<i<<std::endl;
            //std::cout<<"Minimo entre: "<<std::endl;
            for (int k=1;k<=j-2;k++)
            {
                const Punto& pk = vertices[(i+k)%this->N];
                double c1=0,c2=0,d1=0,d2=0;
                if (k+1>=4)
                    c1=m[(1+k-4)%this->N][i];
                    //std::cout<<"c["<<i<<"]["<<(1+k-4)%this->N<<"] + ";//<<std::endl;
                if (j-k>=4)
                    c2 = m[(j-k-4)%this->N][(i+k)%this->N];
                    //std::cout<<"c["<<(i+k)%this->N<<"]["<<(j-k-4)%this->N<<"] + ";//<<std::endl;
                if (k>1)
                    d1=pi.getDistancia(pk);
                    //std::cout<<"d(v"<<i<<";v"<<(i+k)%this->N<<") + ";//<<std::endl;
                if (k+1<j-1)
                    d2=pj.getDistancia(pk);
                    //std::cout<<"d(v"<<(i+k)%this->N<<";v"<<(i+j-1)%this->N<<")"<<std::endl;
                double costo_k = d1+d2+c1+c2;
                //std::cout<<"k = "<<k<<" C: "<<costo_k<<std::endl;
                if (m[j-4][i]>costo_k)
                    m[j-4][i] = costo_k;
                    //t[j-4][i] = k;
            }

        }

    }
    for (int i=0;i<=N-4;i++)
    {
        for (int j=0;j<N;j++)
            std::cout << m[i][j]<<" - ";
        std::cout<<std::endl;
    }
    /**
    for (int i=0;i<=N-4;i++){
        for (int j=0;j<N;j++)
            std::cout << t[i][j]<<" - ";
        std::cout<<std::endl;
    }
    **/
    return 0;
}

int Poligono::getTotalVertices() const
{
    return this->N;
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

    return gotNegative;
}

bool Poligono::sentidoAntihorario() const {

    double sum = 0.0;

    for (int i = 0; i < this->cantidad; ++i) {
        const Punto& current = this->vertices[i];
        const Punto& next = this->vertices[(i + 1) % this->cantidad];
        sum += (next.getX() - current.getX()) * (next.getY() + current.getY());
    }

    return sum < 0;
}
