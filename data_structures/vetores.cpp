// Apenas para usar a função "cout"
#include <iostream>
// Para calcular o tempo gasto em v.colocar(b)
#include <chrono>
using namespace std;
#include "vetores.h"

// Testando o programa, obtive resultados um pouco melhores que O(n) no tempo.
// Acredito que isso seja por alguma otimização no compilador.


// Medir tempo de execução de "v.colocar(i)"
int main()
{
    Vetor v;

    auto start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i++)
    {
        v.colocar(i);
    }
    auto current_time = chrono::high_resolution_clock::now();

    float duration = chrono::duration_cast<std::chrono::nanoseconds>(current_time - start_time).count();
    cout << "Leva " << duration << " nanosegundos para realizar 100.000 iterações." << "\n";

    start_time = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; i++)
    {
        v.colocar(i);
    }
    current_time = chrono::high_resolution_clock::now();

    float duration_new = chrono::duration_cast<std::chrono::nanoseconds>(current_time - start_time).count();
    cout << "Leva " << duration_new << " nanosegundos para realizar 100.000.000 iterações." << "\n";

    cout << "Seu aumento de tempo após cem vezes mais iterações é de " << duration_new / duration << " vezes." "\n";

	return 0;
}
