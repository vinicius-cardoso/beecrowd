#include <iostream>
#include <string>

#define PRE_ORDEM 1
#define IN_ORDEM 2
#define POS_ORDEM 3

using namespace std;

template <class T>
class Arvore;

template <class T>
class No {
   private:
    T conteudo;
    No<T> *esquerda;
    No<T> *direita;

   public:
    No();
    No(T item);
    void SetItem(T item);
    T GetItem();

    friend class Arvore<T>;
};

template <class T>
No<T>::No() {
    conteudo = -1;
    No<T> *esquerda = nullptr;
    No<T> *direita = nullptr;
}

template <class T>
No<T>::No(T item) {
    conteudo = item;
    esquerda = nullptr;
    direita = nullptr;
}

template <class T>
void No<T>::SetItem(T item) {
    conteudo = item;
}

template <class T>
T No<T>::GetItem() {
    return conteudo;
}

template <class T>
class Arvore {
   private:
    No<T> *raiz;
    int tamanho;
    int tamanho_variavel;

    void InserirRecursivo(No<T> *&p, T item);
    void RemoverRecursivo(No<T> *p);
    No<T> PesquisaRecursivo(No<T> *p, T chave);

   public:
    Arvore();
    ~Arvore();

    bool IsVazia();
    int GetTamanho();
    void SetTamanhoVariavel(int tamanho);
    int GetTamanhoVariavel();
    void Inserir(T item);
    void Caminha(int tipo);
    void PreOrdem(No<T> *p);
    void InOrdem(No<T> *p);
    void PosOrdem(No<T> *p);
    No<T> Pesquisa(T chave);
    void Limpa();
};

template <class T>
Arvore<T>::Arvore() {
    this->tamanho = 0;
    this->raiz = nullptr;
}

template <class T>
Arvore<T>::~Arvore() {
    Limpa();
    delete this->raiz;
}

template <class T>
bool Arvore<T>::IsVazia() {
    return this->raiz == -1;
}

template <class T>
int Arvore<T>::GetTamanho() {
    return this->tamanho;
}

template <class T>
void Arvore<T>::SetTamanhoVariavel(int tamanho) {
    this->tamanho_variavel = tamanho;
}

template <class T>
int Arvore<T>::GetTamanhoVariavel() {
    return this->tamanho_fixo;
}

template <class T>
void Arvore<T>::InserirRecursivo(No<T> *&p, T item) {
    if (p == nullptr) {
        p = new No<T>();
        p->SetItem(item);
    } else {
        if (item < p->GetItem())
            InserirRecursivo(p->esquerda, item);
        else
            InserirRecursivo(p->direita, item);
    }
}

template <class T>
void Arvore<T>::Inserir(T item) {
    InserirRecursivo(raiz, item);
    this->tamanho++;
}

template <class T>
void Arvore<T>::Caminha(int tipo) {
    switch (tipo) {
        case 1:
            PreOrdem(raiz);
            cout << endl;
            break;
        case 2:
            InOrdem(raiz);
            cout << endl;
            break;
        case 3:
            PosOrdem(raiz);
            cout << endl;
            break;
    }
}

template <class T>
void Arvore<T>::PreOrdem(No<T> *p) {
    if (p != nullptr) {
        cout << p->conteudo;

        if (this->tamanho_variavel > 1) {
            cout << " ";
        }

        this->tamanho_variavel--;

        PreOrdem(p->esquerda);
        PreOrdem(p->direita);
    }
}

template <class T>
void Arvore<T>::InOrdem(No<T> *p) {
    if (p != nullptr) {
        InOrdem(p->esquerda);
        cout << p->conteudo;

        if (this->tamanho_variavel > 1) {
            cout << " ";
        }

        this->tamanho_variavel--;
        InOrdem(p->direita);
    }
}

template <class T>
void Arvore<T>::PosOrdem(No<T> *p) {
    if (p != nullptr) {
        PosOrdem(p->esquerda);
        PosOrdem(p->direita);

        cout << p->conteudo;

        if (this->tamanho_variavel > 1) {
            cout << " ";
        }

        this->tamanho_variavel--;
    }
}

template <class T>
void Arvore<T>::RemoverRecursivo(No<T> *p) {
    if (p != nullptr) {
        RemoverRecursivo(p->esquerda);
        RemoverRecursivo(p->direita);

        delete p;
    }
}

template <class T>
void Arvore<T>::Limpa() {
    RemoverRecursivo(raiz);
    raiz = nullptr;
}

template <class T>
No<T> Arvore<T>::Pesquisa(T chave) {
    return PesquisaRecursivo(this->raiz, chave);
}

template <class T>
No<T> Arvore<T>::PesquisaRecursivo(No<T> *p, T chave) {
    No<T> aux;

    if (p == nullptr) {
        aux.SetItem(-1);

        return aux;
    }

    if (chave < p->conteudo)
        return PesquisaRecursivo(p->esquerda, chave);
    else if (chave > p->conteudo)
        return PesquisaRecursivo(p->direita, chave);
    else
        return p->conteudo;
}

int main() {
    Arvore<char> a;
    string item;
    char elemento;

    while (cin >> item) {
        if (item == "I") {
            cin >> elemento;
            a.Inserir(elemento);
        } else if (item == "P") {
            cin >> elemento;

            if (a.Pesquisa(elemento).GetItem() == -1) {
                cout << elemento << " nao existe" << endl;
            } else {
                cout << elemento << " existe" << endl;
            }
        } else if (item.length() >= 6) {
            if (item == "INFIXA") {
                a.SetTamanhoVariavel(a.GetTamanho());
                a.Caminha(IN_ORDEM);
            } else if (item == "PREFIXA") {
                a.SetTamanhoVariavel(a.GetTamanho());
                a.Caminha(PRE_ORDEM);
            } else if (item == "POSFIXA") {
                a.SetTamanhoVariavel(a.GetTamanho());
                a.Caminha(POS_ORDEM);
            } else {
                cout << "ERRO";
            }
        }
    }

    return 0;
}