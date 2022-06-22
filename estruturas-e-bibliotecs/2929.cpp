#include <iostream>
#include <string>

using namespace std;

// class No {
//    private:
//     int conteudo;
//     No *proximo;

//    public:
//     No();
//     No(int item);

//     friend class Pilha;
// };

// No::No() {
//     conteudo = -1;
//     No *proximo = nullptr;
// }

// No::No(int item) {
//     conteudo = item;
//     proximo = nullptr;
// }

// class Pilha {
//    private:
//     int tamanho;
//     No *topo;

//    public:
//     Pilha();
//     ~Pilha();

//     bool IsVazia();
//     int GetTamanho();
//     void Empilhar(int item);
//     void Desempilhar();
//     void Limpa();
//     int GetMin();
// };

// Pilha::Pilha() {
//     topo = new No();
//     tamanho = 0;
// }

// Pilha::~Pilha() {
//     Limpa();
//     delete topo;
// }

// bool Pilha::IsVazia() {
//     return topo == nullptr;
// }

// int Pilha::GetTamanho() {
//     return tamanho;
// }

// void Pilha::Empilhar(int item) {
//     No *nova = new No();

//     nova->conteudo = item;
//     nova->proximo = topo;
//     topo = nova;

//     tamanho++;
// }

// void Pilha::Desempilhar() {
//     if (tamanho == 0)
//         throw "Pilha vazia!";

//     No *aux = topo;
//     topo = topo->proximo;

//     delete aux;

//     tamanho--;
// }

// void Pilha::Limpa() {
//     No *p;
//     p = topo->proximo;

//     while (p != nullptr) {
//         topo->proximo = p->proximo;
//         delete p;
//         p = topo->proximo;
//     }

//     tamanho = 0;
// }

// int Pilha::GetMin() {
//     No *p = topo;

//     int menor = 1000000;

//     while (p->proximo != nullptr) {
//         if (p->conteudo < menor) {
//             menor = p->conteudo;
//         } else {
//             p = p->proximo;
//         }
//     }

//     return menor;
// }

class Pilha {
   private:
    int tamanho;

   public:
    Pilha();
    ~Pilha();

    int menor;
    int topo;
    bool IsVazia();
    int GetTamanho();
    void Empilhar(int item);
    void Desempilhar();
    void GetMin();
};

Pilha::Pilha() {
    topo = 0;
    tamanho = 0;
}

Pilha::~Pilha() {
}

int Pilha::GetTamanho() {
    return tamanho;
}

void Pilha::Empilhar(int elemento) {
    if (GetTamanho() == 0) {
        menor = elemento;

        Empilhar(elemento);

        return;
    }

    else if (elemento < menor) {
        Empilhar(2 * elemento - menor);
        menor = elemento;
    }

    else
        Empilhar(elemento);
}

void Pilha::Desempilhar() {
    if (GetTamanho() == 0) {
        cout << "EMPTY";
        return;
    }

    int t = topo;

    Desempilhar();

    if (t < menor) {
        menor = 2 * menor - t;
    }

    else
        cout << t << endl;
}

void Pilha::GetMin() {
    if (GetTamanho() == 0)
        cout << "EMPTY";
    else
        cout << menor << endl;
}

int main() {
    int N;
    int elemento;
    string comando;

    Pilha p;

    cin >> N;

    while (N--) {
        cin >> comando;

        if (comando == "PUSH") {
            cin >> elemento;
            p.Empilhar(elemento);
        } else if (comando == "POP") {
            // if (p.GetTamanho() == 0) {
            //     cout << "EMPTY" << endl;
            // } else {
            p.Desempilhar();
            // }

            continue;
        } else if (comando == "MIN") {
            // if (p.GetTamanho() == 0)
            //     cout << "EMPTY" << endl;
            // else
            // cout << p.GetMin() << endl;
            p.GetMin();

            continue;
        }
    }

    return 0;
}
