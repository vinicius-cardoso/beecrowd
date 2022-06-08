#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
    string palavra;
    int tamanho;
} Palavra;

int main() {
    int casos_de_teste;

    cin >> casos_de_teste;

    string lista_palavras[casos_de_teste][50];

    for (int i = 0; i < casos_de_teste; i++) {
        string frase, aux;
        int espacos = 0;

        while (getline(cin, frase))
            if (frase != "")
                break;

        stringstream ss(frase);

        for (int j = 0; j < frase.size(); j++) {
            if (frase[j] == ' ') {
                espacos++;
            }
        }

        Palavra palavras[espacos + 1];
        int indice = 0;

        while (getline(ss, aux, ' ')) {
            palavras[indice].palavra = aux;
            palavras[indice].tamanho = aux.size();

            indice++;
        }

        for (int k = 0; k < indice; k++) {
            for (int l = 0; l < indice - k - 1; l++) {
                if (palavras[l].tamanho < palavras[l + 1].tamanho) {
                    Palavra aux = palavras[l];
                    palavras[l] = palavras[l + 1];
                    palavras[l + 1] = aux;
                }
            }
        }

        for (int m = 0; m < indice; m++) {
            lista_palavras[i][m] = palavras[m].palavra;
        }
    }

    for (int i = 0; i < casos_de_teste; i++) {
        for (int j = 0; j < 50; j++) {
            cout << lista_palavras[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
