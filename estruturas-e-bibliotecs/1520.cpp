#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int casos_teste;

    while (cin >> casos_teste) {
        int inicio, fim;
        int pesquisa;
        vector<int> numeros;
        int indice = 0;

        for (int i = 0; i < casos_teste; i++) {
            cin >> inicio >> fim;

            for (int num = inicio; num <= fim; num++) {
                numeros.push_back(num);

                indice++;
            }
        }

        cin >> pesquisa;

        sort(numeros.begin(), numeros.end());

        bool aparece = false;
        int primeira_aparicao, ultima_aparicao;

        for (int i = 0; i < indice; i++) {
            if (pesquisa == numeros[i]) {
                aparece = true;
                primeira_aparicao = i;

                while (pesquisa == numeros[i]) {
                    i++;
                }

                ultima_aparicao = i - 1;
            }
        }

        if (aparece == false) {
            cout << pesquisa << " not found" << endl;
        } else {
            cout << pesquisa << " found from " << primeira_aparicao << " to " << ultima_aparicao << endl;
        }
    }

    return 0;
}
