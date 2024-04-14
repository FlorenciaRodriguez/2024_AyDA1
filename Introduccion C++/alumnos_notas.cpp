#include <iostream>
#include <stdlib.h>
#include <fstream>

#define SEPARADOR ','

using namespace std;
void mostrarArreglos(const string nombreEstudiantes[], const float calificaciones[], int cantEstudiantes)
{
    cout <<"Nombre\tCalificacion obtenida\n";
    for (int i = 0; i < cantEstudiantes; i++)
    {
        cout << nombreEstudiantes[i] <<"\t" << calificaciones[i] <<endl;
    }
}

float calcularPromedio(const float calificaciones[], int numEstudiantes)
{
    float suma = 0.0;
    for (int i = 0; i < numEstudiantes; i++)
    {
        suma += calificaciones[i];
    }
    return suma / numEstudiantes;
}

bool cargarDatos(string nombreEstudiantes[], float calificaciones[], int & numEstudiantes)
// Alternativa: con punteros
//bool cargarDatos(string*& nombreEstudiantes, float*& calificaciones, int & numEstudiantes)

{
    ifstream archivo("datos.csv");
    bool abriArchivo = archivo.is_open(); // Intenta abrir el archivo. Devuelve true si lo abre, false caso contrario.
    if (!abriArchivo)
    {
        cerr << "Error al abrir el archivo datos.csv \n";
        return false;
    }
    else
    {
        string primeraLinea;
        if (!getline(archivo, primeraLinea))
        {
            cerr << "Error: archivo datos.csv esta vacio" << endl;
            return false;
        }
        else
        {
            numEstudiantes = atoi(primeraLinea.c_str());// Convierte la primera línea, con la cantidad de estudiantes a integer

            // Si trabajan con punteros:
            //calificaciones = new float[numEstudiantes];
            //nombreEstudiantes = new string[numEstudiantes];

            // Comienza la lectura de las líneas con los nombres y las notas
            for (int i = 0; i < numEstudiantes; i++)
            {
                string linea;
                bool leerLinea = getline(archivo, linea);
                if (!leerLinea)
                {
                    cerr << "Error: archivo datos.csv no contiene suficientes lineas" << endl;
                    return false;
                }
                else
                {
                    string nombreEstudiante, notaString;
                    int j = 0, maxLinea= linea.length();

                    // Lectura de los caracteres hasta la coma
                    while (j < maxLinea && linea[j] != ','){
                        nombreEstudiante += linea[j];
                        j++;
                    }

                    j++; // Avanzamos la posición

                    // Caracteres posteriores a la coma
                    while (j < maxLinea){
                        notaString += linea[j];
                        j++;
                    }
                    calificaciones[i] = atof(notaString.c_str());
                    nombreEstudiantes[i] = nombreEstudiante;


                    // Alternativa: uso de buffers. Agregar la directiva #include <sstream>

                    //stringstream ss(linea); //Usamos un buffer para consumir/leer el string linea. En linea guardamos las linea leída en la iteración i
                    //getline(ss, nombreEstudiantes[i], SEPARADOR); // Leemos la linea i hasta la primer coma y guardamos en nombreEstudiantes[i]
                    //string notaString;
                    //getline(ss, notaString, SEPARADOR); // En notaString guardamos los caracteres leídos posteriores a la coma
                    //calificaciones[i] = atof(notaString.c_str()); // Convertimos a float, dado que tenemos el numero almacenado en un string

                }
            }
            archivo.close();
        }
    }
    return true;
}
int main()
{

    int numEstudiantes;

    const int INF = 99;
    float calificaciones[INF];
    string nombreEstudiantes[INF];

    // En lugar de definirlos como arreglos, pueden usar punteros:
    // float* calificaciones;
    // string* nombreEstudiantes;

    bool cargaCorrecta = cargarDatos (nombreEstudiantes, calificaciones, numEstudiantes);
    if (cargaCorrecta)
    {
        mostrarArreglos(nombreEstudiantes, calificaciones, numEstudiantes);
        double promedio = calcularPromedio(calificaciones, numEstudiantes);
        cout << "El promedio de calificaciones es: " << promedio << endl;
    }
    else
    {
        cout << "Error al cargar los datos.\n";
    }
    return 0;
}
