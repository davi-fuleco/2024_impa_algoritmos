// Para lidar com erros
#include <iostream>
using namespace std;
#include "vetores.h"

// Definição de lista encadeada
class Lista_Encadeada
{
    public:
        Vetor v;
        float cabeça();
        float conteudo(int ender);
        int proximo(int ender);
        void inserir_depois(int ender, float b);
        void inserir_inicio(float b);
        void apagar_proximo(int ender);

        Lista_Encadeada()
        {
            v.colocar(0);
            v.colocar(-1);
        }
    private:
        float c = 0;
};

    // Implementação de listas encadeadas em C++

// Cabeça da lista
float Lista_Encadeada::cabeça()
{
    return c;
}


// Conteudo de um endereço da lista
float Lista_Encadeada::conteudo(int ender)
{
    if (ender >= v.n || ender % 2 != 0)
    {
        throw std::invalid_argument("Posição inválida");
    }

    if (proximo(ender) == -1)
    {
        throw std::invalid_argument("Fim da lista");
    }

    return v.ler(ender);
}


// Próximo endereço
int Lista_Encadeada::proximo(int ender)
{
    if (ender >= v.n || ender % 2 != 0)
    {
        throw std::invalid_argument("Endereço inválida");
    }
    return v.ler(ender+1);
}


// Inserir b depois de certo endereço
void Lista_Encadeada::inserir_depois(int ender, float b)
{
    if (proximo(ender) == -1)
    {
        throw std::invalid_argument("Fim da lista");
    }

    v.colocar(b);
    v.colocar(proximo(ender));
    v.alterar(ender+1, v.n-2);
}


// Inserir b no início
void Lista_Encadeada::inserir_inicio(float b)
{
    v.colocar(b);
    v.colocar(c);
    c = v.n-2;
}


// Apagar próximo endereço
void Lista_Encadeada::apagar_proximo(int ender)
{
    if (proximo(ender) == -1)
    {
        throw std::invalid_argument("Fim da lista");
    }

    int neto = proximo(proximo(ender));
    v.alterar(ender+1, neto);
}


// Buscar



// Separar Lista Encadeada em duas



