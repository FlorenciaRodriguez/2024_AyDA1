#include <iostream>
#include <cstdlib> // Libreria para generar numeros aleatorios
#include <chrono>  // Libreria para calculos de tiempo de ejecucion
#include <iomanip> // Libreria para redondeo de variables de punto flotante

using namespace std;

const int TAMANO = 10;
const int NMAX = 10000;
const int NEJECUCIONES = 150;

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
void encontrarMaxMin(const int *arr, int inicio, int fin, int &maximo, int &minimo)
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
  encontrarMaxMin(arr, inicio, medio, max_aux_1, min_aux_1);
  encontrarMaxMin(arr, medio + 1, fin, max_aux_2, min_aux_2);

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

// Estrategia divide y conquista con seguimiento de llamados recursivos
void encontrarMaxMin_conSeguimiento(const int *arr, int inicio, int fin, int &maximo, int &minimo, int &recursiones)
{
  // Salidas por pantalla para guiar el seguimiento de la recursión
  cout << "----------------------------------------------------------------\n"
       << "Llamado: " << recursiones << "\nParametros: \n\tinico = " << inicio << " -- fin = " << fin << " \n\tminimo = " << minimo << " -- maximo = " << maximo << "\n\tarr = ";
  mostrarArreglo(arr, inicio, fin);
  cout << endl;
  //

  // Caso base
  if (inicio == fin)
  {
    maximo = arr[inicio];
    minimo = arr[inicio];
    cout << "Retorna: maximo = " << maximo << " -- minimo =" << minimo << endl;
    return;
  }
  if (fin == inicio + 1)
  {
    minimo = min(arr[inicio], arr[fin]); // Función de la librería iostream. Complejidad O(1)
    maximo = max(arr[inicio], arr[fin]);
    cout << "Retorna: maximo = " << maximo << " -- minimo = " << minimo << endl;
    return;
  }
  // Divide
  int medio = (inicio + fin) / 2;
  int min_aux_1, min_aux_2 = NMAX;
  int max_aux_1, max_aux_2 = -NMAX;

  // Salidas por pantalla para guiar el seguimiento de la recursión
  int llamadonro = recursiones;
  recursiones++;
  cout << "Locales: medio = " << medio << endl;
  cout << "Llama al nro " << recursiones << " con inicio = " << inicio << " -- fin = " << medio << " -- arr = ";
  mostrarArreglo(arr, inicio, medio);
  cout << endl;
  cout << "Llama al nro " << medio - inicio + llamadonro + 2 - ((medio - inicio) % 2) << " con inicio = " << medio + 1 << " -- fin = " << fin << " -- arr = ";
  mostrarArreglo(arr, medio + 1, fin);
  cout << endl;
  //

  // Recursiones
  encontrarMaxMin_conSeguimiento(arr, inicio, medio, max_aux_1, min_aux_1, recursiones);
  recursiones++;
  encontrarMaxMin_conSeguimiento(arr, medio + 1, fin, max_aux_2, min_aux_2, recursiones);

  // Combinar
  minimo = min(min_aux_1, min_aux_2);
  maximo = max(max_aux_1, max_aux_2);

  cout << "----------------------------------------------------------------\nDesapila llamado recursivo nro " << llamadonro << " \nRetorna min(" << min_aux_1 << ";" << min_aux_2 << ") = " << minimo << " -- max(" << max_aux_1 << ";" << max_aux_2 << ") = " << maximo << endl;

  return;
}

// Estrategia intuitiva con seguimiento
void encontrarMaxMin_naive_conSeguimiento(const int *arr, int &maximo, int &minimo)
{
  maximo = -NMAX;
  minimo = NMAX;
  for (int i = 0; i < TAMANO; ++i)
  {

    cout << "----------------------------------------------------------------\n"
         << "Iteracion: " << i << "\nMaximo local: " << maximo << " -- Minimo local: " << minimo << endl;

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

// Ejecuta la funcion DyC NEJECUCIONES veces y devuelve el tiempo promedio de ejecucion medido en milisegundos
double getTiempoPromedioEjecucionDyC(const int *arr)
{
  double tiempo_ms = 0;
  for (int i = 0; i < NEJECUCIONES; i++)
  {
    int minimo, maximo = 0;
    auto start = chrono::steady_clock::now(); // Marca para calcular el tiempo en ejecuión
    encontrarMaxMin(arr, 0, TAMANO - 1, maximo, minimo);
    auto end = chrono::steady_clock::now();                            // Marca de fin de ejecución
    tiempo_ms += chrono::duration<double, milli>(end - start).count(); // Tiempo en milisegundos
  }
  return tiempo_ms / NEJECUCIONES;
}

// Ejecuta la funcion naive NEJECUCIONES veces y devuelve el tiempo promedio de ejecucion medido en milisegundos
double getTiempoPromedioEjecucionNaive(const int *arr)
{
  double tiempo_ms = 0;
  for (int i = 0; i < NEJECUCIONES; i++)
  {
    int minimo, maximo = 0;
    auto start = chrono::steady_clock::now(); // Marca para calcular el tiempo en ejecuión
    encontrarMaxMin_naive(arr, maximo, minimo);
    auto end = chrono::steady_clock::now();                            // Marca de fin de ejecución
    tiempo_ms += chrono::duration<double, milli>(end - start).count(); // Tiempo en milisegundos
  }
  return tiempo_ms / NEJECUCIONES;
}
void compararTiempos(const int *arr)
{
  // Tiempor promedios de ejecucion
  double t_dyc = getTiempoPromedioEjecucionDyC(arr);
  double t_naive = getTiempoPromedioEjecucionNaive(arr);
  cout << "\n\nTiempo promedio de ejecución estrategia divide y conquista: " << t_dyc << " ms" << endl
       << "Tiempo promedio de ejecución estrategia iterativa: " << t_naive << " ms" << endl
       << endl;
  double mejora = ((t_dyc - t_naive) / t_dyc) * 100;
  if (mejora > 0)
  {
    cout << "El algoritmo intuitivo ejecuta más rápido y mejora la velocidad en un " << setprecision(4) << mejora << " % \n\n";
  }
  else
  {
    mejora = ((t_naive - t_dyc) / t_naive) * 100;
    cout << "El algoritmo divide y conquista ejecuta más rápido y mejora la velocidad en un " << setprecision(4) << mejora << " % \n\n";
  }
}
int main()
{
  int maximo_dyc = 0, maximo_naive = 0, minimo_naive = 0, minimo_dyc = 0, recursiones = 0;
  int arreglo[TAMANO]; // arreglo semiestatico

  inicializarArreglo(arreglo);
  cout << "Arreglo\n";
  mostrarArreglo(arreglo, 0, TAMANO - 1);

  cout << "\n\nSeguimiento de ejecución de estrategia divide y conquista\n";
  encontrarMaxMin_conSeguimiento(arreglo, 0, TAMANO - 1, maximo_dyc, minimo_dyc, recursiones);

  cout << "\n\nSeguimiento de ejecución de estrategia intuitiva\n";
  encontrarMaxMin_naive_conSeguimiento(arreglo, maximo_naive, minimo_naive);

  cout << "\n\nOutput divide y conquista: \n\tMaximo = " << maximo_dyc << "\n\tMinimo = " << minimo_dyc << endl
       << "Output estrategia intuitiva: \n\tMaximo = " << maximo_naive << "\n\tMinimo = " << minimo_naive << endl
       << "\nIteraciones : " << TAMANO << "\nLlamadas recursivas: " << recursiones;
  compararTiempos(arreglo);

  int *ptr_arreglo = new int[TAMANO]; // arreglo dinamico
  cout << "----------------------------------------------------------------\n----------------------------------------------------------------\nResolución mediante arreglos dinámicos\n\n";
  inicializarArreglo(ptr_arreglo);
  cout << "Arreglo\n";
  mostrarArreglo(ptr_arreglo, 0, TAMANO - 1);
  compararTiempos(ptr_arreglo);

  delete[] ptr_arreglo;

  return 0;
}
