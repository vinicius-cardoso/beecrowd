#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Vendedor{
    char nome[20];
    double salario;
    double montante;
    double total;
};

int main(){
    Vendedor v;

    cin >> v.nome;
    cin >> v.salario;
    cin >> v.montante;

    v.total = v.salario + (v.montante * 0.15);

    cout << "TOTAL = R$ " << fixed << setprecision(2) << v.total << endl;

    return 0;
}