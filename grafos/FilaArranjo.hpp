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
    static const int MAXTAM = 8;
    TipoNo* itens[MAXTAM];

   protected:
    int tamanho = 0;
};

FilaArranjo::FilaArranjo() {
    frente = 0;
    tras = 0;
}

void FilaArranjo::Enfileira(TipoNo* item) {
    if (tamanho == MAXTAM)
        throw "Fila Cheia!";

    itens[tras] = item;
    // fila circular
    tras = (tras + 1) % MAXTAM;

    tamanho++;
}

TipoNo* FilaArranjo::Desenfileira() {
    TipoNo* aux;

    if (tamanho == 0)
        throw "Fila está vazia!";

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