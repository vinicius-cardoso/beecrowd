#include <iostream>

using namespace std;

int main() {
    int qtd_valores;

    cin >> qtd_valores;

    int valores[qtd_valores + 1];

    for (int i = 0; i < qtd_valores; i++) {
        cin >> valores[i];
    }

    for (int i = 0; i < qtd_valores; i++) {
        for (int j = 0; j < qtd_valores - 1; j++) {
            int aux;
            if (valores[j] > valores[j + 1]) {
                aux = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = aux;
            }
        }
    }

    int i, j, k;

    k = 1;

    for (j = 0; j < qtd_valores; j++) {
        if (valores[j] == valores[j + 1])
            k++;
        else {
            cout << valores[j] << " aparece " << k << " vez(es)" << endl;
            k = 1;
        }
    }

    return 0;
}