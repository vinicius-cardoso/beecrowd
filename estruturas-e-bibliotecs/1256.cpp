#include <iostream>

using namespace std;

int main() {
    int casos_teste;
    int enderecos, chaves;
    int chave;

    cin >> casos_teste;

    for (int i = 0; i < casos_teste; i++) {
        if (i != 0)
            cout << endl;

        cin >> enderecos >> chaves;

        int lista_chaves[chaves];

        for (int j = 0; j < chaves; j++) {
            cin >> lista_chaves[j];
        }

        for (int k = 0; k < enderecos; k++) {
            cout << k << " -> ";

            for (int l = 0; l < chaves; l++) {
                if (lista_chaves[l] % enderecos == k)
                    cout << lista_chaves[l] << " -> ";
            }

            cout << "\\" << endl;
        }
    }

    return 0;
}