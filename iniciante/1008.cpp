#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Funcionario{
    int numero;
    int horas;
    float phora;
    float salario;
};

int main(){
    Funcionario f;

    cin >> f.numero; 
    cin >> f.horas; 
    cin >> f.phora;

    f.salario = f.horas * f.phora;

    cout << "NUMBER = " << f.numero << endl;

    cout << "SALARY = U$ " << fixed << setprecision(2) << f.salario << endl;

    return 0;
}