#include <iostream> 
#include <string>
using namespace std;
int main()
{
    string nombre;
    cout << "Ingrese su nombre: \n";
    getline(cin,nombre);
    cout << "Hola "<< nombre << "!\n";
    return 0;
}
