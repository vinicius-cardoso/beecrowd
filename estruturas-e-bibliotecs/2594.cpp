#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int numero_de_textos;
    string palavra;

    cin >> numero_de_textos;
    cin.ignore();

    for (int i = 0; i < numero_de_textos; i++) {
        string texto, palavra, aux;
        int espacos = 0;

        getline(cin, texto);
        getline(cin, palavra);

        stringstream ss(texto);

        for (int j = 0; j < texto.size(); j++) {
            if (texto[j] == ' ') {
                espacos++;
            }
        }

        string palavras[espacos + 1];
        int indice = 0;

        while (getline(ss, aux, ' ')) {
            palavras[indice] = aux;

            indice++;
        }

        int local = 0;
        bool encontrado = false;

        for (int k = 0; k <= espacos; k++) {
            if (palavra == palavras[k]) {
                if (encontrado) {
                    cout << " ";
                }

                cout << local;

                encontrado = true;
            }

            local += palavras[k].size() + 1;
        }

        if (!encontrado)
            cout << "-1";

        cout << endl;
    }

    return 0;
}
