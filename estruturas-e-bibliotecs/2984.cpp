#include <iostream>
#include <string>

using namespace std;

class Pilha {
   private:
    int *pilha;
    int max_tam;
    int topo;

   public:
    Pilha();
    ~Pilha();
    void Empilhar(char elem);
    void Desempilhar();
    bool IsVazia();
    int GetTamanho();
};

Pilha::Pilha() {
    pilha = new int[100000];
    max_tam = 100000;
    topo = -1;
}

Pilha::~Pilha() {
    delete[] pilha;
}

void Pilha::Empilhar(char elem) {
    if (topo == max_tam)
        throw "Pilha cheia!";
    else
        pilha[++topo] = elem;
}

void Pilha::Desempilhar() {
    if (topo == -1)
        throw "Pilha vazia!";
    else
        topo--;
}

bool Pilha::IsVazia() {
    if (topo == -1)
        return true;
    else
        return false;
}

int Pilha::GetTamanho() {
    return topo + 1;
}

int main() {
    Pilha p;

    string entrada;

    cin >> entrada;

    for (int i = 0; i < entrada.size(); i++) {
        if (entrada[i] == '(') {
            p.Empilhar(entrada[i]);
        } else if (entrada[i] == ')') {
            if (p.IsVazia()) {
                continue;
            } else {
                p.Desempilhar();
            }
        } else {
            throw "Erro";
        }
    }

    if (p.IsVazia()) {
        cout << "Partiu RU!" << endl;
    } else {
        cout << "Ainda temos " << p.GetTamanho() << " assunto(s) pendente(s)!" << endl;
    }

    return 0;
}
