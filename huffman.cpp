// Nesse código eu implementei uma código de huffman que 
// codifica um string como uma sequência de 1's e 0's e
// decodifica para obter a mensagem original.

// A maneira certa de fazer isso com certeza não é representando
// a mensagem codificada como uma string, mas fiz dessa forma para
// simplificar um pouco o código, já que o mais importante é a
// lógica por trás.

#include <iostream>
// Para usar fila de prioridade
#include <queue>
// Para usar tabela chave valor
#include <map>
// Para usar a função log
#include <math.h>
using namespace std;

// Definir um node
struct Arvore{
    int freq;
    string letter;
    Arvore* left;
    Arvore* right;

    Arvore(){}


    Arvore(int new_freq, string new_letter)
    {
        freq = new_freq;
        letter = new_letter;
        left = nullptr;
        right = nullptr;
    }

    bool operator<(const Arvore& p) const
    {
        return this->freq > p.freq;
    }
};


// Criar fila de prioridade com as letras e suas frequências
priority_queue<Arvore> counter(string T)
{
    map<char, Arvore> Counter;

    // Construindo o counter
    for (char& c : T)
    {
        if (Counter.count(c) == 0)
        {
            string s = new char(1);
            s[0] = c;
            Arvore G = Arvore(1, s);
            Counter.emplace(c, G);
        }
        else
        {
            Counter[c].freq++;
        }
    }

    priority_queue<Arvore> Galhos;

    // Passando os galhos para a fila de prioridade
    for (map<char, Arvore>::iterator iter = Counter.begin(); iter != Counter.end(); ++iter)
    {
        Galhos.push(iter->second);
    }

    return Galhos;
}


float Entropia(priority_queue<Arvore> Galhos)
{
    float Entropia = 0;
    float total = 0;

    int n = Galhos.size();

    priority_queue<Arvore> G = Galhos;
    // Calculando a soma das frequências para conseguir
    // calcular a probabilidade
    for (int i = 0; i < n; i++)
    {
        Arvore galho = G.top();
        G.pop();

        total += galho.freq;
    }

    // Calculando a entropia
    for (int i = 0; i < n; i++)
    {
        Arvore galho = Galhos.top();
        Galhos.pop();

        float prob = galho.freq / total;

        Entropia -= prob * log2(prob);
    }
    return Entropia;
}


Arvore Huffman(priority_queue<Arvore> Galhos)
{
    int n = Galhos.size();

    for (int i = 1; i < n; i++)
    {
        Arvore *Right = new Arvore;
        *Right = Galhos.top();
        Galhos.pop();

        Arvore *Left = new Arvore;
        *Left = Galhos.top();
        Galhos.pop();

        Arvore Pai = Arvore(Right->freq + Left->freq, Right->letter + Left->letter);
        Pai.right = Right;
        Pai.left = Left;

        Galhos.emplace(Pai);
    }
    return Galhos.top();
};

    // Encoder

// Left => 1, Right => 0
string encode_letter(char L, Arvore G)
{
    string code = "";

    while (G.left != nullptr || G.right != nullptr)
    {
        if (G.left->letter.find(L) != std::string::npos)
        {
            code += '1';
            G = *G.left;
        }
        else
        {
            code += '0';
            G = *G.right;
        }
    }
    return code;
}


string Encoder(string T, Arvore G)
{
    string msg = "";

    for (char& c : T)
    {
        msg += encode_letter(c, G);
    }
    return msg;
}

    // Decoder

string Decoder(string T, Arvore G)
{
    string msg = "";

    Arvore Head = G;

    for (char& c : T)
    {
        if (c == '1')
        {
            G = *G.left;
        }
        else
        {
            G = *G.right;
        }


        if (G.left == nullptr || G.right == nullptr)
        {
            msg += G.letter;
            G = Head;
        }
    }

    return msg;
}


float* huffman_sub_entropy(Arvore Galho, int info)
{
    if (Galho.left == nullptr || Galho.right == nullptr)
    {
        float Freq = static_cast<float> (Galho.freq);

        float* sub_entropy = new float[2];

        sub_entropy[0] = (Freq * info);
        sub_entropy[1] = Freq;
        return sub_entropy;
    }

    float* L = huffman_sub_entropy(*Galho.left, info + 1);
    float* R = huffman_sub_entropy(*Galho.right, info + 1);

    float* entropy = L;
    entropy[0] += R[0];
    entropy[1] += R[1];

    delete R;

    return entropy;
}


float huffman_entropy(Arvore Galho)
{
    float* L = huffman_sub_entropy(*Galho.left, 1);
    float* R = huffman_sub_entropy(*Galho.right, 1);

    float huffman = (L[0] + R[0]) / (L[1] + R[1]);

    delete L;
    delete R;

    return huffman;
}


// Criar um código que recebe uma String e constroi um encoder e um decoder para ela.
int main(){
    
    // Mensagem que será codificada
    string S = "sem perceber, meu corpo se tornou gelido como a superficie do espelho que me encarava";

    cout << "Texto: " << S << "\n";

    priority_queue<Arvore> contador = counter(S);

    float entropia_esperada = Entropia(contador);

    cout << "Entropia esperada: " << entropia_esperada << "\n";

    Arvore Huff = Huffman(contador);

    float entropia_huff = huffman_entropy(Huff);

    cout << "Entropia do codificador: " << entropia_huff << "\n";

    string msg_encoded = Encoder(S, Huff);

    cout << "Mensagem codificada: " << msg_encoded << "\n";

    string msg_decoded = Decoder(msg_encoded, Huff);

    cout << "Mensagem decodificada: " << msg_decoded << "\n";

    bool result = (msg_decoded == S);

    cout << "Resultado: ";
    if (result)
    {
        cout << "True" << "\n";
    }
    else
    {
        cout << "False" << "\n";
    }




    return 0;
}
