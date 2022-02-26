// beecrowd | 1021 - Notas e Moedas

#include <iostream>

using namespace std;

int main(){
    double valor;
    int reais, centavos;

    cin >> valor;

    reais = valor;
    centavos = (valor - reais) * 100;

    cout << "NOTAS:" << endl;

    cout << reais / 100 << " nota(s) de R$ 100.00" << endl;

    reais = reais % 100;
    cout << reais / 50 << " nota(s) de R$ 50.00" << endl;

    reais = reais % 50;
    cout << reais / 20 << " nota(s) de R$ 20.00" << endl;

    reais = reais % 20;
    cout << reais / 10 << " nota(s) de R$ 10.00" << endl;

    reais = reais % 10;
    cout << reais / 5 << " nota(s) de R$ 5.00" << endl;

    reais = reais % 5;
    cout << reais / 2 << " nota(s) de R$ 2.00" << endl;

    cout << "MOEDAS:" << endl;

    reais = reais % 2;
    cout << reais / 1 << " moeda(s) de R$ 1.00" << endl;

    centavos = centavos % 100;
    cout << centavos / 50 << " moeda(s) de R$ 0.50" << endl;

    centavos = centavos % 50;
    cout << centavos / 25 << " moeda(s) de R$ 0.25" << endl;

    centavos = centavos % 25;
    cout << centavos / 10 << " moeda(s) de R$ 0.10" << endl;

    centavos = centavos % 5;
    cout << centavos / 5 << " moeda(s) de R$ 0.05" << endl;

    centavos = centavos % 5;
    cout << centavos / 1 << " moeda(s) de R$ 0.01" << endl;

    return 0;
}