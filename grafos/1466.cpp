#include <iostream>
#include <string>

#define MAXTAM 500

using namespace std;

class TipoNo {
   public:
    TipoNo();

   private:
    int item;
    TipoNo* esq;
    TipoNo* dir;

    friend class ArvoreBinaria;
};

TipoNo::TipoNo() {
    item = -1;
    esq = NULL;
    dir = NULL;
};

class FilaArranjo {
   public:
    FilaArranjo();
    bool IsVazia() { return tamanho == 0; };
    void Enfileira(TipoNo* item);
    TipoNo* Desenfileira();
    void Limpa();

   private:
    int frente;
    int tras;
    TipoNo* itens[MAXTAM];

   protected:
    int tamanho = 0;
};

FilaArranjo::FilaArranjo() {
    frente = 0;
    tras = 0;
}

void FilaArranjo::Enfileira(TipoNo* item) {
    itens[tras] = item;
    // fila circular
    tras = (tras + 1) % MAXTAM;

    tamanho++;
}

TipoNo* FilaArranjo::Desenfileira() {
    TipoNo* aux;

    aux = itens[frente];
    // fila circular
    frente = (frente + 1) % MAXTAM;
    tamanho--;

    return aux;
}

void FilaArranjo::Limpa() {
    frente = 0;
    tras = 0;
    tamanho = 0;
}

class ArvoreBinaria {
   public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    void Insere(int item);
    void Limpa();
    void CaminhaNivel(int n);
    int n;

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

void ArvoreBinaria::CaminhaNivel(int n) {
    FilaArranjo F;  // fila de apontadores para nos
    TipoNo* p;

    F.Enfileira(raiz);

    int i = 1;

    while (!F.IsVazia()) {
        p = F.Desenfileira();

        if (p != NULL) {
            cout << p->item;

            if (i != n)
                cout << " ";

            F.Enfileira(p->esq);
            F.Enfileira(p->dir);

            i++;
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
    int c, n;

    cin >> c;

    ArvoreBinaria arvores[c + 1];

    for (int i = 0; i < c; i++) {
        cin >> n;

        int vetor[n + 1];

        for (int j = 0; j < n; j++) {
            cin >> vetor[j];

            arvores[i].Insere(vetor[j]);
            arvores[i].n = n;
        }
    }

    for (int i = 0; i < c; i++) {
        cout << "Case " << i + 1 << ":" << endl;

        arvores[i].CaminhaNivel(arvores[i].n);
        arvores[i].Limpa();
    }
}
