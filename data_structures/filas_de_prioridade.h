// Para lidar com erros
#include <iostream>
// Para usar a função floor
#include <cmath>
using namespace std;
#include "vetores.h"

// Definição de fila de prioridade
class Fila_De_Prioridade
{
    public:
        float menor();
        float remover_minimo();
        void inserir(float u);
    private:
        Vetor v;
        void reorganizar();
        void reorganizar_sub(int i);
};

    // Implementação de filas de prioridade em C++

// Menor
float Fila_De_Prioridade::menor()
{
    if (v.n == 0)
    {
        throw std::invalid_argument("Posição inválida");
    }
    return v.ler(0);
}


// Remover mínimo
float Fila_De_Prioridade::remover_minimo()
{
    float m = menor();
    float u = v.pegar();
    v.alterar(0, u);
    reorganizar();
    return m;
}


// Reorganizar
void Fila_De_Prioridade::reorganizar()
{
    reorganizar_sub(1);
}


// Reorganizar_sub
void Fila_De_Prioridade::reorganizar_sub(int i)
{
    float pai = v.ler(i - 1);
    float esq;
    float dir;

    // Definindo "esq" e "dir" caso eles não existirem
    if (v.n < 2 * i)
    {
        esq = pai + 1;
    }
    else
    {
        esq = v.ler(2 * i - 1);
    }

    if (v.n < 2 * i + 1)
    {
        dir = pai + 1;
    }
    else
    {
        dir = v.ler(2 * i);
    }

    float min;

    // Descobrindo qual caso lidar
    if (pai <= esq || pai <= dir)
    {
        min = 0;
    }
    else if (esq < pai || esq <= dir)
    {
        min = 1;
    }
    else
    {
        min = 2;
    }

    if (min == 0)
    {
        return;
    }
    else if (min == 1)
    {
        v.alterar(i - 1, esq);
        v.alterar(2 * i - 1, pai);
        reorganizar_sub(2 * i);
    }
    else
    {
        v.alterar(i - 1, dir);
        v.alterar(2 * i, pai);
        reorganizar_sub(2 * i + 1);
    }
}


// Inserir
void Fila_De_Prioridade::inserir(float u)
{
    v.colocar(u);
    int i = v.n;

    float filho;
    float pai;
    while (i > 1)
    {
        filho = v.ler(i - 1);
        pai = v.ler(floor(i / 2) - 1);

        if (pai <= filho)
        {
            return;
        }
        else
        {
            v.alterar(i - 1, pai);
            v.alterar(floor(i/2) - 1, filho);
            i = floor(i / 2);
        }
    }
}



