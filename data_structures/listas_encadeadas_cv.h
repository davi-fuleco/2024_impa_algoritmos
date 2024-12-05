// Para lidar com erros
#include <iostream>
using namespace std;
#include "vetores.h"

// Definição de lista encadeada chave valor
// Estou assumindo que "chave" é um inteiro não negativo
class Lista_Encadeada_CV
{
    public:
        Vetor v;
        float cabeça();
        float *conteudo(int ender);
        int proximo(int ender);
        void inserir_depois(int ender, float chave, float valor);
        void inserir_inicio(float chave, float valor);
        void apagar_proximo(int ender);
        float *buscar(int chave);

        Lista_Encadeada_CV()
        {
            v.colocar(0);
            v.colocar(0);
            v.colocar(-1);
        }
    private:
        float c = 0;
};

    // Implementação de listas encadeadas em C++

// Cabeça da lista
float Lista_Encadeada_CV::cabeça()
{
    return c;
}


// Conteudo de um endereço da lista
float *Lista_Encadeada_CV::conteudo(int ender)
{
    if (ender >= v.n || ender % 3 != 0)
    {
        throw std::invalid_argument("Posição inválida");
    }

    if (proximo(ender) == -1)
    {
        throw std::invalid_argument("Fim da lista");
    }

    float CV[] = {v.ler(ender), v.ler(ender+1)};

    return CV;
}


// Próximo endereço
int Lista_Encadeada_CV::proximo(int ender)
{
    if (ender >= v.n || ender % 3 != 0)
    {
        throw std::invalid_argument("Endereço inválida");
    }
    return v.ler(ender+2);
}


// Inserir b depois de certo endereço
void Lista_Encadeada_CV::inserir_depois(int ender, float chave, float valor)
{
    if (proximo(ender) == -1)
    {
        throw std::invalid_argument("Fim da lista");
    }

    v.colocar(chave);
    v.colocar(valor);
    v.colocar(proximo(ender));
    v.alterar(ender+2, v.n-3);
}


// Inserir b no início
void Lista_Encadeada_CV::inserir_inicio(float chave, float valor)
{
    v.colocar(chave);
    v.colocar(valor);
    v.colocar(c);
    c = v.n-3;
}


// Apagar próximo endereço
void Lista_Encadeada_CV::apagar_proximo(int ender)
{
    if (proximo(ender) == -1)
    {
        throw std::invalid_argument("Fim da lista");
    }

    int neto = proximo(proximo(ender));
    v.alterar(ender+2, neto);
}


// Buscar o par (chave, valor) dado "chave"
float *Lista_Encadeada_CV::buscar(int chave)
{
    int atual = c;
    while (proximo(atual) != -1)
    {
        if (conteudo(atual)[0] == chave)
        {
            return conteudo(atual);
        }
        atual = proximo(atual);
    }
    float erro[2] = {-1, 0};
    return erro;
}


// Separar Lista Encadeada em duas



