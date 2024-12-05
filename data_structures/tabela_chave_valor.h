// Para lidar com erros
#include <iostream>
using namespace std;
#include "listas_encadeadas_cv.h"

// Definição de tabela chave-valor
// Estou assumindo que "chave" é um inteiro não negativo
class Chave_Valor
{
    public:
        Lista_Encadeada_CV ler(int chave);
        float buscar(int chave);
        void escrever(float chave, float valor);

    private:
        int m = 8; // Capacidade (8 por enquanto)
        // To apanhando para isso aqui
        Lista_Encadeada_CV *p = new Lista_Encadeada_CV[m]; // Ponteiro
        Lista_Encadeada_CV *p_new;
        int hash(int chave); // Hash function simples
        void nova(int M);
        void realocar(int M);
};

    // Implementação de tabela chave-valor em C++

// Hash function
int Chave_Valor::hash(int chave)
{
    return chave % m;
}


// Redimensionar a tabela chave-valor apagando a informação antiga
void Chave_Valor::nova(int M)
{
    p_new = new Lista_Encadeada_CV[M];

    for (int i = 0; i < M; i++)
    {
        Lista_Encadeada_CV l;
        p_new[i] = l;
    }
}


// Ler
Lista_Encadeada_CV Chave_Valor::ler(int chave)
{
    return p[hash(chave)];
}


// Buscar
float Chave_Valor::buscar(int chave)
{
    Lista_Encadeada_CV l = ler(chave);
    return l.buscar(chave)[1];
}


// Escrever
void Chave_Valor::escrever(float chave, float valor)
{
    Lista_Encadeada_CV l = ler(chave);
    float *a = l.buscar(chave);

    if (a[0] == -1)
    {
        l.inserir_inicio(chave, valor);
    }
}


// Realocar
void Chave_Valor::realocar(int M)
{
    nova(M);
    float chave;
    float valor;
    for (int i = 0; i < m; i++)
    {
        Lista_Encadeada_CV l = p[i];
        int atual = l.cabeça();
        
        while (l.proximo(atual) != -1)
        {
            chave = l.conteudo(atual)[0];
            valor = l.conteudo(atual)[1];
            p_new[i].inserir_inicio(chave, valor);
            atual = l.proximo(atual);
        }
    }

    delete p;
    p = p_new;
    m = M;
}


