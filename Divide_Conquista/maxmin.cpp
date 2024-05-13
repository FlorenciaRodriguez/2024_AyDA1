#include <iostream>
#include <cstdlib> // Libreria para generar numeros aleatorios

using namespace std;

const int TAMANO = 10;
const int NMAX = 10000;

void inicializarArreglo(int *arreglo)
{
  for (int i = 0; i < TAMANO; ++i)
  {
    arreglo[i] = rand() % NMAX; // Numero random en [0;NMAX-1]. Complejidad: O(1)
  }
}

void mostrarArreglo(const int arreglo[], int inicio, int fin)
{
  for (int i = inicio; i <= fin; ++i)
  {
    cout << "|| " << arreglo[i] << " ";
  }
  cout << "||";
}

// Resolución estrategia divide y conquista
void encontrarMaxMin(const int *arr, int inicio, int fin, int &maximo, int &minimo, int &recursiones)
{
  // Caso base
  if (inicio == fin)
  {
    maximo = arr[inicio];
    minimo = arr[inicio];
    return;
  }
  if (fin == inicio + 1)
  {
    minimo = min(arr[inicio], arr[fin]); // Función de la librería iostream. Complejidad O(1)
    maximo = max(arr[inicio], arr[fin]);
    return;
  }

  // Divide
  int medio = (inicio + fin) / 2;
  int min_aux_1, min_aux_2 = NMAX;
  int max_aux_1, max_aux_2 = -NMAX;
  recursiones++;
  encontrarMaxMin(arr, inicio, medio, max_aux_1, min_aux_1, recursiones);
  recursiones++;
  encontrarMaxMin(arr, medio + 1, fin, max_aux_2, min_aux_2, recursiones);

  // Combinar
  minimo = min(min_aux_1, min_aux_2);
  maximo = max(max_aux_1, max_aux_2);

  return;
}
// Estrategia intuitiva
void encontrarMaxMin_naive(const int *arr, int &maximo, int &minimo)
{
  maximo = -NMAX;
  minimo = NMAX;
  for (int i = 0; i < TAMANO; ++i)
  {
    if (arr[i] > maximo)
    {
      maximo = arr[i];
    }
    if (arr[i] < minimo)
    {
      minimo = arr[i];
    }
  }
}

int main()
{
  int maximo = 0, minimo = 0, recursiones = 0;
  int arreglo[TAMANO]; // arreglo semiestatico

  inicializarArreglo(arreglo);
  cout << "Arreglo\n";
  mostrarArreglo(arreglo, 0, TAMANO - 1);

  encontrarMaxMin(arreglo, 0, TAMANO - 1, maximo, minimo, recursiones);
  cout << "\n\nOutput divide y conquista: \n\tMaximo = " << maximo << "\n\tMinimo = " << minimo << "\nLlamadas recursivas: " << recursiones << endl;

  encontrarMaxMin_naive(arreglo, maximo, minimo);
  cout << "Output estrategia intuitiva: \n\tMaximo = " << maximo << "\n\tMinimo = " << minimo << endl
       << "\nIteraciones : " << TAMANO;

  /**
    int *ptr_arreglo = new int[TAMANO]; // arreglo dinamico
    cout << "----------------------------------------------------------------\n----------------------------------------------------------------\nResolución mediante arreglos dinámicos\n\n";
    inicializarArreglo(ptr_arreglo);
    cout << "Arreglo\n";
    mostrarArreglo(ptr_arreglo, 0, TAMANO - 1);

    recursiones = 0;
    encontrarMaxMin(arreglo, 0, TAMANO - 1, maximo_dyc, minimo_dyc, recursiones);
    encontrarMaxMin_naive(arreglo, maximo_naive, minimo_naive);

    cout << "\n\nOutput divide y conquista: \n\tMaximo = " << maximo_dyc << "\n\tMinimo = " << minimo_dyc << endl
         << "Output estrategia intuitiva: \n\tMaximo = " << maximo_naive << "\n\tMinimo = " << minimo_naive << endl
         << "\nIteraciones : " << TAMANO << "\nLlamadas recursivas: " << recursiones;

    delete[] ptr_arreglo;
  **/
  return 0;
}
