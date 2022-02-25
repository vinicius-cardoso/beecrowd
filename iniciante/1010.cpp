#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Peca{
    int codigo;
    int nr_pecas;
    float valor;
};

int main(){
    Peca p1, p2;
    float total;

    cin >> p1.codigo >> p1.nr_pecas >> p1.valor;  
    cin >> p2.codigo >> p2.nr_pecas >> p2.valor;  

    total = (p1.nr_pecas * p1.valor) + (p2.nr_pecas * p2.valor);

    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << total << endl;

    return 0;
}