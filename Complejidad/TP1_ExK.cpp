#include <iostream>
#include <math.h>
#include <cstdlib>
#define MIN 1
#define MAX 32
#define EJEMPLOS 15

using namespace std;

int contar (int n, int m, int& its) {
    int j,  contadorSentencias = 0,  i = 1;
    its = 0;
    while (i <= m) {
        j = n;
        while (j != 0){
            j = j / 2; 
          contadorSentencias ++;
            its++;
        }
        i++;
    }
    return contadorSentencias;
}


int main()
{

    cout<<"its: iteraciones\nn\tm\tits\t(log2 n) + 1\tm ((log2 n) +1)\n";

    for (int i = 0; i < EJEMPLOS; ++i) {
        int its = 0;
        
        int m = MIN + rand() % MAX; // Numero random entre MIN y MAX
        int n = MIN + rand() % MAX;
        int x = contar (n, m, its);
        
        int log_ = ceil(log(n)) + 1;
        
        cout << n << "\t" << m << "\t" << its << "\t" <<  log_ << "\t\t" << m*log_ << endl;
    }

    return 0;
}
