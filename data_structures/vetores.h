// Para lidar com erros
#include <iostream>
using namespace std;

// Definição de vetor
class Vetor
{
    public:
        int n = 0; // Tamanho
        float ler(int i);
        void colocar(float b);
        void alterar(int i, float b);
        float pegar();
        void inserir_em(int k, float b);

    private:
        int c = 8; // Capacidade
        float *p = new float[c]; // Ponteiro
        float *p_new; // Novo ponteiro
        void redimensionar(int M);
};


    // Implementação de vetores em C++

// Ler elemento na posição i
float Vetor::ler(int i)
{
    // Checar se i é uma posição válida
    if (i > n || i < 0)
    {
        throw std::invalid_argument("Posição inválida");
    }
    return p[i];
}


// Colocar elemento b no final
void Vetor::colocar(float b)
{
    // Checar se existe espaço
    if (n == c)
    {
        redimensionar(2*c);
    }
    p[n] = b;
    n++;
}


// Alterar elemento da posição i por b
void Vetor::alterar(int i, float b)
{
    // Checar se i é uma posição válida
    if (i >= n || i < 0)
    {
        throw std::invalid_argument("Posição inválida");
    }
    p[i] = b;
}


// Pegar último elemento (Ler e eliminar elemento)
float Vetor::pegar()
{
    // Checar se i é uma posição válida
    if (n == 0)
    {
        throw std::invalid_argument("Vetor vazio");
    }
    n--;
    return p[n];
}


// Redimensionar o vetor para ter capacidade l
void Vetor::redimensionar(int M)
{
    p_new = new float[M];
    for (int j = 0; j < c; j++)
    {
        p_new[j] = p[j];
    }
    delete p;
    p = p_new;
    c = M;
}


// Inserir b na posição k
void Vetor::inserir_em(int k, float b)
{
    // Checar se k é uma posição válida
    if (k > n || k < 0)
    {
        throw std::invalid_argument("Posição inválida");
    }
    
    // Checar se existe espaço
    if (n == c)
    {
        redimensionar(2*c);
    }

    float p_old = p[k];
    float p_next;
    for (int i = k+1; i < n+1; i++)
    {
        p_next = p[i];
        p[i] = p_old;
        p_old = p_next;
    }
    p[k] = b;
    n++;
}
