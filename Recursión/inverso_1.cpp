#include <iostream>
#include <math.h>
#include <cstdlib>

#define BASE 10

using namespace std;

int calcularInversoRecursivo (int coeficiente, int grado, int& recursiones)
{
    if (coeficiente <= BASE - 1)
    {
        recursiones++;
        return coeficiente;
    }
    else
    {
        recursiones++;
        return ((coeficiente % BASE)*pow(BASE,grado-1)+ calcularInversoRecursivo(coeficiente/BASE,grado-1,recursiones));
    }
}
int numCifrasRecursivo (int numero)
{
    if (numero <= BASE - 1)
        return 1;
    else
    {
        int n = numero/BASE;
        return numCifrasRecursivo(n)+1;
    }
}
int main()
{
    cout<<"Numero\t Llamados recursivos\t log 10 (numero)\tCantidad de digitos \n";
    int recursiones=0;
    int valorAInvertir = 97812465;
    int digitos = numCifrasRecursivo (valorAInvertir);
    int valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;
    recursiones=0;
    valorAInvertir = 58842;
    digitos = numCifrasRecursivo (valorAInvertir);
    valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;
    recursiones=0;
    valorAInvertir = 15467;
    digitos = numCifrasRecursivo (valorAInvertir);
    valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;
    valorAInvertir = 2156;
    recursiones=0;
    digitos = numCifrasRecursivo (valorAInvertir);
    valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;

    return 0;
}
