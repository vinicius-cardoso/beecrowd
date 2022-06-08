#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    Node *prox;
} Node;

class Pilha {
   private:
    Node *topo;
    int tamanho = 0;

   public:
    Pilha();
    ~Pilha();
    void Empilhar();
    void Desempilhar();
    bool IsVazia();
    int GetTamanho();
};

Pilha::Pilha() {
    topo = NULL;
}

Pilha::~Pilha() {
    while (topo != NULL) {
        Node *aux = topo;
        topo = topo->prox;

        delete aux;
    }
}

void Pilha::Empilhar() {
    Node *aux;

    aux = new Node;
    aux->prox = topo;
    topo = aux;

    tamanho++;
}

void Pilha::Desempilhar() {
    if (topo != NULL) {
        Node *aux = topo;
        topo = topo->prox;

        delete aux;

        tamanho--;
    }
}

bool Pilha::IsVazia() {
    if (topo == NULL)
        return true;
    else
        return false;
}

int Pilha::GetTamanho() {
    return tamanho;
}

int main() {
    Pilha p;

    string entrada;
    cin >> entrada;

    for (int i = 0; i < entrada.size(); i++) {
        if (entrada[i] == '(') {
            p.Empilhar();
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
