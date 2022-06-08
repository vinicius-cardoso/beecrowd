#include <iostream>

#include "FilaArranjo.hpp"

class ArvoreBinaria {
   public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void Insere(int item);
    void Limpa();
    void CaminhaNivel();

   private:
    void InsereRecursivo(TipoNo*& p, int item);
    void ApagaRecursivo(TipoNo* p);

    TipoNo* raiz;
};

ArvoreBinaria::ArvoreBinaria() {
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpa();
}

void ArvoreBinaria::Insere(int item) {
    InsereRecursivo(raiz, item);
}
void ArvoreBinaria::InsereRecursivo(TipoNo*& p, int item) {
    if (p == NULL) {
        p = new TipoNo();
        p->item = item;
    } else {
        if (item < p->item)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::CaminhaNivel() {
    FilaArranjo F;  // fila de apontadores para nos
    TipoNo* p;

    F.Enfileira(raiz);

    while (!F.IsVazia()) {
        p = F.Desenfileira();
        if (p != NULL) {
            cout << p->item << " ";
            F.Enfileira(p->esq);
            F.Enfileira(p->dir);
        }
    }

    cout << endl
         << endl;
}

void ArvoreBinaria::Limpa() {
    ApagaRecursivo(raiz);
    raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo* p) {
    if (p != NULL) {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);

        delete p;
    }
}

int main() {
    ArvoreBinaria a;

    int c, n;

    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> n;

        int vetor[n + 1];

        for (int j = 0; j < n; j++) {
            cin >> vetor[j];

            a.Insere(vetor[j]);
        }

        cout << "Case " << i + 1 << ":" << endl;

        a.CaminhaNivel();

        a.Limpa();
    }
}