#include <iostream>

using namespace std;

typedef struct Node {
    int conteudo;
    Node *proximo;
} Node;

class Fila {
   private:
    Node *inicio;
    Node *fim;
    int tamanho = 0;

   public:
    Fila();
    ~Fila();

    void Enfileirar(int item);
    int Desenfileirar();
    void Limpa();
};

Fila::Fila() {
    inicio = new Node;
    fim = inicio;
}

Fila::~Fila() {
    Limpa();

    delete inicio;
}

void Fila::Enfileirar(int item) {
    Node *novo;

    novo = new Node;
    novo->conteudo = item;
    fim->proximo = novo;
    fim = novo;

    tamanho++;
}

int Fila::Desenfileirar() {
    Node *p;
    int aux;

    if (tamanho == 0)
        throw "Fila vazia!";

    aux = inicio->proximo->conteudo;

    p = inicio;
    inicio = inicio->proximo;

    delete p;

    tamanho--;

    return aux;
}

void Fila::Limpa() {
    Node *p;

    p = inicio->proximo;

    while (p != NULL) {
        inicio->proximo = p->proximo;

        delete p;

        p = inicio->proximo;
    }

    tamanho = 0;

    fim = inicio;
}

int main() {
    Fila f;

    for (int i = 0; i < 10; i++) {
        f.Enfileirar(i);
    }

    for (int i = 0; i < 10; i++) {
        cout << f.Desenfileirar();
    }
}