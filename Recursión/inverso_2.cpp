#include <iostream>
#include <math.h>
#include <cstdlib>

#define BASE 10

using namespace std;

int calcularInversoRecursivo (int coeficiente, int& grado, int& recursiones)
{
    if (coeficiente < BASE)
    {
      grado++;
      recursiones++;
      return coeficiente;
    }
    else
    {
      int aux = calcularInversoRecursivo (coeficiente/BASE, grado,recursiones) + coeficiente%BASE * pow(BASE,grado);
      grado++;
      recursiones++;
      return aux;
    }
}

int main()
{
    cout<<"Numero\t Llamados recursivos\t log 10 (numero)\tCantidad de digitos \n";
    int recursiones=0;
    int valorAInvertir = 97812465;
    int digitos = 0;
    int valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;
    recursiones=0;
    digitos = 0;
    valorAInvertir = 58842;
    valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;
    recursiones=0;
    digitos = 0;
    valorAInvertir = 15467;
    valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;
    valorAInvertir = 2156;
    recursiones=0;
    digitos = 0;
    valorInverso = calcularInversoRecursivo (valorAInvertir, digitos,recursiones);
    cout << valorAInvertir << "\t\t" << recursiones <<"\t\t\t"<<ceil(log10(valorAInvertir))<<"\t\t"<<digitos<<endl;

    return 0;
}
