#include <iostream>

#include "Fila.hpp"

using namespace std;

// typedef struct Node {
//     int conteudo;
//     Node *esq;
//     Node *dir;
// } Node;

class Node {
   private:
    Node *esq;
    Node *dir;

   public:
    int conteudo;
    Node();

    friend class Arvore;
};

class Arvore {
   private:
    Node *raiz;

    void InserirRecursivamente(Node *&p, int item);
    void ApagarRecursivamente(Node *p);
    void PorNivel();
    void PreOrdem(Node *p);
    void InOrdem(Node *p);
    void PosOrdem(Node *p);

   public:
    Arvore();
    ~Arvore();

    void Inserir(int item);
    bool Remover(int item);
    void Caminhar(int tipo);
    void Limpa();
};

Arvore::Arvore() {
    raiz = NULL;
}

Arvore::~Arvore() {
    Limpa();
}

void Arvore::Inserir(int item) {
    InserirRecursivamente(raiz, item);
}

void Arvore::InserirRecursivamente(Node *&p, int item) {
    if (p == NULL) {
        p = new Node();
        p->conteudo = item;
    } else {
        if (item < p->conteudo) {
            InserirRecursivamente(p->esq, item);
        } else
            InserirRecursivamente(p->dir, item);
    }
}

void Arvore::Limpa() {
    ApagarRecursivamente(raiz);
    raiz = NULL;
}

void Arvore::ApagarRecursivamente(Node *p) {
    if (p != NULL) {
        ApagarRecursivamente(p->esq);
        ApagarRecursivamente(p->dir);
        delete p;
    }
}

void Arvore::PorNivel() {
    Fila f;  // fila de apontadores para nos

    Node *p;
    f.Enfileirar(raiz);
    while (!f.Vazia()) {
        p = f.Desenfileirar();
        if (p != NULL) {
            p->item.Imprime();
            f.Enfileirar(p->esq);
            f.Enfileirar(p->dir);
        }
    }
}

int main() {
    Arvore a;

    for (int i = 0; i < 5; i++) {
        a.Inserir(i);
    }

    for (int i = 0; i < 5; i++) {
        a.Limpa();
    }

    return 0;
}