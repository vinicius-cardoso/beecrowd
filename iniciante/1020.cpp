#include <iostream>

using namespace std;

int main(){
    int dias, meses, anos;

    cin >> dias;

    anos = dias / 365;
    dias = dias % 365;

    meses = dias / 30;
    dias = dias % 30;

    cout << anos << " ano (s)" << endl;
    cout << meses << " mes (es)" << endl;
    cout << dias << " dia (s)" << endl;

    return 0;
}