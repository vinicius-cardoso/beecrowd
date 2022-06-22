#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string nome;
    int ouro;
    int prata;
    int bronze;
} Pais;

void Swap(Pais *paises, int *j) {
    Pais aux = paises[*j + 1];
    paises[*j + 1] = paises[*j];
    paises[*j] = aux;
}

void Ordenar(Pais *paises, int tamanho) {
    // Ordenar por nome
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (paises[j].nome > paises[j + 1].nome) {
                Swap(paises, &j);
            }
        }
    }

    // Ordenar por bronze
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (paises[j].bronze < paises[j + 1].bronze) {
                Swap(paises, &j);
            }
        }
    }

    // Ordenar por prata
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (paises[j].prata < paises[j + 1].prata) {
                Swap(paises, &j);
            }
        }
    }

    // Ordenar por ouro
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (paises[j].ouro < paises[j + 1].ouro) {
                Swap(paises, &j);
            }
        }
    }

    for (int i = 0; i < tamanho; i++) {
        cout << paises[i].nome << " " << paises[i].ouro << " " << paises[i].prata << " " << paises[i].bronze << endl;
    }
}

int main() {
    int N, tamanho;

    cin >> N;

    tamanho = N;

    Pais *paises = new Pais[N];

    while (N--) {
        cin >> paises[N].nome >> paises[N].ouro >> paises[N].prata >> paises[N].bronze;
    }

    Ordenar(paises, tamanho);

    delete[] paises;
}
