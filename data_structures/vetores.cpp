#include <iostream>
using namespace std;

// Implementação de vetores em C++
class Vetor
{
    public:
        int n = 0; // tamanho
        float ler(int i);
        void colocar(float b);
        void alterar(int i, float b);
    private:
        int c = 8; // capacidade
        float *p = new float[c]; // ponteiro
};

// Ler elemento na posição i
float Vetor::ler(int i)
{
    // Checar se i é uma posição válida
    if (i > n || i < 0)
    {
        throw std::invalid_argument( "Posição inválida" );
    }
    return p[i];
}


// Colocar elemento b no final
void Vetor::colocar(float b)
{
    // Checar se existe espaço
    if (n == c)
    {
        // redimensionar
    }
    p[n] = b;
    n++;
}


// Alterar elemento da posição i por b
// Testar
void Vetor::alterar(int i, float b)
{
    // Checar se i é uma posição válida
    if (i > n || i < 0)
    {
        throw std::invalid_argument( "Posição inválida" );
    }
    p[i] = b;
}


// Pegar último elemento (Ler e eliminar elemento)



// Redimensionar o vetor para ter capacidade l



// Medir tempo de execução de "v.colocar(i)"
int main()
{
    Vetor v;
    // entender pq não esta funcionando (estou usando ponteiros errado)
    v.colocar(5);
    v.colocar(20);
    v.colocar(1.55);
    cout << v.ler(0) << "\n";
    cout << v.ler(1) << "\n";
    cout << v.ler(2) << "\n";
}
